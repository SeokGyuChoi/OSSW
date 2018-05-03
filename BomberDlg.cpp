
// BomberDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Bomber.h"
#include "BomberDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CBomberDlg ��ȭ ����



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


// CBomberDlg �޽��� ó����

BOOL CBomberDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CBomberDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
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

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CBomberDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



int CBomberDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	//m_imgList.Create(IDB_BITMAP1, 48, 1, RGB(255, 255, 255));
	CBitmap BmpImageList;
	BmpImageList.LoadBitmapW(IDB_BITMAP2);
	m_imgList.Create(48, 48, ILC_COLOR24, 0, 3);
	m_imgList.Add(&BmpImageList, RGB(255, 255, 255));
	return 0;
}
