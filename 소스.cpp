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
	int c;//멤버 변수로
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
	this->b = b;//주차장 초기화


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
				cout << i + 1 << "층" << j + 1 << "번째" << ") " << " 비어있음" << endl;
			}
			else
			{
				end = clock();
				cout << i + 1 << "층" << j + 1 << "번째" << ")" << " 사용중" << " " << (double)(end - p[i][j].start) / CLK_TCK << endl;
				count++;
			}
		}
	}
	cout << "비어있는 자리는 총 " << (a*b) - count << " 입니다." << endl;
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
				cout << "남은자리는" << i + 1 << "층" << j + 1 << "번째 열입니다." << endl;
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
		
		cout << "몇층의 몇번째자리에 주차하시겠습니까?" << endl;
		cin >> i >> j;

		cout << endl;
		p[i - 1][j - 1].start = clock();
		p[i - 1][j - 1].state = 0;
		cout << i << "층" << j << "번 째에 주차 되었습니다." << endl;
		cout << endl;
	}
	else {
		cout << "꽉 찼습니다. 주차대기를 해주세요";
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

	Total += money;
}

void Car::sum()
{

	cout << "현재까지 총 금액은" << Total << "원 입니다" << endl;
}

int Car::getTotal()
{
	return Total;
}

void Car::print()
{
	cout << "------------------" << endl;
	cout << "1번 : 주차중인 자리보기" << endl;
	cout << "2번 : 주차가능 자리보기" << endl;
	cout << "3번 : 주차하기" << endl;
	cout << "4번 : 출차하기" << endl;
	cout << "5번 : 총액" << endl;
	cout << "6번 : 주차대기하기" << endl;
	cout << "7번 : 주차대기빼기" << endl;
	cout << "8번 : 종        료" << endl;
	cout << "------------------" << endl;
}

void Car::waiting()
{
	int i, j;
	int a;
	int n;
	
	
	cout << "몇층에 주차대기를 하실건가요?";
	cin >> n;
	int number;
	int c ;
	for (i = 0; i < b; i++)
	{
		if (p[n-1][i].state == 0)//1은 비어있음 0은 주차중
			c = 0;
		else if(p[n-1][i].state == 1){
			c = 1;
			cout << "빈 자리가 있습니다." << endl;
			break;
		}
	}
	if (c ==0)
	{
		cout << "차량번호를 입력하세요";
		cin >> number;
		q.push(number);
		a = q.front();
		cout << "현재 주차 대기 1번" << a;
		cout << "현재 주차대기열" << q.size();

	}
	
	
		
	}
	


void Car::All()
{
	int i, j;


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
}
void Car::remove() {
	q.pop();
	cout << "주차 대기1순위를 뺐습니다";
	cout << "현재 주차 대기 1번" << q.front();
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
			cout << "주차장 상태" << endl;
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