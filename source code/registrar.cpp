#include"registrar.h"

//DINH NGHIA STUDENT

void student::TenSinhVien(string name)
{
	tenhocsinh = name;
}
void student::XoaKhoaHoc(string name)
{
	khoabieu.xoakhoahoc(name);
}
void student::ThemKhoaHoc(string name)
{
	khoabieu.ThemKhoaHoc(name);
}
void student::XuatTTSv()
{
	cout << "==============================================="<<endl;
	cout << "Ten sinh vien: "<<tenhocsinh << endl;
	khoabieu.XuatDSDK();
}
//DINH NGHIA SCHEDULE
void schedule::ThemKhoaHoc(string name)
{
	tenkhoahoc.push_back(name);
}
void schedule::xoakhoahoc(string name)
{
	for (int i = 0; i < tenkhoahoc.size(); i++)
	{
		if (name == tenkhoahoc[i])
		{
			tenkhoahoc.erase(tenkhoahoc.begin() + i);
			return;
		}
	}
	cout << "Ko tim thay khoa hoc!"<<endl;
}
bool schedule::checkTrungKhoa(string name)
{
	for (int i = 0; i < tenkhoahoc.size(); i++)
	{
		if (tenkhoahoc[i] == name)
			return 1;
	}
	return 0;
}
void schedule::XuatDSDK()
{
	cout << "Danh sach mon da dang ki: "<<endl;
	for (int i = 0; i < tenkhoahoc.size(); i++)
	{
		cout << tenkhoahoc[i] << endl;
	}
}
//DINH NGHIA COURSE
void course::themsv(string name)
{
	dshocsinh.ThemSv(name);
}
void course::xoaSv(string name)
{
	dshocsinh.xoaSv(name);
}
void course::XuatTTKhoaHoc()
{
	cout << "=========================================="<<endl;
	cout << "Ten mon hoc: " << tenkhoahoc << endl;
	dshocsinh.XuatDSSVDK();
}
course::course(string ten)
{
	tenkhoahoc = ten;
}
//DINH NGHIA ROSTER
void roster::ThemSv(string name)
{
	if(tensv.size()<=40)
		tensv.push_back(name);
	else
	{
		cout << "Da full! Khong the them" << endl;
	}
}
void roster::xoaSv(string name)
{
	for (int i = 0; i < tensv.size(); i++)
	{
		if (name == tensv[i])
		{
			tensv.erase(tensv.begin() + i);
			return;
		}
	}
	cout << "Khong tim thay sinh vien de xoa!";
}
void roster::XuatDSSVDK()
{
	cout << "Danh sach sinh vien dang ki: " << endl;
	for (int i = 0; i < tensv.size(); i++)
	{
		cout << tensv[i] << endl;
	}
}
//KIEM TRA DIEU KIEN
int checkKhoaHoc(string name, vector<course> &kh)
{
	for (int i = 0; i < kh.size(); i++)
	{
		if (name == kh[i].getTenKhoaHoc() and kh[i].soluonghocvien() <= 40)
		{
			return i;
		}
	}
	return -1;
}
bool checkHocSinh(string name, vector<student> hs)
{
	for (int i = 0; i < hs.size(); i++)
	{
		if (name == hs[i].getTenHS())
			return i;
	}
	return -1;
}

//DINH NGHIA REGISTRAR
void registrar::dangki(vector<course>& x, student& y)
{
	string tensv;
	cout << "Nhap ten sinh vien: ";
	cin.ignore();
	getline(cin, tensv);
	y.TenSinhVien(tensv);
	int n = 0;
	cout << "Nhap so khoa hoc can dang ki: ";
	cin >> n;
	while (n > 5)
	{
		cout << "Toi da chi 5 khoa hoc!!. Moi nhap lai so luong khoa hoc: ";
		cin >> n;
	}
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string tkh;
		cout << "Nhap ten khoa hoc: ";
		getline(cin, tkh);
		while (checkKhoaHoc(tkh, x)==-1 )
		{
			cout << "Khoa hoc khong ton tai hoac da full hoc vien! Vui long dang ki lai: ";
			getline(cin, tkh);
		}
		while (y.getTKB().checkTrungKhoa(tkh) == 1)
		{
			cout << "Khoa hoc da duoc dang ki truoc do! Xin chon khoa khac: ";
			getline(cin, tkh);
		}
		x[checkKhoaHoc(tkh, x)].themsv(tensv);
		y.ThemKhoaHoc(tkh);
	}
}
void registrar::huymon(vector<course>& x, vector<student>&y)
{	
	string tensv;
	cout << "Nhap ten sinh vien: ";
	cin.ignore();
	getline(cin, tensv);
	cout << tensv << endl;
	if (checkHocSinh(tensv, y)==-1)
	{
		cout << "Khong ton tai sv!"<<endl;
		return;
	}
	string tkh;
	cout << "Nhap ten khoa hoc can huy: ";
	getline(cin, tkh);
	int ind = checkHocSinh(tensv, y);
	y[ind].XoaKhoaHoc(tkh);
	int indx = checkKhoaHoc(tkh, x);
	if (checkKhoaHoc(tkh, x) == -1)
	{
		return;
	}
	x[indx].xoaSv(tensv);
}
void menu()
{
	vector<student> dshs;
	vector<course> dsmh;
	registrar dk;
	int n = 0;
	int slsv = 0;
	cout << "Nhap so mon dang hien co: ";
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string tenmon;
		cout << "Nhap ten mon: ";
		getline(cin, tenmon);
		course y(tenmon);
		dsmh.push_back(y);
	}
	system("pause");
	while (true)
	{
		system("cls");
		cout << "========MENU=======" << endl;
		cout << "0. Thoat khoi menu" << endl;
		cout << "1. Dang ki mon hoc " << endl;
		cout << "2. Them mon hoc vao danh sach mon hoc" << endl;
		cout << "3. Xoa mon hoc da dang ki" << endl;
		cout << "4. Xuat danh sach hoc sinh" << endl;
		cout << "5. Xuat danh sach khoa hoc" << endl;
		int lc = 0;
		cout << "Nhap lua chon: ";
		cin >> lc;
		switch (lc)
		{
		case 0:
		{
			return;
		}
		case 1:
		{
			student hs;
			dk.dangki(dsmh,hs);
			dshs.push_back(hs);
			break;
		}
		case 2:
		{
			string tenmon;
			cout << "Nhap ten mon: ";
			cin.ignore();
			getline(cin, tenmon);
			course y(tenmon);
			dsmh.push_back(y);
			break;
		}
		case 3:
		{
			dk.huymon(dsmh, dshs);
			break;
		}
		case 4:
		{
			for (int i = 0; i < dshs.size(); i++)
			{
				dshs[i].XuatTTSv();
			}
			break;
		}
		case 5:
		{
			for (int i = 0; i < dsmh.size(); i++)
			{
				dsmh[i].XuatTTKhoaHoc();
			}
			break;
		}
		default:
			break;
		}
		system("pause");
	}
}
int main()
{
	menu();
	
	return 0;
}