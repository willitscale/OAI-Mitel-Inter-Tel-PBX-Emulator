#include "stdafx.h"

class Lock
{
public:

	Lock(Lockable &lockable) : 
		m_Lockable(lockable), 
		m_locked(true)
	{
		lockable.lock();
	}

	~Lock()
	{
		m_Lockable.unlock();
	}

	operator bool() const
	{
		return m_locked;
	}

	void setUnlock()
	{
		m_locked = false;
	}

private:
	Lockable &m_Lockable;
	bool m_locked;
};