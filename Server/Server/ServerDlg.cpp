
// ServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ServerDlg.h"
#include "stdlib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CServerDlg dialog



CServerDlg::CServerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CServerDlg::IDD, pParent)
	, m_NumClient(_T(""))
	, m_Q1(_T(""))
	, m_Q2(_T(""))
	, m_Q3(_T(""))
	, m_Q4(_T(""))
	, m_Q5(_T(""))
	, m_Q6(_T(""))
	, m_Time(_T(""))
	, m_MSGBox(_T(""))
	, m_Time1(_T(""))
	, m_Time2(_T(""))
	, m_Time3(_T(""))
	, m_Time4(_T(""))
	, m_Time5(_T(""))
	, m_Time6(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDCM_ENumClient, m_NumClient);
	DDX_Text(pDX, IDC_EDIT8, m_Q1);
	DDX_Text(pDX, IDC_EDIT3, m_Q2);
	DDX_Text(pDX, IDC_EDIT4, m_Q3);
	DDX_Text(pDX, IDC_EDIT5, m_Q4);
	DDX_Text(pDX, IDC_EDIT6, m_Q5);
	DDX_Text(pDX, IDC_EDIT7, m_Q6);
	DDX_Text(pDX, IDC_EDIT9, m_Time);
	DDX_Text(pDX, IDC_EDIT1, m_MSGBox);
	DDX_Control(pDX, IDC_EDIT9, c_Time);
	DDX_Text(pDX, IDCM_N1, m_Time1);
	DDX_Text(pDX, IDCM_N2, m_Time2);
	DDX_Text(pDX, IDCM_N3, m_Time3);
	DDX_Text(pDX, IDCM_N4, m_Time4);
	DDX_Text(pDX, IDCM_N5, m_Time5);
	DDX_Text(pDX, IDCM_N6, m_Time6);
}

BEGIN_MESSAGE_MAP(CServerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCM_BListent, &CServerDlg::OnBnClickedBlistent)
	ON_BN_CLICKED(IDCM_BTime, &CServerDlg::OnBnClickedBtime)
	ON_BN_CLICKED(IDCM_BQ1, &CServerDlg::OnBnClickedBq1)
	ON_BN_CLICKED(IDCM_BQ2, &CServerDlg::OnBnClickedBq2)
	ON_BN_CLICKED(IDCM_BQ3, &CServerDlg::OnBnClickedBq3)
	ON_BN_CLICKED(IDCM_BQ4, &CServerDlg::OnBnClickedBq4)
	ON_BN_CLICKED(IDCM_BQ5, &CServerDlg::OnBnClickedBq5)
	ON_BN_CLICKED(IDCM_BQ6, &CServerDlg::OnBnClickedBq6)
	ON_BN_CLICKED(IDCM_BPlay, &CServerDlg::OnBnClickedBplay)
	ON_BN_CLICKED(IDCM_BExit, &CServerDlg::OnBnClickedBexit)
	ON_BN_CLICKED(IDCM_BRePlay, &CServerDlg::OnBnClickedBreplay)
	ON_BN_CLICKED(IDCM_BCancel, &CServerDlg::OnBnClickedBcancel)
END_MESSAGE_MAP()


// CServerDlg message handlers

BOOL CServerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_Server.SetParentDlg(this);
	n_Client = 0;
	CStdioFile fp;

	fp.Open(_T("InfoQues.txt"), CFile::modeRead);
	int i =0;
	fp.ReadString( m_Question[i] );
	while (i < 6)
	{
		fp.ReadString( m_Question[i] );
		m_Question[i] = m_Question[i].Trim(_T(" "));
		fp.ReadString( m_Answer[i] );
		m_Answer[i] = m_Answer[i].Trim(_T(" "));
		fp.ReadString( m_KiTu[i] );
		m_KiTu[i] = m_KiTu[i].Trim(_T(" "));
		fp.ReadString( m_NGuess[i] );
		m_NGuess[i] = m_NGuess[i].Trim(_T(" "));

		i++;
	}
	
	fp.Close();
	VisibleButton(false);
	GetDlgItem(IDCM_BPlay)->EnableWindow(false);
	GetDlgItem(IDCM_BRePlay)->EnableWindow(false);

	m_Q1 = m_Question[0];
	m_Q2 = m_Question[1];
	m_Q3 = m_Question[2];
	m_Q4 = m_Question[3];
	m_Q5 = m_Question[4];
	m_Q6 = m_Question[5];
	m_Time1 = m_NGuess[0];
	m_Time2 = m_NGuess[1];
	m_Time3 = m_NGuess[2];
	m_Time4 = m_NGuess[3];
	m_Time5 = m_NGuess[4];
	m_Time6 = m_NGuess[5];
	
	GetDlgItem(IDCM_BCancel)->EnableWindow(false);
	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CServerDlg::OnPaint()
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
HCURSOR CServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CServerDlg::OnClose(){
	MessageBox(_T("zxczxcz"));
	return;
}

void CServerDlg::OnAccept(){
	//m_Client.m_hSocket = INVALID_SOCKET;
	//int n = atoi(m_NumClient.GetString());
	
	//m_Client[n_Client].m_hSocket = INVALID_SOCKET;
	//Accept(m_Client[n_Client]);
	
	//m_Server.Accept(m_Client[n_Client]);

	int n2 = atoi((char*)(LPCTSTR)m_NumClient);
	if(m_Server.nClient2 >=n2)
	{
		SenMSG("12","","",m_Server.nClient2,"");
		return;
	}else{
		SenMSG("1","","",m_Server.nClient2,"");
		
	}

	return;
}
void CServerDlg::SenMSG(char* Flag, char* MSG, char* _Name,int _Client, char* _Ex)
{
	UpdateData(TRUE);
	userinfo uinf;
	if(_Client < 0)
	{
		for(int i = 0; i < m_Server.nClient2; i++)
		{
				strcpy_s(uinf.cUserName,_Name);
				strcpy_s(uinf.csMsg,MSG);
				strcpy_s(uinf.cFlag,Flag);
				strcpy_s(uinf.cEx,_Ex);
				char *buff=(char*)&uinf;
				m_Server.m_Client2[i].Send(buff,sizeof(userinfo));
		}
		return;
	}
	if(_Ex == "")
	{
	//const char* cstr = (char *)(LPCTSTR)m_User;
	
		strcpy_s(uinf.cUserName,_Name);
		strcpy_s(uinf.csMsg,MSG);
		strcpy_s(uinf.cFlag,Flag);
		strcpy_s(uinf.cEx,_Ex);

		char *buff=(char*)&uinf;
	
		m_Server.m_Client2[_Client].Send(buff,sizeof(userinfo));
	}else{
		for(int i =0; i < m_Server.nClient2; i++)
		{
			if(i == _Client)
			{
				strcpy_s(uinf.cUserName,_Name);
				strcpy_s(uinf.csMsg,_Ex);
				strcpy_s(uinf.cFlag,Flag);
				strcpy_s(uinf.cEx,_Ex);

				char *buff=(char*)&uinf;
	
				m_Server.m_Client2[_Client].Send(buff,sizeof(userinfo));
			}else{
				strcpy_s(uinf.cUserName,_Name);
				strcpy_s(uinf.csMsg,MSG);
				strcpy_s(uinf.cFlag,Flag);
				strcpy_s(uinf.cEx,_Ex);

				char *buff=(char*)&uinf;
	
				m_Server.m_Client2[i].Send(buff,sizeof(userinfo));
			}
		}
	}

}
void CServerDlg::NextRound(int _Client)
{
	
			if(_Client < (m_Server.nClient2-1 ))
			{
				if(client_Lost[_Client+1] == false)
				{
					NextRound(_Client + 1);
					return;
				}
				char* mes = ConvertToChar(_T("Turn  ")+name_client[_Client + 1] );
				// thong bao cho tat ca clien client 0 se quay
				Sleep(100);
				SenMSG("3",mes,"",_Client + 1,"Your turn");
			}else{
				if(client_Lost[0] == false)
				{
					NextRound(0);
					return;
				}
				char* mes = ConvertToChar(_T("Turn  ")+name_client[0] );
				// thong bao cho tat ca clien client 0 se quay
				Sleep(100);
				SenMSG("3",mes,"",0,"Your turn");
				//SenMSG("3","","",0,"");
			}
	return;
}
void CServerDlg::OnReceive(userinfo* udata){
	CString _Name(udata->cUserName);
	int _nClient ;
	for(int i = 0; i < m_Server.nClient2 ; i++)
	{
		if(_Name.Compare( name_client[i] ) == 0 )
		{
			_nClient = i;
		}
	}
	CString _MSG(udata->csMsg);
	int _Flag;
	_Flag = atoi(udata->cFlag);
	CString _Ex(udata->cEx);

	switch (_Flag)
	{
	default:
		break;
	case 1:
		{
			if(m_Server.nClient2 > 0)
			{
				for(int i = 0; i < m_Server.nClient2; i++)
				{
					//strcmp(udata->cUserName,name_client[i])
					if( _Name.Compare( name_client[i] ) == 0 )
					{
						SenMSG("13","","",m_Server.nClient2,"");
						return;
					}
				}
				
				m_Server.nameUser2[m_Server.nClient2] = udata->cUserName;
				name_client[m_Server.nClient2] = udata->cUserName;
				SenMSG("11","","",m_Server.nClient2,"");
				m_MSGBox += _Name + _T(" Login\r\n");
				
				m_Server.nClient2++;
				if(m_Server.nClient2 == atoi((char*)(LPCTSTR)m_NumClient))
				{
					VisibleButton(true);
					GetDlgItem(IDCM_BTime)->EnableWindow(false);
					c_Time.EnableWindow(false);
				}
			}
			else{
				//const char* s = udata->cUserName;
			
				m_Server.nameUser2[0] = udata->cUserName;
				name_client[0] = udata->cUserName;
				
				SenMSG("11","","",m_Server.nClient2,"");
				m_MSGBox += _Name + _T(" Login\r\n");
				m_Server.nClient2 = 1;
			}
			UpdateData(FALSE);
			break;
		}
	case 2:
		{

			break;
		}
	case 5:
		{
			int p1,p2;
			p1 = _MSG.Find(_T("|"), 0);
			//des[0] = src.Mid(0, p1);
			CString des1 = _MSG.Mid(0, p1);
			CString p,s,mes;
			mes = name_client[_nClient] + _T(" guess ")+ des1;
			p2 = _MSG.Find(_T("|"), p1 + 1);
			//des[1] = src.Mid(p1 + 1, p2 - (p1 + 1));
			CString des2 = _MSG.Mid(p1 + 1, p2 - (p1 + 1));
			
			for(int i = 0; i< m_Answer[nQ].GetLength(); i++)
			{
				if(des1[0] == m_Answer[nQ][i])
				{
					s.Format(_T("%d"),i+1);
					p += (_T(" ") + s);
					s = _T("");
				}
			}
			if(p.Compare(_T(""))!=0)
			{
				
				mes += _T(" correct, point is") + p;
				CString mes2 = _T("Your correct, point is") + p;
				int _Point = atoi(ConvertToChar(des2));
				_Point = _Point;
				point_client[_nClient] += _Point;
				SenMSG("5",ConvertToChar(mes),ConvertToChar(name_client[_nClient]),_nClient,ConvertToChar(mes2));
				Sleep(100);
				// sua diem
				s.Format(_T("%d"),point_client[_nClient]);
				SenMSG("4",ConvertToChar(s),"",_nClient,"");
				
			}
			else{
				mes += _T(" incorrect");
				SenMSG("5",ConvertToChar(mes),ConvertToChar(name_client[_nClient]),_nClient,"Your InCorrect");
			}
			nGuess++;
			if(nGuess >= atoi(ConvertToChar(m_NGuess[nQ])))
			{
				Sleep(100);
				SenMSG("71","","",-1,"");
				GetDlgItem(IDCM_BRePlay)->EnableWindow(true);
				GetDlgItem(IDCM_BPlay)->EnableWindow(false);
				return;
			}

			NextRound(_nClient);
			
			break;
		}

	case 51:
		 {
			 SenMSG("0",ConvertToChar(name_client[_nClient] + _T(" lost a round")),"",_nClient,"You lost a round");
			 NextRound(_nClient);
		 }
	case 6:
		{
			int p1,p2;
			p1 = _MSG.Find(_T("|"), 0);
			//des[0] = src.Mid(0, p1);
			CString des1 = _MSG.Mid(0, p1);

			p2 = _MSG.Find(_T("|"), p1 + 1);
			//des[1] = src.Mid(p1 + 1, p2 - (p1 + 1));
			CString des2 = _MSG.Mid(p1 + 1, p2 - (p1 + 1));
			
			

			if(des1.Compare(m_Answer[nQ]) == 0)
			{
				CString mes = name_client[_nClient] + _T(" answer ")+ des1 + _T(" correct.");
				CString mes2 = _T("Your answer correct.");
				int _Point = atoi(ConvertToChar(des2));
				_Point = _Point *3;
				point_client[_nClient] += _Point;
				CString _nPoint;
				CString _mes;
				for(int i = 0;i < m_Server.nClient2; i++)
				{
					_nPoint.Format(_T("%d"),point_client[i]);
					_mes+=name_client[i] + _T(": ") + _nPoint + _T("\r\n");

				}
				char* C = ConvertToChar(_mes);
				Sleep(100);
				//send message thong bao tra loi dung
				SenMSG("6",ConvertToChar(mes),ConvertToChar(name_client[_nClient]),-1,ConvertToChar(mes2));
				//send message sua diem cho cliem gui
				_nPoint.Format(_T("%d"),point_client[_nClient]);
				Sleep(100);
				SenMSG("4",ConvertToChar(_nPoint),"",_nClient,"");
				Sleep(100);
				// send message bang diem
				SenMSG("0",C,"",-1,"");
				Sleep(100);
				// send end game
				SenMSG("7",ConvertToChar(name_client[_nClient] + _T(" WIN!!!!!!!!!!!")),"",_nClient,"You WIN!!!!!!!!!!!");
				
				GetDlgItem(IDCM_BRePlay)->EnableWindow(true);
				GetDlgItem(IDCM_BPlay)->EnableWindow(false);

				
			}
			else{
				//send message giai sai o chu
				CString mes = name_client[_nClient] + _T(" answer ")+ des1 + _T(" Incorrect.");
				CString mes2 = _T("Your answer Incorrect.");
				Sleep(100);
				SenMSG("6",ConvertToChar(mes),ConvertToChar(name_client[_nClient]),-1,ConvertToChar(mes2));
				
				
				nGuess++;
				if(nGuess >= atoi(ConvertToChar(m_NGuess[nQ])))
				{
						Sleep(100);
						SenMSG("71","","",-1,"");
						GetDlgItem(IDCM_BRePlay)->EnableWindow(true);
						GetDlgItem(IDCM_BPlay)->EnableWindow(false);
						return;
				}
				NextRound(_nClient);
				
			}

			break;
		}
	case 8:
		{
			HasClose ++;
			if(HasClose >= m_Server.nClient2)
			{
				MessageBox(_T("Game Over!\r\n"));
				GetDlgItem(IDCM_BRePlay)->EnableWindow(true);
				GetDlgItem(IDCM_BPlay)->EnableWindow(false);
				return;
			}
			m_MSGBox += name_client[_nClient] + _T(" is close\r\n");
			SenMSG("0",ConvertToChar(name_client[_nClient] + _T(" is close")),"",-1,"");
			client_Lost[_nClient] = false;
			
			UpdateData(FALSE);
			break;
		}
	}
	return;
}



void CServerDlg::OnBnClickedBlistent()
{
	UpdateData(TRUE);
	// TODO: Add your control notification handler code here
	int n = atoi(ConvertToChar(m_NumClient));
	name_client = new CString [n];
	nGuess =0;
	HasClose =0;
	m_Client = new CSocket[n];
	m_Server.m_Client2 = new MyClient[n+1];
	m_Server.nameUser2 = new char *[n];
	m_Server.nClient2 =0;
	point_client = new int[n];
	client_Lost = new bool[n];
	for (int i = 0; i < n; i++)
	{
		point_client[i] = 0;
		client_Lost[i] = true;
	}

	for (int i = 0; i < n+1; i++)
	{
		m_Server.m_Client2[i].SetParentDlg(this);
	}

	m_Server.nClient2 = 0;
	if( AfxSocketInit() == FALSE)
	{ 
		AfxMessageBox(_T("Failed to Initialize Sockets\n")); 
		return; 
	}


	if(m_Server.Create(1234)==FALSE)
	{
		AfxMessageBox(_T("Failed to create\n")); 
		
		return;
	}
	
	if(m_Server.Listen(10)==FALSE)
	{
		AfxMessageBox(_T("Failed\n")); 
	
		return;
	}
	
	GetDlgItem(IDCM_BCancel)->EnableWindow(true);
	GetDlgItem(IDCM_BListent)->EnableWindow(false);
	
}

void CServerDlg:: VisibleButton(bool b){
					GetDlgItem(IDCM_BQ1)->EnableWindow(b);
					GetDlgItem(IDCM_BQ2)->EnableWindow(b);
					GetDlgItem(IDCM_BQ3)->EnableWindow(b);
					GetDlgItem(IDCM_BQ4)->EnableWindow(b);
					GetDlgItem(IDCM_BQ5)->EnableWindow(b);
					GetDlgItem(IDCM_BQ6)->EnableWindow(b);
					GetDlgItem(IDCM_BTime)->EnableWindow(b);
					c_Time.EnableWindow(b);
}

void CServerDlg::OnBnClickedBtime()
{
	VisibleButton(false);
	GetDlgItem(IDCM_BPlay)->EnableWindow(true);
	// TODO: Add your control notification handler code here
}


void CServerDlg::OnBnClickedBq1()
{

	// TODO: Add your control notification handler code here
	VisibleButton(true);
	nQ = 0;
	GetDlgItem(IDCM_BQ1)->EnableWindow(false);
}


void CServerDlg::OnBnClickedBq2()
{
	// TODO: Add your control notification handler code here
	VisibleButton(true);
	nQ = 1;
	GetDlgItem(IDCM_BQ2)->EnableWindow(false);
}


void CServerDlg::OnBnClickedBq3()
{
	// TODO: Add your control notification handler code here
	VisibleButton(true);
	nQ = 2;
	GetDlgItem(IDCM_BQ3)->EnableWindow(false);
}


void CServerDlg::OnBnClickedBq4()
{
	// TODO: Add your control notification handler code here
	VisibleButton(true);
	nQ = 3;
	GetDlgItem(IDCM_BQ4)->EnableWindow(false);
}


void CServerDlg::OnBnClickedBq5()
{
	// TODO: Add your control notification handler code here
	VisibleButton(true);
	nQ = 4;
	GetDlgItem(IDCM_BQ5)->EnableWindow(false);
}


void CServerDlg::OnBnClickedBq6()
{
	// TODO: Add your control notification handler code here
	VisibleButton(true);
	nQ = 5;
	GetDlgItem(IDCM_BQ6)->EnableWindow(false);
}


void CServerDlg::OnBnClickedBplay()
{
	// TODO: Add your control notification handler code here
	

	for(int i = 0; i < m_Server.nClient2  ; i++)
	{
		UpdateData(TRUE);
		char* m =  new char[4];
		memset(m, 0, 3);
		char msg[200]; //= new char[200];
		//msg = "|";
		size_t CharactersConverted=0;
		_itoa_s(m_Server.nClient2 ,msg,sizeof(msg),10);
		_itoa_s(i+1,m,sizeof(m),10);
		
		// so nguoi choi
		// so thu tu
		strcat_s(msg,sizeof(msg),"|");
		strcat_s(msg,sizeof(msg),m);
		// so ki tu
		char* nkitu = ConvertToChar(m_KiTu[nQ]);
		strcat_s(msg,sizeof(msg),"|");
		strcat_s(msg,sizeof(msg),nkitu);
		// goi y
		char* mGoiY = ConvertToChar(m_Question[nQ]);
		strcat_s(msg,200,"|");
		strcat_s(msg,200,mGoiY);
		strcat_s(msg,200,"|");
		char* mTime = ConvertToChar(m_Time);
		strcat_s(msg,200,mTime);
		strcat_s(msg,200,"|");
		char* mGuess = ConvertToChar(m_NGuess[nQ]);
		strcat_s(msg,200,mGuess);
		strcat_s(msg,200,"|");
		
		SenMSG("2",msg,"",i,"");
	
		
		
	}
	CString m(m_Server.nameUser2[0]);
	m_MSGBox += _T("has initialize for clients\r\n");
	NextRound(-1);
	/*
	m_MSGBox += _T("Turn ") + m + _T("\r\n");
	UpdateData(FALSE);
	char* mes = ConvertToChar(_T("Turn  ")+name_client[0] );
	// thong bao cho tat ca clien client 0 se quay
	SenMSG("3",mes,"",0,"Your turn");
	// thong bao cho client 0 duoc quay
	//SenMSG("3","","",0,"");*/
}


char* CServerDlg::ConvertToChar(const CString &s)
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

void CServerDlg::OnBnClickedBexit()
{
	// TODO: Add your control notification handler code here
	INT_PTR i = MessageBox(_T("Do you want exit"), _T("Confirm"), MB_OKCANCEL);
	if (i == IDCANCEL)
		return;
	m_Server.Close();
	for(int i = 0; i < m_Server.nClient2; i++)
		m_Server.m_Client2[i].Close();
	SenMSG("8","Server is close!","",-1,"");
	EndDialog(0);
	//Command = _T("3\r\n");
	//mSend(Command);
}


void CServerDlg::OnBnClickedBreplay()
{
	// TODO: Add your control notification handler code here
	VisibleButton(true);
	GetDlgItem(IDCM_BTime)->EnableWindow(false);
	c_Time.EnableWindow(false);
	GetDlgItem(IDCM_BPlay)->EnableWindow(false);
	GetDlgItem(IDCM_BRePlay)->EnableWindow(false);
	m_MSGBox = _T("");
	UpdateData(FALSE);
	UpdateData(TRUE);
	// TODO: Add your control notification handler code here
	int n = atoi(ConvertToChar(m_NumClient));
	nGuess =0;

	for (int i = 0; i < n; i++)
	{
		point_client[i] = 0;
	
	}
	Sleep(100);
	SenMSG("9","","",-1,"");
	Sleep(100);
	VisibleButton(true);
	GetDlgItem(IDCM_BTime)->EnableWindow(false);
	c_Time.EnableWindow(false);



}


void CServerDlg::OnBnClickedBcancel()
{
	// TODO: Add your control notification handler code here
	SenMSG("82","Server deconnection!","",-1,"");
	m_Server.Close();
	for(int i = 0; i < m_Server.nClient2; i++)
		m_Server.m_Client2[i].Close();
	
	GetDlgItem(IDCM_BListent)->EnableWindow(true);
	GetDlgItem(IDCM_BCancel)->EnableWindow(false);
	m_MSGBox = _T("");
	UpdateData(FALSE);
}




