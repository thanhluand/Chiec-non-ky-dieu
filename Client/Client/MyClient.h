#pragma once
#include "afxsock.h"
#include	"Client.h"
class MyClient :
	public CSocket
{
public:
	MyClient(void);
	virtual ~MyClient(void);

// Overrides
public:
	void SetParentDlg(CDialog* pDlg);
	virtual void OnAccept(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnOutOfBandData(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
protected:
private:
	CDialog* m_pDlg;
};

