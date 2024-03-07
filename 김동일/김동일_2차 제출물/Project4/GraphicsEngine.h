#pragma once

#include <d3d11.h>
#include <d3dcompiler.h>
#include <directxmath.h>
#include "Linkedlist.h"

struct Vertex
{
	DirectX::XMFLOAT3 Position;
	DirectX::XMFLOAT4 Color;
};

class GraphicsEngine
{
public:
	GraphicsEngine() {};
	~GraphicsEngine() {};

	void Initialize(HWND hwnd, float screenWidth, float screenHeight);
	void Update();
	void Render();
	void Finalize();

	void Shutdown();
	void BeginDraw();
	void EndDraw();

private:
	IDXGISwapChain* m_swapChain = nullptr;
	ID3D11Device* m_device = nullptr;
	ID3D11DeviceContext* m_deviceContext = nullptr;
	ID3D11RenderTargetView* m_renderTargetView = nullptr;
	ID3D11Texture2D* m_depthStencilBuffer = nullptr;
	ID3D11DepthStencilState* m_depthStencilState = nullptr;
	ID3D11DepthStencilView* m_depthStencilView = nullptr;
	ID3D11RasterizerState* m_rasterState = nullptr;
	//DirectX::XMMATRIX m_projectionMatrix;
	//DirectX::XMMATRIX m_worldMatrix;
	//DirectX::XMMATRIX m_orthoMatrix;
	int m_videoCardMemory = 0;
	char m_videoCardDescription[128] = { 0, };

	ID3D10Blob* m_vsBlob;
	ID3D10Blob* m_psBlob;
	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;
	ID3D11Buffer* m_vertexBuffer;
	ID3D11InputLayout* m_inputLayout;

public:
	Linkedlist<int> m_list;
};

