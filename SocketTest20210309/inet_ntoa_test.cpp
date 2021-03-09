#include <iostream>
// #include "protocol_head.hpp"
// #include <stdio.h>
#include <string>
#include <winsock2.h>
#include <WS2tcpip.h>
#include <windows.h>
#include <bitset>
#pragma comment(lib, "ws2_32")
using namespace std;
// int sendTcp(u_short desPort, const char* desIP)
// {
//     WSADATA WSAData;
//     SOCKET sock;
//     SOCKADDR_IN addr_in;
//     IP_HEADER ipHeader;
//     TCP_HEADER tcpHeader;
//     PSD_HEADER psdHeader;

//     char szSendBuf[1024] = {0};
//     BOOL flag;
//     int rect, nTimeOver;

//     if(WSAStartup(MAKEWORD(2, 2), &WSAData) != 0)
//     {
//         cerr << "WSAStartup Error!\n" << endl;
//         return false;
//     }

//     if ((sock = WSASocket(AF_INET, SOCK_RAW, IPPROTO_RAW, NULL, 0,
//     WSA_FLAG_OVERLAPPED)) == INVALID_SOCKET)
//     {
//         cout << "Socket Setup Error!" << endl;
//         return false;
//     }

//     flag = true;
//     if (setsockopt(sock, IPPROTO_IP, IP_HDRINCL, (char*) &flag,
//     sizeof(flag)) == SOCKET_ERROR)
//     {
//         cout << "setsockopt IP_HDRINCL error" << endl;
//         return false;
//     }

//     nTimeOver = 1000;
//     if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char*)
//     &nTimeOver, sizeof(nTimeOver)) == SOCKET_ERROR)
//     {
//         cout << "setsockopt SO_SNDTIMEO error" << endl;
//         return false;
//     }

//     addr_in.sin_family = AF_INET;
//     addr_in.sin_port = htons(desPort);
//     addr_in.sin_addr.S_un.S_addr = inet_addr(desIP);

//     // 填充ip报头
//     ipHeader.h_verlen = (4 << 4 | sizeof(ipHeader) / sizeof(unsigned long));
//     ipHeader.ident = 1;
//     ipHeader.frag_and_flags = 0;
//     ipHeader.ttl = 128;
//     ipHeader.proto = IPPROTO_TCP;
//     ipHeader.checksum = 0;
//     ipHeader.sourceIP = inet_addr("localhost");
//     ipHeader.destIP = inet_addr(desIP);

//     // 填充TCP报头
//     tcpHeader.th_dport = htons(desPort);
//     tcpHeader.th_sport = htons(9999); // 源端口号
//     tcpHeader.th_seq = htonl(0X12345678);
//     tcpHeader.th_ack = 0;
//     tcpHeader.th_lenres = (sizeof(tcpHeader) / 4 << 4 | 0);
//     tcpHeader.th_flag = 2; // 标志位探测, 2 是SYN
//     tcpHeader.th_win = htons(512);
//     tcpHeader.th_urp = 0;
//     tcpHeader.th_sum = 0;

//     // 计算校验和
//     memcpy(szSendBuf, &psdHeader, sizeof(psdHeader));
//     memcpy(szSendBuf + sizeof(psdHeader), &tcpHeader, sizeof(tcpHeader));
//   //tcpHeader.th_sum = checksum((unsigned short*) szSendBuf, sizeof(psdHeader) + sizeof(tcpHeader));
//     memcpy(szSendBuf, &ipHeader, sizeof(ipHeader));
//     memcpy(szSendBuf + sizeof(ipHeader) + sizeof(tcpHeader), 0, 4);
//     // ipHeader.checksum = checksum((unsigned short*) szSendBuf, sizeof(ipHeader) + sizeof(tcpHeader));
//     memcpy(szSendBuf, &ipHeader, sizeof(ipHeader));
//     rect = sendto(sock, szSendBuf, sizeof(ipHeader) + sizeof(tcpHeader), 
//     0, (struct sockaddr*) &addr_in, sizeof(addr_in));
//     if (rect == SOCKET_ERROR)
//     {
//         cout << "send error!: " << WSAGetLastError() << endl;
//         return false;
//     }else 
//     {
//         cout << "send ok" << endl;
//     }
//     closesocket(sock);
//     WSACleanup();
//     return rect;
// }

// int main(int argc, char* argv[])
// {
//     sendTcp(9999, "127.0.0.1");
//     return 0;
// }
#ifndef SIO_RCVALL
#define SIO_RCVALL _WSAIOW(IOC_VENDOR,1)
#endif
int main(void) 
{
    SOCKET sock;
struct sockaddr_in addr_in;
HOSTENT* pHost;
char  LocalName[16];
WSADATA WSAData;
// 检查 Winsock 版本号，WSAData为WSADATA结构对象
WSAStartup(MAKEWORD(2, 2), &WSAData);
// 创建原始套接字
sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
// 设置IP头操作选项，其中flag 设置为ture，亲自对IP头进行处理
BOOL flag = true;
setsockopt(sock, IPPROTO_IP, IP_HDRINCL, (char*)&flag, sizeof(flag));
// 获取本机名
 gethostname((char*)LocalName, sizeof(LocalName)-1);
 cout << LocalName << endl;
// 获取本地 IP 地址
pHost = gethostbyname((char*)LocalName);
cout << pHost << endl;
cout << LocalName << endl;
// 填充SOCKADDR_IN结构
addr_in.sin_addr = *(in_addr *)pHost->h_addr_list[0]; //IP
addr_in.sin_family = AF_INET;
addr_in.sin_port = htons(57274);
// 把原始套接字sock 绑定到本地网卡地址上
bind(sock, (PSOCKADDR)&addr_in, sizeof(addr_in));
// dwValue为输入输出参数，为1时执行，0时取消
DWORD dwValue = 1; 
// 设置 SOCK_RAW 为SIO_RCVALL，以便接收所有的IP包。其中SIO_RCVALL
// 的定义为： #define SIO_RCVALL _WSAIOW(IOC_VENDOR,1)
ioctlsocket(sock, SIO_RCVALL, &dwValue);

#define BUFFER_SIZE 1024
char RecvBuf[BUFFER_SIZE];
while (true)
{
// 接收原始数据包信息
int ret = recv(sock, RecvBuf, BUFFER_SIZE, 0);
int count = 0;
if (ret > 0)
{
std::cout << RecvBuf << std::endl;
for (int i = 0; i < 1024; i++)
{
    if (RecvBuf[i] != 0)
    {
        cout << bitset<8>(RecvBuf[i]) << endl;
        count++;
    }
}
cout << "##################" << endl;
cout << "count is " << count << endl;
}
memset(RecvBuf, 0, sizeof(RecvBuf));
count= 0;
cout << " " << endl;
}
return 0;
}