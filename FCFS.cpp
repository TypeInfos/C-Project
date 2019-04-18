
#include "iostream"
#include "math.h"
using namespace std;
struct node{
	char name[20];   /*���̱�ʶ��*/
	int arrivetime; //�����ʱ��
	int cputime;   /*CPUִ��ʱ��*/
	int needtime;   /*����ִ������Ҫ��ʱ��*/
	char state;    /*���̵�״̬��W��������̬��R����ִ��̬��F�������̬*/
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
	cout << "��������̵ĸ���:";
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
	cout << "����PID\t\t����ʱ��\t\tִ�й���ʱ��\t\t����������תʱ��\t\t����״̬" << endl;
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
		cout << "���������PID:";
		cin >> p->name;
		cout << "���������Ԥ�ƿ�ʼ��ʱ��:";
		cin >> p->arrivetime;
		cout << "���������ִ����Ҫ��ʱ��:";
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
		//��һ�����ֺ���һ�����
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