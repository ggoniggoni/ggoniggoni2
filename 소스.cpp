#include <iostream>
#include <ctime>
#include <queue>
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
	int getTotal();
	void make_park(int a, int b);
	void print();
	void parkstate();
	void empty();
	void incoming();
	void outcoming();
	void sum();
	void waiting();
	void All();
	void remove();
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
void Car::parkstate()
{
	int i, j;
	int count = 0;
	clock_t end;
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++)
		{
			if (!p[i][j].state == 0)
			{
				cout << i + 1 << "��" << j + 1 << "��°" << ") " << " �������" << endl;
			}
			else
			{
				end = clock();
				cout << i + 1 << "��" << j + 1 << "��°" << ")" << " �����" << " " << (double)(end - p[i][j].start) / CLK_TCK << endl;
				count++;
			}
		}
	}
	cout << "����ִ� �ڸ��� �� " << (a*b) - count << " �Դϴ�." << endl;
	cout << endl;
}

void Car::empty()
{
	int i, j;
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++)
		{
			if (!p[i][j].state == 0)
			{
				cout << "�����ڸ���" << i + 1 << "��" << j + 1 << "��° ���Դϴ�." << endl;
			}
		}
		cout << endl;
	}
}


void Car::incoming()
{
	int i, j;
	
	int c;
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++) {
			if (p[i][j].state != 1)
				c = 0;
			else c = 1;
		}
	}
	if (c == 1) {
		
		cout << "������ ���°�ڸ��� �����Ͻðڽ��ϱ�?" << endl;
		cin >> i >> j;

		cout << endl;
		p[i - 1][j - 1].start = clock();
		p[i - 1][j - 1].state = 0;
		cout << i << "��" << j << "�� °�� ���� �Ǿ����ϴ�." << endl;
		cout << endl;
	}
	else {
		cout << "�� á���ϴ�. ������⸦ ���ּ���";
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

	Total += money;
}

void Car::sum()
{

	cout << "������� �� �ݾ���" << Total << "�� �Դϴ�" << endl;
}

int Car::getTotal()
{
	return Total;
}

void Car::print()
{
	cout << "------------------" << endl;
	cout << "1�� : �������� �ڸ�����" << endl;
	cout << "2�� : �������� �ڸ�����" << endl;
	cout << "3�� : �����ϱ�" << endl;
	cout << "4�� : �����ϱ�" << endl;
	cout << "5�� : �Ѿ�" << endl;
	cout << "6�� : ��������ϱ�" << endl;
	cout << "7�� : ������⻩��" << endl;
	cout << "8�� : ��        ��" << endl;
	cout << "------------------" << endl;
}

void Car::waiting()
{
	int i, j;
	int a;
	int n;
	
	
	cout << "������ ������⸦ �Ͻǰǰ���?";
	cin >> n;
	int number;
	int c ;
	for (i = 0; i < b; i++)
	{
		if (p[n-1][i].state == 0)//1�� ������� 0�� ������
			c = 0;
		else if(p[n-1][i].state == 1){
			c = 1;
			cout << "�� �ڸ��� �ֽ��ϴ�." << endl;
			break;
		}
	}
	if (c ==0)
	{
		cout << "������ȣ�� �Է��ϼ���";
		cin >> number;
		q.push(number);
		a = q.front();
		cout << "���� ���� ��� 1��" << a;
		cout << "���� ������⿭" << q.size();

	}
	
	
		
	}
	


void Car::All()
{
	int i, j;


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
}
void Car::remove() {
	q.pop();
	cout << "���� ���1������ �����ϴ�";
	cout << "���� ���� ��� 1��" << q.front();
}

int main()
{
	//int a, b;
	int n;
	Car car;

	car.make_park(2,2);
	while (1)
	{
		car.print();
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "������ ����" << endl;
			car.All();
			car.parkstate();
			cout << endl;
			break;
		case 2:
			car.empty();
			cout << endl;
			break;
		case 3:

			car.incoming();
			car.parkstate();
			cout << endl;
			break;
		case 4:

			car.outcoming();
			car.parkstate();
			cout << endl;
			break;

		case 5:
			car.sum();
			cout << endl;
			break;
		case 6:
			car.waiting();
			cout << endl;
			break;
		case 7:
			car.remove();
			cout << endl;
			break;

		case 8:
			exit(0);
		default:
			break;
		}
	}

	return 0;

}