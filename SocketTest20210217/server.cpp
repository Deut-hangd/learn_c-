#include <iostream>
#include <unistd.h>
#include <stdio.h>

#include <Winsock2.h>
#include <sys/types.h>
//#pragma comment(lib, "ws2_32.lib")
using namespace std;
int main(int argc, char* argv[]) 
{
    //SOCKADDR_IN addServer;
    WORD sockVersion = MAKEWORD(2, 2);
    WSAData wsaData;
    if (WSAStartup(sockVersion, &wsaData) != 0)
    {
        return 0;
    }
    // 创建socket
    SOCKET fd = socket(AF_INET, SOCK_STREAM, 0);

    if (fd == INVALID_SOCKET)
    {
        cout << "socket error!" << endl;
        return 0;
    }

    // 绑定ip和端口号
    //绑定IP和端口号
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8888);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
	if (bind(fd, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR) {

		printf("bind error!");

	}

	//开始监听
	
	if (listen(fd, 5) == SOCKET_ERROR) {

		printf("listen error!");
		return 0;
	}

	//循环接受数据
	SOCKET sClient;
	sockaddr_in remoteAddr;
	int nAddrlen = sizeof(remoteAddr);
	char revData[255];
	while (true) {

		printf("waitting for connection ......\n");
		sClient = accept(fd, (SOCKADDR*)&remoteAddr, &nAddrlen);
		if (sClient == INVALID_SOCKET) {
			printf(" accept error!");
			continue;
		}

		printf("accept a connection：%s\r\n", inet_ntoa(remoteAddr.sin_addr));

		//接收数据
		int ret = recv(sClient, revData, 255, 0);
		if (ret> 0) {

			revData[ret] = 0x00;
			printf(revData);
		}

		//发送数据
		const char* sendData = "hello，TCP Client:s！\n";
		send(sClient, sendData, strlen(sendData), 0);
		closesocket(sClient);


	}
	closesocket(fd);
	WSACleanup();
    return 0;
}



