
// BomberDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Bomber.h"
#include "BomberDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CBomberDlg 대화 상자



CBomberDlg::CBomberDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBomberDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBomberDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBomberDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CBomberDlg 메시지 처리기

BOOL CBomberDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CBomberDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CBomberDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();

		CClientDC dc(this);
		//dc.MoveTo(0, 0);
		//dc.LineTo(100, 100);
		//m_imageList.SetBkObject
		//m_imgList.Draw(&dc, 0, CPoint(50, 50), ILD_NORMAL);
		//m_imgList.Draw(&dc, 1, CPoint(100, 50), ILD_NORMAL);
		m_imgList.SetBkColor(CLR_NONE);
		m_imgList.Draw(&dc, 2, CPoint(650, 50), ILD_TRANSPARENT);
		m_imgList.Draw(&dc, 2, CPoint(650, 50), ILD_MASK);
		//char *Map = "1001001001";
		/*
		CBitmap BmpImageList;
		BmpImageList.LoadBitmapW(IDB_IMAGELIST);
		m_ImageList.Create(45, 15, ILC_COLOR24, 0, 3);
		m_ImageList.Add(&BmpImageList, RGB(255, 0, 255);
		*/


		char* Map[10] = {

			"0101101110101",
			"1010010101001",
			"1000111000101",
			"0101011101110",
			"1011100010110",
			"0010110101011",
			"1110010111100",
			"0110110111010",
			"1010001001000",
			"0101101110101"
		};

		for(int j = 0; j < 10; j++)
		{
			for (int i = 0; i < 10; i++)
			{
				if (Map[i][j] == '1')
				{
					m_imgList.Draw(&dc, 0, CPoint(48 + (48 * i), 48 + (48 * j)), ILD_NORMAL);
				}
				else if (Map[i][j] == '0')
				{
					m_imgList.Draw(&dc, 1, CPoint(48 + (48 * i), 48 + (48 * j)), ILD_NORMAL);
				}
			}
		}
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CBomberDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



int CBomberDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	//m_imgList.Create(IDB_BITMAP1, 48, 1, RGB(255, 255, 255));
	CBitmap BmpImageList;
	BmpImageList.LoadBitmapW(IDB_BITMAP2);
	m_imgList.Create(48, 48, ILC_COLOR24, 0, 3);
	m_imgList.Add(&BmpImageList, RGB(255, 255, 255));
	return 0;
}
