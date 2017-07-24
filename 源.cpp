#include<iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
static int sum = 0;

class Xinxi
{
protected:
	int number;//��Ʒ����
	string name;//��Ʒ����
	double inprice;//��Ʒ����
	int kucun;//��Ʒ���
public:
	Xinxi() 
	{
		number = 0;
		name = " ";
		inprice = 0;
		kucun = 0;
	}
	//�޲ι��캯��
	Xinxi(int a, string b, double c, int d)
	//�в����Ĺ��캯��
	{
		a = number;
		b = name;
		c = inprice;
		d = kucun;
	}
	~Xinxi() {};//��������
};
class Xiaoshou:public Xinxi//Xinxi��������࣬���м̳�
{
protected:
	double outprice;//��Ʒ�ۼ�
	int outkucun;//��Ʒ������
	int sykucun;//��Ʒʣ����
	int year, month, day;//������
	double getprice;//���۶�
	double syprice;//����
public:
	Xiaoshou() 
	{
		outprice = 0;
		outkucun = 0;
		sykucun = 0;
		year = 0;
		month = 0;
		getprice = 0;
		syprice = 0;
	}
	Xiaoshou(int a, char *b, double c, int d, double e, int f, int g, int h, int p,double q,double o) :Xinxi(a, b, c, d)
	{
		e = outprice;
		f = outkucun;
		g = year;
		h = month;
		p = day;
		q = getprice;
		o = syprice;
	}
	~Xiaoshou() {};//��������
	void record();//����ģ��
	void add();//����ģ��
	void del();//ɾ��ģ��
	void nchaxun();//��ѯģ��
	void mchaxun();//��ѯģ��
	void chakc();
	void display();
	void xiaoshoue();
	void xiaoli();
	void output();
};
Xiaoshou goods[100];//������ȫ�ֶ�������
void Xiaoshou::record()
{
	cout << "\t�������꣺";
	cin >> year;
	cout << "\t�������£�";
	cin >> month;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))//�ж���ƽ�껹������
	{
		if (month == 2)//����2����29��
		{
			day = 29;
		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)//1��3��5��7��8��10��12��31��
		{
			day = 31;
		}
		else
		{
			day = 30;
		}
	}
	else
	{
		if (month == 2)
		{
			day = 28;
		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			day = 31;
		}
		else
		{
			day = 30;
		}
	}
	day = 2;
	char c;
	int a=0;
	do//do...while����ѭ��������Ʒ��Ϣ
	{
		cout << "\t��������Ʒ��ţ�";
		cin >> goods[sum].number;
		cout << "\t��������Ʒ���ƣ�";
		cin >> goods[sum].name;
		cout << "\t��������Ʒ�����ۣ�";
		cin >> goods[sum].inprice;
		cout << "\t��������Ʒ�ۼۣ�";
		cin >> goods[sum].outprice;
		top:cout << "\t��������Ʒ��ʼ��棺";
		cin >> goods[sum].kucun;
		cout << "\t������ͳ�ƣ�" << endl;
		goods[sum].outkucun = 0;
		goods[sum].getprice = 0;
		goods[sum].syprice = 0;//��ʼ��Щ����
		for (int i = 1;i<=day;i++)
		{
			cout <<"\t"<< year << "��" << month << "��" << i << "�գ�";
			cin >> a;
			goods[sum].outkucun += a;//����������
			goods[sum].sykucun = goods[sum].kucun - goods[sum].outkucun;//����ʣ������
			if (goods[sum].sykucun < 0)
			{
				cout << "\t�������ݴ���ʣ��������С��0�����������룡" << endl;
				goto top;
			}
		}
		goods[sum].getprice = goods[sum].outkucun*goods[sum].outprice;//�������۶�
		goods[sum].syprice = goods[sum].getprice - goods[sum].outkucun*goods[sum].inprice;//��������
		cout<<"\t��Y��������N��������";
		cin>>c;
		sum++;
		cout << endl;
	} while (c == 'Y');
	cout << "\t������Ϣ������" << endl << endl << endl << endl << endl; 
	sum--;
}
void Xiaoshou::add()//������Ʒ��Ϣģ��
{
	cout << endl << endl << endl;
	int a=0;
	sum++;
	cout << "\t��������Ʒ��ţ�";
	cin >> goods[sum].number;
	cout << "\t��������Ʒ���ƣ�";
	cin >> goods[sum].name;
	cout << "\t��������Ʒ�����ۣ�";
	cin >> goods[sum].inprice;
	cout << "\t��������Ʒ�ۼۣ�";
	cin >> goods[sum].outprice;
	top2:cout << "\t��������Ʒ��ʼ��棺";
	cin >> goods[sum].kucun;
	cout << "\t������ͳ�ƣ�" << endl;
	goods[sum].outkucun = 0;
	goods[sum].getprice = 0;
	goods[sum].syprice = 0;
	for (int k = 1;k<=day;k++)
	{
		cout <<"\t"<< year << "��" << month << "��" << k << "�գ�";
		cin >> a;
		goods[sum].outkucun += a;
		goods[sum].sykucun = goods[sum].kucun - goods[sum].outkucun;
		if (goods[sum].sykucun < 0)
		{
			cout << "\t�������ݴ���ʣ��������С��0�����������룡"<<endl;
			goto top2;
		}
	}
	goods[sum].getprice = goods[sum].outkucun*goods[sum].outprice;
	goods[sum].syprice = goods[sum].getprice - goods[sum].outkucun*goods[sum].inprice;
	cout << endl;
}
void Xiaoshou::del()//ɾ����Ʒ��Ϣģ��
{
	cout<<endl<<endl<<endl;
	int num;
	int i, j = 1000, k = 10000;
	char c;
	cout<<"\t������Ҫɾ������Ʒ��ţ�";
	cin>>num;
	for(i = 0;i<=sum;i++)
	{
		if(goods[i].number==num)
		{
			j = i;
			k = i;
		}
	}
	if (j == k)
	{
		for (; j < sum; j++)
		{
			goods[j].number = goods[j + 1].number;
			goods[j].name = goods[j + 1].name;
			goods[j].inprice = goods[j + 1].inprice;
			goods[j].kucun = goods[j + 1].kucun;
			goods[j].outprice = goods[j + 1].outprice;
			goods[j].outkucun = goods[j + 1].outkucun;
			goods[j].sykucun = goods[j + 1].sykucun;
			goods[j].getprice = goods[j + 1].getprice;
			goods[j].syprice = goods[j + 1].syprice;
		}
		sum--;
		cout << "\t��Ҫɾ������Ϣ��ɾ��!!!" << endl;
	} 
	else
	{
		cout << "\tδ�ҵ���Ϣ���Ƿ�����������Ʒ��ţ�Y/N����";
		cin >> c;
		if (c == 'Y')
		{
			del();
		} 
	}
}
void Xiaoshou::nchaxun()//����Ʒ��Ų�ѯ��Ʒ��Ϣ
{
	cout<<endl<<endl<<endl;
	int num;
	cout<<"\t������Ҫ��ѯ����Ʒ��ţ�";
	cin>>num;
	int i, j = 1000, k = 10000;
	char c;
	for (i = 0; i <= sum; i++)
	{
		if (goods[i].number == num)
		{
			j = i;
			k = i;
		}
	}
	if (j == k)
	{
		cout << "\t��Ʒ���\t��Ʒ����\t��Ʒ������\t��Ʒ��ʼ���\t��Ʒ�ۼ�\t��Ʒ������\t��Ʒʣ����\n";
		cout << "\t" << setw(5) << goods[j].number ;
		cout << "\t\t" << setw(5) << goods[j].name ;
		cout << "\t\t" << setw(5) << goods[j].inprice ;
		cout << "\t\t" << setw(5) << goods[j].kucun ;
		cout << "\t\t" << setw(5) << goods[j].outprice ;
		cout << "\t\t" << setw(5) << goods[j].outkucun ;
		cout << "\t\t" << setw(5) << goods[j].sykucun << endl;
	}
	else
	{
		cout << "\tδ�ҵ���Ϣ���Ƿ�����������Ʒ��ţ�Y/N����";
		cin >> c;
		if (c == 'Y')
		{
			nchaxun();
		}
	}
}
void Xiaoshou::mchaxun()//����Ʒ���Ʋ�ѯ��Ʒ��Ϣ
{
	cout<<endl<<endl<<endl;
	string mname;
	cout<<"\t������Ҫ��ѯ����Ʒ���ƣ�";
	cin>>mname;
	int i, j = 1000, k = 10000;
	char c;
	for(i = 0;i<=sum;i++)
	{
		if(goods[i].name==mname)
		{
			j = i;
			k = i;
		}
	}
	if (j == k)
	{
		cout << "\t��Ʒ���\t��Ʒ����\t��Ʒ������\t��Ʒ��ʼ���\t��Ʒ�ۼ�\t��Ʒ������\t��Ʒʣ����\n";
		cout << "\t" << setw(5) << goods[j].number;
		cout << "\t\t" << setw(5) << goods[j].name;
		cout << "\t\t" << setw(5) << goods[j].inprice;
		cout << "\t\t" << setw(5) << goods[j].kucun;
		cout << "\t\t" << setw(5) << goods[j].outprice;
		cout << "\t\t" << setw(5) << goods[j].outkucun;
		cout << "\t\t" << setw(5) << goods[j].sykucun << endl;
	}
	else
	{
		cout << "\tδ�ҵ���Ϣ���Ƿ�����������Ʒ��ţ�Y/N����";
		cin >> c;
		if (c == 'Y')
		{
			mchaxun();
		}
	}
}
void Xiaoshou::chakc()//�Զ���ѯ���С�ڵ���10����Ʒ��Ϣ��
{
	cout<<endl<<endl<<endl;
	cout<<"\t�����<=10����Ʒ��"<<endl;
	int i, j = 1000, k = 10000;
	for (i = 0; i <= sum; i++)
	{
		if (goods[i].sykucun <= 10)
		{
			j = i;
			k = i;
		}
	}
	if (j == k)
	{
		cout << "\t��Ʒ���\t��Ʒ����\t��Ʒ������\t��Ʒʣ����\n";
		for (i = 0; i <= sum; i++)
		{
			if (goods[i].sykucun <= 10)
			{
				cout << "\t" << setw(5) << goods[i].number;
				cout << "\t\t" << setw(5) << goods[i].name;
				cout << "\t\t" << setw(5) << goods[i].inprice;
				cout << "\t\t" << setw(5) << goods[i].sykucun << endl;
			}
		}
	}
	else
	{
		cout << "\t������Ʒ�����㣬���貹����" << endl;
	}
}
void Xiaoshou::display()//��ʾ������Ʒ���۶��嵥
{
	cout<<endl<<endl<<endl;
	cout<<"\t��Ʒ���۶��嵥��"<<endl;
	cout << "\t��Ʒ���\t��Ʒ����\t��Ʒ������\t��Ʒ���۶�\n";
	for(int i = 0;i<=sum;i++)
	{
		cout<< "\t" << setw(5) <<goods[i].number;
		cout<< "\t\t" << setw(5) <<goods[i].name;
		cout<< "\t\t" << setw(5) <<goods[i].outkucun;
		cout<< "\t\t" << setw(5) <<goods[i].getprice;
		cout<<endl;
	}
}
Xiaoshou B;//����ȫ�ֱ���
void Xiaoshou::xiaoshoue()
{
	int l;
	cout<<endl<<endl<<endl;
	cout<<"\t���۶�����ǰʮ����Ʒ��"<<endl;
	for(int k = 1;k<=sum;k++)//ð������
	{
		for(int j = 0;j<=sum-k;j++)
		{
			if(goods[j].outkucun<goods[j+1].outkucun)
			{
				B.number = goods[j].number;
				B.name = goods[j].name;
				B.inprice = goods[j].inprice;
				B.kucun = goods[j].kucun;
				B.outprice = goods[j].outprice;
				B.outkucun = goods[j].outkucun;
				B.sykucun = goods[j].sykucun;
				B.getprice = goods[j].getprice;
				B.syprice = goods[j].syprice;
				goods[j].number = goods[j+1].number;
				goods[j].name=goods[j+1].name;
				goods[j].inprice=goods[j+1].inprice;
				goods[j].kucun=goods[j+1].kucun;
				goods[j].outprice=goods[j+1].outprice;
				goods[j].outkucun=goods[j+1].outkucun;
				goods[j].sykucun=goods[j+1].sykucun;
				goods[j].getprice=goods[j+1].getprice;
				goods[j].syprice=goods[j+1].syprice;
				goods[j+1].number = B.number;
				goods[j+1].name=B.name;
				goods[j+1].inprice=B.inprice;
				goods[j+1].kucun=B.kucun;
				goods[j+1].outprice=B.outprice;
				goods[j+1].outkucun=B.outkucun;
				goods[j+1].sykucun=B.sykucun;
				goods[j+1].getprice=B.getprice;
				goods[j+1].syprice=B.syprice;
			}
		}
	}
	cout << "\t��Ʒ���\t��Ʒ����\t��Ʒ������\t��Ʒ���۶�\n";
	if (sum<=10)
	{
		l = 10;
	} 
	else
	{
		l = sum;
	}
	for(int i = 0;i<l;i++)
	{
		cout<< "\t" << setw(5) <<goods[i].number;
		cout<< "\t\t" << setw(5) <<goods[i].name;
		cout<< "\t\t" << setw(5) <<goods[i].outkucun;
		cout<< "\t\t" << setw(5) <<goods[i].getprice<<endl;
	}
	ofstream outfile("���۶�ǰʮ����Ʒ.txt", ios::out);
	outfile << "***************" << year << "��" << month << "����Ʒ���۶�ǰʮ��ͳ�Ʊ�" << "***************\n";
	outfile << setw(20) <<"��Ʒ���"<< setw(20)<<"��Ʒ����" << setw(20) << "��Ʒ������" << setw(20) << "��Ʒ���۶�\n";
	for (int i = 0; i < l; i++)
	{
		outfile << setw(20) << goods[i].number;
		outfile << setw(20) << goods[i].name;
		outfile << setw(20) << goods[i].outkucun;
		outfile << setw(20) << goods[i].getprice << "\n";
	}
	outfile.close();
	cout << "\t�Ѵ�ӡ�����۶�ǰʮ����Ʒ.txt'!" << endl << endl;
}
void Xiaoshou::xiaoli()
{
	int l;
	cout<<endl<<endl<<endl;
	cout<<"\t��������ǰʮ����Ʒ��"<<endl;
	for(int k = 1;k<=sum;k++)
	{
		for(int j = 0;j<=sum-k;j++)
		{
			if(goods[j].syprice<goods[j+1].syprice)
			{
				B.number = goods[j].number;
				B.name = goods[j].name;
				B.inprice = goods[j].inprice;
				B.kucun = goods[j].kucun;
				B.outprice = goods[j].outprice;
				B.outkucun = goods[j].outkucun;
				B.sykucun = goods[j].sykucun;
				B.getprice = goods[j].getprice;
				B.syprice = goods[j].syprice;
				goods[j].number = goods[j + 1].number;
				goods[j].name = goods[j + 1].name;
				goods[j].inprice = goods[j + 1].inprice;
				goods[j].kucun = goods[j + 1].kucun;
				goods[j].outprice = goods[j + 1].outprice;
				goods[j].outkucun = goods[j + 1].outkucun;
				goods[j].sykucun = goods[j + 1].sykucun;
				goods[j].getprice = goods[j + 1].getprice;
				goods[j].syprice = goods[j + 1].syprice;
				goods[j + 1].number = B.number;
				goods[j + 1].name = B.name;
				goods[j + 1].inprice = B.inprice;
				goods[j + 1].kucun = B.kucun;
				goods[j + 1].outprice = B.outprice;
				goods[j + 1].outkucun = B.outkucun;
				goods[j + 1].sykucun = B.sykucun;
				goods[j + 1].getprice = B.getprice;
				goods[j + 1].syprice = B.syprice;
			}
		}
	}
	if (sum <= 10)
	{
		l = 10;
	}
	else
	{
		l = sum;
	}
	cout << "\t��Ʒ���\t��Ʒ����\t��Ʒ������\t��Ʒ�ۼ�\t��Ʒ������\t����\n";
	for(int i = 0;i<l;i++)
	{
		cout<<"\t"<<setw(5)<<goods[i].number;
		cout<< "\t\t" << setw(5) <<goods[i].name;
		cout<< "\t\t" << setw(5) <<goods[i].inprice;
		cout<< "\t\t" << setw(5) <<goods[i].outprice;
		cout<< "\t\t" << setw(5) <<goods[i].outkucun;
		cout<< "\t\t" << setw(5) <<goods[i].syprice;
		cout<<endl;
	}
	ofstream outfile("��������ǰʮ����Ʒ.txt", ios::out);
	outfile << "***************" << year << "��" << month << "����Ʒ��������ǰʮ��ͳ�Ʊ�" << "***************\n";
	outfile << setw(20) << "��Ʒ���" << setw(20) << "��Ʒ����" << setw(20) << "��Ʒ������" << setw(20) << "��Ʒ�ۼ�" << setw(20) << "��Ʒ������" << setw(20) << "����\n";
	for (int i = 0; i < l; i++)
	{
		outfile << setw(20) << goods[i].number;
		outfile << setw(20) << goods[i].name;
		outfile << setw(20) << goods[i].inprice;
		outfile << setw(20) << goods[i].outprice;
		outfile << setw(20) << goods[i].outkucun;
		outfile << setw(20) << goods[i].syprice<<"\n";
	}
	outfile.close();
	cout << "\t�Ѵ�ӡ����������ǰʮ����Ʒ.txt'!" << endl << endl;
}
void Xiaoshou::output()
{
	double allsyprice = 0;
	ofstream outfile("��Ʒ��Ϣ��.txt", ios::out);
	outfile << "**********************************" << year << "��" << month << "����Ʒ����ͳ�Ʊ�" << "**********************************\n";
	outfile << setw(20) << "��Ʒ���"<< setw(20)<<"��Ʒ����" << setw(20) << "��Ʒ������" << setw(20) << "��Ʒ��ʼ���" << setw(20) << "��Ʒ�ۼ�" << setw(20) << "��Ʒ������" << setw(20) << "��Ʒʣ����" << setw(20) << "���۶�" << setw(20) << "����\n";
	for (int i = 0;i<=sum;i++)
	{
		outfile << setw(20) << goods[i].number;
		outfile << setw(20) << goods[i].name;
		outfile << setw(20) << goods[i].inprice;
		outfile << setw(20) << goods[i].kucun;
		outfile << setw(20) << goods[i].outprice;
		outfile << setw(20) << goods[i].outkucun;
		outfile << setw(20) << goods[i].sykucun;
		outfile << setw(20) << goods[i].getprice;
		outfile << setw(20) << goods[i].syprice << "\n";
		allsyprice += goods[i].syprice;
	}
	outfile << "������Ϊ��" << allsyprice;
	outfile.close();
	cout << "\t�Ѵ�ӡ����Ʒ��Ϣ��.txt'!" << endl << endl;
}
Xiaoshou T;//����ȫ�ֱ���
int main()
{

	int a = 0;
	cout<<"\t****************************************************************"<<endl;
	cout<<"\t************************��Ʒ���۹���ϵͳ************************"<<endl;
	cout<<"\t****************************************************************"<<endl;
	cout<<"\t*                       1��������Ʒ��Ϣ                        *"<<endl;
	cout<<"\t*                       2��������Ʒ��Ϣ                        *"<<endl;
	cout<<"\t*                       3��ɾ����Ʒ��Ϣ                        *"<<endl;
	cout<<"\t*                       4������Ʒ��Ų�����Ʒ��Ϣ              *"<<endl;
	cout<<"\t*                       5������Ʒ���Ʋ�����Ʒ��Ϣ              *"<<endl;
	cout<<"\t*                       6����ʾ��Ʒ���۶���Ϣ                  *"<<endl;
	cout<<"\t*                       7����ʾ��Ʒ������ǰʮ                  *"<<endl;
	cout<<"\t*                       8����ʾ��Ʒ��������ǰʮ                *"<<endl;
	cout<<"\t*                       9����ӡtxt�ļ�                         *"<<endl;
	cout<<"\t*                       0���˳�                                *"<<endl;
	cout<<"\t****************************************************************"<<endl;
	cout<<"\t���������:";
	cin>>a;
	if(a==1)
	{
		T. record();
		T. chakc();
		main();
	}
	else if(a==2)
	{
		T. add();
		T. chakc();
		main();
	}
	else if(a==3)
	{
		T. del();
		main();
	}
	else if(a==4)
	{
		T.nchaxun();
		main();
	}
	else if(a==5)
	{
		T. mchaxun();
		main();
	}
	else if(a==6)
	{
		T. display();
		main();
	}
	else if(a==7)
	{
		T. xiaoshoue();
		main();
	}
	else if(a==8)
	{
		T. xiaoli();
		main();
	}
	else if(a==9)
	{
		T.output();
		main();
	}
	else if (a == 0)
	{
		T.output();
		T.xiaoshoue();
		T.xiaoli();
		return 0;
	}
	else
	{
		cout<<"\t������󣡣��������������룡"<<endl;
		main();
	}
	
}