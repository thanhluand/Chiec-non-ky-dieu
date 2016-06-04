#pragma once
#include "afxsock.h"
class MyClient :
	public CSocket
{
public:
	MyClient(void);
	virtual ~MyClient(void);

public:
	void SetParentDlg(CDialog* pDlg);
	virtual void OnReceive(int nErrorCode);
private:
	CDialog* m_pDlg;
};

