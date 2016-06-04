#include "stdafx.h"
#include "MyServer.h"
#include "ServerDlg.h"




MyServer::MyServer(void)
{
}


MyServer::~MyServer(void)
{
}

#if 0
BEGIN_MESSAGE_MAP(MyEchoSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(MyEchoSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif

void MyServer::OnAccept(int nErrorCode) 
	{
		// TODO: Add your specialized code here and/or call the base class
		if(nErrorCode==0)
		{
			m_Client2[nClient2].m_hSocket = INVALID_SOCKET;
			Accept(m_Client2[nClient2]);
			((CServerDlg*)m_pDlg)->OnAccept();
		}
		CAsyncSocket::OnAccept(nErrorCode);
	}

void MyServer::OnClose(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(nErrorCode==0)
	{
		((CServerDlg*)m_pDlg)->OnClose(); 
	}

	
	CAsyncSocket::OnClose(nErrorCode);
}

void MyServer::OnConnect(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class

	
	CAsyncSocket::OnConnect(nErrorCode);
}

void MyServer::OnOutOfBandData(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CAsyncSocket::OnOutOfBandData(nErrorCode);
}

void MyServer::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	/*if(nErrorCode==0)
	{
		char buff[1000];
		int br=Receive(buff,1000);
		buff[br]='\0';


		userinfo *udata;
		udata=(userinfo*)buff;
		((CServerDlg*)m_pDlg)->OnReceive(udata); 
	}*/
	
	CAsyncSocket::OnReceive(nErrorCode);
}

void MyServer::OnSend(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CAsyncSocket::OnSend(nErrorCode);
}

void MyServer::SetParentDlg(CDialog *pDlg)
{
	m_pDlg=pDlg;
}

