#include "yeu_cau_2.h"

void tao_hoc_ky() //LƯU Ý: PHẢI KIỂM TRA TẠO NĂM HỌC TRƯỚC THÌ MỚI ĐƯỢC TỚI HÀM TẠO HỌC KỲ
{
	int hk;
	//Nhập học kì bạn muốn tạo, lưu ý là chỉ có học kì 1,2,3
	cin >> hk;
	while (hk != 1 && hk != 2 && hk != 3)
	{
		//Nhập lại các kiểu
		cin >> hk;
	}
	hoc_ki = nam_hoc_hien_tai+"/Hoc ki " + to_string(hk); //Mục đích là để lưu folder học kì vào folder năm học, tuy nhiên CÓ THỂ CHƯA ĐÚNG
	//Kiểm tra xem học kì đã được khởi tạo chưa
	if (Kiem_tra_folder(hoc_ki))
		cout << "Hoc ki nay da duoc tạo.\n"; //Chỉnh đồ họa nha
	else
	{
		if (Tao_folder(hoc_ki))
			cout << "Hoc ki da duoc tao xong.\n"; //Chỉnh đồ họa nha
		else
			cout << "Co loi khi tao hoc ki nay. Vui long thu lai.\n"; //Chỉnh đồ họa nha
	}
	string file_hoc_ki;
	file_hoc_ki = nam_hoc_hien_tai + "/Thong tin hoc ki " + to_string(hk) + ".txt"; //Dùng để tạo ra file được lưu trong folder năm học, file này ghi thông tin năm học, ngày bắt đầu, ngày kết thúc
	string ngay_bat_dau, ngay_ket_thuc;
	//Nhập ngày bắt đầu học kì
	cin.ignore();
	getline(cin, ngay_bat_dau);
	//Nhập ngày kết thúc học kì
	getline(cin, ngay_ket_thuc);
	ofstream fout;
	fout.open(file_hoc_ki);
	fout << nam_hoc_hien_tai << "\n"
		<< ngay_bat_dau << "\n"
		<< ngay_ket_thuc << "\n";
	fout.close();

	//Tạo một file csv lưu tất cả các thông tin của các khóa học
	thong_tin_cac_khoa_hoc = hoc_ki + "/Thong tin cac khoa hoc.csv";
	ofstream info_courses;
	info_courses.open(thong_tin_cac_khoa_hoc);
	info_courses << "Ma mon hoc,Ten khoa hoc,Ten lop,Ten giang vien,So tin chi,So luong sinh vien toi da,Buoi hoc,Khung gio hoc\n";
	info_courses.close();
}

void tao_khoa_hoc()
{
	//Cần kiểm tra học kì đã được tạo hay chưa
	string course;
	//Nhập tên khóa học
	getline(cin, course);
	string Khoa_hoc = hoc_ki + "/" + course;
	if (Tao_folder(Khoa_hoc))
	{
		//Tạo xong
	}
	string info;
	info = "Thong tin khoa hoc";
	string INFO; //Đây là để tạo file txt chứa thông tin khóa học
	INFO = Khoa_hoc + "/" + info + ".txt";
	ofstream nhap_info;
	nhap_info.open(INFO);
	//Nhớ chỉnh đồ họa khúc này nha
	khoa_hoc* k;
	k = new khoa_hoc;
	//Nhớ căn chỉnh đồ họa
	cout << "Ma mon hoc: ";
	getline(cin, k->ma_mon_hoc);
	cout << "Ten khoa hoc: ";
	getline(cin, k->ten_khoa_hoc);
	cout << "Ten lop: ";
	getline(cin, k->ten_lop);
	cout << "Ten giang vien: ";
	getline(cin, k->ten_giang_vien);
	cout << "So tin chi: ";
	cin >> k->so_tin_chi;
	cout << "So luong sinh vien toi da: ";
	cin >> k->sinh_vien_toi_da;
	while (k->sinh_vien_toi_da > 50 || k->sinh_vien_toi_da < 1)
	{
		//Nhập lại
		cin >> k->sinh_vien_toi_da;
	}

	int buoihoc;
	cout << "Buoi hoc se la mot ngay tu thu hai den thu bay. Vui long nhap mot so nguyen tu 2 den 7.\n";
	cout << "Buoi hoc: Thu ";
	cin >> buoihoc;
	while (buoihoc < 2 || buoihoc>7)
	{
		//Nhập lại
		cin >> buoihoc;
	}
	k->buoi_hoc = "Thu " + to_string(buoihoc);

	int khunggio;
	cout << "Khung gio hoc co cac khung gio sau.\n"
		<< "S1(07:30).\n"
		<< "S2(09:30).\n"
		<< "S3(13:30).\n"
		<< "S4(15:30).\n"
		<< "Vui long nhap mot so tu nhien tu 1 den 4.\n";
	cout << "Khung gio hoc: S";
	cin >> khunggio;
	while (khunggio < 1 || khunggio>4)
	{
		//Nhập lại;
		cin >> khunggio;
	}
	if (khunggio == 1)
		k->khung_gio = "S1(07:30)";
	else if (khunggio == 2)
		k->khung_gio = "S2(09:30)";
	else if (khunggio == 3)
		k->khung_gio = "S3(13:30)";
	else if (khunggio == 4)
		k->khung_gio = "S4(15:30)";

	k->pNext = nullptr;
	nhap_info << k->ma_mon_hoc << ","
		<< k->ten_khoa_hoc << ","
		<< k->ten_lop << ","
		<< k->ten_giang_vien << ","
		<< k->so_tin_chi << ","
		<< k->sinh_vien_toi_da << ","
		<< k->buoi_hoc << ","
		<< k->khung_gio;
	nhap_info.close();

	//Nhập thông tin khóa học vừa có vào file thông tin các khóa học
	fstream nhap_info_csv;
	nhap_info_csv.open(thong_tin_cac_khoa_hoc, ios_base::app);
	nhap_info_csv << k->ma_mon_hoc << ","
		<< k->ten_khoa_hoc << ","
		<< k->ten_lop << ","
		<< k->ten_giang_vien << ","
		<< k->so_tin_chi << ","
		<< k->sinh_vien_toi_da << ","
		<< k->buoi_hoc << ","
		<< k->khung_gio << "\n";
	nhap_info_csv.close();


}