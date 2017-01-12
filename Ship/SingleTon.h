#pragma once

template <class T>
class SingleTon
{
private:
	static T* instance;
	
public:
	static T* GetInstance()
	{
		if (instance == nullptr)
			instance = new T();

		return instance;
	}
};

template <class T>
T* SingleTon<T>::instance = nullptr;