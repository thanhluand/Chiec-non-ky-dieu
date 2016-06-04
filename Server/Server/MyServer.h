#pragma once
#include "afxsock.h"
#include "Server.h"
#include "MyClient.h"
class MyServer :
	public CSocket
{
public:
	MyServer(void);
	virtual ~MyServer(void);
public:
	void SetParentDlg(CDialog *pDlg);
	MyClient* m_Client2;
	char** nameUser2;
	int nClient2;
	// Virtual 
public:
	virtual void OnAccept(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnOutOfBandData(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);

private:
	CDialog * m_pDlg;
};

