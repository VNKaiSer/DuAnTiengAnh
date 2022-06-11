#include "AVL.cpp"
#define filech "cauhoi.txt"
using namespace std;
struct NOIDUNGCH
{
	int id;
	string cauHoi;
	string cauA;
	string cauB;
	string cauC;
	string cauD;
};
struct CAUHOI
{
	NOIDUNGCH noidung;
	string dapAn;
};
struct node
{
	CAUHOI data;
	node *next;
};
struct List
{
	node *Head;
	node *Tail;
};
void CreateList(List &l);
int conver(string s);
void docTungCau(ifstream &file_in, CAUHOI &ch);
node *createNode(CAUHOI x);
void AddHead(List &l, node *node);
void AddTail(List &l, node *node);
void addfirst(List &l,node *new_ele);
void RemoveList (List &l);
void docDanhSach(ifstream &file_in, List &l);
void incauhoi(CAUHOI ch);
void printList(List l);
void docDapAn(List l, Tree &t);
void printDapAn(Tree t);
string seachDapAn(Tree t, int x);
void generateRandomResponse(vector<string> randomResponse );
void themDapAn(NOIDUNGCH ch);
void nhapDapAn (Tree t,int &ans, int id); 
bool kiemTraDungD(Tree t, int ans, int id);
void setScore(int &score);
void randomCauHoi(vector<NOIDUNGCH> CauHoi, Tree t);
void lapCauHoi(List l, Tree t, int goiCau, string hoten, int socaude);
void themCauHoi(List &l, int &socaude);
void xoaCauHoi(List &l);
void deleteNode(List &l , int key);
void LuuTungCau(ofstream &fileout, CAUHOI dulieu);
void LuuTungCauCuoi(ofstream &fileout,CAUHOI dulieu);
int  LuuDanhSach(List l, int socaude);
void setAutoID(int &n);
void LuuLichSu(ofstream &fileout);
void XuLyRanDomGoiCau(List l, int goicau);
void luuLichSuThi(FILE *f,float diem,string hoten,int goicau);
int  lichSuThiGanNhat(float diem,string hoten,int goicau);
double tinhDiem(int score, int goicau);
void tinhSoCauKhoDe(int goicau,int &caude, int &caukho);
//-------------------menu va do hoa --------------------------------
class ColorMenu{
	
	private:
		int colorFocus;
		int colorNormal;
		int len;
		string* options;
		
	public:
		ColorMenu(string*, int, int, int);
		~ColorMenu();
		int getMenuLength();
		void printMenu(int);
		int handleMenu();
		
};
void setcolor(short x);
void SetColor(int backgound_color, int text_color);
void ShowCur(bool CursorVisibility);
void DisableSelection();
void gotoxy(short x,short y);
void NameAthur();
void KhungThemCauHoi();
void clean();
void cleanRow(int x,int y,int space);
void printRow(string &hoten,int &goicau);
void KhungBaoDiem();
void KhungXoaCauHoi();
void LoaiBo1CauSai(Tree t,int id);
void KhungNhapTen(string &hoten,int &goicau);
void khungBaoDiem(int goicau, double diem, Tree t);
void KhungCauHoiThi();
void KhungBatDauKhongDeLay();
void printRowKhongDeLay();
void KhungXemLaiDapAn(Tree t);
void ending();
void cleanKhungDapAn();
char* getdate();
