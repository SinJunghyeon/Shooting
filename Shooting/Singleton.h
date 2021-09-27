#pragma once

template <typename T>
class Singleton
{
protected:
	static T* instance;		// static 멤버 변수

	Singleton() {};		// 생성자, 소멸자를 직접 호출하지 못하게 할거다.
	~Singleton() {};

public:
	static T* GetSingleton();
	void ReleaseSingleton();
};

template<typename T>
T* Singleton<T>::instance = nullptr;

template<typename T>
inline T* Singleton<T>::GetSingleton()
{
	if (!instance)
	{
		instance = new T;
	}
	return instance;
}

template<typename T>
inline void Singleton<T>::ReleaseSingleton()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}