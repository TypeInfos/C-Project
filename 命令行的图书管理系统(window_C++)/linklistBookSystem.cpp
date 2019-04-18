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
			cout << "请输入ISBN:";
			cin >> s->isbn;
			cout << "请输入书名:";
			cin >> s->booktitle;
			cout << "请输入作者名:";
			cin >> s->author;
			cout << "请输入出版社:";
			cin >> s->pubisher;
			cout << "请输入批发价:";
			cin >> s->wholesale;
			cout << "请输入零售价:";
			cin >> s->retail;
			cout << "请输入进货量:";
			cin >> s->qtyonhand;
			time(&nowtime);
			strftime(date, 20, "%Y-%m-%d %X", localtime(&nowtime));
			strcpy(s->dateadded, date);
			cout << "\n已自动获取当前时间!" << endl;
			p->next = s;
			s->prior = p;
			h->prior = s;
			s->next = h;
			updata();
			cout << "\n添加书籍完成,这是你刚添加的信息：" << endl;
			cout << "\n继续添加请按y,返回上一级按任意键,输入:";
			cin >> flag;
			if (flag == 'y' || flag == 'Y')
				cout << "\n再次添加！" << endl;
			else
			{
				cout << "已退出增加书籍！" << endl;
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
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tISBN号\t\t书名\t\t作者\t\t出版社\t\t库存量\t\t零售价" << endl;
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
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t序号\tISBN号\t\t书名\t\t作者\t\t出版社\t\t库存量\t\t零售价" << endl;
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
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t序号\tISBN号\t\t书名\t\t作者\t\t出版社\t\t库存量\t\t零售价" << endl;
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
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t序号\tISBN号\t\t书名\t\t作者\t\t出版社\t\t库存量\t\t零售价" << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------------" << endl;
		while (m != h)
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t" << j << "\t" << m->isbn << "\t" << "\t" << m->booktitle << "\t" << "\t" << m->author << "\t" << "\t"
				<< m->pubisher << "\t" << m->qtyonhand << "\t" << "\t" << m->retail << endl;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------------" << endl;
			m = m->next;
			j++;
		}
		cout << "\n输入你想修改书的序号:";
		cin >> i;
		while (p != h)
		{
			if (i == num)
				break;
			p = p->next;
			num++;
		}
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t你将要修改书的信息为:" << endl;
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
				cout << "请输入修改后的ISBN号:" << endl;
				while (1)
				{
					cin >> ISBN;
					if (!check_isbn(ISBN))
					{
						p->isbn = ISBN;
						cout << "\n修改成功！" << endl;
						break;
					}
					else
						cout << "\nISBN已存在，请重新出入:";
				}
				mark_1 = 1;
				break;
			case 2:
				while (1)
				{
					char bookname[20];
					cout << "请输入修改后的书名:" << endl;
					cin >> bookname;
					if (!check_title(bookname))
					{
						cout << "修改成功！" << endl;
						strcpy(p->booktitle, bookname);
						break;
					}
					else
						cout << "\n书名已存在已存在，请重新出入:";
				}
				mark_1 = 1;
				break;
			case 3:
				char bookpubisher[20];
				cout << "请输入修改后的出版社:" << endl;
				cin >> bookpubisher;
				strcmp(p->pubisher, bookpubisher);
				cout << "修改成功！" << endl;
				mark_1 = 1;
				break;
			case 4:
				char bookauthor[20];
				cout << "请输入修改后的作者:" << endl;
				cin >> bookauthor;
				strcpy(p->author, bookauthor);
				cout << "修改成功！" << endl;
				mark_1 = 1;
				break;
			case 5:
				double price;
				cout << "请输入修改后的零售价:" << endl;
				cin >> price;
				p->retail = price;
				cout << "修改成功！" << endl;
				mark_1 = 1;
				break;
			default:
				cout << "你的输入有误，请重新输入！" << "\n" << "输入选择(1~5) :" << endl;
				mark_1 = 0;
				break;
			}
			updata();
			if (mark_1)
			{
				cout << "\n返回上一级按N,继续按任意键!\n输入:";
				cin >> pro_1;
			}
		}
	}
	void interface_changebookdata()
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t                 图书修改系统 " << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t-------------------------------------------------------------------------------" << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t   1:修改ISBN    2:修改书名   3:修改出版社   4:修改作者   5:修改零售价 " << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t-------------------------------------------------------------------------------" << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t输入数字:";
	}
	void find_Bookauthor()
	{
		data *p = new data;
		p = h->next;
		char author[20];
		int num = 0;
		cout << "请输入你要查询的作者 :";
		cin >> author;
		while (p != h)
		{
			if (strcpy(p->author, author))
			{
				if (num > 0)
				{
					cout << "\n\t\t\t\t\t\t\t\t\t\t\tISBN号\t\t书名\t\t作者\t\t出版社\t\t库存量\t\t批发价" << endl;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------------" << endl;
				}
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t" << p->isbn << "\t" << "\t" << p->booktitle << "\t" << "\t" << p->author << "\t" << "\t"
					<< p->pubisher << "\t" << p->qtyonhand << "\t" << "\t" << p->wholesale << endl;
				num++;
			}
			else
				cout << "抱歉，没有你所查询的作者！" << endl;
		}
	}
	void delete_book()
	{
		data *p = new data;
		p = h->next;
		char flag;
		char name[20];
		showAllBook();
		cout << "\n输入你想删除书的名字:";
		cin >> name;
		if (check_title(name))
		{
			cout << "\n你将要删除书的信息为:" << endl;
			showinfo(name);
			while (p != h)
			{
				if (!strcmp(p->booktitle, name))
					break;
				p = p->next;
			}
			p->prior->next = p->next;
			p->next->prior = p->prior;

			cout << "\n确认删除请按y，取消删除请按任意键！" << endl;
			cin >> flag;
			if (flag == 'y' || flag == 'Y')
			{
				updata();
				cout << "\n删除成功！" << endl;
			}
			else
				cout << "\n已取消删除！" << endl;
		}
		else
			cout << "\n抱歉，没找到你要查询的书名！" << endl;
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
				cout << "\n\n◆◆◆◆◆◆◆◆◆所有图书:" << endl;
				function_findBook();
				break;
			case 2:changeBook();
				break;
			case 3:add_books();
				break;
			case 4:delete_book();
				char cc;
				cout << "\n返回书库管理按任意键:";
				cin >> cc;
				break;
			case 5:showAllBook();
				cout << "\n返回书库管理按任意键:";
				char c;
				cin >> c;
				break;
			case 6:
				pro_1 = 'n';
				break;
			default:
				cout << "\n你的输入有误，请重新输入！" << "\n" << "输入选择(1~6) :" << endl;
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
			cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t             请输入你要查询的方式" << endl;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t---------------------------------------------------------" << endl;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t   1:按书名查找     2:按ISBN号查找      3:按作者查询" << endl;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t---------------------------------------------------------" << endl;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t输入数字:";
			cin >> pro_num;
			switch (pro_num)
			{
			case 1:
				cout << "\n请输入你想要查询的书名:";
				char title[20];
				cin >> title;
				if (check_title(title))
					showinfo(title);
				else
					cout << "抱歉，没找到你要查询的书名！" << endl;
				mark_1 = 1;
				break;
			case 2:
				cout << "\n请输入你想要查询的ISBN号:";
				cin >> id;
				if (check_isbn(id))
					showinfo(id);
				else
					cout << "抱歉，没找到你要查询的IBSN号！" << endl;
				mark_1 = 1;
				break;
			case 3:
				char author[20];
				cout << "\n请输入你想要查询的作者：";
				cin >> author;
				if (check_author(author))
				{
					showinfo_author(author);
				}
				else
					cout << "抱歉，没找到你要查询的作者!" << endl;
				mark_1 = 1;
				break;
			default:
				cout << "\n你的输入有误，请重新输入！" << "\n" << "输入选择(1~3) :" << endl;
				mark_1 = 0;
				break;
			}
			if (mark_1)
			{
				cout << "\n返回上一级按N,继续查询按任意键" << endl;
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
			cout << "退出系统！" << endl;
			exit(1);
		default:
			cout << "你的输入有误，请重新输入！" << "\n" << "输入选择(1~4) :" << endl;
			break;
		}
	}
}
void interface()
{
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t               图书管理系统        " << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------" << endl;
	cout << "\n" << "\n"
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t◆◆◆◆◆主菜单◆◆◆◆◆" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t☆                      ☆" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t☆      1.书库模块      ☆" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t☆                      ☆" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t☆      2.收银模块      ☆" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t☆                      ☆" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t☆      3.报表模块      ☆" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t☆                      ☆" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t☆      4.退出系统      ☆" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t☆                      ☆" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t◆◆◆◆◆◆◆◆◆◆◆◆◆" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t☆☆☆☆☆输入选择(1~4):";
}
void bookmanager()
{
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t                 书库管理模块        " << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------" << endl;
	cout << "\n" << "\n"
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t☆                            ☆" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t☆        1、查找书           ☆" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t☆                            ☆" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t☆        2、修改书           ☆" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t☆                            ☆" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t☆        3、增加书           ☆" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t☆                            ☆" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t☆        4、删除书           ☆" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t☆                            ☆" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t☆        5、查看图书         ☆" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t☆                            ☆" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t☆        6、返回主菜单       ☆" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t☆                            ☆" << endl
		<< "\t\t\t\t\t\t\t\t\t\t\t\t\t◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t☆☆☆☆☆输入选择(1~6):";
}

