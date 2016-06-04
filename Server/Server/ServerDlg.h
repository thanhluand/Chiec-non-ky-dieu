
// ServerDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "MyServer.h"



// CServerDlg dialog
class CServerDlg : public CDialogEx
{
// Construction
public:
	
	CServerDlg(CWnd* pParent = NULL);	// standard constructor
	void OnClose();
	void OnAccept();
	void OnReceive(userinfo* udata);
	void SenMSG(char* Flag, char* MSG, char* _Name, int _Client, char* _Ex);
	void VisibleButton(bool b);
	void initAllClient();
	char* ConvertToChar(const CString &s);
	void NextRound(int _Client);

// Dialog Data
	enum { IDD = IDD_SERVER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_NumClient;
	CString m_Q1;
	
	CString m_Q2;
	
	CString m_Q3;
	CString m_Q4;
	CString m_Q5;
	CString m_Q6;
	CString m_Time;
	CString m_MSGBox;
	int n_Client;
	int nQ;
	int nGuess;
	CSocket* m_Client;
	MyServer m_Server;
	CStringW m_KiTu[6];
	CStringW m_Question[6];
	CStringW m_Answer[6];
	CStringW m_NGuess[6];
	

	CString* name_client;
	int* point_client;
	bool* client_Lost;
	int HasClose;
	bool IsPlay;

	afx_msg void OnBnClickedBlistent();
	
	CEdit c_Time;
	afx_msg void OnBnClickedBtime();
	afx_msg void OnBnClickedBq1();
	afx_msg void OnBnClickedBq2();
	afx_msg void OnBnClickedBq3();
	afx_msg void OnBnClickedBq4();
	afx_msg void OnBnClickedBq5();
	afx_msg void OnBnClickedBq6();
	afx_msg void OnBnClickedBplay();
	afx_msg void OnBnClickedBexit();
	afx_msg void OnBnClickedBreplay();
	afx_msg void OnBnClickedBcancel();
	CString m_Time1;
	CString m_Time2;
	CString m_Time3;
	CString m_Time4;
	CString m_Time5;
	CString m_Time6;
};
