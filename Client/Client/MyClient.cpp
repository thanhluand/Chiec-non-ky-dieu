#include "stdafx.h"
#include "MyClient.h"
#include "Client.h"
#include "ClientDlg.h"


MyClient::MyClient(void)
{
}


MyClient::~MyClient(void)
{
}

// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(MyEchoSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(MyEchoSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0


	void MyClient::OnAccept(int nErrorCode) 
	{
		// TODO: Add your specialized code here and/or call the base class
		
		CAsyncSocket::OnAccept(nErrorCode);
	}

void MyClient::OnClose(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(nErrorCode==0)
	{
		((CClientDlg*)m_pDlg)->OnClose(); 
	}

	
	CAsyncSocket::OnClose(nErrorCode);
}

void MyClient::OnConnect(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class

	
	CAsyncSocket::OnConnect(nErrorCode);
}

void MyClient::OnOutOfBandData(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CAsyncSocket::OnOutOfBandData(nErrorCode);
}

void MyClient::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class

	if(nErrorCode==0)
	{
		char buff[1000];
		int br=Receive(buff,1000);
		buff[br]='\0';


		userinfo *udata;
		udata=(userinfo*)buff;
		((CClientDlg*)m_pDlg)->OnReceive(udata); 
	}
	
	CAsyncSocket::OnReceive(nErrorCode);
}

void MyClient::OnSend(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CAsyncSocket::OnSend(nErrorCode);
}
void MyClient::SetParentDlg(CDialog *pDlg)
{
	m_pDlg=pDlg;
}
