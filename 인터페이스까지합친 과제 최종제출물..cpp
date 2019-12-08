#include <iostream>
#include <ctime>
#include <queue>
#include <string>
#include <conio.h>
#include <Windows.h>
#define UP 1
#define DOWN 2
#define ENTER 3

using namespace std;
int keyControl();
int menuDraw();
void gotoxy(int, int);
void titleDraw();

queue<int> q;

struct park
{
	int state;
	clock_t start;
};

class Car
{
private:
	int Total = 0;
	park** p;
	int a;
	int b;
	int c;//멤버 변수로
public:

	void make_park(int a, int b);
	void print();

	void incoming();
	void outcoming();

	void All();

};


void Car::make_park(int a, int b)
{
	int i, j;

	this->a = a;
	this->b = b;//주차장 초기화


	p = new park *[a];
	for (i = 0; i < a; i++)
	{
		p[i] = new park[b];
	}
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++)
		{
			p[i][j].state = 1;
		}
	}
}



void Car::incoming()
{
	int i, j;
	char w;
	int n = 0;
	int esc = 0;
	int k = 0;
	int number;

	int c;

	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++) {
			if (p[i][j].state != 1)//1은비어있음,0은주차중
				c = 0;

			else if (p[i][j].state != 0) {
				c = 1;
				esc = 1;
				break;
			}
		}
		if (esc == 1)
			break;
	}
	if (c == 1) {
		if (q.empty() == 1)
		{
			cout << "몇층의 몇번째자리에 주차하시겠습니까?" << endl;
			cin >> i >> j;
			cout << endl;
			if (p[i - 1][j - 1].state == 1) {
				p[i - 1][j - 1].start = clock();
				p[i - 1][j - 1].state = 0;
				cout << i << "층" << j << "번 째에 주차 되었습니다." << endl;
				cout << endl;
			}
			else if (p[i - 1][j - 1].state == 0) {
				cout << "이미 주차된 자리입니다" << endl;

			}
		}
		else if (q.empty() == 0) {
			q.pop();
			if (q.empty() == 0) {
				cout << "현재 주차 대기 1번  " << q.front() << endl;
				cout << "현재 주차대기열" << q.size() << endl;
				cout << "몇층의 몇번째자리에 주차하시겠습니까? " << endl;
				cin >> i >> j;

				cout << endl;
			}
			else {
				cout << "현재 주차 대기열은 없습니다" << endl;
				cout << "몇층의 몇번째자리에 주차하시겠습니까?" << endl;
				cin >> i >> j;

				cout << endl;
			}
			if (p[i - 1][j - 1].state == 1)
			{
				p[i - 1][j - 1].start = clock();
				p[i - 1][j - 1].state = 0;
				cout << i << "층" << j << " 번 째에 주차 되었습니다." << endl;
				cout << endl;
			}
			else if (p[i - 1][j - 1].state == 0)
			{
				cout << "이미 주차된 자리입니다." << endl;
			}
		}
	}
	else if (c == 0) {
		cout << "꽉 찼습니다. 주차대기를 하시겠나요?" << "(Y or N)";
		cin >> w;
		if (w == 'Y') {

			cout << "차량번호를 입력하세요 ";
			cin >> number;
			q.push(number);

			cout << "현재 주차 대기 1번" << q.front();
			cout << "현재 주차대기열" << q.size();


		}
		else if (w == 'N') {
			cout << "안녕히 가세요";
		}
		else {
			cout << "잘못 입력하셨습니다";
		}


	}
}

void Car::outcoming()
{
	int i, j;
	int money = 0;
	int end = clock();


	cout << "몇층의 몇번째자리에서 나가시겠습니까?" << endl;
	cin >> i >> j;

	p[i - 1][j - 1].state = 1;
	money = (end - p[i - 1][j - 1].start) / (CLK_TCK * 0.01);
	cout << "요금 : " << money << "원 입니다" << endl;
	cout << i << "층" << j << "번 째 자리에서 나갔습니다." << endl;
	cout << endl;
	if (q.empty() == 0) {
		q.pop();
		p[i - 1][j - 1].state = 0;
		p[i - 1][j - 1].start = clock();
		if (q.empty() == 0) {
			cout << "현재 주차 대기 1번" << q.front() << endl;
			cout << "현재 주차대기열" << q.size() << endl;

		}
	}


}



void Car::All()
{
	int i, j;
	clock_t end;



	for (i = 0; i < a; i++)
	{
		cout << i + 1 << "층:";
		for (j = 0; j < b; j++)
		{

			if (!p[i][j].state == 1)
			{
				printf("■");

			}
			else if (!p[i][j].state == 0)
			{
				printf("□");
			}
		}
		cout << endl;

	}
	cout << "■:주차중 □:빈 자리" << endl;
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++)
		{
			if (!p[i][j].state == 1)
			{
				end = clock();
				cout << i + 1 << "층 " << j + 1 << "번째 " << ")" << " 사용중인 시간 " << " " << (double)(end - p[i][j].start) / CLK_TCK << endl;

			}
		}
	}
	if (q.empty() == 0) {
		cout << "현재 주차 대기 1번" << q.front() << endl;
		cout << "현재 주차대기열" << q.size() << endl;
	}
}


int main()
{
	int a, b;
	int n;
	Car car;

	car.make_park(2, 2);
	while (1)
	{
		titleDraw();
		int menuCode = menuDraw();
		if (menuCode == 1)
		{
			system("cls");
			car.All();//주차현황
			cout << "--엔터키를 제외한 키를 누르면 메뉴로 돌아갑니다--" << endl;
			cout << "--엔터키를 누르면 강제종료--" << endl;
			if (keyControl() == ENTER)
				break;

		}
		else if (menuCode == 2)
		{
			system("cls");
			car.incoming(); //주차하기
			cout << "--엔터키를 제외한 키를 누르면 메뉴로 돌아갑니다--" << endl;
			cout << "--엔터키를 누르면 강제종료--" << endl;
			if (keyControl() == ENTER)
				break;


		}
		else if (menuCode == 3)
		{
			system("cls");
			car.outcoming(); //출차하기
			cout << "--엔터키를 제외한 키를 누르면 메뉴로 돌아갑니다--" << endl;
			cout << "--엔터키를 누르면 강제종료--" << endl;
			if (keyControl() == ENTER)
				break;


		}
		system("cls");

	}

	return 0;

}
int keyControl() {
	int temp = _getch();
	if (temp == 224)
		temp = _getch(); //224가 반환되면 다시한번 반환값을 얻는다
	if (temp == 72)
		return UP;
	else if (temp == 80)
		return DOWN;
	else if (temp == 13)
		return ENTER;
	/*else if (temp == 's')
	return DOWN;
	else if (temp == 'd')
	return RIGHT;
	*/
}
void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);// 콘솔 핸들 가져오기
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
int menuDraw() {
	int x = 20;
	int y = 12;
	gotoxy(x - 2, y);

	cout << "> 주차현황" << endl;

	gotoxy(x, y + 1);
	cout << "주차하기" << endl;

	gotoxy(x, y + 2);
	cout << "출차하기 " << endl;


	while (1)
	{
		int num = keyControl();
		switch (num)
		{
		case UP: {
			if (y > 12)
			{
				gotoxy(x - 2, y);
				cout << (" ") << endl;;
				gotoxy(x - 2, --y);
				printf(">");

			}
			break;
		}

		case DOWN: {
			if (y < 14)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");

			}
			break;
		}
		case ENTER: {
			return y - 11;

		}
		}
	}
}
void titleDraw()
{
	cout << "\n" << endl;
	cout << "\n" << endl;
	cout << "\n" << endl;
	cout << "\n" << endl;
	cout << "                  무인주차 시스템" << endl;
}