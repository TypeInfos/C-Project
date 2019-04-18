#include "iostream"
#include "fstream"
#include "cstring"
#include "stdlib.h"
#include "ctime"
#include "iomanip"
using namespace std;
class bookdata{
private:
    char booktitle[20];
    char author[20];
    char pubisher[20];
    char dateadded[20];
    double isbn;
    double qtyonhand;
    double wholesale;
    double retail;
public:
    bookdata(){
        this->isbn = 0;
    }
    bookdata(double isbn, char *name, char *au,
             char *da, char *pu, double wholesale, double retail, double qtyonhand)
    {
        this->isbn = isbn;
        strcpy(booktitle, name);
        strcpy(author, au);
        strcpy(dateadded, da);
        strcpy(pubisher, pu);
        this->wholesale = wholesale;
        this->retail = retail;
        this->qtyonhand = qtyonhand;
    }
    void addBookdata(double isbn, char *name, char *au,
                     char *da, char *pu, double wholesale, double retail, double qtyonhand)
    {
        this->isbn = isbn;
        strcpy(booktitle, name);
        strcpy(author, au);
        strcpy(dateadded, da);
        strcpy(pubisher, pu);
        this->wholesale = wholesale;
        this->retail = retail;
        this->qtyonhand = qtyonhand;
    }
    void setIsbn(double id)
    {
        this->isbn = id;
    }
    void setBookname(char *name)
    {
        strcpy(booktitle, name);
    }
    void setRetail(double retail)
    {
        this->retail = retail;
    }
    void setPubisher(char *name)
    {
        strcpy(pubisher, name);
    }
    void setAuthor(char *au)
    {
        strcpy(author, au);
    }
    void setQtyonhand(double n)
    {
        qtyonhand = n;
    }
    void setWholesale(double n)
    {
        wholesale = n;
    }
    void setDateadded(char *date)
    {
        strcpy(dateadded, date);
    }
    double getIsbn()
    {
        return isbn;
    }
    char* getBooktile()
    {
        return booktitle;
    }
    char* getAuthor()
    {
        return author;
    }
    char* getDateadded()
    {
        return dateadded;
    }
    char* getPubisher()
    {
        return pubisher;
    }
    double getWholesale()
    {
        return wholesale;
    }
    double getRetail()
    {
        return retail;
    }
    double getQtyonhand()
    {
        return qtyonhand;
    }
    
    void showAllBook();
    int findBook_bookname(char *name);
    int findBook_bookisbn(double isbn);
    void addBook();
    void changeBook();
    void displayBook_underline(int i);
    void deleteBook();
    void function_manager();
    void function_findBook();
    int displaygoods();
    int getOrder();
    void displayBook_rank(int i);
    bool check_isbn(double n);
    bool check_name(char *name);
    bool check_author(char *name);
    void check_qh();
};
class sales :public bookdata{
private:
    int order;
    int number;
    double total;
public:
    sales()
    {
        this->order = 0;
    }
    int getOrder()
    {
        return order;
    }
    void setOrder(int n)
    {
        this->order = n;
    }
    
    int getNumber()
    {
        return number;
    }
    void setNumber(int n)
    {
        this->number = n;
    }
    double getTotal()
    {
        return total;
    }
    void setTotal(double n)
    {
        this->total = n;
    }
    void input_data(bookdata *book);
    void account_shop();
    void function_shop(bookdata *book);
    void display_line(int i);
};
class Report{
public:
    void report_Book(bookdata *obj);
    void report_Wholesale(bookdata *obj);
    void report_Retail(bookdata *obj);
    void report_Quantity(bookdata *obj);
    void report_Values(bookdata *obj);
    void report_Dateadd(bookdata *obj);
    void function_Report(bookdata *obj);
};
void interface();
void bookmanager();
void updata(bookdata *obj);
void datainto(bookdata *obj);
void interface();
void interface_changebookdata();
void interface_table();
int geto(int i);
int getn(int i);
const int MAX = 100;
int Order;
int Number;
int main()
{
    bookdata obj[MAX];
    sales sale[MAX];
    Report report;
    datainto(obj);
    while (1){
        int pro_num;
        system("cls");
        interface();
        cin >> pro_num;
        switch (pro_num)
        {
            case 1:
                system("cls");
                obj[0].function_manager();
                break;
            case 2:sale[0].function_shop(obj);
                break;
            case 3:report.function_Report(obj);
                break;
            case 4:
                cout << "\n退出系统！" << endl;
                exit(1);
            default:
                cout << "\n你的输入有误，请重新输入！" << "\n" << "输入选择(1~4) :" << endl;
                break;
        }
    }
}
void bookdata::showAllBook()
{
    int i = 0;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\tISBN号\t\t书名\t\t作者\t\t出版社\t\t库存量\t\t批发价" << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------------" << endl;
    while (this[i].getIsbn() != 0)
    {
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t" << this[i].getIsbn() << "\t" << "\t" << this[i].getBooktile() << "\t" << "\t" << this[i].getAuthor() << "\t" << "\t"
        << this[i].getPubisher() << "\t" << this[i].getQtyonhand() << "\t" << "\t" << this[i].getWholesale() << endl;
        cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------------" << endl;
        i++;
    }
}
int bookdata::findBook_bookname(char *name)
{
    int i = 0, j = 0;
    while (this[i].getIsbn() != 0)
    {
        if (!strcmp(this[i].getBooktile(), name))
        {
            j=1;
            break;
        }
        i++;
    }
    if (j ==1)
        return ++i;
    else
        return 0;
}
void bookdata::changeBook()
{
    char name[20];
    int k;
    this[0].showAllBook();
    cout << "输入你想修改书的名字:";
    cin >> name;
    k = this[0].findBook_bookname(name);
    if(k)
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t你将要修改书的信息为:" << endl;
        k--;
        this[0].displayBook_underline(k);
        int mark_1;
        char pro_1 = 'y';
        while (pro_1 != 'N'&&pro_1 != 'n'){
            int pro_num;
            interface_changebookdata();
            cin >> pro_num;
            switch (pro_num)
            {
                case 1:double isbn;
                    cout << "\n请输入修改后的ISBN号:" << endl;
                    while (1)
                    {
                        cin >> isbn;
                        if (!this[0].check_isbn(isbn))
                        {
                            this[k].setIsbn(isbn);
                            cout << "\n修改成功！" << endl;
                            break;
                        }
                        else
                            cout << "\nISBN已存在，请重新出入:";
                    }
                    mark_1 = 1;
                    break;
                case 2:
                    char bookname[20];
                    cout << "\n请输入修改后的书名:" << endl;
                    while (1)
                    {
                        cin >>bookname;
                        if (!this[0].check_name(bookname))
                        {
                            this[k].setBookname(bookname);
                            cout << "\n修改成功！" << endl;
                            break;
                        }
                        else
                            cout << "\n书名已存在，请重新出入:";
                    }
                    mark_1 = 1;
                    break;
                case 3:
                    char bookpubisher[20];
                    cout << "请输入修改后的出版社:" << endl;
                    cin >> bookpubisher;
                    this[k].setPubisher(bookpubisher);
                    cout << "\n修改成功！" << endl;
                    mark_1 = 1;
                    break;
                case 4:
                    char bookauthor[20];
                    cout << "\n请输入修改后的作者:" << endl;
                    cin >> bookauthor;
                    this[k].setAuthor(bookauthor);
                    cout << "\n修改成功！" << endl;
                    mark_1 = 1;
                    break;
                case 5:
                    double price;
                    cout << "\n请输入修改后的零售价:" << endl;
                    cin >> price;
                    this[k].setRetail(price);
                    cout << "\n修改成功！" << endl;
                    mark_1 = 1;
                    break;
                default:
                    cout << "\n你的输入有误，请重新输入！" << "\n" << "输入选择(1~5) :" << endl;
                    mark_1 = 0;
                    break;
            }
            updata(this);
            datainto(this);
            if (mark_1)
            {
                cout << "\n返回上一级按N,继续按任意键!\n输入:" ;
                cin >> pro_1;
            }
        }
    }
    else
        cout << "\n抱歉，找不到你想要找的书！";
}
bool bookdata::check_isbn(double n){
    for (int i = 0; this[i].getIsbn() != 0; i++)
    {
        if (this[i].getIsbn() == n)
            return true;
    }
    return false;
}
bool bookdata::check_name(char *name)
{
    for (int i = 0; this[i].getIsbn() != 0; i++)
    {
        if (!strcmp(this[i].getBooktile(),name))
            return true;
    }
    return false;
}
int bookdata::findBook_bookisbn(double isbn)
{
    int i = 0, j = 0;
    while (this[i].getIsbn() != 0)
    {
        if (this[i].getIsbn()==isbn)
        {
            j = 1;
            break;
        }
        i++;
    }
    if (j ==1)
        return ++i;
    else
        return 0;
}
void bookdata::deleteBook()
{
    char name[10];
    char flag;
    int  k;
    this[0].showAllBook();
    cout << "输入你想删除书的名字:";
    cin >> name;
    k = this[0].findBook_bookname(name) - 1;
    if (this[0].findBook_bookname(name))
    {
        cout << "你将要删除书的信息为:" << endl;
        this[0].displayBook_underline(k);
        cout << "确认删除请按y，取消删除请按任意键！" << endl;
        cin >> flag;
        if (flag == 'y' || flag == 'Y')
        {
            int i = 0;
            while (this[i].getIsbn() != 0)
            {
                i++;
            }
            for (; k < i; k++)
            {
                this[k].setIsbn(this[k + 1].getIsbn());
                this[k].setAuthor(this[k + 1].getAuthor());
                this[k].setBookname(this[k + 1].getBooktile());
                this[k].setPubisher(this[k + 1].getPubisher());
                this[k].setRetail(this[k + 1].getRetail());
                this[k].setQtyonhand(this[k + 1].getWholesale());
                this[k].setDateadded(this[k + 1].getDateadded());
                this[k].setWholesale(this[k + 1].getWholesale());
            }
            this[i - 1].setIsbn(0);
            updata(this);
            cout << "删除成功！" << endl;
        }
        else
            cout << "已取消删除！" << endl;
        
    }
    else
        cout << "抱歉，找不到你想要找的书！" << endl;
}
void bookdata::addBook()
{
    char booktitle[20];
    char author[20];
    char pubisher[20];
    char dateadded[20];
    double isbn;
    double qtyonhand;
    double wholesale;
    double retail;
    time_t nowtime;
    int i = 0;
    char flag;
    while (this[i].getIsbn() != 0)
    {
        if (this[i].getIsbn() == 0)
            break;
        i++;
    }
    cout << "有空闲位置，可以增加书籍！" << endl;
    while (1)
    {
        cout << "请输入ISBN:";
        cin >> isbn;
        cout << "请输入书名:";
        cin >> booktitle;
        cout << "请输入作者名:";
        cin >> author;
        cout << "请输入出版社:";
        cin >> pubisher;
        cout << "请输入批发价:";
        cin >> wholesale;
        cout << "请输入零售价:";
        cin >> retail;
        cout << "请输入进货量:";
        cin >> qtyonhand;
        time(&nowtime);
        strftime(dateadded, 20, "%Y-%m-%d %X", localtime(&nowtime));
        if (!this[0].check_isbn(isbn) && !this[0].check_name(booktitle))
        {
            
        }
        else
        {
            cout << "ISBN号或书名重复，请重新输入！" << endl;
            continue;
        }
        cout << "\n已自动获取当前时间!" << endl;
        this[i].addBookdata(isbn, booktitle, author, dateadded, pubisher, wholesale, retail, qtyonhand);
        updata(this);
        cout << "\n添加书籍完成,这是你刚添加的信息：" << endl;
        this[0].displayBook_underline(i);
        cout << "\n继续添加请按y,返回上一级按任意键,输入:";
        cin >> flag;
        if (flag == 'y' || flag == 'Y')
        {
            cout << "再次添加！" << endl;
            i++;
        }
        else
        {
            cout << "已退出增加书籍！" << endl;
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

void bookdata::displayBook_underline(int i)
{
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t|------------------------|" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t|     ISBN号:" <<std::left<<setw(12)<< this[i].getIsbn() <<"|"<< endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t|     书  名:" << std::left << setw(12) << this[i].getBooktile() << "|" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t|     作  者:" << std::left << setw(12) << this[i].getAuthor() << "|" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t|     出版社:" << std::left << setw(12) << this[i].getPubisher() << "|" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t|     库存量:" << std::left << setw(12) << this[i].getQtyonhand() << "|" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t|     批发价:" << std::left << setw(12) << this[i].getWholesale() << "|" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t|     零售价:" << std::left << setw(12) << this[i].getRetail() << "|" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t|------------------------|" << endl;
    
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
void interface_changebookdata()
{
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t                 图书修改系统 " << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t-------------------------------------------------------------------------------------" << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t   1:修改ISBN    2:修改书名   3:修改出版社   4:修改作者   5:修改零售价  " << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t-------------------------------------------------------------------------------------" << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t输入数字:";
}
int bookdata::getOrder()
{
    int i;
    for (i = 0; this[i].getIsbn() != 0; i++)
    {
    }
    return i;
}
bool bookdata::check_author(char *name)
{
    for (int i = 0; this[i].getIsbn() != 0; i++)
    {
        if (!strcmp(this[i].getAuthor(), name))
            return true;
    }
    return false;
}
void bookdata::function_findBook()
{
    int mark_1,ma=0;
    char pro_1 = 'y';
    char name[20];
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
                cin >> name;
                if (this[0].findBook_bookname(name)!=0)
                    this[0].displayBook_underline(this[0].findBook_bookname(name)-1);
                else
                    cout << "抱歉，没找到你要查询的书名！" << endl;
                mark_1 = 1;
                break;
            case 2:
                cout << "\n请输入你想要查询的ISBN号:";
                cin >> id;
                if (this[0].findBook_bookisbn(id)!=0)
                    this[0].displayBook_underline(this[0].findBook_bookisbn(id)-1);
                else
                    cout << "抱歉，没找到你要查询的IBSN号！" << endl;
                mark_1 = 1;
                break;
            case 3:
                char author[20];
                cout << "\n请输入你想要查询的作者：";
                cin >> author;
                if (this[0].check_author(author))
                {
                    for (int i = 0; this[i].getIsbn() != 0; i++)
                    {
                        if (!strcmp(author, this[i].getAuthor()))
                        {
                            ma++;
                            this[0].displayBook_underline(i);
                            if (ma > 0)
                                cout << "\n" << endl;
                        }
                    }
                }
                else
                    cout << "抱歉，没找到你要查询的作者！" << endl;
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
void bookdata::function_manager()
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
                this[0].function_findBook();
                break;
            case 2:this[0].changeBook();
                break;
            case 3:this[0].addBook();
                break;
            case 4:this[0].deleteBook();
                char cc;
                cout << "\n返回书库管理按任意键:";
                cin >> cc;
                break;
            case 5:this[0].showAllBook();
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
void updata(bookdata *obj)
{
    int i = 0;
    fstream out;
    out.open("D:\\C++_DATA\\bookdata.txt", ios::out);
    while (obj[i].getIsbn() != 0)
    {
        out.write((char *)&obj[i], sizeof(obj[i]));
        i++;
    }
    out.close();
}
void datainto(bookdata *obj)
{
    fstream in;
    int i = 0;
    in.open("D:\\C++_DATA\\bookdata.txt", ios::in);
    while (in)
    {
        in.read((char *)&obj[i], sizeof(obj[i]));
        i++;
    }
    in.close();
}
void sales::function_shop(bookdata *book)
{
    int sym=1;
    char a;
    while (sym)
    {
        sym=book[0].displaygoods();
        this[0].input_data(book);
        if (sym == 2)
            break;
    }
    if (sym==0)
        this[0].account_shop();
    book[0].check_qh();
    cout << "\n按任意键返回主菜单:"<<endl;
    cin >> a;
}
void bookdata::check_qh()
{
    int i = 0;
    while (this[i].getIsbn() != 0)
    {
        if (this[i].getQtyonhand() <= 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\t\t" << "ISBN号:" << this[i].getIsbn() << "\t" << "书名:" << this[i].getBooktile() << "\t" << "库存量:" << this[i].getQtyonhand() << endl;
            cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------" << endl;
            cout << "发现有书籍库存为零或者库存不正常，请及时去书库管理系统修改信息！" << endl;
            break;
        }
        i++;
    }
}
int bookdata::displaygoods()
{
    int k,last,num,i = 0;
    char mark,sym1;
    system("cls");
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------" << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t               欢迎来到陌陌商店        " << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------" << endl;
    cout << "请选择你需要的商品：" << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t----\t-----\t-----\t-----\t      -----\t-----\t" << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t序 号\tISBN号\t书  名\t出版社\t      库存量\t零售价" << endl;
    while (this[i].getIsbn() != 0)
    {
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t" << i + 1 << "\t" << this[i].getIsbn() << "\t" << this[i].getBooktile() << "\t" << this[i].getPubisher() << "\t" << this[i].getQtyonhand() << "\t"
        << this[i].getRetail() << endl;
        cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------" << endl;
        i++;
    }
    cout << "\n输入序号:";
    cin >> num;
    cout << "\n你想要的这本" << this[num-1].getBooktile() << "的" << "单价是:RMB" << this[num-1].getRetail() << "，确认下单请按y:" ;
    cin >> mark;
    if (mark == 'y' || mark == 'Y')
    {
        cout << "亲，您要几本:";
        cin >> k;
        while (this[num - 1].getQtyonhand() < k)
        {
            cout << "\n库存不足，请重新输入你要购买的数量：";
            cin >> k;
        }
        this[num - 1].setQtyonhand(this[num - 1].getQtyonhand() - k);
        Order = num - 1;
        Number = k;
        updata(this);
        cout << "\n下单完成！" << endl;
        cout << "\n亲，请问你要继续购买么？\n\n退出书店按N，继续选购请按任意键:" << endl;
        cin >> sym1;
        if (sym1 == 'n' || sym1 == 'N')
            last = 0;
        else
            last = 1;
    }
    else
    {
        char na;
        cout << "\n亲，不中意的话，您可以再看看本店的其它书籍！" << endl;
        cout << "\n输入'n'退出商店,输入任意键继续浏览书店,:" ;
        cin >> na;
        if (na == 'n' || na == 'N')
            last = 2;
        else
            last = 1;
    }
    return last;
}
void sales::input_data(bookdata *book)
{
    int i;
    i = 0;
    while (this[i].getOrder()!= 0)
    {
        i++;
    }
    this[i].setIsbn(book[Order].getIsbn());
    this[i].setOrder(i + 1);
    this[i].setNumber(Number);
    this[i].setBookname(book[Order].getBooktile());
    this[i].setRetail(book[Order].getRetail());
    this[i].setTotal(Number*book[Order].getRetail());
}
void sales::display_line(int i)
{
    cout << "\n\t\t\t\t\t\t\t\t" << this[i].getOrder() << "\t" << this[i].getNumber() << "\t" << this[i].getIsbn() << "\t" << this[i].getBooktile() << "\t"
    << this[i].getRetail() << "\t" << this[i].getTotal() <<"\t"<< endl;
    cout << "\t\t\t\t\t\t\t\t---------------------------------------------------------------------------------------" << endl;
}
void sales::account_shop()
{
    int i;
    double total;
    total = 0;
    char date[20];
    i = 0;
    time_t nowtime;
    time(&nowtime);
    strftime(date, 20, "%Y年-%m月-%d号", localtime(&nowtime));
    cout << "\n\n\t\t\t\t\t\t\t\t日期:" <<date<< endl;
    cout << "\n\t\t\t\t\t\t\t\t序号\t数量\tISBN号\t书名\t单价\t金额\n"<< endl;
    cout << "\t\t\t\t\t\t\t\t~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ " << endl;
    
    while (this[i].getOrder()!= 0)
    {
        total = total + this[i].getTotal();
        this[0].display_line(i);
        i++;
    }
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << "打印凭条:" << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << "|-------------------------------|" << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << "|      销售合计:RMB" <<std::left<<setw(8)<< total <<"\t|"<< endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << "|      零售税:RMB" << std::left << setw(8) << total*0.03 << "\t|" << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << "|      应付款:RMB" << std::left << setw(8) << total - (total*0.03) << "\t|" << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << "|-------------------------------|" << endl;
    
}
void bookdata::displayBook_rank(int i)
{
    
    cout << "\n\t\t\t\t\t\t" << this[i].getIsbn() << "\t" << "\t" << this[i].getBooktile() << "\t" << "\t" << this[i].getAuthor() << "\t" << "\t"
    << this[i].getPubisher()<<"\t"<<this[i].getDateadded() << "\t"<< this[i].getQtyonhand() << "\t" << "\t" << this[i].getWholesale()<< "\t" << "\t" << this[i].getRetail() << endl;
    cout << "\t\t\t\t\t\t---------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
void Report::report_Wholesale(bookdata *obj)
{
    int  k = 0, arr = -1;
    double *q = new double[MAX];
    int sum = obj[0].getOrder();
    double  *p = new double[sum];
    for (int i = 0; i < sum; i++)
    {
        p[i] = obj[i].getWholesale();
    }
    for (int i = 0; i < sum; i++)
        for (int j = i + 1; j < sum; j++)
        {
            if (p[i]>p[j])
            {
                double temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    
    while (k<sum)
    {
        
        while (k < sum)
        {
            if (p[k] == p[k + 1])
                k++;
            else
            {
                arr++;
                q[arr] = p[k];
                break;
            }
            
        }
        k++;
    }
    cout << "\n\t\t\t\t\t\t按批发价从小到大排列:" << endl;
    cout << "\n\t\t\t\t\t\t" << "\t" << "ISBN号" << "\t" << "\t" << "书  名" << "\t" << "\t" << "作  者" << "\t" << "\t" << "出版社"
    << "\t" << "\t" << "进书日期" << "\t" << "\t" << "库存量" << "\t" << "\t" << "批发价" << "\t" << "\t" << "零售价" << endl;
    for (int i = 0; i < arr+1;i++)
        for (int j = 0; j< sum; j++)
        {
            if (q[i] == obj[j].getWholesale())
                obj[0].displayBook_rank(j);
        }
}
void Report::report_Retail(bookdata *obj)
{
    int  k = 0, arr = -1;
    double *q = new double[MAX];
    int sum = obj[0].getOrder();
    double  *p = new double[sum];
    for (int i = 0; i < sum; i++)
    {
        p[i] = obj[i].getRetail();
    }
    for (int i = 0; i < sum; i++)
        for (int j = i + 1; j < sum; j++)
        {
            if (p[i]>p[j])
            {
                double temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    while (k<sum)
    {
        while (k < sum)
        {
            if (p[k] == p[k + 1])
                k++;
            else
            {
                arr++;
                q[arr] = p[k];
                break;
            }
        }
        k++;
    }
    cout << "\n\t\t\t\t\t\t" << "按零售价从小到大排列:" << endl;
    cout << "\n\t\t\t\t\t\t" << "\t" << "ISBN号" << "\t" << "\t" << "书  名" << "\t" << "\t" << "作  者" << "\t" << "\t" << "出版社"
    << "\t" << "\t" << "进书日期" << "\t" << "\t" << "库存量" << "\t" << "\t" << "批发价" << "\t" << "\t" << "零售价" << endl;
    for (int i = 0; i < arr + 1; i++)
        for (int j = 0; j< sum; j++)
        {
            if (q[i] == obj[j].getRetail())
                obj[0].displayBook_rank(j);
        }
}
void Report::report_Quantity(bookdata *obj)
{
    int  k = 0, arr = -1;
    double *q = new double[MAX];
    int sum = obj[0].getOrder();
    double  *p = new double[sum];
    for (int i = 0; i < sum; i++)
    {
        p[i] = obj[i].getQtyonhand();
    }
    for (int i = 0; i < sum; i++)
        for (int j = i + 1; j < sum; j++)
        {
            if (p[i]>p[j])
            {
                double temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    while (k<sum)
    {
        while (k < sum)
        {
            if (p[k] == p[k + 1])
                k++;
            else
            {
                arr++;
                q[arr] = p[k];
                break;
            }
        }
        k++;
    }
    cout << "\n\t\t\t\t\t\t" << "按库存量从少到多排列:" << endl;
    cout << "\n\t\t\t\t\t\t" << "ISBN号" << "\t" << "\t" << "书  名" << "\t" << "\t" << "作  者" << "\t" << "\t" << "出版社"
    << "\t" << "\t" << "进书日期" << "\t" << "\t" << "库存量"  << "\t" << "\t" << "批发价" << "\t" << "\t" << "零售价" << endl;
    for (int i = 0; i < arr + 1; i++)
        for (int j = 0; j< sum; j++)
        {
            if (q[i] == obj[j].getQtyonhand())
                obj[0].displayBook_rank(j);
        }
}
void Report::report_Book(bookdata *obj)
{
    int i = 0;
    cout <<"\n\t\t\t\t\t\t"<< "|按书库顺序排列|:" << endl;
    cout << "\n\t\t\t\t\t\tISBN号" << "\t" << "\t" << "书名" << "\t" << "\t" << "作者" << "\t" << "\t"
    << "出版社" << "\t" << "\t" << "进书日期" << "\t" << "\t" << "\t" << "库存量" << "\t" << "\t" << "批发价" << "\t" << "\t" <<"零售价"<< endl;
    while (i<obj[0].getOrder())
    {
        
        cout << "\n\t\t\t\t\t\t"<<obj[i].getIsbn() << "\t" << "\t" << obj[i].getBooktile() << "\t" << "\t" << obj[i].getAuthor() << "\t" << "\t"
        << obj[i].getPubisher() << "\t" << obj[i].getDateadded() << "\t" << "\t" << obj[i].getQtyonhand() << "\t" << "\t"
        << obj[i].getWholesale() << "\t" << "\t" <<obj[i].getRetail()<< endl;
        cout << "\t\t\t\t\t\t---------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        i++;
    }
}
void interface_table()
{
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------" << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t                  报表模块         " << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------" << endl;
    cout << "\n" << "\n"
    << "\n\t\t\t\t\t\t\t\t◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ " << endl
    << "\n\t\t\t\t\t\t\t\t☆1:书库列表    ☆2:按批发价列表     ☆3:按零售价列表    ☆4:按书的数量列表   ☆5:按进书日期列表  ☆6:返回到主菜单" << endl
    << "\n\t\t\t\t\t\t\t\t◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ " << endl
    << "\n\t\t\t\t\t\t\t\t☆☆☆☆☆输入选择(1~6):";
}
void Report::report_Dateadd(bookdata *obj)
{
    int sum;
    cout << "\n\t\t\t\t\t\t" << "|按进书日期排列|:" << endl;
    cout << "\n\t\t\t\t\t\tISBN号" << "\t" << "\t" << "书名" << "\t" << "\t" << "作者" << "\t" << "\t"
    << "出版社" << "\t" << "\t" << "进书日期" << "\t" << "\t" << "\t" << "库存量" << "\t" << "\t" << "批发价" << "\t" << "\t" << "零售价" << endl;
    for (sum = 0; obj[sum].getIsbn() != 0; sum++)
    {
    }
    sum--;
    while ( sum>=0)
    {
        cout << "\n\t\t\t\t\t\t" << obj[sum].getIsbn() << "\t" << "\t" << obj[sum].getBooktile() << "\t" << "\t" << obj[sum].getAuthor() << "\t" << "\t"
        << obj[sum].getPubisher() << "\t" << obj[sum].getDateadded() << "\t" << "\t" << obj[sum].getQtyonhand() << "\t" << "\t"
        << obj[sum].getWholesale() << "\t" << "\t" << obj[sum].getRetail() << endl;
        cout << "\t\t\t\t\t\t---------------------------------------------------------------------------------------------------------------------------------------" << endl;
        sum--;
    }
}
void Report::function_Report(bookdata *obj)
{
    char flag = 'y';
    int num,i=0;
    system("cls");
    interface_table();
    while (flag!='n'&&flag!='N')
    {
        if (i > 0)
        {
            interface_table();
        }
        i++;
        cin >> num;
        switch (num)
        {
            case 1:this[0].report_Book(obj);
                break;
            case 2:this[0].report_Wholesale(obj);
                break;
            case 3:this[0].report_Retail(obj);
                break;
            case 4:this[0].report_Quantity(obj);
                break;
            case 5:this[0].report_Dateadd(obj);
                break;
            case 6:
                flag = 'n';
                break;
            default:
                cout << "你的输入有误，请重新输入！" << "\n" << "输入选择(1~6) :";
                break;
        }
    }
}


