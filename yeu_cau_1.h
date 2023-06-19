#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <cstdio>
#include <sstream>


using namespace std;

//Cấu trúc thời gian 
struct Thoi_gian_hien_tai
{
	int ngay;
	int thang;
	int nam;
	string wday;
};

struct Lop_hoc
{
	string ten_lop;
	Lop_hoc* pPrev;
	Lop_hoc* pNext;
};

struct List_lop_hoc
{
	Lop_hoc* pHead;
	Lop_hoc* pTail;
};

struct sinh_vien
{
	string mssv;
	string ho;
	string ten;
	string gioi_tinh;
	string ngay_sinh;
	string cccd;
	sinh_vien* pNext;
};

struct List_sinh_vien
{
	sinh_vien* pHead;
	sinh_vien* pTail;
};

struct khoa_hoc
{
	string ma_mon_hoc;
	string ten_khoa_hoc;
	string ten_lop;
	string ten_giang_vien;
	int so_tin_chi;
	int sinh_vien_toi_da;
	string buoi_hoc;
	string khung_gio;
	khoa_hoc* pNext;
};

struct List_khoa_hoc
{
	khoa_hoc* pHead;
	khoa_hoc* pTail;
};

Thoi_gian_hien_tai tght;
string nam_hoc_hien_tai;

void Lay_thoi_gian_hien_tai();
bool Kiem_tra_folder(string& ten_folder);
bool Tao_folder(string& ten_folder);
void Tao_mot_nam_hoc();
void Tao_lop();
void Them_1_sinh_vien(sinh_vien*& sv);
void Tao_danh_sach(List_sinh_vien& l);
void Them_sv_vao_danh_sach(List_sinh_vien& l);
void Them_sv_vao_file();