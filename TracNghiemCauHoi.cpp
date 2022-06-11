#include "TracNghiemCauHoi.h"
#include <windows.h>
#define filech "cauhoi.txt"
#define CLR_FOCUS 207
#define CLR_NORML 15
#include<conio.h>
int autoID = 0, idDe = 0;
vector<string> afterRanDom;
int score, soluong = 0;
using namespace std;

void CreateList(List &l)
{
	l.Head = l.Tail = NULL;
}
int conver(string s)
{
	stringstream id(s);
	int x = 0;
	id >> x;
	return x;
}
void docTungCau(ifstream &file_in, CAUHOI &ch)
{
	string id;
	//	getline(file_in,ch.data.id);
	getline(file_in, id);
	ch.noidung.id = conver(id);
	getline(file_in, ch.noidung.cauHoi);
	getline(file_in, ch.noidung.cauA);
	getline(file_in, ch.noidung.cauB);
	getline(file_in, ch.noidung.cauC);
	getline(file_in, ch.noidung.cauD);
	getline(file_in, ch.dapAn);
}
node *createNode(CAUHOI x){
	node *p = new node;
	if (p == NULL)
		return NULL;
	p->data=x;
	p->next=NULL;
	return p;
}
void AddHead(List &l, node *node)
{
	if (l.Head == NULL)
	{
		l.Head = node;
		l.Tail = node;
	}
	else
	{
		node->next = l.Head;
		l.Head = node;
	}
}

void AddTail(List &l, node *node)
{
	if (l.Head == NULL)
	{
		l.Head = node;
		l.Tail = node;
	}
	else
	{
		l.Tail->next = node;
		l.Tail = node;
	}
}
void addfirst(List &l,node *new_ele)
{
	if(l.Head == NULL)
	{
		l.Head=l.Tail=new_ele;
	}
	else
	{
		l.Tail->next = new_ele;
		l.Tail = new_ele;
	}
}
void docDanhSach(ifstream &file_in, List &l)
{
	while (!file_in.eof())
	{
		CAUHOI dulieu;
		docTungCau(file_in, dulieu);
		soluong++;
		AddTail(l, createNode(dulieu));
	}
}
void incauhoi(CAUHOI ch){
	cout << ch.noidung.cauHoi<<"\n";
	cout << ch.noidung.cauA<<"\n";
	cout << ch.noidung.cauB<<"\n";
	cout << ch.noidung.cauC<<"\n";
	cout << ch.noidung.cauD<<"\n";
	cout << "Nhap dap an: \n";
	string dapan;
	cin >> dapan;
	cout << ch.dapAn<<"\n";
}
void printList(List l)
{
	node *p = l.Head;
	while (p != NULL)
	{
		incauhoi(p->data);
		p = p->next;
	}
}
void docDapAn(List l, Tree &t){
	node *p = l.Head;int autoid = 1; 
	t = NULL;
	DAPAN temp;
	while (p != NULL)
	{
		temp.id = autoid++;
		strcpy(temp.dan, p->data.dapAn.c_str());
		t = insert(t,temp);
		p = p->next;
	}
	while(!checkAvl(t)){
		t = updateTreeAvl(t);		
	}
}
void printDapAn(Tree t){
	if (t != NULL){
		if (t->left != NULL)
			printDapAn(t->left);
		cout <<"ID:"<<t->data.id<<" "<<endl;
		cout <<"Dap an:"<<t->data.dan<<" "<<endl; 
		//cout<<endl;
		if (t->right != NULL)
			printDapAn(t->right);
	}
}
string seachDapAn(Tree t, int x){
	if (t == NULL) return "";
	if (t->data.id == x) return t->data.dan;
	else if (t->data.id  < x) return seachDapAn(t->right, x);
	return seachDapAn(t->left, x);
}
//------------------------------------------------------------------
// ham random dap an
string DE[] = {"A","B","C","D"};
void generateRandomResponse(vector<string> randomResponse ) {
	int j = 0;gotoxy(0,0);printRowKhongDeLay();
	while(randomResponse.size() > 0)
	{
		srand (time(NULL));
    	int i = rand() % randomResponse.size() - 1 + 1; // random tu 0 den size() cua vector randomResponse luu 4 dap an
    	if(j == 0)
    		gotoxy(16,13);
    	if(j == 1)
    		gotoxy(71,13);
    	if(j == 2)
    		gotoxy(16,18);
    	if(j == 3)
    		gotoxy(71,18);
    	cout <<DE[j++] <<"."<< randomResponse[i];  // in lan luot dap an random
    	afterRanDom.push_back(randomResponse[i]); // luu thu tu dap an moi vao vector afterRanDom
    	randomResponse.erase(randomResponse.begin() + i);  // xoa dap an da in ra khoi vector randomResponse de tiep tuc in
	}
}
void themDapAn(NOIDUNGCH ch){
	vector<string> randomResponse;
	randomResponse.push_back(ch.cauA);
	randomResponse.push_back(ch.cauB);
	randomResponse.push_back(ch.cauC);
	randomResponse.push_back(ch.cauD);
	generateRandomResponse(randomResponse);
}
void nhapDapAn (Tree t,int &ans, int id)
{		
		int solantg = 0;
		again:
		gotoxy(54,24);
    	char rep; 
		fflush(stdin);
		cin >> rep;
    	while(rep != 'A' && rep != 'a' && rep != 'B' && rep != 'b' && rep != 'C' &&rep != 'c' &&rep != 'D' &&rep != 'd' &&rep!= 'q')
    	{	
    		gotoxy(50,22);
    		cout <<"Vui long nhap dung! ";
    		gotoxy(52, 24); cout <<"                          ";
    		gotoxy(54,24);
    		cin >> rep;
		}
    	switch(rep){
    		case 'A':
				ans = 0; 
				break;
			case 'a':
				ans = 0; 
				break;
			case 'B':
				ans = 1; 
				break;
			case 'b':
				ans = 1; 
				break;
			case 'C':
				ans = 2; 
				break;
			case 'c':
				ans = 2; 
				break;
			case 'D':
				ans = 3; 
				break;
			case 'd':
				ans = 3; 
				break;
			case 'q':
				if(solantg == 0)
				{
					LoaiBo1CauSai(t, id);
					gotoxy(52, 24); cout <<"                          ";
					solantg++;	
				}
				else 
				{
					gotoxy(50,22);
					cout <<" Da su dung roi         ";
					gotoxy(52, 24); cout <<"                          ";
				} 
				goto again;
				break; 
			}
} 
bool kiemTraDungD(Tree t, int ans, int id){
	return  afterRanDom[ans] == seachDapAn(t,id) ? true : false;
}
void setScore(int &score){
	score = 0;
}
vector<NOIDUNGCH> CauHoiDung; // luu cau hoi tra loi dung
vector<NOIDUNGCH> CauHoiSai;  // luu cau hoi tra loi sai
// ham nay cach thuc hoat dong tuong tu random cau hoi
void randomCauHoi(vector<NOIDUNGCH> CauHoi, Tree t){
	CauHoiDung.erase(CauHoiDung.begin(),CauHoiDung.end()); // xoa bo tat ca cac cau hoi thi lan truoc 
	CauHoiSai.erase(CauHoiSai.begin(),CauHoiSai.end());
	int j = 1, ans;
	while(CauHoi.size() > 0)
	{
		bool check = false;
		int index = 0;
		srand (time(NULL));
    	int i = rand() % CauHoi.size() - 1 + 1;
    	gotoxy(17,7);
    	cout << j++ <<".";
    	// in cho dep
    	if(CauHoi[i].cauHoi.length() > 70)
    	{
    		gotoxy(20,7);
    		while(!check)
    		{
    			cout <<CauHoi[i].cauHoi[index];
    			index ++;
    			if(index > 60 && CauHoi[i].cauHoi[index] == ' ')
    				check = true;
			}
			gotoxy(20,8);
			for(int k = index + 1; index < CauHoi[i].cauHoi.length(); index++)
    		{
    			cout << CauHoi[i].cauHoi[index];
    				
			}
		}
    	else
    	{
    		gotoxy(20,7);
    		cout << CauHoi[i].cauHoi;
		}
			
    	themDapAn(CauHoi[i]);
    	nhapDapAn(t,ans,CauHoi[i].id);
    	if(kiemTraDungD(t,ans,CauHoi[i].id))
    	{
    		score++;
    		CauHoiDung.push_back(CauHoi[i]);
    	}
    	else
    		CauHoiSai.push_back(CauHoi[i]);
    		
    	system("cls");
    	KhungCauHoiThi();
    	afterRanDom.erase(afterRanDom.begin(), afterRanDom.end() );
    	CauHoi.erase(CauHoi.begin() + i);  
	}
}

void lapCauHoi(List l, Tree t, int goiCau, string hoten, int socaude){
	
	vector<NOIDUNGCH> CauHoi;
	int caukho, caude;
	node *p = l.Head;int ans;
	setScore(score);
	tinhSoCauKhoDe(goiCau,caude,caukho);
	
	srand((int)time(0));
	int r = 1 + rand() % ((socaude - caude) + 1 - 1); // rd cau hoi tu 1 den so cau de - so cau de duoc chon
	for(int i = 1; i <= r; i++) // dieu chinh con tro p den vi tri id cau de da ran dom
	{
		p = p->next;
	}
	
	for(int i = 1; i <= caude; i++) // dua cac cau hoi duoc chon vao vector CauHoi tien hanh random roi thi
	{
		CauHoi.push_back(p->data.noidung);
		p = p->next;
	} 
	srand((int)time(0)); 
	// rd tu vi so cau de + 1 den soluong cac cau hoi - so luong cau kho duoc chon
	int r2 = (socaude + 1) + rand() % ((soluong - caukho - 1) + 1 - (socaude + 1)); 	

	for(int i = r + caude; i <= r2; i++) // dieu chinh con tro p den vi tri id
	{
		p = p->next;
	}
	
	for(int i = 1; i <= caukho; i++)
	{
		CauHoi.push_back(p->data.noidung);
		p = p->next;
	} 
	randomCauHoi(CauHoi, t); // tien hanh thuat toan rd cau hoi
	gotoxy(54,24);
	system("cls");
	double diem = tinhDiem(score,goiCau);
	khungBaoDiem(goiCau, diem,t);
	lichSuThiGanNhat(diem,hoten,goiCau);
	Sleep(500);
}
//--------------------------------------------------------------------
void themCauHoi(List &l, int &socaude)
{	
	ShowCur(true);
	KhungThemCauHoi();
	CAUHOI x; int mucdo;
	gotoxy(55,13);
	cout <<"Ban muon nhap cau hoi kho hay de: ";
	gotoxy(55,14);
	cout <<"[1]. De";
	gotoxy(55,15);
	cout <<"[khac]. Kho";
	gotoxy(55,17);
	cout <<" Nhap lua chon: ";
	cin >> mucdo;
	cleanRow(55,17,25);gotoxy(55,17);
	cout <<"Nhap cau hoi: ";
	fflush(stdin);
	getline( cin,x.noidung.cauHoi);
	cleanRow(55,17,25);gotoxy(55,17);
	cout <<"Dap an A: ";
	fflush(stdin);
	getline(cin,x.noidung.cauA);
	fflush(stdin);
	cleanRow(55,17,25);gotoxy(55,17);
	cout <<"Dap an B: ";
	getline(cin,x.noidung.cauB);
	fflush(stdin);
	cleanRow(55,17,25);gotoxy(55,17);
	cout <<"Dap an C: ";
	fflush(stdin);
	getline(cin,x.noidung.cauC);
	cleanRow(55,17,25);gotoxy(55,17);
	cout <<"Dap an D: ";
	fflush(stdin);
	getline(cin,x.noidung.cauD);
	cleanRow(55,17,25);gotoxy(55,17);
	cout <<"Dap an dung: ";
	fflush(stdin);
	getline(cin,x.dapAn);
	if(mucdo == 1)
	{
		x.noidung.id = idDe--;
		socaude++;
		AddHead(l,createNode(x));
	}
	else
	{
		x.noidung.id = ++soluong;
		AddTail(l,createNode(x));
	}
}
void deleteNode(List &l , int key)
{
	node *temp = l.Head;
	node *prev = NULL;
	// neu la node dau 
	// xoa node va doi dau
	if (temp != NULL && temp->data.noidung.id == key)
    {
        l.Head = temp->next; 
        delete temp;           
        return;
    }
 
    // neu khong phai node dau 
    else
    {
    	//tim vi tri node do
    while (temp != NULL && temp->data.noidung.id != key)
    {
        prev = temp;
        temp = temp->next;
    }  
    // dung tai vi tri node can xoa
	if (temp == NULL)
        return;
	
	// con khong thi xoa node va cap nhat cap nhat 	
    prev->next = temp->next;
    delete temp;
    }
}
void RemoveList (List &l)
{	
	node *p;
	while (l.Head != NULL) 
	{
		p = l.Head;
		l.Head = p->next;
	   delete p;
	}
	l.Tail = NULL;
}
void xoaCauHoi(List &l)
{
	ShowCur(true);
	KhungXoaCauHoi();
	int mucdo, id,co;
	gotoxy(55,13);
	cout <<"Ban muon xoa cau hoi kho hay de: ";
	gotoxy(55,14);
	cout <<"[1]. De";
	gotoxy(55,15);
	cout <<"[khac]. Kho\n";
	gotoxy(55,17);
	cout <<"Nhap lua chon: ";
	cin >> mucdo;
	cleanRow(55,17,25);gotoxy(55,17);
	cout <<"Nhap id can xoa: ";
	cin >> id;
	cleanRow(55,13,40);gotoxy(55,13);
	cout <<"Ban co thuc su muon xoa: ";
	gotoxy(55,14);
	cout <<"[1]. Co";
	gotoxy(55,15);
	cout <<"[khac]. Khong\n";
	cleanRow(55,17,40);
	gotoxy(55,16);
	cout <<"Nhap lua chon: ";
	cin >> co;
	if (co==1){
		gotoxy(55,17);
		deleteNode(l ,id);
		cout <<"Xoa thanh cong. ";
		}
	else
	return;
	
}
void LuuTungCau(ofstream &fileout,CAUHOI dulieu) //ghi du lieu theo thu tu tung dong
{
	fileout<< ++autoID<<endl;
	fileout<<dulieu.noidung.cauHoi<<endl;
	fileout<<dulieu.noidung.cauA<<endl;
	fileout<<dulieu.noidung.cauB<<endl;
	fileout<<dulieu.noidung.cauC<<endl;
	fileout<<dulieu.noidung.cauD<<endl;
	fileout<<dulieu.dapAn<<endl;
}
void LuuTungCauCuoi(ofstream &fileout,CAUHOI dulieu) //ghi du lieu theo thu tu tung dong
{
	fileout<< ++autoID<<endl;
	fileout<<dulieu.noidung.cauHoi<<endl;
	fileout<<dulieu.noidung.cauA<<endl;
	fileout<<dulieu.noidung.cauB<<endl;
	fileout<<dulieu.noidung.cauC<<endl;
	fileout<<dulieu.noidung.cauD<<endl;
	fileout<<dulieu.dapAn;
}
void setAutoID(int &n)
{
	n = 0;
}
int  LuuDanhSach(List l, int socaude)
{
	setAutoID(autoID);
	ofstream fileout, fileout2;
	fileout.open("cauhoi.txt",ios::out);
	fileout2.open("cauhoikho.txt",ios::out);
	if (!fileout)
		return 0;
	node *p = l.Head;
	for(int i = 1; i < socaude ; i ++)
	{
		LuuTungCau(fileout,p->data);
		p = p->next;
		if(i == socaude - 1)
			LuuTungCauCuoi(fileout,p->data);
	}
	p = p->next;
	while( p != l.Tail)
	{
		LuuTungCau(fileout2,p->data);
		p = p->next;
		if(p == l.Tail)
		{
			LuuTungCauCuoi(fileout2,p->data);
		}
	}
	fileout.close();fileout2.close();
	return 1;
}
void luuLichSuThi(FILE *f,float diem,string hoten,int goicau){
	fputs(hoten.c_str(),f);
	fflush(stdin);
	fprintf(f,"\n");
	fflush(stdin);
	fprintf(f,"%.2f\n",diem);
	fflush(stdin);
	fprintf(f,"%d\n",goicau);
	fflush(stdin);
	fputs(getdate(),f);
} 
int  lichSuThiGanNhat(float diem,string hoten,int goicau)
{
	FILE *f =fopen("lichsuthi.txt","a+");
	if (f == NULL)
		return 0;
	luuLichSuThi(f,diem,hoten,goicau);
	fclose(f);
	return 1;
}
double tinhDiem(int score, int goicau){
	return score*1.0/goicau*10;
}
void tinhSoCauKhoDe(int goicau,int &caude, int &caukho){
	if (goicau==10){
		caude=7;
		caukho=3;
	}else if (goicau==20){
		caude=15;
		caukho=5;
	}else if (goicau==30){
		caude=23;
		caukho=7;
	}
}
//------------------DoHoa-------------------------------
ColorMenu::ColorMenu(string* options2, int len2, int colorFocus2, int colorNormal2) {
	colorFocus = colorFocus2;
	colorNormal = colorNormal2;
	len = len2;

	options = new string[len];
	for (int i = 0; i < len; i++) {
		options[i] = options2[i];
		//cout << options[i] << endl;
	}
}

ColorMenu::~ColorMenu() {
	system("cls");
	ending();
	_getch();
}

int ColorMenu::getMenuLength() {
	return len;
}

void ColorMenu::printMenu(int focus) {

	//system("cls");
	int k;
	gotoxy(9,2);
	cout << "TRAC NGHIEM TIENG ANH";
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl;
	for (int i = 0; i < len; i++) {
		if (i == focus) {
			// set highlight color
			SetConsoleTextAttribute(hConsole, colorFocus);
		} else {
			// reset color
			SetConsoleTextAttribute(hConsole, colorNormal);
		}
		if(i == 0)
			gotoxy(9, 5 + i);
		if(i == 1)
			gotoxy(9, 5 + i);
		if(i == 2)
			gotoxy(9, 5 + i);
		if(i == 3)
			gotoxy(9, 5 + i);
		if(i == 4)
			gotoxy(9, 5 + i);
		cout << "  " << i+1 << ". " << options[i] << endl;
	}
	NameAthur();
	// reset color
	SetConsoleTextAttribute(hConsole, colorNormal);
	cout << endl;
	//cout << "focus=" << focus << "; len=" << len << endl;
}

int ColorMenu::handleMenu() {

	int focus = 0;
	printMenu(focus);

	do {
		// Cac phim UP, DOWN, LEFT, RIGHT
		// nhan vao gia tri kep
		// la int 224 va char.
		// Do do ta phai co 2 lan
		// xu ly o day
		int ch = getch();
		if (ch == 0 || ch == 224) {
			char c = getch();
			switch(c) {
				// UP
				case 72:
					if (focus == 0) {
						focus = len - 1;
					} else {
						focus--;
					}
					break;
				// DOWN
				case 80:
					if (focus == len - 1) {
						focus = 0;
					} else {
						focus++;
					}
					break;
			}
		} else if (ch == 13){
			// ENTER
			return focus;
		}

		printMenu(focus);
	} while (true);

}

void setcolor(short x) { //Ham thay doi textcolor va backgroundcolor
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, x);
}

void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;
    
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = CursorVisibility;
    
    SetConsoleCursorInfo(handle, &ConCurInf);
}
void DisableSelection()
{
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

    SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
}
void gotoxy(short x,short y) { //Ham di chuyen con tro den vi tri nao do trong Console
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {x, y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void NameAthur()
{
	gotoxy(5,14);SetColor(3,0);
	cout <<"            DHTH16H           ";
	gotoxy(10,17);SetColor(0,3);
	cout <<"@AUTHOR";
	gotoxy(10,19);SetColor(0,4);
	cout <<"VO TAN DAT";
	gotoxy(10,20);SetColor(0,2);
	cout <<"LE THANH NGHIA";
	gotoxy(10,21);SetColor(0,6);
	cout <<"VO THI MINH TIEN";
	gotoxy(10,22);SetColor(0,5);
	cout <<"NGUYEN TUAN HIEP";
}
void clean()
{
	for(int i = 41; i < 118; i++)
		for(int j = 2; j < 26; j++  )
		{
			gotoxy(i,j);setcolor(3);
			cout <<" ";
		}			
}
void KhungThemCauHoi()
{	
	gotoxy(52,9);
	cout <<" ____________________________________________________" << endl;
	gotoxy(52,10);
	cout <<"|                                                    |"<< endl;
	gotoxy(52,11);
	cout <<"|                   THEM CAU HOI                     |"<< endl;
	gotoxy(52,12);
	cout <<"|                                                    |"<< endl;
	gotoxy(52,13);
	cout <<"|                                                    |"<< endl;
	gotoxy(52,14);
	cout <<"|                                                    |"<< endl;
	gotoxy(52,15);
	cout <<"|                                                    |"<< endl;
	gotoxy(52,16);
	cout <<"|                                                    |"<< endl;
	gotoxy(52,17);
	cout <<"|                                                    |"<< endl;
	gotoxy(52,18);
	cout <<"|____________________________________________________|"<< endl;
	
	
}
void KhungXoaCauHoi()
{	
	gotoxy(52,9);
	cout <<" ____________________________________________________" << endl;
	gotoxy(52,10);
	cout <<"|                                                    |"<< endl;
	gotoxy(52,11);
	cout <<"|                   XOA CAU HOI                      |"<< endl;
	gotoxy(52,12);
	cout <<"|                                                    |"<< endl;
	gotoxy(52,13);
	cout <<"|                                                    |"<< endl;
	gotoxy(52,14);
	cout <<"|                                                    |"<< endl;
	gotoxy(52,15);
	cout <<"|                                                    |"<< endl;
	gotoxy(52,16);
	cout <<"|                                                    |"<< endl;
	gotoxy(52,17);
	cout <<"|                                                    |"<< endl;
	gotoxy(52,18);
	cout <<"|____________________________________________________|"<< endl;
	
	
}
void cleanRow(int x,int y,int space){
	gotoxy(x,y);
	for(int i = 0; i < space; i++)
		cout << " ";
}
void printRow(){ 
	
	for(int i = 0; i < 119; i++)
	{
		Sleep(1);setcolor(9);
		printf("%c",219);
	}
	for(int i = 0 ; i < 27; i++)
	{
		Sleep(1);
		gotoxy(0,i);setcolor(9);
		printf("%c",219);
		gotoxy(1,i);setcolor(9);
		printf("%c",219);
		
		gotoxy(119,i);setcolor(9);
		printf("%c",219);
		gotoxy(118,i);setcolor(9);
		printf("%c",219);
	}
	for(int i = 0; i < 61; i++)
	{
		Sleep(1);gotoxy(i, 27);
		printf("%c",219);
		gotoxy(120 - i,27);
		printf("%c",219);
	} 
	gotoxy(58,11);
	cout <<"Loangding...";
	for(int i = 0; i < 40; i++)
	{
		Sleep(1);
		gotoxy(40 + i,13);setcolor(9);
		printf("%c",219);
	}
	gotoxy(58,11);
	cout <<"              ";
	for(int i = 0; i < 40; i++)
	{
		Sleep(1);
		gotoxy(40 + i,13);setcolor(0);
		printf("%c",219);
	}
}
void KhungCauHoiThi()
{	
	// khung cau hoi 
	setcolor(15);
	for(int i = 1; i < 95; i++)
	{
		gotoxy(12 + i,5);
		cout << char(205);
		gotoxy(12 + i, 9);
		cout << char(205);
	}
	for(int i = 1; i < 4; i++)
	{
		gotoxy(12 ,5 + i);
		cout << char(186);
		gotoxy(12 + 95,5 + i);
		cout << char(186);
	}
	gotoxy(12, 9); cout << char(200);
	gotoxy(12 + 95, 9); cout << char(188);
	gotoxy(12 + 95, 5); cout << char(187);
	gotoxy(12,5); cout << char(201);
	// khung cau a 
	for(int i = 1; i < 40; i++)
	{
		gotoxy(12 + i, 12);
		cout << char(205);
		gotoxy(12 + i, 14);
		cout << char(205);
	}
	for(int i = 1; i < 2; i++)
	{
		gotoxy(12 ,12 + i);
		cout << char(186);
		gotoxy(12 + 40,12 + i);
		cout << char(186);
	}
	gotoxy(12, 14); cout << char(200); // duoi trai
	gotoxy(12 + 40, 14); cout << char(188);// duoi phai
	gotoxy(12 + 40, 12); cout << char(187);
	gotoxy(12,12); cout << char(201);
	// khung cau b
	for(int i = 1; i < 40; i++)
	{
		gotoxy(67 + i, 12);
		cout << char(205);
		gotoxy(67 + i, 14);
		cout << char(205);
	}
	for(int i = 1; i < 2; i++)
	{
		gotoxy(67 ,12 + i);
		cout << char(186);
		gotoxy(67 + 40,12 + i);
		cout << char(186);
	}
	gotoxy(67, 14); cout << char(200); // duoi trai
	gotoxy(67 + 40, 14); cout << char(188);// duoi phai
	gotoxy(67 + 40, 12); cout << char(187);
	gotoxy(67,12); cout << char(201);
	// khung cau c
	for(int i = 1; i < 40; i++)
	{
		gotoxy(12 + i, 17);
		cout << char(205);
		gotoxy(12 + i, 19);
		cout << char(205);
	}
	for(int i = 1; i < 2; i++)
	{
		gotoxy(12 ,17 + i);
		cout << char(186);
		gotoxy(12 + 40,17 + i);
		cout << char(186);
	}
	gotoxy(12, 19); cout << char(200); // duoi trai
	gotoxy(12 + 40, 19); cout << char(188);// duoi phai
	gotoxy(12 + 40, 17); cout << char(187);
	gotoxy(12,17); cout << char(201);
	// cau d
	for(int i = 1; i < 40; i++)
	{
		gotoxy(67 + i, 17);
		cout << char(205);
		gotoxy(67 + i, 19);
		cout << char(205);
	}
	for(int i = 1; i < 2; i++)
	{
		gotoxy(67 ,17 + i);
		cout << char(186);
		gotoxy(67 + 40,17 + i);
		cout << char(186);
	}
	gotoxy(67, 19); cout << char(200); // duoi trai
	gotoxy(67 + 40, 19); cout << char(188);// duoi phai
	gotoxy(67 + 40, 17); cout << char(187);
	gotoxy(67,17); cout << char(201);
	for(int i = 0; i < 40; i++)
	{
		gotoxy(40 + i, 25);
		cout << char(205);
	}
		gotoxy(40, 24);
		cout <<"Nhap dap an: ";
		gotoxy(54, 24);ShowCur(true);
}
void KhungBatDauKhongDeLay()
{
	for(int i = 0; i < 119; i++)
	{
		printf("%c",219);
	}
	for(int i = 0 ; i < 27; i++)
	{
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
		gotoxy(i, 27);
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
}
void printRowKhongDeLay()
{
	for(int i = 0; i < 119; i++)
	{
		setcolor(9);
		printf("%c",219);
	}
	for(int i = 0 ; i < 27; i++)
	{
		gotoxy(0,i);setcolor(9);
		printf("%c",219);
		gotoxy(1,i);setcolor(9);
		printf("%c",219);
		
		gotoxy(119,i);setcolor(9);
		printf("%c",219);
		gotoxy(118,i);setcolor(9);
		printf("%c",219);
	}
	for(int i = 0; i < 61; i++)
	{
		gotoxy(i, 27);
		printf("%c",219);
		gotoxy(120 - i,27);
		printf("%c",219);
	}
}
void LoaiBo1CauSai(Tree t,int id)
{	 
	bool check = false; // kiem tra da su dung tro giup lan nao nao hay chua
	while(!check)
	{
		srand(time(NULL));
		int r = 0 + rand() % 4 ; // random tu 0 -> 3
		switch(r)
		{
			case 0: 
			if(!kiemTraDungD(t,0,id))
			{	
				gotoxy(16, 13);
				cout <<"                                   ";
				check = true;
				
			}
			break;
			case 1: 
			if(!kiemTraDungD(t,1,id))	
			{
				gotoxy(71, 13);
				cout <<"                                   ";
				check = true;
			}
			break;
			case 2:
			if(!kiemTraDungD(t,2,id))	
			{
				gotoxy(16, 18);
				cout <<"                                  ";
				check = true;
			}
			break;
			case 3:
			if(!kiemTraDungD(t,3,id))	
			{
 				gotoxy(71, 13);
				cout <<"                                  ";
				check = true;
			}
			break;		
		}
	}
}
void KhungNhapTen(string &hoten,int &goicau)
{	
	gotoxy(36,9);
	cout <<" ____________________________________________________" << endl;
	gotoxy(36,10);
	cout <<"|                                                    |"<< endl;
	gotoxy(36,11);
	cout <<"|                 Nhap ten cua ban:                  |"<< endl;
	gotoxy(36,12);
	cout <<"|                                                    |"<< endl;
	gotoxy(36,13);
	cout <<"|                                                    |"<< endl;
	gotoxy(36,14);
	cout <<"|____________________________________________________|"<< endl;
	gotoxy(53,12);
	fflush(stdin);
	gotoxy(55,13);
	getline(cin,hoten);
	gotoxy(53,13); cout <<"                                   ";
	fflush(stdin);
	gotoxy(36,11);
	cout <<"|             Nhap goi cau hoi (10,20,30)            |"<< endl;
	gotoxy(60,13);
	goicau = 0;
	while (goicau != 10 && goicau != 20 && goicau !=30){
		gotoxy(60,13);cout <<"           ";
		gotoxy(60,13);
		cin>>goicau;
	}	
	system("cls");
}
void khungBaoDiem(int goicau, double diem, Tree t)
{
	ShowCur(true);
	setcolor(15);
	for(int i = 1; i < 60; i++)
	{
		gotoxy(27 + i,5);
		cout << char(205);
		gotoxy(27 + i, 9+8);
		cout << char(205);
	}
	for(int i = 1; i < 12; i++)
	{
		gotoxy(27 ,5 + i);
		cout << char(186);
		gotoxy(12 + 75,5 + i);
		cout << char(186);
	}
	int a;
	gotoxy(37 , 8);
	cout <<"Diem cua ban la: " << diem;
	gotoxy(37 , 9);
	cout <<"Goi cau: " << goicau;
	gotoxy(37 , 10);
	cout <<"So cau dung sai: " << score <<"/"<<goicau;	
	gotoxy(37 , 11);
	cout <<"Ban co muon xem lai sai: ";	
	gotoxy(37 , 12);
	cout <<"[1]. Co";
	gotoxy(37 , 13);
	cout <<"[2]. Khong\n";
	gotoxy(37 , 14);
	cout <<"Nhap lua chon: ";
	cin >> a;
	if(a == 1)
	{
		KhungXemLaiDapAn(t);
	}
	
}
void KhungXemLaiDapAnDH()
{
	system("cls");
	ShowCur(false);
	system("cls");
	setcolor(15);
	for(int i = 1; i < 95; i++)
	{
		gotoxy(12 + i,5);
		cout << char(205);
		gotoxy(12 + i, 9);
		cout << char(205);
	}
	for(int i = 1; i < 4; i++)
	{
		gotoxy(12 ,5 + i);
		cout << char(186);
		gotoxy(12 + 95,5 + i);
		cout << char(186);
	}
	gotoxy(12, 9); cout << char(200);
	gotoxy(12 + 95, 9); cout << char(188);
	gotoxy(12 + 95, 5); cout << char(187);
	gotoxy(12,5); cout << char(201);
	
	setcolor(15);
	for(int i = 1; i < 95; i++)
	{
		gotoxy(12 + i,15);
		cout << char(205);
		gotoxy(12 + i, 17);
		cout << char(205);
	}
	for(int i = 1; i < 2; i++)
	{
		gotoxy(12 ,15 + i);
		cout << char(186);
		gotoxy(12 + 95,15 + i);
		cout << char(186);
	}
	gotoxy(12, 17); cout << char(200);
	gotoxy(12 + 95, 17); cout << char(188);
	gotoxy(12 + 95, 15); cout << char(187);
	gotoxy(12,15); cout << char(201);
	gotoxy(37,16); cout <<"Answer: ";
}
/*void cleanKhungDapAn()
{
	gotoxy(20,7);     
	cout <<"                                                          ";
	gotoxy(17,7);
	cout <<"                                                          ";
}*/
void KhungXemLaiDapAn(Tree t)
{
	ShowCur(false);
	system("cls");
	setcolor(15);
	for(int i = 1; i < 95; i++)
	{
		gotoxy(12 + i,5);
		cout << char(205);
		gotoxy(12 + i, 9);
		cout << char(205);
	}
	for(int i = 1; i < 4; i++)
	{
		gotoxy(12 ,5 + i);
		cout << char(186);
		gotoxy(12 + 95,5 + i);
		cout << char(186);
	}
	gotoxy(12, 9); cout << char(200);
	gotoxy(12 + 95, 9); cout << char(188);
	gotoxy(12 + 95, 5); cout << char(187);
	gotoxy(12,5); cout << char(201);
	
	setcolor(15);
	for(int i = 1; i < 95; i++)
	{
		gotoxy(12 + i,15);
		cout << char(205);
		gotoxy(12 + i, 17);
		cout << char(205);
	}
	for(int i = 1; i < 2; i++)
	{
		gotoxy(12 ,15 + i);
		cout << char(186);
		gotoxy(12 + 95,15 + i);
		cout << char(186);
	}
	gotoxy(12, 17); cout << char(200);
	gotoxy(12 + 95, 17); cout << char(188);
	gotoxy(12 + 95, 15); cout << char(187);
	gotoxy(12,15); cout << char(201);
	gotoxy(37,16); cout <<"Answer: ";
	
	gotoxy(30,3); cout <<"                     CAC CAU DUNG";
	int i = 0;
	for(int j = 0; j < CauHoiDung.size(); j++)
	{
		KhungXemLaiDapAnDH();
		gotoxy(17,7);
    	cout << ++i <<".";
    	gotoxy(20,7);
    	if(CauHoiDung[j].cauHoi.length() > 70)
    	{
    		for(int k = 0 ; k < 70; k++ )
    			cout <<CauHoiDung[j].cauHoi[k];
    		cout <<" ...";
		}
		else 
			cout << CauHoiDung[j].cauHoi;
		gotoxy(45,16);
		gotoxy(45,16);
		cout << seachDapAn(t,CauHoiDung[j].id);
		_getch();
		//Sleep(1000);
	}
	gotoxy(30,3); cout <<"                     CAC CAU SAI      ";
	for(int j = 0; j < CauHoiSai.size(); j++)
	{
		KhungXemLaiDapAnDH();
		gotoxy(17,7);
    	cout << ++i <<".";
    	gotoxy(20,7);
		if(CauHoiSai[j].cauHoi.length() > 70)
    	{
    		for(int k = 0 ; k < 70; k++ )
    			cout <<CauHoiSai[j].cauHoi[k];
    		cout <<" ...";
		}
		else 
			cout << CauHoiSai[j].cauHoi;
		gotoxy(45,16);
		cout << seachDapAn(t,CauHoiSai[j].id);
		_getch();
		//Sleep(1000);
	}
	
}
void ending(){
	ifstream file_ending;
	file_ending.open("tpwc.txt",ios::in);
	string line; int i = 0;
	while(!file_ending.eof())	
	{
		getline(file_ending,line);
		gotoxy(25, 10 + i);setcolor(2);
		i++;
		cout <<line<<endl;
	}
	file_ending.close();
}
char* getdate() {
   // th?i gian hi?n t?i tính theo h? th?ng
   time_t now = time(0);
   
   // convert sang string
   char* dt = ctime(&now);
	return dt;
}
void CleanLS()
{
	gotoxy(49,11);
	cout <<"|   Ten nguoi thi:                                   |"<< endl;
	gotoxy(49,12);
	cout <<"|   Diem         :                                   |"<< endl;
	gotoxy(49,13);
	cout <<"|   Goi cau      :                                   |"<< endl;
	gotoxy(49,14);
	cout <<"|   Ngay gio thi :                                   |"<< endl;
}
void DocMotLichSu(ifstream &f )
{
	CleanLS();
	string line;
	getline(f,line);
	gotoxy(68,11); cout << line;
	getline(f,line);
	gotoxy(68,12); cout << line;
	getline(f,line);
	gotoxy(68,13); cout << line;
	getline(f,line);
	gotoxy(68,14); cout << line;
	_getch();
}
void KhungLichSu(ifstream &file_lichsu){
	gotoxy(49,9);
	cout <<"______________________________________________________" << endl;
	gotoxy(49,10);
	cout <<"|                    LICH SU THI                     |"<< endl;
	gotoxy(49,11);
	cout <<"|   Ten nguoi thi:                                   |"<< endl;
	gotoxy(49,12);
	cout <<"|   Diem         :                                   |"<< endl;
	gotoxy(49,13);
	cout <<"|   Goi cau      :                                   |"<< endl;
	gotoxy(49,14);
	cout <<"|   Ngay gio thi :                                   |"<< endl;
	gotoxy(49,15);
	cout <<"|____________________________________________________|"<< endl;
	while (!file_lichsu.eof()){
		DocMotLichSu(file_lichsu);
	}
	clean();			
}
