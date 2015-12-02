#include "stdafx.h"

//using namespace std;

class Lockable
{
public:
	void lock()
	{
		this->m_Mutex.lock();
	}

	void unlock()
	{
		this->m_Mutex.unlock();
	}

private:
	std::mutex m_Mutex;
};