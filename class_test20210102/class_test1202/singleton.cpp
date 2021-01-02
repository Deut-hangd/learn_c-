#include <iostream>
#include <windows.h>
#include <chrono>
#include <mutex>
#include <thread>
using namespace std;

class Singleton
{

public:
	static Singleton* GetInstance()
	{
		if (nullptr == m_pInstance)
		{
			//m_mtx.lock();
			if (nullptr == m_pInstance)
			{
				//std::this_thread::sleep_for(std::chrono::milliseconds(5000));
				m_pInstance = new Singleton();
			}
		    //m_mtx.unlock();
		}
		
		return m_pInstance;
	}

	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (Singleton::m_pInstance)
			{
				delete Singleton::m_pInstance;
			}
		}
	};
	static CGarbo Garbo;
private:
	Singleton(){}

	Singleton(Singleton const&);
	Singleton& operator= (Singleton const&);

	static Singleton* m_pInstance;
	static mutex m_mtx;
};

Singleton* Singleton::m_pInstance = nullptr;
Singleton::CGarbo garbo;
mutex Singleton::m_mtx;

mutex m;
void func1(int n)
{
	m.lock();
	//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	cout << "当前线程是: " << std::this_thread::get_id() << " ";
	cout << Singleton::GetInstance() << endl;
	m.unlock();
	
}

int m19()
{
	thread t1(func1, 10);
	thread t2(func1, 10);
	t1.join();
	t2.join();
	cout << Singleton::GetInstance << endl;
	cout << Singleton::GetInstance << endl;

	auto n = thread::hardware_concurrency();
	cout << n << endl;
	system("pause");
	return 0;
}