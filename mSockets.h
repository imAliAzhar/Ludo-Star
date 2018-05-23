#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include <conio.h>
#include <iostream>
#include<stdio.h>
#include<string>

using namespace std;

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

string recvd;				//// Encapsulation!!!!!!
string sendd;

char recvdCoverted[DEFAULT_BUFLEN];


DWORD WINAPI receive_cmds(LPVOID lpParam)
{
	cout << "Thread created for receiving\n";

	SOCKET current_client = (SOCKET)lpParam;

	int result;
	result = recv(current_client, recvdCoverted, DEFAULT_BUFLEN, 0);
	recvd = recvdCoverted;

	ExitThread(0);
}
DWORD WINAPI send_cmds(LPVOID lpParam)
{
	cout << "Thread created for sending\n";

	SOCKET current_client = (SOCKET)lpParam;

	int result = 1;
	result = send(current_client, sendd.c_str(), sendd.size(), 0);
	ExitThread(0);
}

class mSocket
{
	WSADATA wsaData;
	int iResult;

	SOCKET ListenSocket;
	SOCKET ClientSocket;
	SOCKET ConnectSocket;

	char who;

	struct addrinfo *result, *ptr;
	struct addrinfo hints;

	int iSendResult;
	//char recvbuf[DEFAULT_BUFLEN];

	DWORD thread;

public:

	mSocket()
	{
		ListenSocket = INVALID_SOCKET;
		ClientSocket = INVALID_SOCKET;
		ConnectSocket = INVALID_SOCKET;

		result = NULL;
		ptr = NULL;

		// Initialize Winsock
		iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (iResult != 0) {
			cout << "WSAStartup failed with error:\n" << iResult;
		}
	}

	~mSocket()
	{
		closesocket(ClientSocket);
		closesocket(ConnectSocket);
		WSACleanup();
	}


	void receiving()
	{
		if (who == 's')
		{
			// Accept a client socket
			cout << "\nserver started receiving\n";

			//CreateThread(NULL, 0, receive_cmds, (LPVOID)ClientSocket, 0, &thread);
			iResult = recv(ClientSocket, recvdCoverted, DEFAULT_BUFLEN, 0);
			recvd = recvdCoverted;

		}
		else if (who == 'c')
		{
			cout << "\nclient started receiving\n";
			iResult = recv(ConnectSocket, recvdCoverted, DEFAULT_BUFLEN, 0);
			recvd = recvdCoverted;
			//cout << recvbuf;
		}
	}

	void sending()
	{
		if (who == 's')
		{
			// Accept a client socket
			cout << "\nserver started sending\n";


			//CreateThread(NULL, 0, send_cmds, (LPVOID)ClientSocket, 0, &thread);
			iResult = send(ClientSocket, sendd.c_str(), sendd.size(), 0);
		}
		else if (who == 'c')
		{
			cout << "\nclient started sending\n";
			iResult = send(ConnectSocket, sendd.c_str(), sendd.size(), 0);
		}

		cout << "Done Sending\n";
	}

	void setData(string data)
	{
		sendd = data;
	}

	string getData()
	{
		return recvd;
	}

	void setWho(char w)
	{
		who = w;
		if (who == 's')
		{

			ZeroMemory(&hints, sizeof(hints));
			hints.ai_family = AF_INET;
			hints.ai_socktype = SOCK_STREAM;
			hints.ai_protocol = IPPROTO_TCP;
			hints.ai_flags = AI_PASSIVE;

			// Resolve the server address and port
			iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
			if (iResult != 0) {
				cout << "getaddrinfo failed with error:\n", iResult;
				WSACleanup();
			}

			// Create a SOCKET for connecting to server
			ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
			if (ListenSocket == INVALID_SOCKET) {
				cout << "socket failed with error:\n" << WSAGetLastError();
				freeaddrinfo(result);
				WSACleanup();
			}

			// Setup the TCP listening socket
			iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
			if (iResult == SOCKET_ERROR) {
				cout << "bind failed with error:\n" << WSAGetLastError();
				freeaddrinfo(result);
				closesocket(ListenSocket);
				WSACleanup();
			}

			freeaddrinfo(result);

			iResult = listen(ListenSocket, SOMAXCONN);
			if (iResult == SOCKET_ERROR) {
				cout << "listen failed with error:\n" << WSAGetLastError();
				closesocket(ListenSocket);
				WSACleanup();
			}

			ClientSocket = accept(ListenSocket, NULL, NULL);
			if (ClientSocket == INVALID_SOCKET) {
				cout << "accept failed with error:\n" << WSAGetLastError();
				closesocket(ListenSocket);
				WSACleanup();
			}
		}
		else if (who = 'c')
		{

			ZeroMemory(&hints, sizeof(hints));
			hints.ai_family = AF_UNSPEC;
			hints.ai_socktype = SOCK_STREAM;
			hints.ai_protocol = IPPROTO_TCP;

			// Resolve the server address and port
			iResult = getaddrinfo("192.168.43.192", DEFAULT_PORT, &hints, &result);
			if (iResult != 0) {
				cout << "getaddrinfo failed with error: \n" << iResult;
				WSACleanup();
			}

			for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

				// Create a SOCKET for connecting to server
				ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
					ptr->ai_protocol);
				if (ConnectSocket == INVALID_SOCKET) {
					cout << "socket failed with error: \n" << WSAGetLastError();
					WSACleanup();
				}

				// Connect to server.
				iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
				if (iResult == SOCKET_ERROR) {
					closesocket(ConnectSocket);
					ConnectSocket = INVALID_SOCKET;
					continue;
				}
				break;
			}

			freeaddrinfo(result);

			if (ConnectSocket == INVALID_SOCKET) {
				cout << "Unable to connect to server!\n";
				WSACleanup();
			}

		}
	}

	char getWho() const { return who; }
};