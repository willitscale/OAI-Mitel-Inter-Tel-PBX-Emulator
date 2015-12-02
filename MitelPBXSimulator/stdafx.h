#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <io.h>

#include <sys/types.h> 

// I hate programming for Windows -- ALL NIX DEVELOPERS EVER!
#ifdef _WIN32

#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <string.h>

#define bzero(memArea, len)  memset((memArea), 0, (len))
#define bcopy(memSrc, memDst, memLen) memcpy((memDst), (memSrc), (memLen)) 

#define x__read(handle,buffer,size) _read(handle,buffer,size)
#define x__write(handle,buffer,size) _write(handle,buffer,size)
#define x__close(handle) _close(handle)

#pragma comment (lib, "Ws2_32.lib")

#else

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define x__read(handle,buffer,size) read(handle,buffer,size)
#define x__write(handle,buffer,size) write(handle,buffer,size)
#define x__close(handle) close(handle)

#endif

#include <thread>
#include <mutex>
#include <iostream>
#include <string>

// Currently not used, but may be used later for thread wait/notify
// See http://www.cplusplus.com/reference/condition_variable/condition_variable/wait/
#include <condition_variable>

#include "Lockable.h"
#include "Lock.h"

#define synchronized(M)  for(Lock M##_lock = M; M##_lock; M##_lock.setUnlock())

// Utilities
#include "Utils.h"

// Models
#include "Agent.h"
#include "Call.h"
#include "Device.h"
#include "DND.h"
#include "HuntGroup.h"
#include "Node.h"
#include "Trunk.h"

// Networking
#include "Client.h"
#include "Server.h"