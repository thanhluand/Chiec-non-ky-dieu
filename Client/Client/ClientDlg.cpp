
// ClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Client.h"
#include "ClientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CClientDlg dialog



CClientDlg::CClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CClientDlg::IDD, pParent)
	, m_msgString(_T(""))
	, m_Test(_T(""))
	, m_IP(0)
	, m_User(_T(""))
	, m_No(_T(""))
	, m_Round(_T(""))
	, m_Point(_T(""))
	, m_NoP(_T(""))
	, m_Question(_T(""))
	, m_NoC(_T(""))
	, m_Dial(_T(""))
	, m_Time(_T(""))
	, m_Answer(_T(""))
	, m_Guess(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MSGBOX, m_msgString);
	DDX_Text(pDX, IDC_TESTMSG, m_Test);
	DDX_Control(pDX, IDC_MSGBOX, m_CMSGBOX);
	DDX_IPAddress(pDX, IDCM_IP, m_IP);
	DDX_Text(pDX, IDCM_EUser, m_User);
	DDV_MaxChars(pDX, m_User, 20);
	DDX_Text(pDX, IDCM_STNO, m_No);
	DDX_Text(pDX, IDCM_STRound, m_Round);
	DDX_Text(pDX, IDCM_STPoint, m_Point);
	DDX_Text(pDX, IDCM_STNOP, m_NoP);
	DDX_Text(pDX, IDC_EDIT7, m_Question);
	DDX_Control(pDX, IDC_EDIT7, m_CQuestion);
	DDX_Text(pDX, IDCMST_STNOC, m_NoC);
	DDX_Text(pDX, IDC_EDIT8, m_Dial);
	DDX_Text(pDX, IDC_EDIT9, m_Time);
	DDX_Text(pDX, IDCE_EAnswer, m_Answer);
	DDX_Control(pDX, IDCM_IP, m_CIP);
	DDX_Text(pDX, IDCM_ENumGuess, m_Guess);
	DDX_Control(pDX, IDCM_Avatar, cImg);
}

BEGIN_MESSAGE_MAP(CClientDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCM_BTLogin, &CClientDlg::OnBnClickedBtlogin)
	ON_BN_CLICKED(IDCM_BTDial, &CClientDlg::OnBnClickedBtdial)
	ON_BN_CLICKED(IDCM_BTAnswer, &CClientDlg::OnBnClickedBtanswer)
	ON_BN_CLICKED(IDCM_BTLogout, &CClientDlg::OnBnClickedBtlogout)
	ON_BN_CLICKED(IDCM_BTAVAR, &CClientDlg::OnBnClickedBtavar)
END_MESSAGE_MAP()


// CClientDlg message handlers

BOOL CClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_Client.SetParentDlg(this);
	GetDlgItem(IDCM_BTLogout)->EnableWindow(false);
	GetDlgItem(IDCM_BTLogin)->EnableWindow(true);
	GetDlgItem(IDCM_BTDial)->EnableWindow(false);
	GetDlgItem(IDCM_BTAnswer)->EnableWindow(false);
	m_CIP.SetWindowText(_T("127.0.0.1"));
	IsLogin = false;
	UpdateData(TRUE);
	UpdateData(FALSE);
	CString zxc = _T("zxc|cvb|asd|fgh|");	
	CString vb[4];
	Split(zxc,vb);
	CString m = vb[1];
	//m_CMSGBOX.ShowScrollBar(SB_VERT, TRUE);
	
	CFont *m_pFont = new CFont();
    m_pFont->CreatePointFont(500, _T("Arial"));
	GetDlgItem(IDC_EDIT8)->SetFont(m_pFont, TRUE);
	m_Dial = _T("0");
	UpdateData(FALSE);
	OnBnClickedBtavar();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//////////////////////////// MMy Code ////////////////////////////
bool testString(CString s)
{


	for (int i = 0; i < s.GetLength(); i++)
	{
		if (((s[i] >= '0') && (s[i] <= '9')) || ((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= 'A') && (s[i] <= 'Z')) || s[i] == '_')
			continue;
		else
			return false;
	}

	return true;
}






void CClientDlg::mSend(CString Command)
{
	int Len = Command.GetLength();
	Len += Len;
	PBYTE sendBuff = new BYTE[1000];
	memset(sendBuff, 0, 1000);
	memcpy(sendBuff, (PBYTE)(LPCTSTR)Command, Len);
	send(m_Client, (char*)&Len, sizeof(Len), 0);
	send(m_Client, (char*)sendBuff, Len, 0);
	delete sendBuff;
}

void CClientDlg::OnBnClickedBtlogin()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	// KT tên User có null
	if(m_User == "")
	{
		MessageBox(_T("Tên User không được để trống"),_T("WARRING"));
		return;
	}

	// Kiêm tra ten User co hop le
	if(!testString(m_User))
	{
		MessageBox(_T("Tên User nhập không hợp lệ \n Tên User không được chứa kí tự đặt biệt"),_T("NOTES"));
		return;
	}
	// Khởi tạo lại thư viện socket
	UpdateData(TRUE);

	if( AfxSocketInit(NULL) == FALSE)
	{ 
		AfxMessageBox(_T("Failed to Initialize Sockets")); 
		return; 
	}

	if(m_Client.Create()==FALSE)
	{
		MessageBox(_T("Failed to Create Socket"));
		return;

	}
	CString _IP;
	m_CIP.GetWindowText(_IP);

	if(m_Client.Connect(_T("127.0.0.1"),1234)==FALSE)
	{
		MessageBox(_T("Failed to Connect"));
		m_Client.Close();
		return;

	}

	//SenMSG("1","zxc");
	CleanAllData();
	

}
char* CClientDlg::ConvertToChar(const CString &s)
{
	int nSize = s.GetLength();
	char *pAnsiString = new char[nSize + 1];
	memset(pAnsiString, 0, nSize + 1);
//	wcstombs(pAnsiString, s, nSize + 1);
	//wcstombs_s(nSize +1,pAnsiString,s,nSize+1);
	//;
    size_t CharactersConverted=0;

	wcstombs_s(&CharactersConverted, pAnsiString, s.GetLength()+1, 
        s, _TRUNCATE);
	return pAnsiString;
}
void CClientDlg::Split(CString src, CString des[4])
{
	int p1, p2,p3,p4;

	p1 = src.Find(_T("|"), 0);
	//des[0] = src.Mid(0, p1);
	CString des1 = src.Mid(0, p1);

	p2 = src.Find(_T("|"), p1 + 1);
	des[1] = src.Mid(p1 + 1, p2 - (p1 + 1));
	CString des2 = src.Mid(p1 + 1, p2 - (p1 + 1));

	p3 = src.Find(_T("|"), p2 + 1);
	des[2] = src.Mid(p2 + 1, p3 - (p2 + 1));
	CString des3 = src.Mid(p2 + 1, p3 - (p2 + 1));

	p4 = src.Find(_T("|"), p3 + 1);
	des[3] = src.Mid(p3 + 1, p4 - (p3 + 1));
	CString des4 = src.Mid(p3 +1, p4 - (p3 + 1));
	int n =5;


}
void CClientDlg::SenMSG(char* Flag, char* MSG)
{
	UpdateData(TRUE);
	userinfo uinf;
	char* cstr =  ConvertToChar( m_User);
	
	strcpy_s(uinf.cUserName,cstr);
	strcpy_s(uinf.csMsg,MSG);
	strcpy_s(uinf.cFlag,Flag);
	strcpy_s(uinf.cEx,"");

	char *buff=(char*)&uinf;

	m_Client.Send(buff,sizeof(userinfo));

}


void CClientDlg::OnClose(){
	
	return;
}
void CClientDlg::OnReceive(userinfo* udata){
	
	int _Flag;
	_Flag = atoi(udata->cFlag);
	CString _Name(udata->cUserName);
	CString _MSG(udata->csMsg);
	CString _Ex(udata->cEx);
	switch (_Flag)
	{
	case 1:
		{
			SenMSG("1","");
			break;
		}
	case 11:
		{
			m_msgString+=_T("Login success\r\n");
			GetDlgItem(IDCM_BTLogout)->EnableWindow(true);
			GetDlgItem(IDCM_BTLogin)->EnableWindow(false);
			UpdateData(FALSE);
			break;
		}
	case 12:
		{
			m_msgString+=_T("Server Full\r\n");
			m_Client.Close();
			UpdateData(FALSE);
			break;

		}
	case 13:
		{
			m_msgString+=_T("Someone already has that username. Try another? \r\n");
			m_Client.Close();
			UpdateData(FALSE);
			break;

		}
	case 2:
		{
			int p1, p2,p3,p4,p5,p6;

			p1 = _MSG.Find(_T("|"), 0);
			//des[0] = src.Mid(0, p1);
			CString des1 = _MSG.Mid(0, p1);

			p2 = _MSG.Find(_T("|"), p1 + 1);
			//des[1] = src.Mid(p1 + 1, p2 - (p1 + 1));
			CString des2 = _MSG.Mid(p1 + 1, p2 - (p1 + 1));

			p3 = _MSG.Find(_T("|"), p2 + 1);
			//des[2] = src.Mid(p2 + 1, p3 - (p2 + 1));
			CString des3 = _MSG.Mid(p2 + 1, p3 - (p2 + 1));

			p4 = _MSG.Find(_T("|"), p3 + 1);
			//des[3] = src.Mid(p3 + 1, p4 - (p3 + 1));
			CString des4 = _MSG.Mid(p3 +1, p4 - (p3 + 1));

			p5 = _MSG.Find(_T("|"), p4 + 1);
			//des[3] = src.Mid(p3 + 1, p4 - (p3 + 1));
			CString des5 = _MSG.Mid(p4 +1, p5 - (p4 + 1));

			p6 = _MSG.Find(_T("|"), p5 + 1);
			//des[3] = src.Mid(p3 + 1, p4 - (p3 + 1));
			CString des6 = _MSG.Mid(p5 +1, p6 - (p5 + 1));

			m_NoP = _T("Number Player: ") + des1 ;
			m_No = _T("NO. ") + des2;
			m_NoC = _T("Number of characters: ") + des3;
			m_Question = des4;
			m_msgString += _T("Initialize success\r\n");
			m_Point = _T("Point: 0");
			nRound =0;
			m_Round = _T("Round: 0");
			m_Time = des5;
			m_Guess = _T("Num Guess: ") + des6;
			int nTime = atoi(ConvertToChar(des5));
			UpdateData(FALSE);
			
			break;

		}
	case 3:
		{
			if(_MSG.Compare(_T("Your turn"))==0)
				GetDlgItem(IDCM_BTDial)->EnableWindow(true);

			m_msgString +=_MSG + _T("\r\n");
			
			UpdateData(FALSE);
			break;
		}
	case 0:
		{
			m_msgString += _MSG + _T("\r\n");
			UpdateData(FALSE);
			break;
		}
	case 4:
		{
			
			m_Point = _T("Point: ") + _MSG;
			UpdateData(FALSE);
			break;
		}
	case 5:
		{
			
				m_msgString +=  _MSG + _T("\r\n");
				nRound ++;
				CString d ;
				d.Format(_T("%d"),nRound);
				m_Round = _T("Round: ") + d;
				UpdateData(FALSE);
			
			break;
		}
	
	case 6:
		{
			
				m_msgString += _MSG + _T("\r\n");
				nRound ++;
				CString d ;
				d.Format(_T("%d"),nRound);
				m_Round = _T("Round: ") + d;
				UpdateData(FALSE);

			
			
			break;
		}
	case 7:
		{
			AfxMessageBox(_MSG);

			break;
		}
	case 71:
		{
			m_msgString += _T("Game over because game has out turns guessing\r\n");
			AfxMessageBox(_T("Game Over"));
			m_Client.Close();
			GetDlgItem(IDCM_BTLogin)->EnableWindow(true);
			GetDlgItem(IDCM_BTLogout)->EnableWindow(false);
			GetDlgItem(IDCM_BTDial)->EnableWindow(false);
			UpdateData(FALSE);
			break;
		}
	case 72:
		{
			m_msgString += _T("Game over because game Server hasn't Client\r\n");
			AfxMessageBox(_T("Game Over"));
			m_Client.Close();
			GetDlgItem(IDCM_BTLogin)->EnableWindow(true);
			GetDlgItem(IDCM_BTLogout)->EnableWindow(false);
			GetDlgItem(IDCM_BTDial)->EnableWindow(false);
			UpdateData(FALSE);
			break;
		}
	case 8:
		{
			m_msgString += _T("Game over because  Server is close\r\n");
			AfxMessageBox(_T("Game Over"));
			m_Client.Close();
			GetDlgItem(IDCM_BTLogin)->EnableWindow(true);
			GetDlgItem(IDCM_BTLogout)->EnableWindow(false);
			GetDlgItem(IDCM_BTDial)->EnableWindow(false);
			UpdateData(FALSE);
			break;
		}
	case 82:
		{
			m_msgString += _MSG + _T("\r\n");
			m_Client.Close();
			GetDlgItem(IDCM_BTDial)->EnableWindow(false);
			GetDlgItem(IDCM_BTLogin)->EnableWindow(true);
			GetDlgItem(IDCM_BTLogout)->EnableWindow(false);
			UpdateData(FALSE);
			break;
		}
	case 9:
		{
			m_Point = _T("Point: 0");
			m_msgString = _T("");
			m_Round = _T("Round: 0");
			m_Question = _T("");
			UpdateData(FALSE);
			break;
		}


	default:
		break;

	}
	


}

void CClientDlg::CleanAllData()
{
	m_msgString = _T("");
	m_No = _T("NO: 0");
	m_NoC = _T("Number of character: 0");
	m_NoP = _T("Number Play: 0");
	m_Point = _T("Point: 0");
	m_Round = _T("Round: 0");
	m_Guess = _T("Guess: 0");
	m_Question = _T("");
	UpdateData(FALSE);
	
	
}

void CClientDlg::OnBnClickedBtdial()
{
	// TODO: Add your control notification handler code here
	CString s;
	int ti = 0;
	
		srand(time(0));
		DPoint =rand()%101;
		s.Format(_T("%d"),DPoint);
		m_Dial = s;
		UpdateData(FALSE);
	

		

	if(DPoint == 0)
	{
		SenMSG("51","");
	}
	
	s.Format(_T("%d"),DPoint);
	m_Dial = s;
	
	//MessageBox(_T("You has ") + s );
	GetDlgItem(IDCM_BTDial)->EnableWindow(false);
	GetDlgItem(IDCM_BTAnswer)->EnableWindow(true);
	
}





void CClientDlg::OnBnClickedBtanswer()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString _Point;
	_Point.Format(_T("%d"),DPoint);
	if(m_Answer == _T(""))
		return;
	int s = m_Answer.GetLength();
	if(m_Answer.GetLength() == 1)
	{
		char* C = ConvertToChar(m_Answer + _T("|") + _Point+ _T("|"));
		SenMSG("5",C);
	}else
	{
		char* C = ConvertToChar(m_Answer + _T("|") + _Point+ _T("|"));
		SenMSG("6",C);
	}
	m_Answer = _T("");
	GetDlgItem(IDCM_BTAnswer)->EnableWindow(false);
	UpdateData(FALSE);

}


void CClientDlg::OnBnClickedBtlogout()
{
	// TODO: Add your control notification handler code here
	SenMSG("8","");
	m_Client.Close();
	GetDlgItem(IDCM_BTLogin)->EnableWindow(true);
	GetDlgItem(IDCM_BTLogout)->EnableWindow(false);
	
}


void CClientDlg::OnBnClickedBtavar()
{
	// TODO: Add your control notification handler code here
	mPicture = (CStatic *)GetDlgItem(IDCM_Avatar);
	srand(GetTickCount());
	DPoint =rand()%10;
	CString s;
	s.Format(_T("%d"),DPoint);
	CImage im;
	s = _T("Avatar\\Avatar") + s + _T(".jpg");
	im.Load(s);
	CBitmap bm ;
	bm.Attach(im.Detach());
	//HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),path, IMAGE_BITMAP, 145, 140, LR_LOADFROMFILE);
	//mPicture->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
	mPicture->SetBitmap(bm);
		
	UpdateData(FALSE);
}
