#include "stdafx.h"
#include "MyClient.h"
#include "ServerDlg.h"


MyClient::MyClient(void)
{
}


MyClient::~MyClient(void)
{
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
		((CServerDlg*)m_pDlg)->OnReceive(udata); 
	}
	
	CAsyncSocket::OnReceive(nErrorCode);
}

void MyClient::SetParentDlg(CDialog *pDlg)
{
	m_pDlg=pDlg;
}
