# include <iostream>
# include <fstream> //文件的使用
# include <string.h>
#include<stdlib.h>
#include <conio.h>//用getch();
using namespace std;

class Supermarket //定义商品管理类
{
 public:
 char name[20];
 char Num[20];
 int Cnum;
 //进货总数
 int Mnum;
 //销售数目
 int Enum;
 //剩余库存数目
 double Price;
 //单价
 char Add[20];
 //产地
 double Sum;
 //销售额
 Supermarket * Next;

 void Input()
 {
 cout<<"\t\t请输入商品名：";
 cin>>name;
 cout<<"\t\t请输入商品编号：";
 cin>>Num;
 cout<<"\t\t请输入商品进货总数：";
 cin>>Cnum;
 cout<<"\t\t请输入商品销售数目：";
 cin>>Mnum;
 cout<<"\t\t请输入商品剩余库存数目：";
 cin>>Enum;
 cout<<"\t\t请输入商品产地：";
 cin>>Add;
 cout<<"\t\t请输入商品单价:";
 cin>>Price;
  Sum=Mnum*Price;
 }


 void ReadFile(istream & in)//文件指针
 {
	 cin>>name>>Num>>Cnum>>Mnum>>Enum>>Add>>Price>>Sum;
 }


 void Show() //显示模块
 {
 cout<<"商品名:"<<name<<endl
 <<"商品编号:"<<Num<<endl
 <<"进货总数:"<<Cnum<<endl
 <<"销售数目:"<<Mnum<<endl
 <<"剩余库存:"<<Enum<<endl
 <<"产地:"<<Add<<endl
 <<"单价:"<<Price<<endl
 <<"销售额:"<<Sum<<endl<<endl;
 }
 };


 class Supermarketmassage//定义管理系统各功能模块类

 { public:
   Supermarketmassage();
   ~Supermarketmassage();
   void ShowMenu();  //显示模块
   void Find();//查找模块
   void Save();
   void ModifyItem(); //修改模块
   void RemoveItem();   //删除模块

   int ListCount();   //void Average(); //统计模块

   void Display()  //显示
   {
   for(Supermarket * p=Head->Next;p!=End;p=p->Next)
   p->Show();
   cout<<"输入任意字符！继续……";
   getch();
   }


   void AddItem() //添加
   {
   End->Input();
   End->Next=new Supermarket;
   End=End->Next;
   cout<<"添加成功!"<<endl;
   cout<<"输入任意字符！继续……";
   getch();
   }


   private:
    Supermarket * Head,* End;
    ifstream in;
	ofstream out;

	Supermarket *FindItem(char * name) //按照姓名查找商品
	{
	for(Supermarket * p=Head;p->Next!=End;p=p->Next)//匹配成功则返回上一个 指针，不成功就返回空
	if(!strcmp(p->Next->name,name))
	return p;
	return NULL;
	}

	Supermarket *FindNum(char * Num)   //按照编号查找
	{
		for(Supermarket * p=Head;p->Next!=End;p=p->Next)//匹配成功则返回上一个指针，不成功就返回空
	    if(!strcmp(p->Next->Num,Num))
		return p;
	    return NULL;
	}

	Supermarket *FindAdd(char * Add)
       {
		for(Supermarket * p=Head;p->Next!=End;p=p->Next)//匹配成功则返回上一个 指针，不成就返回空
         if(!strcmp(p->Next->Add,Add))return p;
		 return NULL;
	}
};



   //构造函数
   Supermarketmassage::Supermarketmassage()
   {
	   Head=new Supermarket;
       Head->Next=new Supermarket;
   End=Head->Next;
   in.open("sort.txt");
   if(!in)
	   cout<<"这是一个新系统，无商品信息。请先输入。"<<endl;
   else
   {     while(in.eof())
   {       End->ReadFile(in);
   if(End->name[0]=='\0') break;
   End->Next=new Supermarket;
   End=End->Next;
   }
      cout<<"输入任意字符！继续……";
   getch();
   in.close();
   cout<<"\t\t读取商品信息成功!"<<endl;
   }
   }
   Supermarketmassage::~Supermarketmassage()
   {   Save();
   for(Supermarket * temp;Head->Next!=End;)
   {
	   temp=Head->Next;
   Head->Next=Head->Next->Next;
   delete temp;
   }
   delete Head,End;
   }

   void Supermarketmassage::ShowMenu()
   {cout<<"〒〒〒〒〒〒〒〒〒〒  ☆       商 品 管 理 系  统     ☆  〒〒〒〒〒〒〒〒〒〒"<<endl;
    cout<<"〒〒〒〒〒〒〒★★★★★         ★★★★★★★★       ★★★★★〒 〒〒〒〒〒〒"<<endl;
    cout<<"〒〒〒〒〒〒〒〒〒★  ☆          1.增加商品信息        ☆  ★〒〒〒 〒〒〒〒〒〒"<<endl;
    cout<<"〒〒〒〒〒〒〒〒〒★  ☆          2.显示商品信息        ☆  ★〒〒〒 〒〒〒〒〒〒"<<endl;
    cout<<"〒〒〒〒〒〒〒〒〒★  ☆          3.查找商品信息        ☆  ★〒〒〒 〒〒〒〒〒〒"<<endl;
    cout<<"〒〒〒〒〒〒〒〒〒★  ☆          4.删除商品信息        ☆  ★〒〒〒 〒〒〒〒〒〒"<<endl;
    cout<<"〒〒〒〒〒〒〒〒〒★  ☆          5.修改商品信息        ☆  ★〒〒〒 〒〒〒〒〒〒"<<endl;
    cout<<"〒〒〒〒〒〒〒〒〒★  ☆          0.保存文件退出        ☆  ★〒〒〒 〒〒〒〒〒〒"<<endl;
    cout<<"\n\t\t\n\t\t请选择：";  }


   void Supermarketmassage::Find()//查找模块
   {   char name[20] ,Num[10];
   int x;
   Supermarket * p=NULL;
   cout<<"\n\t\t*********************************\n";
   cout<<"\t\t※ 1.按商品的名称查找\n\t\t※ 2.按商品编号查找";
   cout<<"\n\t\t*********************************\n请选择：";
   cin>>x;
   switch(x)
   {       case 1:
   {        cout<<"\t\t请输入要查找的商品的名称：";
   cin>>name;
   if(p=FindItem(name))
   {           p->Next->Show();
   cout<<"输入任意字符！继续……";
   getch();
   }
   else
   {            cout<<"\t\t没有找到该商品信息！"<<'\n'<<endl;
   cout<<"输入任意字符！继续……";
   getch();
   }
   }break;
   case 2:
	   {        cout<<"\t\t请输入要查找的商品编号：";
	   cin>>Num;
	   if(p=FindNum(Num))
	   {          p->Next->Show();
	   cout<<"输入任意字符！继续……";
	   getch();
	   }
	   else
       {          cout<<"\t\t没有找到该编号的商品！"<<'\n'<<endl;
	   cout<<"输入任意字符！继续……";
       getch();
	   }
	   }
	   break;
   }
  }

  void Supermarketmassage::ModifyItem()    //修改信息
  {   char name[20];
  Supermarket* p=NULL;
  cout<<"\t\t请输入要修改的商品名:";
  cin>>name;
  if(p=FindItem(name))
  {
	  cout<<"\t\t已找到商品的信息，请输入新的信息!"<<endl;
  p->Next->Input();
  cout<<"修改成功！"<<endl;
  cout<<"输入任意字符！继续……";
  getch();
  }
  else
  {   cout<<"\t\t没有找到!"<<endl;
  cout<<"输入任意字符！继续……";
  getch();
  }  }


  void Supermarketmassage::RemoveItem()   // 删除信息
  {   char name[20];
  Supermarket * p=NULL,*temp=NULL;
  cout<<"\t\t请输入要删除的商品名:"<<endl;cin>>name;
  if(p=FindItem(name))
	{     temp=p->Next;
  p->Next=p->Next->Next;
  delete temp;
  cout<<"\t\t删除成功!"<<endl;
  cout<<"输入任意字符！继续……";
 getch();
 }
  else
  {     cout<<"\t\t没有找到!"<<endl;
  cout<<"输入任意字符！继续……";
 getch();
  }
  }



  //﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌统计﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
  int Supermarketmassage::ListCount()//统计当前链表的记录总数，返回一个整数
  {   if(! Head)
  return 0;
  int n=0;
  for(Supermarket * p=Head->Next;p!=End;p=p->Next)
  {
  n++;
  }
  return n;
 }





  //保存函数
  void Supermarketmassage::Save()

{   out.open("sort.txt");
  for(Supermarket *p=Head->Next;p!=End;p=p->Next)
	  out<<"商品名称:"<<p->name<<"\t\t"   <<"商品编号:"<<p->Num<<"\t\t"
      <<"进货总数:"<<p->Cnum<<"\t\t"            <<"销售数目:"<<p->Mnum<<"\t\t"
       <<"剩余库存:"<<p->Enum<<"\t\t"   <<"商品产地:"<<p->Add<<"\t\t"
         <<"商品单价:"<<p->Price<<"\t\t"    <<"销售额:"<<p->Sum<<'\n';
           out.close();
           }



 //主函数
  int main() {   int x,i=0;   bool quit=false;
  cout<<"\t\t§§§§§§§§§§§§§§§§§§§§§§§§§§"<<endl;
  for(i=0;i<3;i++)
 cout<<"\t\t◎\t\t\t\t\t\t  ◎"<<endl;
  cout<<"\t\t◎★★★★【  欢迎进入商品管理系统  】★★★★◎"<<endl;
  for(i=0;i<3;i++)
 cout<<"\t\t◎\t\t\t\t\t\t  ◎"<<endl;
  cout<<"\t\t§§§§§§§§§§§§§§§§§§§§§§§§§§\n"<<endl;
  Supermarketmassage Grade;
  cout<<"按任意键开始……";
  getch();

 while(!quit)

 {     system("cls");
 Grade.ShowMenu();
 cin>>x;
 switch(x)
 {      case 0:quit=true;break;
 case 1:Grade.AddItem();break;
 case 2:Grade.Display();break;

 case 3:Grade.Find();break;
 case 4:Grade.RemoveItem();break;
 case 5:Grade.ModifyItem();break;
  }
  }
 return 0;
  }

