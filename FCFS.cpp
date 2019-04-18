
#include "iostream"
#include "math.h"
using namespace std;
struct node{
	char name[20];   /*进程标识符*/
	int arrivetime; //到达的时间
	int cputime;   /*CPU执行时间*/
	int needtime;   /*进程执行所需要的时间*/
	char state;    /*进程的状态，W——就绪态，R——执行态，F——完成态*/
	struct node *next;
};
void print_node(node *h);
void endInsertData(node *h, node *d);
void insertNumData(node *h, int mark, node *d);
int returnNum(node *h, int time);
void insertData(node *h, int num);
void print_node(node *h);
void  createList(node *h);
int main()
{
	int num;
	node *h = new node;
	h->next = NULL;
	cout << "FCFS ALGORITHM" << endl;
	cout << "请输入进程的个数:";
	cin >> num;
	insertData(h, num);
	print_node(h);
	return 0;
}
void  createList(node *h)
{
	int time;
	node *l = h;

	cin >> time;
	while (time != -1)
	{
		node *p = new node;
		p->arrivetime = time;
		l->next = p;
		l = p;

		cin >> time;
	}
	if (l != NULL)
		l->next = NULL;
}
void print_node(node *h)
{
	node *p;
	int time_1, time_2, flag;
	time_1 = 0;
	time_2 = 0;
	flag = 0;
	p = h->next;
	cout << "进程PID\t\t到达时间\t\t执行过程时间\t\t进程运行周转时间\t\t进程状态" << endl;
	while (p != NULL)
	{
		if (time_1 == 0)
		{
			cout << p->name << "\t\t\t" << p->arrivetime << "\t\t\t" << p->needtime << "\t\t\t\t" << p->needtime << "\t\t\t\t" << p->state << endl;
		}
		else
		{

			if (p->arrivetime - time_2 - time_1 >0)
			{
				cout << p->name << "\t\t\t" << p->arrivetime << "\t\t\t" << p->needtime << "\t\t\t\t" << std::abs(p->arrivetime - time_2 - time_1) + p->needtime << "\t\t\t\t" << p->state << endl;
			}
			else
			{
				cout << p->name << "\t\t\t" << p->arrivetime << "\t\t\t" << p->needtime << "\t\t\t\t" << time_2 + p->needtime - p->arrivetime << "\t\t\t\t" << p->state << endl;
			}
		}
		time_1 += p->arrivetime;
		time_2 += p->needtime;
		flag = p->arrivetime;
		p = p->next;
	}
}
void insertData(node *h, int num)
{
	int i = 0;
	while (i<num)
	{
		node *p = new node;
		cout << "请输入进程PID:";
		cin >> p->name;
		cout << "请输入进程预计开始的时间:";
		cin >> p->arrivetime;
		cout << "请输入进程执行需要的时间:";
		cin >> p->needtime;
		p->state = 'w';
		p->cputime = 0;
		i++;
		if (i == 1 || i == returnNum(h, p->arrivetime))
		{
			endInsertData(h, p);
		}
		else{

			insertNumData(h, returnNum(h, p->arrivetime), p);
		}

	}
}
int returnNum(node *h, int time)
{
	node *p = h->next;
	int num = 1;
	while (p != NULL)
	{
		if (p->arrivetime <= time)
		{
			num++;
			p = p->next;
		}

		else
			break;

	}
	return num;
}
void insertNumData(node *h, int mark, node *d)
{
	node *p;
	p = h;
	int flag = mark - 1;
	while (flag)
	{
		p = p->next;
		//第一个数字后算一个结点
		flag--;
	}
	d->next = p->next;
	p->next = d;

}
void endInsertData(node *h, node *d)
{
	node *p = h;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = d;
	d->next = NULL;
}