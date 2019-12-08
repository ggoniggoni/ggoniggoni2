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
	int c;//��� ������
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
	this->b = b;//������ �ʱ�ȭ


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
			if (p[i][j].state != 1)//1���������,0��������
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
			cout << "������ ���°�ڸ��� �����Ͻðڽ��ϱ�?" << endl;
			cin >> i >> j;
			cout << endl;
			if (p[i - 1][j - 1].state == 1) {
				p[i - 1][j - 1].start = clock();
				p[i - 1][j - 1].state = 0;
				cout << i << "��" << j << "�� °�� ���� �Ǿ����ϴ�." << endl;
				cout << endl;
			}
			else if (p[i - 1][j - 1].state == 0) {
				cout << "�̹� ������ �ڸ��Դϴ�" << endl;

			}
		}
		else if (q.empty() == 0) {
			q.pop();
			if (q.empty() == 0) {
				cout << "���� ���� ��� 1��  " << q.front() << endl;
				cout << "���� ������⿭" << q.size() << endl;
				cout << "������ ���°�ڸ��� �����Ͻðڽ��ϱ�? " << endl;
				cin >> i >> j;

				cout << endl;
			}
			else {
				cout << "���� ���� ��⿭�� �����ϴ�" << endl;
				cout << "������ ���°�ڸ��� �����Ͻðڽ��ϱ�?" << endl;
				cin >> i >> j;

				cout << endl;
			}
			if (p[i - 1][j - 1].state == 1)
			{
				p[i - 1][j - 1].start = clock();
				p[i - 1][j - 1].state = 0;
				cout << i << "��" << j << " �� °�� ���� �Ǿ����ϴ�." << endl;
				cout << endl;
			}
			else if (p[i - 1][j - 1].state == 0)
			{
				cout << "�̹� ������ �ڸ��Դϴ�." << endl;
			}
		}
	}
	else if (c == 0) {
		cout << "�� á���ϴ�. ������⸦ �Ͻðڳ���?" << "(Y or N)";
		cin >> w;
		if (w == 'Y') {

			cout << "������ȣ�� �Է��ϼ��� ";
			cin >> number;
			q.push(number);

			cout << "���� ���� ��� 1��" << q.front();
			cout << "���� ������⿭" << q.size();


		}
		else if (w == 'N') {
			cout << "�ȳ��� ������";
		}
		else {
			cout << "�߸� �Է��ϼ̽��ϴ�";
		}


	}
}

void Car::outcoming()
{
	int i, j;
	int money = 0;
	int end = clock();


	cout << "������ ���°�ڸ����� �����ðڽ��ϱ�?" << endl;
	cin >> i >> j;

	p[i - 1][j - 1].state = 1;
	money = (end - p[i - 1][j - 1].start) / (CLK_TCK * 0.01);
	cout << "��� : " << money << "�� �Դϴ�" << endl;
	cout << i << "��" << j << "�� ° �ڸ����� �������ϴ�." << endl;
	cout << endl;
	if (q.empty() == 0) {
		q.pop();
		p[i - 1][j - 1].state = 0;
		p[i - 1][j - 1].start = clock();
		if (q.empty() == 0) {
			cout << "���� ���� ��� 1��" << q.front() << endl;
			cout << "���� ������⿭" << q.size() << endl;

		}
	}


}



void Car::All()
{
	int i, j;
	clock_t end;



	for (i = 0; i < a; i++)
	{
		cout << i + 1 << "��:";
		for (j = 0; j < b; j++)
		{

			if (!p[i][j].state == 1)
			{
				printf("��");

			}
			else if (!p[i][j].state == 0)
			{
				printf("��");
			}
		}
		cout << endl;

	}
	cout << "��:������ ��:�� �ڸ�" << endl;
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++)
		{
			if (!p[i][j].state == 1)
			{
				end = clock();
				cout << i + 1 << "�� " << j + 1 << "��° " << ")" << " ������� �ð� " << " " << (double)(end - p[i][j].start) / CLK_TCK << endl;

			}
		}
	}
	if (q.empty() == 0) {
		cout << "���� ���� ��� 1��" << q.front() << endl;
		cout << "���� ������⿭" << q.size() << endl;
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
			car.All();//������Ȳ
			cout << "--����Ű�� ������ Ű�� ������ �޴��� ���ư��ϴ�--" << endl;
			cout << "--����Ű�� ������ ��������--" << endl;
			if (keyControl() == ENTER)
				break;

		}
		else if (menuCode == 2)
		{
			system("cls");
			car.incoming(); //�����ϱ�
			cout << "--����Ű�� ������ Ű�� ������ �޴��� ���ư��ϴ�--" << endl;
			cout << "--����Ű�� ������ ��������--" << endl;
			if (keyControl() == ENTER)
				break;


		}
		else if (menuCode == 3)
		{
			system("cls");
			car.outcoming(); //�����ϱ�
			cout << "--����Ű�� ������ Ű�� ������ �޴��� ���ư��ϴ�--" << endl;
			cout << "--����Ű�� ������ ��������--" << endl;
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
		temp = _getch(); //224�� ��ȯ�Ǹ� �ٽ��ѹ� ��ȯ���� ��´�
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
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);// �ܼ� �ڵ� ��������
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
int menuDraw() {
	int x = 20;
	int y = 12;
	gotoxy(x - 2, y);

	cout << "> ������Ȳ" << endl;

	gotoxy(x, y + 1);
	cout << "�����ϱ�" << endl;

	gotoxy(x, y + 2);
	cout << "�����ϱ� " << endl;


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
	cout << "                  �������� �ý���" << endl;
}