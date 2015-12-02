#include "stdafx.h"

namespace OAI_Networking
{
	class Server : public Lockable
	{
	public:
		Server();
		~Server();

		int Connect();
		bool Connected();

		void Run();

		void Error(std::string error);

		int InitWSA();
		int InitSocket();
		int InitNonBlocking();
		int InitBind();
		int InitListen();

		const static int BUFFER_SIZE = 1024;

		const static int CONNECT_SUCCESSFUL = 0;
		const static int INIT_WSA_ERROR = -1;
		const static int INIT_SOCKET_ERROR = -2;
		const static int INIT_NON_BLOCKING_ERROR = -3;
		const static int INIT_BIND_ERROR = -4;
		const static int INIT_LISTEN_ERROR = -5;

	protected:
		bool m_Connected = false;
		int m_Port = 4001;
		int m_Socket;
		int m_Client;
		int m_Pending = 5;
		int m_ClientLength;

		u_long m_Mode = 0;

		struct sockaddr_in m_Server;
		struct sockaddr_in m_ClientAddr;
	};
}