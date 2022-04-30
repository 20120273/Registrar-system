#pragma once
#ifndef DANGKI_H
#define DANGKI_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class schedule
{
protected:
	vector<string> tenkhoahoc;
public:
	void xoakhoahoc(string name);
	void ThemKhoaHoc(string name);
	bool checkTrungKhoa(string name);
	void XuatDSDK();
};
class student
{
protected:
	string tenhocsinh;
	schedule khoabieu;
public:
	void TenSinhVien(string name);
	void ThemKhoaHoc(string name);
	void XoaKhoaHoc(string name);
	string getTenHS() { return tenhocsinh; }
	schedule getTKB() { return khoabieu; }
	void XuatTTSv();
};

class roster
{
protected:
	vector<string> tensv;
public:
	void xoaSv(string name);
	void ThemSv(string name);
	int soluongsv() { return tensv.size(); }
	void XuatDSSVDK();
};

class course
{
protected:
	string tenkhoahoc;
	roster dshocsinh;
public:
	course(string ten);
	void themsv(string name);
	void xoaSv(string name);
	string getTenKhoaHoc() { return tenkhoahoc; }
	int soluonghocvien() { return dshocsinh.soluongsv(); }
	void XuatTTKhoaHoc();
};
class registrar
{
protected:
public:
	void dangki(vector<course> &x, student &y);
	void huymon(vector<course> &x, vector<student>& y);
};
#endif // !DANGKI_H

