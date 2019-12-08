#include <iostream>
#include <ctime>
#include <queue>
#include <string>
using namespace std;
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
	park **p;
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


	p = new park*[a];
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
				cout << "���� ���� ��� 1��" << q.front() << endl;
				cout << "���� ������⿭" << q.size() << endl;
				cout << "������ ���°�ڸ��� �����Ͻðڽ��ϱ�?" << endl;
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
				cout << i << "��" << j << "�� °�� ���� �Ǿ����ϴ�." << endl;
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

			cout << "������ȣ�� �Է��ϼ���";
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


}



void Car::print()
{
	cout << "------------------" << endl;
	cout << "1�� : ������Ȳ" << endl;
	cout << "2�� : �����ϱ�" << endl;
	cout << "3�� : �����ϱ�" << endl;
	cout << "4�� : ��        ��" << endl;
	cout << "------------------" << endl;
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
				cout << i + 1 << "��" << j + 1 << "��°" << ")" << " ������� �ð�" << " " << (double)(end - p[i][j].start) / CLK_TCK << endl;

			}
		}
	}
}

int main()
{
	//int a, b;
	int n;
	Car car;

	car.make_park(2, 2);
	while (1)
	{
		car.print();
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "������ ����" << endl;
			car.All();
			cout << endl;
			break;
		case 2:

			car.incoming();
			cout << endl;
			break;
		case 3:

			car.outcoming();

			cout << endl;
			break;



		case 4:
			exit(0);
		default:
			break;
		}
	}

	return 0;

}