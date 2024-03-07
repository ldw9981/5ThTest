#pragma once

template<typename T>
class Data
{
public:
	T m_data;

	Data* m_Prev = nullptr;
	Data* m_Next = nullptr;

	void PushFront(Data* _Data)
	{
		m_Prev = _Data;
		_Data->m_Next = this;
	}

	void PushBack(Data* _Data)
	{
		m_Next = _Data;
		_Data->m_Prev = this;
	}

	void Delete()
	{
		m_Prev->m_Next = m_Next;
		m_Next->m_Prev = m_Prev;
		m_Prev = m_Next = nullptr;
	}

	Data* Find(int& _Index, int _FindIndex)
	{

		if (_Index == _FindIndex)
			return this;
		else
		{
			if (m_Next == nullptr)
			{
				return nullptr;
			}
			_Index++;
			return m_Next->Find(_Index, _FindIndex);
		}
	}

	void DeleteAll()
	{
		if (m_Next != nullptr)
		{
			m_Next->DeleteAll();
			delete m_Next;
			m_Next = nullptr;
		}
	}
};

template<typename T>
class LinkedList
{
public:
	Data<T>* m_Head = nullptr;
	Data<T>* m_Tail = nullptr;

	void PushFront(T _data)
	{
		Data<T>* data = new Data<T>;
		data->m_data = _data;
		if (m_Head == nullptr)
		{
			m_Head = m_Tail = data;
			m_Head->PushBack(data);
			m_Tail->PushFront(data);
			return;
		}

		m_Head->PushFront(data);
		m_Head = data;
	}

	void PushBack(T _data)
	{
		Data<T>* data = new Data<T>;
		data->m_data = _data;
		if (m_Tail == nullptr)
		{
			m_Head = m_Tail = data;
			m_Head->PushBack(data);
			m_Tail->PushFront(data);
			return;
		}

		m_Tail->PushBack(data);
		m_Tail = data;
	}

	void Insert(int _FindIndex, T _data)
	{
		if (m_Head == nullptr)
		{
			PushFront(_data);
			return;
		}
		int index = 0;
		Data<T>* data;
		data = m_Head->Find(index, _FindIndex);
		if (data != nullptr)
		{
			Data<T>* newData = new Data<T>;
			newData->m_data = _data;
			Data<T>* next;
			next = data->m_Next;
			data->PushBack(newData);
			next->PushFront(newData);
		}
	}

	void Delete(int _FindIndex)
	{
		int index = 0;
		Data<T>* deleteData;
		deleteData = m_Head->Find(index, _FindIndex);
		if (deleteData == nullptr)
			return;
		deleteData->Delete();
		delete deleteData;
	}

	void DeleteAll()
	{
		if (m_Head != nullptr)
		{
			m_Head->DeleteAll();
			delete m_Head;
			m_Head = nullptr;
		}
	}

	bool GetData(int _FindIndex, T& _Out)
	{
		if (m_Head == nullptr)
		{
			return false;
		}
		int index = 0;
		Data<T>* data;
		data = m_Head->Find(index, _FindIndex);
		if (data == nullptr)
		{
			return false;

		}
		_Out = data->m_data;
		return true;
	}
};