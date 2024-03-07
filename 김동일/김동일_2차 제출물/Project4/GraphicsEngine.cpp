#include "pch.h"
#include "GraphicsEngine.h"


void GraphicsEngine::Initialize(HWND hwnd, float screenWidth, float screenHeight)
{
	// DirectX 그래픽 인터페이스 팩토리를 생성한다.
	IDXGIFactory* factory = nullptr;
	if (FAILED(CreateDXGIFactory(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&factory))))
		assert(!"error");


	// 팩토리 객체를 사용하여 첫번째 그래픽 카드 인터페이스 어뎁터를 생성한다.
	IDXGIAdapter* adapter = nullptr;
	if (FAILED(factory->EnumAdapters(0, &adapter)))
		assert(!"error");

	// 출력(모니터)에 대한 첫번째 어뎁터를 지정한다.
	IDXGIOutput* adapterOutput = nullptr;
	if (FAILED(adapter->EnumOutputs(0, &adapterOutput)))
		assert(!"error");

	// 출력(모니터)에 대한 DXGI_FORMAT_R8G8B8A8_UNORM 표시 형식에 맞는 모드수를 가져옵니다.
	unsigned int numModes = 0;
	if (FAILED(adapterOutput->GetDisplayModeList(DXGI_FORMAT_B8G8R8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, NULL)))
		assert(!"error");

	// 가능한 모든 모니터와 그래픽카드 조합을 저장할 리스트를 생성한다.
	DXGI_MODE_DESC* displayModeList = new DXGI_MODE_DESC[numModes];
	if (!displayModeList)
		assert(!"error");

	// 이제 디스플레이 모드에 대한 리스트를 채운다.
	if (FAILED(adapterOutput->GetDisplayModeList(DXGI_FORMAT_B8G8R8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, displayModeList)))
		assert(!"error");


	// 이제 모든 디스플레이 모드에 대해 화면 너비/높이에 맞는 디스플레이 모드를 찾는다.
	// 적합한 것을 찾으면 모니터의 새로고침 비율의 분모와 분자값을 저장한다.
	unsigned int numerator = 0;
	unsigned int denominator = 0;


	for (unsigned int i = 0; i < numModes; ++i)
	{
		if (displayModeList[i].Width == static_cast<unsigned>(screenWidth))
		{
			if (displayModeList[i].Height == static_cast<unsigned>(screenHeight))
			{
				numerator = displayModeList[i].RefreshRate.Numerator;
				denominator = displayModeList[i].RefreshRate.Denominator;
			}
		}
	}

	// 비디오카드의 구조체를 얻는다.
	DXGI_ADAPTER_DESC adapterDesc;
	if (FAILED(adapter->GetDesc(&adapterDesc)))
		assert(!"error");

	// 비디오카드 메모리 용량 단위를 메가바이트 단위로 저장한다.
	m_videoCardMemory = static_cast<int>(adapterDesc.DedicatedVideoMemory / 1024 / 1024);


	// 비디오카드의 이름을 저장합니다.
	size_t stringLength = 0;
	if (wcstombs_s(&stringLength, m_videoCardDescription, 128, adapterDesc.Description, 128) != 0)
		assert(!"error");


	// 그래픽 카드 확인 용도.
	const WCHAR* pwcsName;

	// required size
	int size = MultiByteToWideChar(CP_ACP, 0, m_videoCardDescription, -1, NULL, 0);

	// allocate it
	pwcsName = new WCHAR[stringLength];
	MultiByteToWideChar(CP_ACP, 0, m_videoCardDescription, -1, (LPWSTR)pwcsName, size);
	// use it....

	OutputDebugString(pwcsName);
	// delete it
	delete[] pwcsName;

	// 디스플레이 모드 리스트를 해제한다.
	delete[] displayModeList;
	displayModeList = nullptr;

	// 출력 어뎁터를 해제한다.
	adapterOutput->Release();
	adapterOutput = nullptr;

	// 어뎁터를 해제한다.
	adapter->Release();
	adapter = nullptr;


	// 스왑체인 구조체를 초기환한다.
	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));

	// 백버퍼를 1개만 사용하도록 지정한다.
	swapChainDesc.BufferCount = 1;

	// 백버퍼의 넓이와 높이를 지정한다.
	swapChainDesc.BufferDesc.Width = screenWidth;
	swapChainDesc.BufferDesc.Height = screenHeight;

	// 33bit 서피스를 설정한다.
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;

	// 백버퍼의 새로고침 비율을 설정한다.
	swapChainDesc.BufferDesc.RefreshRate.Numerator = numerator;
	swapChainDesc.BufferDesc.RefreshRate.Denominator = denominator;

	// 백버퍼의 사용용도를 지정한다.
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

	// 랜더링에 사용될 윈도우 핸들을 지정한다.
	swapChainDesc.OutputWindow = hwnd;

	// 멀티샘플링을 끈다.
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;

	// 창모드 or 풀스크린 모드를 설정한다.
	swapChainDesc.Windowed = true;


	// 스캔 라인 순서 및 크기를 지정하지 않음으로 설정한다.
	swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

	// 출력된 다음 백버퍼를 비우도록 지정한다.
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	// 추가 옵션 플래그를 사용하지 않는다.
	swapChainDesc.Flags = 0;

	// 피처레벨을 DirectX11로 설정한다.
	D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;

	// 스왑 체인, Direct3D 장치 및 Direct3D 장치 컨텍스트를 만든다.
	if (FAILED(D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, 0, &featureLevel, 1,
		D3D11_SDK_VERSION, &swapChainDesc, &m_swapChain, &m_device, NULL, &m_deviceContext)))
		assert(!"error");


	// 백버퍼 포인터를 얻어온다.
	ID3D11Texture2D* backBufferPtr = nullptr;
	if (FAILED(m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<LPVOID*>(&(backBufferPtr)))))
		assert(!"error");


	// 백 버퍼 포인터로 랜더 타겟 뷰를 생성한다.
	if (FAILED(m_device->CreateRenderTargetView(backBufferPtr, NULL, &m_renderTargetView)))
		assert(!"error");


	// 백버퍼 포인터를 해제한다.
	backBufferPtr->Release();
	backBufferPtr = nullptr;


	//VSBlob
	HRESULT hr;
	hr = D3DCompileFromFile
	(
		L"Color.hlsl", // HLSL 파일 경로
		nullptr,
		nullptr,
		"VS", // 진입점 함수 이름
		"vs_5_0", // HLSL 프로파일
		0,
		0,
		&m_vsBlob,
		nullptr
	);
	assert(SUCCEEDED(hr));

	//Create VertexShader
	hr = m_device->CreateVertexShader
	(
		m_vsBlob->GetBufferPointer(),
		m_vsBlob->GetBufferSize(),
		NULL,
		&m_vertexShader
	);
	assert(SUCCEEDED(hr));

	hr = D3DCompileFromFile
	(
		L"Color.hlsl", // HLSL 파일 경로
		nullptr,
		nullptr,
		"PS", // 진입점 함수 이름
		"ps_5_0", // HLSL 프로파일
		0,
		0,
		&m_psBlob,
		nullptr
	);
	assert(SUCCEEDED(hr));

	//Create PixelShader
	hr = m_device->CreatePixelShader
	(
		m_psBlob->GetBufferPointer(),
		m_psBlob->GetBufferSize(),
		NULL,
		&m_pixelShader
	);
	assert(SUCCEEDED(hr));

	//Set Shader
	m_deviceContext->VSSetShader(m_vertexShader, 0, 0);
	m_deviceContext->PSSetShader(m_pixelShader, 0, 0);


	// 깊이 버퍼 구조체를 초기화 합니다.
	D3D11_TEXTURE2D_DESC depthBufferDesc;
	ZeroMemory(&depthBufferDesc, sizeof(depthBufferDesc));

	// 깊이 버퍼 구조체를 작성합니다.
	depthBufferDesc.Width = screenWidth;
	depthBufferDesc.Height = screenHeight;
	depthBufferDesc.MipLevels = 1;
	depthBufferDesc.ArraySize = 1;
	depthBufferDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	depthBufferDesc.SampleDesc.Count = 1;
	depthBufferDesc.SampleDesc.Quality = 0;
	depthBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	depthBufferDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	depthBufferDesc.CPUAccessFlags = 0;
	depthBufferDesc.MiscFlags = 0;

	// 설정된 깊이버퍼 구조체를 사용하여 깊이 버퍼 텍스쳐를 생성한다.
	if (FAILED(m_device->CreateTexture2D(&depthBufferDesc, NULL, &m_depthStencilBuffer)))
		assert(!"error");

	// 스텐실 상태 구조체를 초기화 합니다.

	D3D11_DEPTH_STENCIL_DESC depthStencilDesc;
	ZeroMemory(&depthStencilDesc, sizeof(depthStencilDesc));

	// 스텐실 상태 구조체를 작성합니다.
	depthStencilDesc.DepthEnable = true;
	depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	depthStencilDesc.DepthFunc = D3D11_COMPARISON_LESS;

	depthStencilDesc.StencilEnable = true;
	depthStencilDesc.StencilReadMask = 0xFF;
	depthStencilDesc.StencilWriteMask = 0xFF;

	// 픽셀 정면의 스텐실 설정입니다.
	depthStencilDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
	depthStencilDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	// 픽셀 뒷면의 스텐실 설정입니다.
	depthStencilDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
	depthStencilDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	// 깊이 스텐실 상태를 설정합니다.
	m_deviceContext->OMSetDepthStencilState(m_depthStencilState, 1);


	// 깊이 스텐실 뷰의 구조체를 초기화합니다.
	D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc;
	ZeroMemory(&depthStencilViewDesc, sizeof(depthStencilViewDesc));

	// 깊이 스텐실 뷰 구조체를 설정한다.
	depthStencilViewDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	depthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	depthStencilViewDesc.Texture2D.MipSlice = 0;

	// 깊이 스텐실 뷰를 생성한다.
	if (FAILED(m_device->CreateDepthStencilView(m_depthStencilBuffer, &depthStencilViewDesc, &m_depthStencilView)))
		assert(!"error");

	// 랜더링 대상 뷰와 깊이 스텐실 버퍼를  출력 렌더 파이프 라인에 바인딩 한다.
	m_deviceContext->OMSetRenderTargets(1, &m_renderTargetView, m_depthStencilView);

	// 그려지는 폴리곤과 방법을 결정할 레스터 구조체를 설정한다.
	D3D11_RASTERIZER_DESC rasterDesc;
	rasterDesc.AntialiasedLineEnable = false;
	rasterDesc.CullMode = D3D11_CULL_BACK;
	rasterDesc.DepthBias = 0;
	rasterDesc.DepthBiasClamp = 0.0f;
	rasterDesc.DepthClipEnable = true;
	rasterDesc.FillMode = D3D11_FILL_SOLID;
	rasterDesc.FrontCounterClockwise = false;
	rasterDesc.MultisampleEnable = false;
	rasterDesc.ScissorEnable = false;
	rasterDesc.SlopeScaledDepthBias = 0.0f;

	// 방금 작성한 구조체에서 레스터 라이저 상태를 만든다.
	if (FAILED(m_device->CreateRasterizerState(&rasterDesc, &m_rasterState)))
		assert(!"error");

	// 이제 레스터 라이저 상태를 설정한다.
	m_deviceContext->RSSetState(m_rasterState);

	// 렌더링을 위해 뷰포트를 설정한다.
	D3D11_VIEWPORT viewport;
	viewport.Width = static_cast<float>(screenWidth);
	viewport.Height = static_cast<float>(screenHeight);
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;
	viewport.TopLeftX = 0.0f;
	viewport.TopLeftY = 0.0f;

	// 뷰포트를 생성한다.
	m_deviceContext->RSSetViewports(1, &viewport);

	// 투영 행렬을 설정한다.
	//float fieldOfView= 3.141592654 / 4.0f;
	//float screenAspect= static_cast<float>(screenWidth) / static_cast<float>(screenHeight);

	// 3D 렌더링을 위핸 투영 행렬을 만든다.
	//m_projectionMatrix= XMMatrixPerspectiveFovLH(fieldOfView, screenAspect, screenNear, screenDepth);

	// 세계 행렬을 항동 행렬로 초기화 한다.
	//m_worldMatrix= XMMatrixIdentity();

	// 2D렌더링을위한 직교 투영 행렬을 만든다.
	//m_orthoMatrix= XMMatrixOrthographicLH(stat
	// ic_cast<float>(screenWidth), static_cast<float>(screenHeight), screenNear, screenDepth);

	D3D11_INPUT_ELEMENT_DESC layoutDesc[] =
	{
		{
			"POSITION", //SemanticName
			0,
			DXGI_FORMAT_R32G32B32_FLOAT,
			0,
			0,
			D3D11_INPUT_PER_VERTEX_DATA,
			0
		},

		{
			"COLOR", //SemanticName
			0,
			DXGI_FORMAT_R32G32B32_FLOAT,
			0,
			12,
			D3D11_INPUT_PER_VERTEX_DATA,
			0
		}
	};

	Vertex vertices[4];

	vertices[0].Position = DirectX::XMFLOAT3(+0.5f, -0.5f, 0.0f);
	vertices[1].Position = DirectX::XMFLOAT3(-0.5f, -0.5f, 0.0f);
	vertices[2].Position = DirectX::XMFLOAT3(-0.5f, +0.5f, 0.0f);
	vertices[3].Position = DirectX::XMFLOAT3(+0.5f, -0.5f, 0.0f);

	vertices[0].Color = DirectX::XMFLOAT4(1, 0, 0, 1);
	vertices[1].Color = DirectX::XMFLOAT4(1, 0, 0, 1);
	vertices[2].Color = DirectX::XMFLOAT4(1, 0, 0, 1);
	vertices[3].Color = DirectX::XMFLOAT4(1, 0, 0, 1);

	//Create VertexBuffer
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.ByteWidth = sizeof(Vertex) * 4;
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

		D3D11_SUBRESOURCE_DATA data;
		ZeroMemory(&data, sizeof(D3D11_SUBRESOURCE_DATA));
		data.pSysMem = vertices;

		HRESULT hr = m_device->CreateBuffer(&desc, &data, &m_vertexBuffer);
		assert(SUCCEEDED(hr));
	}

	//Create InputLayout
	{
		HRESULT hr = m_device->CreateInputLayout
		(
			layoutDesc,
			2,
			m_vsBlob->GetBufferPointer(),
			m_vsBlob->GetBufferSize(),
			&m_inputLayout
		);
		assert(SUCCEEDED(hr));
	}
}

void GraphicsEngine::Update()
{
	
}

void GraphicsEngine::Render()
{
	BeginDraw();

	if(m_list.Size() != 0)
	{
		int n = m_list.Size();
		for (int i = 0; i < n; ++i)
		{
			UINT stride = sizeof(Vertex);
			UINT offset = 0;

			m_deviceContext->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);
			m_deviceContext->IASetInputLayout(m_inputLayout);
			m_deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);

			m_deviceContext->Draw(4, 0);
		}
	}

	EndDraw();
}

void GraphicsEngine::Finalize()
{
	Shutdown();
}

void GraphicsEngine::Shutdown()
{
	if (m_swapChain)
	{
		m_swapChain->SetFullscreenState(false, nullptr);
	}

	if (m_rasterState)
	{
		m_rasterState->Release();
		m_rasterState = nullptr;
	}

	if (m_depthStencilView)
	{
		m_depthStencilView->Release();
		m_depthStencilView = nullptr;
	}

	if (m_depthStencilState)
	{
		m_depthStencilState->Release();
		m_depthStencilState = nullptr;
	}

	if (m_depthStencilBuffer)
	{
		m_depthStencilBuffer->Release();
		m_depthStencilBuffer = nullptr;
	}

	if (m_renderTargetView)
	{
		m_renderTargetView->Release();
		m_renderTargetView = nullptr;
	}

	if (m_deviceContext)
	{
		m_deviceContext->Release();
		m_deviceContext = nullptr;
	}

	if (m_device)
	{
		m_device->Release();
		m_device = nullptr;
	}

	if (m_swapChain)
	{
		m_swapChain->Release();
		m_swapChain = nullptr;
	}
}

void GraphicsEngine::BeginDraw()
{
	float color[4] = { 1, 1, 1, 1 };
	// 백버퍼를 지운다.
	m_deviceContext->ClearRenderTargetView(m_renderTargetView, color);

	// 깊이 버퍼를 지운다.
	m_deviceContext->ClearDepthStencilView(m_depthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
}

void GraphicsEngine::EndDraw()
{
	m_swapChain->Present(1, 0);
}