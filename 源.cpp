#include<iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
static int sum = 0;

class Xinxi
{
protected:
	int number;//商品编码
	string name;//商品名称
	double inprice;//商品进价
	int kucun;//商品库存
public:
	Xinxi() 
	{
		number = 0;
		name = " ";
		inprice = 0;
		kucun = 0;
	}
	//无参构造函数
	Xinxi(int a, string b, double c, int d)
	//有参数的构造函数
	{
		a = number;
		b = name;
		c = inprice;
		d = kucun;
	}
	~Xinxi() {};//析构函数
};
class Xiaoshou:public Xinxi//Xinxi类的派生类，公有继承
{
protected:
	double outprice;//商品售价
	int outkucun;//商品销售量
	int sykucun;//商品剩余量
	int year, month, day;//年月日
	double getprice;//销售额
	double syprice;//利润
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
	~Xiaoshou() {};//类内声明
	void record();//输入模块
	void add();//增加模块
	void del();//删除模块
	void nchaxun();//查询模块
	void mchaxun();//查询模块
	void chakc();
	void display();
	void xiaoshoue();
	void xiaoli();
	void output();
};
Xiaoshou goods[100];//定义了全局对象数组
void Xiaoshou::record()
{
	cout << "\t请输入年：";
	cin >> year;
	cout << "\t请输入月：";
	cin >> month;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))//判断是平年还是闰年
	{
		if (month == 2)//闰年2月有29天
		{
			day = 29;
		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)//1、3、5、7、8、10、12月31天
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
	do//do...while（）循环输入商品信息
	{
		cout << "\t请输入商品编号：";
		cin >> goods[sum].number;
		cout << "\t请输入商品名称：";
		cin >> goods[sum].name;
		cout << "\t请输入商品进货价：";
		cin >> goods[sum].inprice;
		cout << "\t请输入商品售价：";
		cin >> goods[sum].outprice;
		top:cout << "\t请输入商品初始库存：";
		cin >> goods[sum].kucun;
		cout << "\t销售量统计：" << endl;
		goods[sum].outkucun = 0;
		goods[sum].getprice = 0;
		goods[sum].syprice = 0;//初始化些参数
		for (int i = 1;i<=day;i++)
		{
			cout <<"\t"<< year << "年" << month << "月" << i << "日：";
			cin >> a;
			goods[sum].outkucun += a;//计算销售量
			goods[sum].sykucun = goods[sum].kucun - goods[sum].outkucun;//计算剩余库存量
			if (goods[sum].sykucun < 0)
			{
				cout << "\t输入数据错误，剩余库存量已小于0，请重新输入！" << endl;
				goto top;
			}
		}
		goods[sum].getprice = goods[sum].outkucun*goods[sum].outprice;//计算销售额
		goods[sum].syprice = goods[sum].getprice - goods[sum].outkucun*goods[sum].inprice;//计算利润
		cout<<"\t按Y继续，按N结束）：";
		cin>>c;
		sum++;
		cout << endl;
	} while (c == 'Y');
	cout << "\t输入信息结束！" << endl << endl << endl << endl << endl; 
	sum--;
}
void Xiaoshou::add()//增加商品信息模块
{
	cout << endl << endl << endl;
	int a=0;
	sum++;
	cout << "\t请输入商品编号：";
	cin >> goods[sum].number;
	cout << "\t请输入商品名称：";
	cin >> goods[sum].name;
	cout << "\t请输入商品进货价：";
	cin >> goods[sum].inprice;
	cout << "\t请输入商品售价：";
	cin >> goods[sum].outprice;
	top2:cout << "\t请输入商品初始库存：";
	cin >> goods[sum].kucun;
	cout << "\t销售量统计：" << endl;
	goods[sum].outkucun = 0;
	goods[sum].getprice = 0;
	goods[sum].syprice = 0;
	for (int k = 1;k<=day;k++)
	{
		cout <<"\t"<< year << "年" << month << "月" << k << "日：";
		cin >> a;
		goods[sum].outkucun += a;
		goods[sum].sykucun = goods[sum].kucun - goods[sum].outkucun;
		if (goods[sum].sykucun < 0)
		{
			cout << "\t输入数据错误，剩余库存量已小于0，请重新输入！"<<endl;
			goto top2;
		}
	}
	goods[sum].getprice = goods[sum].outkucun*goods[sum].outprice;
	goods[sum].syprice = goods[sum].getprice - goods[sum].outkucun*goods[sum].inprice;
	cout << endl;
}
void Xiaoshou::del()//删除商品信息模块
{
	cout<<endl<<endl<<endl;
	int num;
	int i, j = 1000, k = 10000;
	char c;
	cout<<"\t请输入要删除的商品编号：";
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
		cout << "\t你要删除的信息已删除!!!" << endl;
	} 
	else
	{
		cout << "\t未找到信息！是否重新输入商品编号（Y/N）？";
		cin >> c;
		if (c == 'Y')
		{
			del();
		} 
	}
}
void Xiaoshou::nchaxun()//按商品编号查询商品信息
{
	cout<<endl<<endl<<endl;
	int num;
	cout<<"\t请输入要查询的商品编号：";
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
		cout << "\t商品编号\t商品名称\t商品进货价\t商品初始库存\t商品售价\t商品销售量\t商品剩余量\n";
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
		cout << "\t未找到信息！是否重新输入商品编号（Y/N）？";
		cin >> c;
		if (c == 'Y')
		{
			nchaxun();
		}
	}
}
void Xiaoshou::mchaxun()//按商品名称查询商品信息
{
	cout<<endl<<endl<<endl;
	string mname;
	cout<<"\t请输入要查询的商品名称：";
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
		cout << "\t商品编号\t商品名称\t商品进货价\t商品初始库存\t商品售价\t商品销售量\t商品剩余量\n";
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
		cout << "\t未找到信息！是否重新输入商品编号（Y/N）？";
		cin >> c;
		if (c == 'Y')
		{
			mchaxun();
		}
	}
}
void Xiaoshou::chakc()//自动查询库存小于等于10的商品信息，
{
	cout<<endl<<endl<<endl;
	cout<<"\t清查库存<=10的商品："<<endl;
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
		cout << "\t商品编号\t商品名称\t商品进货价\t商品剩余量\n";
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
		cout << "\t所有商品库存充足，无需补货！" << endl;
	}
}
void Xiaoshou::display()//显示所有商品销售额清单
{
	cout<<endl<<endl<<endl;
	cout<<"\t商品销售额清单："<<endl;
	cout << "\t商品编号\t商品名称\t商品销售量\t商品销售额\n";
	for(int i = 0;i<=sum;i++)
	{
		cout<< "\t" << setw(5) <<goods[i].number;
		cout<< "\t\t" << setw(5) <<goods[i].name;
		cout<< "\t\t" << setw(5) <<goods[i].outkucun;
		cout<< "\t\t" << setw(5) <<goods[i].getprice;
		cout<<endl;
	}
}
Xiaoshou B;//定义全局变量
void Xiaoshou::xiaoshoue()
{
	int l;
	cout<<endl<<endl<<endl;
	cout<<"\t销售额排名前十的商品："<<endl;
	for(int k = 1;k<=sum;k++)//冒泡排序
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
	cout << "\t商品编号\t商品名称\t商品销售量\t商品销售额\n";
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
	ofstream outfile("销售额前十的商品.txt", ios::out);
	outfile << "***************" << year << "年" << month << "月商品销售额前十的统计表" << "***************\n";
	outfile << setw(20) <<"商品编号"<< setw(20)<<"商品名称" << setw(20) << "商品销售量" << setw(20) << "商品销售额\n";
	for (int i = 0; i < l; i++)
	{
		outfile << setw(20) << goods[i].number;
		outfile << setw(20) << goods[i].name;
		outfile << setw(20) << goods[i].outkucun;
		outfile << setw(20) << goods[i].getprice << "\n";
	}
	outfile.close();
	cout << "\t已打印‘销售额前十的商品.txt'!" << endl << endl;
}
void Xiaoshou::xiaoli()
{
	int l;
	cout<<endl<<endl<<endl;
	cout<<"\t利润排名前十的商品："<<endl;
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
	cout << "\t商品编号\t商品名称\t商品进货价\t商品售价\t商品销售量\t利润\n";
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
	ofstream outfile("销售利润前十的商品.txt", ios::out);
	outfile << "***************" << year << "年" << month << "月商品销售利润前十的统计表" << "***************\n";
	outfile << setw(20) << "商品编号" << setw(20) << "商品名称" << setw(20) << "商品进货价" << setw(20) << "商品售价" << setw(20) << "商品销售量" << setw(20) << "利润\n";
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
	cout << "\t已打印‘销售利润前十的商品.txt'!" << endl << endl;
}
void Xiaoshou::output()
{
	double allsyprice = 0;
	ofstream outfile("商品信息表.txt", ios::out);
	outfile << "**********************************" << year << "年" << month << "月商品销售统计表" << "**********************************\n";
	outfile << setw(20) << "商品编号"<< setw(20)<<"商品名称" << setw(20) << "商品进货价" << setw(20) << "商品初始库存" << setw(20) << "商品售价" << setw(20) << "商品销售量" << setw(20) << "商品剩余量" << setw(20) << "销售额" << setw(20) << "利润\n";
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
	outfile << "总利润为：" << allsyprice;
	outfile.close();
	cout << "\t已打印‘商品信息表.txt'!" << endl << endl;
}
Xiaoshou T;//定义全局变量
int main()
{

	int a = 0;
	cout<<"\t****************************************************************"<<endl;
	cout<<"\t************************商品销售管理系统************************"<<endl;
	cout<<"\t****************************************************************"<<endl;
	cout<<"\t*                       1、输入商品信息                        *"<<endl;
	cout<<"\t*                       2、增加商品信息                        *"<<endl;
	cout<<"\t*                       3、删除商品信息                        *"<<endl;
	cout<<"\t*                       4、按商品编号查找商品信息              *"<<endl;
	cout<<"\t*                       5、按商品名称查找商品信息              *"<<endl;
	cout<<"\t*                       6、显示商品销售额信息                  *"<<endl;
	cout<<"\t*                       7、显示商品销售量前十                  *"<<endl;
	cout<<"\t*                       8、显示商品销售利润前十                *"<<endl;
	cout<<"\t*                       9、打印txt文件                         *"<<endl;
	cout<<"\t*                       0、退出                                *"<<endl;
	cout<<"\t****************************************************************"<<endl;
	cout<<"\t请输入序号:";
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
		cout<<"\t输入错误！！！！请重新输入！"<<endl;
		main();
	}
	
}