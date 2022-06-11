/*
@Author
@Vo Tan Dat
@Le Thanh Nghia
@Vo Thi Minh Tien
@Nguyen Tuan Hiep
*/
#include "TracNghiemCauHoi.cpp"
using namespace std;
List l;
Tree tree;
string hoten;
int goicau;
int soluongcaude = 0;

void docCauHoiThi()
{
	ifstream file_in, file_in2;
	file_in.open("cauhoi.txt",ios::in);
	file_in2.open("cauhoikho.txt",ios::in);
	docDanhSach(file_in,l);
	soluongcaude = soluong;
	docDanhSach(file_in2,l);
	docDapAn(l,tree);
	//LuuDanhSach(l,soluongcaude);
	file_in.close();file_in2.close();
}
void option1() {
	system("cls");
	printRow();
	KhungCauHoiThi();
	system("cls");
	KhungNhapTen(hoten,goicau);
	KhungCauHoiThi();
	lapCauHoi(l,tree,goicau,hoten,soluongcaude);
	system("cls");
	gotoxy(0,0);
	setcolor(13);
	KhungBatDauKhongDeLay();
	ShowCur(false);
}

void option2() {
	clean();
	themCauHoi(l,soluongcaude);
	ShowCur(false);
	clean();
}
void option3(){
	clean();
	xoaCauHoi(l);
	clean();
}
void option4(){
	ifstream file_lichsu;
	file_lichsu.open("lichsuthi.txt",ios::in);
	clean();
	KhungLichSu(file_lichsu);
}
void process() {
	
	// declare menu options
	string options[] = {
			"Bai dau thi" , 
			"Them cau hoi", 
			"Xoa cau hoi", 
			"Lich su thi", 
			"Luu va Thoat"};
	int optionsLen = sizeof(options)/sizeof(options[0]);

	// initialize class colorMenu
	
	ColorMenu colorMenu(options, optionsLen, CLR_FOCUS, CLR_NORML);
	
	// handle option choices
	do {
		int optionIndex = colorMenu.handleMenu();	
		switch(optionIndex) {
			case 0: 
				option1();
				break;
			case 1:
				option2();
				break;
			case 2: 
				option3();
				break;
			case 3:
				option4();
				break; 
			case 4:
				LuuDanhSach(l,soluongcaude);
				colorMenu.~ColorMenu();
				exit(0);
				break;
		}		
	} while (true);	
}
void khungBatDau(){
	ShowCur(false);
	for(int i = 0; i < 119; i++)
	{
		Sleep(1);
		printf("%c",219);
	}
	for(int i = 0 ; i < 27; i++)
	{
		Sleep(1);
		gotoxy(0,i);
		printf("%c",219);
		gotoxy(1,i);
		printf("%c",219);
		
		gotoxy(119,i);
		printf("%c",219);
		gotoxy(118,i);
		printf("%c",219);
		gotoxy(39 ,i);
		printf("%c",219);
		gotoxy(40 ,i);
		printf("%c",219);
		/*gotoxy(119, i);
		printf("%c",219);
		printf("%c",219);
		gotoxy(40 ,i);
		printf("%c",219);
		printf("%c",219);*/
	}
	for(int i = 0; i < 61; i++)
	{
		Sleep(1);gotoxy(i, 27);
		printf("%c",219);
		gotoxy(120 - i,27);
		printf("%c",219);
	} 
	for(int i = 0; i < 39; i++)
	{
		Sleep(1);
		gotoxy(i, 12);
		printf("%c",219);
	}
	ifstream file_dohoa;
	file_dohoa.open("ctdl.txt",ios::in);
	string line; int i = 0;
	while(!file_dohoa.eof())	
	{
		getline(file_dohoa,line);
		gotoxy(50, 2 + i);setcolor(2);
		i++;
		cout <<line<<endl;
	}
	process();
	file_dohoa.close();
}
int main()
{
	system("color 0d");
	SetConsoleTitle("TracNghiemTiengAnh.exe");
	DisableSelection();
	docCauHoiThi();

	khungBatDau();
	process();
	KhungCauHoiThi();
	cin.get();
}
