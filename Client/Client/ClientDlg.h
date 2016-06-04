
// ClientDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include <cstdlib>
#include <ctime>
#include "Userdata.h"
#include "MyClient.h"

// CClientDlg dialog
class CClientDlg : public CDialogEx
{
// Construction
public:
	CClientDlg(CWnd* pParent = NULL);	// standard constructor
	void OnReceive(userinfo* udata);
	void OnClose();
	void OnAccept();
	void SenMSG(char* Flag, char* MSG);


// Dialog Data
	enum { IDD = IDD_CLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	// My variables 
	CString m_msgString;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnVscrollSmgbox();
	afx_msg void OnEnChangeMsgbox();
	
	CString m_Test;
	CEdit m_CMSGBOX;
	DWORD m_IP;
	CString m_User;
	CString m_No;
	CString m_Round;
	CString m_Point;
	CString m_NoP;
	CString m_Question;
	CEdit m_CQuestion;
	CString m_NoC;
	CString m_Dial;
	CString m_Time;
	CHotKeyCtrl m_HotKey;
	CString m_Answer;
	BOOLEAN IsLogin;
	
	CString Command;
	void mSend(CString Command);

	afx_msg void OnBnClickedBtlogin();
	char* ConvertToChar(const CString &s);
	void Split(CString src,CString des[4]);
	void CleanAllData();
	int DPoint;
	int nRound;
	int nTime;
	CIPAddressCtrl m_CIP;

	MyClient  m_Client;

	afx_msg void OnBnClickedBtdial();
	afx_msg void OnBnClickedBtguess();
	afx_msg void OnBnClickedBtanswer();
	CString m_Guess;
	afx_msg void OnBnClickedBtlogout();
	afx_msg void OnBnClickedBtavar();
	CStatic cImg;
	CStatic* mPicture;
};
