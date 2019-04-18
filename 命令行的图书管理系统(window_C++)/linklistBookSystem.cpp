#include "iostream"
#include "cstring"
#include "stdlib.h"
#include "ctime"
#include "fstream"
using namespace std;
void bookmanager();
struct data
{
	char booktitle[20];
	char author[20];
	char pubisher[20];
	char dateadded[20];
	double isbn;
	double qtyonhand;
	double wholesale;
	double retail;
	struct data *prior, *next;
};
class book
{
private:
	data *h;
public:
	book()
	{
		data *H = new data;
		h = H;
		h->prior = h;
		h->next = h;
	}
	void add_books()
	{
		char flag;
		char date[20];
		time_t nowtime;
		data *p = new data;
		while (1)
		{
			p = find_final();
			data *s = new data;
			cout << "������ISBN:";
			cin >> s->isbn;
			cout << "����������:";
			cin >> s->booktitle;
			cout << "������������:";
			cin >> s->author;
			cout << "�����������:";
			cin >> s->pubisher;
			cout << "������������:";
			cin >> s->wholesale;
			cout << "���������ۼ�:";
			cin >> s->retail;
			cout << "�����������:";
			cin >> s->qtyonhand;
			time(&nowtime);
			strftime(date, 20, "%Y-%m-%d %X", localtime(&nowtime));
			strcpy(s->dateadded, date);
			cout << "\n���Զ���ȡ��ǰʱ��!" << endl;
			p->next = s;
			s->prior = p;
			h->prior = s;
			s->next = h;
			updata();
			cout << "\n����鼮���,���������ӵ���Ϣ��" << endl;
			cout << "\n��������밴y,������һ���������,����:";
			cin >> flag;
			if (flag == 'y' || flag == 'Y')
				cout << "\n�ٴ���ӣ�" << endl;
			else
			{
				cout << "���˳������鼮��" << endl;
				break;
			}
		}
	}
	data* find_final()
	{
		data *p = new data;
		p = h;
		while (p->next != h)
		{
			p = p->next;
		}
		return p;
	}
	void showAllBook()
	{
		data *p = new data;
		p = h->next;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tISBN��\t\t����\t\t����\t\t������\t\t�����\t\t���ۼ�" << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------------" << endl;
		while (p != h)
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t" << p->isbn << "\t" << "\t" << p->booktitle << "\t" << "\t" << p->author << "\t" << "\t"
				<< p->pubisher << "\t" << p->qtyonhand << "\t" << "\t" << p->retail << endl;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------------" << endl;
			p = p->next;
		}
	}
	data hand_name(char *name)
	{
		data *p = new data;
		p = h;
	}
	void showAllbookbyorder()
	{
		data *p = new data;
		p = h->next;
		int i = 0;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t���\tISBN��\t\t����\t\t����\t\t������\t\t�����\t\t���ۼ�" << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------------" << endl;
		while (p != h)
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t" << i << "\t" << p->isbn << "\t" << "\t" << p->booktitle << "\t" << "\t" << p->author << "\t" << "\t"
				<< p->pubisher << "\t" << p->qtyonhand << "\t" << "\t" << p->retail << endl;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------------" << endl;
			p = p->next;
			i++;
		}
	}
	void showbook_data(data *p)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t���\tISBN��\t\t����\t\t����\t\t������\t\t�����\t\t���ۼ�" << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------------" << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t" << "\t" << p->isbn << "\t" << "\t" << p->booktitle << "\t" << "\t" << p->author << "\t" << "\t"
			<< p->pubisher << "\t" << p->qtyonhand << "\t" << "\t" << p->retail << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------------" << endl;
	}
	bool check_isbn(double isbn)
	{

		data *p = new data;
		p = h->next;
		while (p != h)
		{
			if (p->isbn == isbn)
				return true;
			p = p->next;
		}
		return false;
	}
	bool check_title(char *name)
	{
		data *p = new data;
		p = h->next;
		while (p != h)
		{
			if (!strcmp(p->booktitle, name))
				return true;
			p = p->next;
		}
		return false;
	}
	bool check_author(char *name)
	{
		data *p = new data;
		p = h->next;
		while (p != h)
		{
			if (!strcmp(p->author, name))
				return true;
			p = p->next;
		}
		return false;
	}
	void changeBook()
	{
		data *p = new data;
		p = h->next;
		int i,j=1, num = 1;
		data *m = new data;
		m = h->next;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t���\tISBN��\t\t����\t\t����\t\t������\t\t�����\t\t���ۼ�" << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------------" << endl;
		while (m != h)
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t" << j << "\t" << m->isbn << "\t" << "\t" << m->booktitle << "\t" << "\t" << m->author << "\t" << "\t"
				<< m->pubisher << "\t" << m->qtyonhand << "\t" << "\t" << m->retail << endl;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------------" << endl;
			m = m->next;
			j++;
		}
		cout << "\n���������޸�������:";
		cin >> i;
		while (p != h)
		{
			if (i == num)
				break;
			p = p->next;
			num++;
		}
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t�㽫Ҫ�޸������ϢΪ:" << endl;
		showbook_data(p);
		int mark_1;
		char pro_1 = 'y';
		while (pro_1 != 'N'&&pro_1 != 'n'){
			int pro_num;
			interface_changebookdata();
			cin >> pro_num;
			switch (pro_num)
			{
			case 1:double ISBN;
				cout << "�������޸ĺ��ISBN��:" << endl;
				while (1)
				{
					cin >> ISBN;
					if (!check_isbn(ISBN))
					{
						p->isbn = ISBN;
						cout << "\n�޸ĳɹ���" << endl;
						break;
					}
					else
						cout << "\nISBN�Ѵ��ڣ������³���:";
				}
				mark_1 = 1;
				break;
			case 2:
				while (1)
				{
					char bookname[20];
					cout << "�������޸ĺ������:" << endl;
					cin >> bookname;
					if (!check_title(bookname))
					{
						cout << "�޸ĳɹ���" << endl;
						strcpy(p->booktitle, bookname);
						break;
					}
					else
						cout << "\n�����Ѵ����Ѵ��ڣ������³���:";
				}
				mark_1 = 1;
				break;
			case 3:
				char bookpubisher[20];
				cout << "�������޸ĺ�ĳ�����:" << endl;
				cin >> bookpubisher;
				strcmp(p->pubisher, bookpubisher);
				cout << "�޸ĳɹ���" << endl;
				mark_1 = 1;
				break;
			case 4:
				char bookauthor[20];
				cout << "�������޸ĺ������:" << endl;
				cin >> bookauthor;
				strcpy(p->author, bookauthor);
				cout << "�޸ĳɹ���" << endl;
				mark_1 = 1;
				break;
			case 5:
				double price;
				cout << "�������޸ĺ�����ۼ�:" << endl;
				cin >> price;
				p->retail = price;
				cout << "�޸ĳɹ���" << endl;
				mark_1 = 1;
				break;
			default:
				cout << "��������������������룡" << "\n" << "����ѡ��(1~5) :" << endl;
				mark_1 = 0;
				break;
			}
			updata();
			if (mark_1)
			{
				cout << "\n������һ����N,�����������!\n����:";
				cin >> pro_1;
			}
		}
	}
	void interface_changebookdata()
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t                 ͼ���޸�ϵͳ " << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t-------------------------------------------------------------------------------" << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t   1:�޸�ISBN    2:�޸�����   3:�޸ĳ�����   4:�޸�����   5:�޸����ۼ� " << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t-------------------------------------------------------------------------------" << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t��������:";
	}
	void find_Bookauthor()
	{
		data *p = new data;
		p = h->next;
		char author[20];
		int num = 0;
		cout << "��������Ҫ��ѯ������ :";
		cin >> author;
		while (p != h)
		{
			if (strcpy(p->author, author))
			{
				if (num > 0)
				{
					cout << "\n\t\t\t\t\t\t\t\t\t\t\tISBN��\t\t����\t\t����\t\t������\t\t�����\t\t������" << endl;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------------" << endl;
				}
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t" << p->isbn << "\t" << "\t" << p->booktitle << "\t" << "\t" << p->author << "\t" << "\t"
					<< p->pubisher << "\t" << p->qtyonhand << "\t" << "\t" << p->wholesale << endl;
				num++;
			}
			else
				cout << "��Ǹ��û��������ѯ�����ߣ�" << endl;
		}
	}
	void delete_book()
	{
		data *p = new data;
		p = h->next;
		char flag;
		char name[20];
		showAllBook();
		cout << "\n��������ɾ���������:";
		cin >> name;
		if (check_title(name))
		{
			cout << "\n�㽫Ҫɾ�������ϢΪ:" << endl;
			showinfo(name);
			while (p != h)
			{
				if (!strcmp(p->booktitle, name))
					break;
				p = p->next;
			}
			p->prior->next = p->next;
			p->next->prior = p->prior;

			cout << "\nȷ��ɾ���밴y��ȡ��ɾ���밴�������" << endl;
			cin >> flag;
			if (flag == 'y' || flag == 'Y')
			{
				updata();
				cout << "\nɾ���ɹ���" << endl;
			}
			else
				cout << "\n��ȡ��ɾ����" << endl;
		}
		else
			cout << "\n��Ǹ��û�ҵ���Ҫ��ѯ��������" << endl;
	}
	void updata()
	{
		data *p = new data;
		p = h->next;
		fstream out;
		out.open("D:\\list\\bookdata.txt", ios::out);
		while (p != h)
		{
			out.write((char *)p, sizeof(data));
			p = p->next;
		}
		out.close();
	}
	void datainto()
	{
		data *p = new data;
		data *m = new data;
		p = h;
		fstream input;
		input.open("D:\\list\\bookdata.txt", ios::in);
		while (input)
		{
			data *s = new data;
			input.read((char *)s, sizeof(data));
			p->next = s;
			s->prior = p;
			s->next = h;
			h->prior = s;
			p = s;
			m = s;
		}
		m->prior->next = m->next;
		m->next->prior = m->prior;
		input.close();
	}
	void function_manager()
	{
		char pro_1 = 'y';
		while (pro_1 != 'N'&&pro_1 != 'n'){
			int pro_num;
			system("cls");
			bookmanager();
			cin >> pro_num;
			switch (pro_num)
			{
			case 1:
				cout << "\n\n����������������������ͼ��:" << endl;
				function_findBook();
				break;
			case 2:changeBook();
				break;
			case 3:add_books();
				break;
			case 4:delete_book();
				char cc;
				cout << "\n���������������:";
				cin >> cc;
				break;
			case 5:showAllBook();
				cout << "\n���������������:";
				char c;
				cin >> c;
				break;
			case 6:
				pro_1 = 'n';
				break;
			default:
				cout << "\n��������������������룡" << "\n" << "����ѡ��(1~6) :" << endl;
				break;
			}
		}
	}
	void showinfo(char *name)
	{
		data *p = new data;
		p = h->next;
		while (p != h)
		{
			if (!strcmp(p->booktitle, name))
			{
				showbook_data(p);
			}
			p = p->next;
		}
	}
	void showinfo(double num)
	{
		data *p = new data;
		p = h->next;
		while (p != h)
		{
			if (p->isbn == num)
			{
				showbook_data(p);
			}
			p = p->next;
		}
	}
	void showinfo_author(char *name)
	{
		data *p = new data;
		p = h->next;
		while (p != h)
		{
			if (!strcmp(p->author, name))
			{
				showbook_data(p);
			}
			p = p->next;
		}
	}
	void  function_findBook()
	{
		int mark_1, ma = 0;
		char pro_1 = 'y';
		double id;

		while (pro_1 != 'N'&&pro_1 != 'n'){
			int pro_num;
			system("cls");
			cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t             ��������Ҫ��ѯ�ķ�ʽ" << endl;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t---------------------------------------------------------" << endl;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t   1:����������     2:��ISBN�Ų���      3:�����߲�ѯ" << endl;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t---------------------------------------------------------" << endl;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t��������:";
			cin >> pro_num;
			switch (pro_num)
			{
			case 1:
				cout << "\n����������Ҫ��ѯ������:";
				char title[20];
				cin >> title;
				if (check_title(title))
					showinfo(title);
				else
					cout << "��Ǹ��û�ҵ���Ҫ��ѯ��������" << endl;
				mark_1 = 1;
				break;
			case 2:
				cout << "\n����������Ҫ��ѯ��ISBN��:";
				cin >> id;
				if (check_isbn(id))
					showinfo(id);
				else
					cout << "��Ǹ��û�ҵ���Ҫ��ѯ��IBSN�ţ�" << endl;
				mark_1 = 1;
				break;
			case 3:
				char author[20];
				cout << "\n����������Ҫ��ѯ�����ߣ�";
				cin >> author;
				if (check_author(author))
				{
					showinfo_author(author);
				}
				else
					cout << "��Ǹ��û�ҵ���Ҫ��ѯ������!" << endl;
				mark_1 = 1;
				break;
			default:
				cout << "\n��������������������룡" << "\n" << "����ѡ��(1~3) :" << endl;
				mark_1 = 0;
				break;
			}
			if (mark_1)
			{
				cout << "\n������һ����N,������ѯ�������" << endl;
				cin >> pro_1;
			}
		}
	}
	void crreat()
	{
		data *p = new data;
		p = h->next;
		if (p)
			cout << "s";
	}
};

void interface();
void main()
{

	book k;
	k.datainto();
	while (1){
		int pro_num;
		system("cls");
		interface();
		cin >> pro_num;
		switch (pro_num)
		{
		case 1:k.function_manager();
			system("cls");
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			cout << "�˳�ϵͳ��" << endl;
			exit(1);
		default:
			cout << "��������������������룡" << "\n" << "����ѡ��(1~4) :" << endl;
			break;
		}
	}
}
void interface()
{
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t               ͼ�����ϵͳ        " << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------" << endl;
	cout << "\n" << "\n"
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t�������������˵�����������" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��                      ��" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��      1.���ģ��      ��" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��                      ��" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��      2.����ģ��      ��" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��                      ��" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��      3.����ģ��      ��" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��                      ��" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��      4.�˳�ϵͳ      ��" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��                      ��" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��������������������������" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t����������ѡ��(1~4):";
}
void bookmanager()
{
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t                 ������ģ��        " << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------" << endl;
	cout << "\n" << "\n"
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��������������������������������" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��                            ��" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��        1��������           ��" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��                            ��" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��        2���޸���           ��" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��                            ��" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��        3��������           ��" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��                            ��" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��        4��ɾ����           ��" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��                            ��" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��        5���鿴ͼ��         ��" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��                            ��" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��        6���������˵�       ��" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��                            ��" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t��������������������������������" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t����������ѡ��(1~6):";
}

