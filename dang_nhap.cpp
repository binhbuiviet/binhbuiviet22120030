#include "dang_nhap.h"

void Dang_nhap_tai_khoan_GV(Nguoi_dung_hien_tai& ng)
{
	string Email, Password;
	char PASS;
	system("cls");
	cout << "\x1b[36m\n\n\t\t\t\t\t|*************|\033[0m";
	cout << "\x1b[36m\n\t\t\t\t\t| DANG NHAP |\033[0m";
	cout << "\x1b[36m\n\t\t\t\t\t|*************|\033[0m";
	cout << "\n\n\n  E-mail : ";
	cin >> Email;

	cout << "\n\n  Mat khau : ";

	// Mã hóa mật khẩu để xuất ra màn hình dấu *
	for (int i = 1; i <= 1000; i++)
	{
		PASS = _getch(); // Tìm hiểu cái getch này nha

		if (PASS == 13)
		{
			break;
		}
		Password += PASS;
		if (PASS == 127 || PASS == 8) {
			printf("\b \b");   // Cái này dùng để nếu khi nhập mật khẩu mình nhấn dấu xóa (backspace) thì trên màn hình cũng sẽ xóa bấy nhiêu dấu * 
		}
		else {
			cout << "*";
		}
	}
	//Kiểm tra email đăng nhập và mật khẩu trong file Luu_email_va_Mat_khau_Giang_vien.txt
	int d = 0;
	fstream check;
	check.open("Luu_email_va_Mat_khau_Giang_vien.txt", ios_base::in);
	if (!check)
	{
		cout << "Khong the mo file.\n"; //Nhớ chỉnh màu hoặc UI lại cho đẹp nhaaaa
		return;
	}
	while (check.eof() != true)
	{
		string pass, email;
		string info;
		while (getline(check, info)) {   // Tìm hiểu getline này nha ^^
			stringstream input(info);  // 
			input >> email >> pass;
			if (email == Email && pass == Password) {
				cout << endl << "Dang nhap thanh cong.";
				ng.me = Email;
				ng.mat_khau = Password;
				//Chuyển hướng tới hàm dành cho giảng viên (sẽ viết sau)
				d = 1;
				break;
			}
		}
		if (!d)
		{
			cout << "\x1b[33m\n\n\n\t\t\t\t\t Email dang nhap hoac Mat khau cua ban khong chinh xac. Vui long thu lai...\n  \033[0m\t\t";
			cout << "\n\n\n\n\t\t\t\t\t ";
			system("pause");
		}

	}
	system("pause");
	check.close();
}

void Xem_profile_GV(Nguoi_dung_hien_tai ng)
{
	fstream check;
	check.open("Thong_tin_GV.csv", ios_base::in);
	if (!check)
	{
		cout << "Khong the mo file.\n"; //Nhớ chỉnh màu hoặc UI lại cho đẹp nhaaaa
		return;
	}
	while (check.eof() != true)
	{
		string line;
		int d = 0;
		while (getline(check, line))
		{
			string a[6];
			string::size_type pos = 0;
			while ((pos = line.find(',')) != string::npos) //Tìm hiểu
			{
				a[d] = line.substr(0, pos); // Tìm hiểu
				line.erase(0, pos + 1); // Tìm hiểu
				if (a[0] != ng.me)
					break;
				d++;
			}
			if (d > 0)
			{
				//Nhớ làm màu hay UI khúc này nha 
				cout << "Ho va ten: " << a[1] << "\n";
				cout << "Email: " << a[0] << "\n";
				cout << "Ngay sinh: " << a[2] << "\n";
				cout << "Gioi tinh: " << a[3] << "\n";
				cout << "Chuc vu: " << a[4] << "\n";
				cout << "CCCD/CMND: " << a[5] << "\n";
				break;
			}
		}
		if (d > 0) break;
	}
	check.close();
}

void Doi_mat_khau_GV(Nguoi_dung_hien_tai& ng)
{
	/*
	* Có một ý tưởng là copy toàn bộ thông tin đăng nhập từ file cũ rồi ghi sang file mới, riêng với mật khẩu mới thì sẽ được thay thế bởi mật khẩu cũ
	* Rồi xóa file cũ rồi đổi tên file mới thành tên của file cũ rồi xóa file cũ
	* Tuy vậy phải luôn luôn tạo file mởi???
	* Có cách nào khác không???
	*/
	fstream check;
	check.open("Luu_email_va_Mat_khau_Giang_vien.txt", ios_base::in);
	fstream filetemp;
	filetemp.open("temp.txt", ios_base::out);
	string pass_cu = "";
	char pass;
	// Nhớ làm hình đẹp hoặc UI cho cái này nha 
	cout << "Nhap mat khau cu: ";
	// Mã hóa mật khẩu để xuất ra màn hình dấu *
	for (int i = 1; i <= 1000; i++)
	{
		pass = _getch(); // Tìm hiểu cái getch này nha

		if (pass == 13)
		{
			break;
		}
		pass_cu += pass;
		if (pass == 127 || pass == 8) {
			printf("\b \b");   // Cái này dùng để nếu khi nhập mật khẩu mình nhấn dấu xóa (backspace) thì trên màn hình cũng sẽ xóa bấy nhiêu dấu * 
		}
		else {
			cout << "*";
		}
	}
	while (pass_cu != ng.mat_khau)
	{
		// Nhớ làm hình đẹp hoặc UI cho cái này nha
		cout << "Mat khau cu chua chinh xac, vui long nhap lai.\n";
		pass_cu = "";
		cout << "Nhap mat khau cu: ";
		// Mã hóa mật khẩu để xuất ra màn hình dấu *
		for (int i = 1; i <= 1000; i++)
		{
			pass = _getch(); // Tìm hiểu cái getch này nha

			if (pass == 13)
			{
				break;
			}
			pass_cu += pass;
			if (pass == 127 || pass == 8) {
				printf("\b \b");   // Cái này dùng để nếu khi nhập mật khẩu mình nhấn dấu xóa (backspace) thì trên màn hình cũng sẽ xóa bấy nhiêu dấu * 
			}
			else {
				cout << "*";
			}
		}
	}
	string pass_moi;
	cout << "Nhap mat khau moi: ";
	for (int i = 1; i <= 1000; i++)
	{
		pass = _getch(); // Tìm hiểu cái getch này nha

		if (pass == 13)
		{
			break;
		}
		pass_moi += pass;
		if (pass == 127 || pass == 8) {
			printf("\b \b");   // Cái này dùng để nếu khi nhập mật khẩu mình nhấn dấu xóa (backspace) thì trên màn hình cũng sẽ xóa bấy nhiêu dấu * 
		}
		else {
			cout << "*";
		}
	}
	//Đạt lại màu với UI chỗ này
	if (!check)
	{
		cout << "Khong the mo file Luu_email_va_Mat_khau_Giang_vien.txt\n";
		return;
	}
	if (!filetemp)
	{
		cout << "Khong the mo file temp.txt\n";
		return;
	}
	while (check.eof() != true)
	{
		string email, password;
		string info;
		while (getline(check, info))
		{   // Tìm hiểu getline này nha ^^
			stringstream input(info);  // 
			input >> email >> password;
			if (pass_cu == password && email == ng.me)
			{
				filetemp << email << " " << pass_moi << "\n";
			}
			else
				filetemp << email << " " << pass_cu << "\n";
		}
	}
	ng.mat_khau = pass_moi;
	check.close();
	filetemp.close();


	fstream copy, copytemp;
	copy.open("Luu_email_va_Mat_khau_Giang_vien.txt", ios_base::out);
	copytemp.open("temp.txt", ios_base::in);
	while (copytemp.eof() != true)
	{
		string email, password;
		string info;
		while (getline(copytemp, info))
		{
			stringstream input(info);
			input >> email >> password;
			copy << email << " " << password << "\n";
		}
	}
	copy.close();
	copytemp.close();
	// Đã viết xong nhưng chưa ktra
}
// Dành cho Học sinh/Sinh viên (Tương tự chưa oke)
void Dang_nhap_tai_khoan_SV(Nguoi_dung_hien_tai& ng)
{
	string mssv, Password;
	char PASS;
	system("cls");
	cout << "\x1b[36m\n\n\t\t\t\t\t|*************|\033[0m";
	cout << "\x1b[36m\n\t\t\t\t\t| DANG NHAP |\033[0m";
	cout << "\x1b[36m\n\t\t\t\t\t|*************|\033[0m";
	cout << "\n\n\n  MSSV : ";
	cin >> mssv;

	cout << "\n\n  Mat khau : ";

	// Mã hóa mật khẩu để xuất ra màn hình dấu *
	for (int i = 1; i <= 1000; i++)
	{
		PASS = _getch();
		if (PASS == 13)
		{
			break;
		}
		Password += PASS;
		if (PASS == 127 || PASS == 8) {
			printf("\b \b");   // Cái này dùng để nếu khi nhập mật khẩu mình nhấn dấu xóa (backspace) thì trên màn hình cũng sẽ xóa bấy nhiêu dấu * 
		}
		else {
			cout << "*";
		}
	}
	//Kiểm tra email đăng nhập và mật khẩu trong file Luu_email_va_Mat_khau_Giang_vien.txt
	int d = 0;
	fstream check;
	check.open("Luu_MSSV_va_Mat_khau_Sinh_vien.txt", ios_base::in);
	if (!check)
	{
		cout << "Khong the mo fi.e.\n"; //Nhớ chỉnh màu hoặc UI lại cho đẹp nhaaaa
		return;
	}
	while (check.eof() != true)
	{
		string pass, ms;
		string info;
		while (getline(check, info)) {   // Tìm hiểu getline này nha ^^
			stringstream input(info);  // 
			input >> ms >> pass;
			if (ms == mssv && pass == Password) {
				cout << endl << "Dang nhap thanh cong."; //Chuyển hướng tới hàm dành cho giảng viên (sẽ viết sau)
				d = 1;
				ng.me = mssv;
				ng.mat_khau = Password;
				break;
			}
		}
		if (!d)
		{
			cout << "\x1b[33m\n\n\n\t\t\t\t\t MSSV hoac Mat khau cua ban khong chinh xac. Vui long thu lai...\n  \033[0m\t\t";
			cout << "\n\n\n\n\t\t\t\t\t ";
			system("pause");
		}
	}
	check.close();
}

void Xem_profile_SV(Nguoi_dung_hien_tai ng)
{
	fstream check;
	check.open("Thong_tin_SV.csv", ios_base::in);
	if (!check)
	{
		cout << "Khong the mo file.\n"; //Nhớ chỉnh màu hoặc UI lại cho đẹp nhaaaa
		return;
	}
	while (check.eof() != true)
	{
		string line;
		int d = 0;
		while (getline(check, line))
		{
			string a[7];
			string::size_type pos = 0;
			while ((pos = line.find(',')) != string::npos) //Tìm hiểu
			{
				a[d] = line.substr(0, pos); // Tìm hiểu
				line.erase(0, pos + 1); // Tìm hiểu
				if (a[0] != ng.me)
					break;
				d++;
			}
			if (d > 0)
			{
				//Nhớ làm màu hay UI khúc này nha 
				cout << "Ho va ten: " << a[1] << "\n";
				cout << "MSSV: " << a[2] << "\n";
				cout << "Email: " << a[0] << "\n";
				cout << "Ngay sinh: " << a[3] << "\n";
				cout << "Gioi tinh: " << a[4] << "\n";
				cout << "Chuc vu: " << a[5] << "\n";
				cout << "CCCD/CMND: " << a[6] << "\n";
				break;
			}
		}
		if (d > 0) break;
	}
	check.close();
}

void Menu_chinh()
{
	int ans;
	Nguoi_dung_hien_tai ng;
	do
	{
		system("cls");
		//Menu chinh
		cout << "\n\n\n\n\t\t\t\t\t\x1b\033[3;47;35mCHAO MUNG DEN VOI HE THONG QUAN LY KHOA HOC. \033[0m\033[0m\n"; //Có thể đặt lại màu cho đẹp hơn
		cout << "\n\x1b[33m\n\n\n\t 1. Ban la Giang vien/ Giao vien.\033[0m\t\t";
		cout << "\x1b[33m\n\n\t 2. Ban la Hoc sinh/ Sinh vien.\033[0m\t\t";
		cout << "\x1b[33m\n\n\t 3. THOAT.\033[0m\t\t";
		cout << "\n\n\t  Nhap lua chon cua ban :: ";
		cin >> ans;

		switch (ans)
		{
		case 1:
			Dang_nhap_tai_khoan_GV(ng);//Hàm dành cho giảng viên/giáo viên; 
			break;
		case 2: //Hàm dành cho học sinh sinh viên;
			Dang_nhap_tai_khoan_SV(ng);
			break;
		case 3: exit(0);
		default:cout << "\x1b[33m\n\n\n\n\t\t\t\t\t Gia tri nhap khong hop le. Vui long nhap lai....\n  \033[0m\t\t";
			cout << "\n\n\n\n\t\t\t\t\t ";
			system("pause");
		}
	} while (1);
}