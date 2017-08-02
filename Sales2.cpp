#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream.h>
#include<iomanip.h>
void controlling(void);
void centrify_output(char [50]);
const int nameWidth =12;
const int disWidth  =20;
const int dateWidth = 0;
const int manWidth  =20;
const char separator=' ';
const int manWidth2 =20;
 
char ch;
struct date
{ int day;
  int month;
  int year;
}current_date;
 
 
class product
{ int pro_code;
  double pro_cost;
  double pro_quantity;
  char pro_name[30];
  date pro_date;
  int n;
  public:
  void put();
  void get();
  void func();
  void putcmy()
  { cout<<" Enter no of products "<<"\n";
    cin>>n;
    int i;
    for(i=0;i<n;i++)
    this->put();
  }
};
 
void product::put()
{ int valid=1;
  fstream file;
  cout<<" --------------------Enter New Product Details---------------"<<"\n";
  cout<<"-------------------------------------------------------------"<<"\n";
  cout<<" Enter Product Code : ";
  cin>>pro_code;
  cout<<" Enter Product Cost : ";
  cin>>pro_cost;
  cout<<" Enter Product Quantity : ";
  cin>>pro_quantity;
  while(valid!=0)
  {cout<<" Enter Current Date(dd/mm/yy): ";
   cin>>current_date.day>>ch>>current_date.month>>ch>>current_date.year;
   valid=((current_date.day<0)||(current_date.day>31)||(current_date.month>12)
   ||(current_date.month<=0)||(current_date.year<1998));
   if(valid!=0)
   cout<<" !!!!!! Invalid date ";
  }
  pro_date=current_date;
  cout<<" Enter Product Name :";
  cin>>pro_name;
  cout<<" --------------Thank you for entering details----------- ";
  file.open("pro.dat",ios::out|ios::app);
  file.write((char*)this,sizeof(product));
  file.close();
}
 
void product::get()
{ fstream file;
  file.open("pro.dat",ios::in);
  file.seekg(0,ios::beg);
  int f=0;
  cout<<" --------------Product Details Are As Follows-------------- "<<"\n";
  cout<<"------------------------------------------------------------"<<"\n"<<"\n";
  while(file.read((char*)this,sizeof(product)))
  {  if(f==0)
     { cout <<setw(nameWidth)<<setfill(separator)<<"Code ";
       cout<<setw(nameWidth)<<setfill(separator)<<"Name ";
       cout<<setw(nameWidth)<<setfill(separator)<<"Quantity ";
       cout<<setw(nameWidth)<<setfill(separator)<<"Cost";
       cout<<setw(nameWidth)<<setfill(separator)<<"Date";
       cout<<endl<<endl;
     }
     cout<<setw(nameWidth)<<setfill(separator)<<pro_code;
     cout<<setw(nameWidth)<<setfill(separator)<<pro_name;
     cout<<setw(nameWidth)<<setfill(separator)<<pro_quantity;
     cout<<setw(nameWidth)<<setfill(separator)<<pro_cost<<"    ";
     cout<<setw(dateWidth)<<setfill(separator)<<pro_date.day;
     cout<<"/";
     cout<<setw(dateWidth)<<setfill(separator)<<pro_date.month;
     cout<<"/";
     cout<<setw(dateWidth)<<setfill(separator)<<pro_date.year;
     cout<<endl<<endl;
     f++;
  }
  if(f==0)
  {
    cout<<"!!!!!!! Sorry No Product Details Are Available"<<"\n";
  }
  file.close();
  cout<<" Press 1 for menu "<<"\n";
  while(1)
  {
    cin>>f;
    if(f==1)
    return;
  }
}
 
void product::func()
{  clrscr();
   char line[6][50]=
   { "------------------------------------------------",
     "||                 Menu                        ||" ,
     "||       1)  To view produt  details           ||" ,
     "||       2)  To enter product details          ||" ,
     "||       3)  To return back to main menu       ||" ,
     "________________________________________________",
};
   int i;
   for(i=0;i<6;i++)
   { centrify_output(line[i]);
     cout<<endl;
   }
   int choice;
   cin>>choice;
   clrscr();
   switch(choice)
   { case 1: this->get();
     break;
     case 2: this->putcmy();
     break;
     case 3: controlling();
     break;
     default: cout<<" You have entered wrong choice please re-enter "<<"\n";
     break;
   }
   func();
}
 
class manufacturer
{
  public:
  char man_name[20];
  char man_address[20];
  long int man_number;
  int man_numberofproducts;
 
  struct man_pro
  { int pro_code;
    double pro_cost;
    double pro_quantity;
    date pro_date;
    char pro_name[20];
  }obj[10];
  void put();
  void get();
  void func();
  void update();
  void update2(manufacturer);
  void quantity();
  void add();
}man;
 
void manufacturer::put()
{
 int n,i=0,valid=1;
 clrscr();
 fstream file;
 cout<<"--------------Enter New Manufacturer details-----------"<<"\n";
 cout<<"-------------------------------------------------------"<<"\n";
 cout<<"Enter Manufacturer Name"<<"\n";
 cin>>man_name;
 cout<<"Enter Manufacturer address"<<"\n";
 cin>>man_address;
 cout<<"Enter Manufacturer Contact"<<"\n";
 cin>>man_number;
 cout<<"Number of Products Manufacturer Holds"<<"\n";
 cin>>man_numberofproducts;
 n=man_numberofproducts;
 while(n--)
 { cout<<"Enter Product Details"<<"\n";
   cout<<"Enter Product Code"<<"\n";
   cin>>obj[i].pro_code;
   cout<<"Enter Product Cost"<<"\n";
   cin>>obj[i].pro_cost;
   cout<<"Enter Product Quantity"<<"\n";
   cin>>obj[i].pro_quantity;
   while(valid!=0)
   {cout<<"Enter Current Date(dd/mm/yyyy): ";
    cin>>current_date.day>>ch>>current_date.month>>ch>>current_date.year;
    valid=((current_date.day<0)||(current_date.day>31)||(current_date.month>12)||(current_date.month<=0)||(current_date.year<1998));
    if(valid!=0)
    cout<<"!!!! Invalid date"<<endl;
    cout<<endl;
   }
   obj[i].pro_date=current_date;
   cout<<"Enter Product Name"<<endl;
   cin>>obj[i].pro_name;
   cout<<endl;
   cout<<"!!!!! Thank you for entering details"<<endl<<endl;
   i++;
   valid=1;
 }
 file.open("man.dat",ios::out|ios::app);
 file.write((char *)this,sizeof(manufacturer));
 file.close();
}
 
void manufacturer::get()
{ fstream file;
  file.open("man.dat",ios::in);
  file.seekg(0,ios::beg);
  int f=0;
  char name[30];
  int number;
  cout<<"Enter the name of the manufacturer "<<"\n";
  cin>>name;
  cout<<"Enter contact number of the manufacturer "<<"\n";
  cin>>number;
 
  while(file.read((char*)this,sizeof(manufacturer)))
  {
   if(strcmp(man_name,name)==0&&number==man_number)
   {
    clrscr();
    cout<<"---------- Manufacturer details are as follows---------"<<"\n";
    cout<<"--------------------------------------------------------"<<"\n"<<"\n";
    cout<<setw(manWidth)<<setfill(separator)<<"Manufacturer name        ";
    cout<<setw(manWidth)<<setfill(separator)<<"Manufacturer address    ";
    cout<<setw(manWidth)<<setfill(separator)<<"Manufacturer Number ";
    cout<<"\n"<<"\n";
    cout<<setw(manWidth)<<setfill(separator)<<man_name;
    cout<<setw(manWidth)<<setfill(separator)<<man_address;
    cout<<setw(manWidth)<<setfill(separator)<<man_number;
    cout<<"\n"<<"\n";
    cout<<" Product details "<<endl<<endl;
    int i=0;
    if(man_numberofproducts>=1)
    {
    cout<<setw(nameWidth)<<setfill(separator)<<"Product code";
    cout<<setw(nameWidth)<<setfill(separator)<<"Product name";
    cout<<setw(nameWidth)<<setfill(separator)<<"Product quantity";
    cout<<setw(nameWidth)<<setfill(separator)<<"Product Cost";
    cout<<setw(nameWidth)<<setfill(separator)<<"Product Date";
    cout<<endl<<endl;
    cout<<setw(nameWidth)<<setfill(separator)<<obj[i].pro_code;
    cout<<setw(nameWidth)<<setfill(separator)<<obj[i].pro_name;
    cout<<setw(nameWidth)<<setfill(separator)<<obj[i].pro_quantity;
    cout<<setw(nameWidth)<<setfill(separator)<<obj[i].pro_cost;
    cout<<setw(dateWidth)<<setfill(separator)<<obj[i].pro_date.day;
    cout<<"/";
    cout<<setw(dateWidth)<<setfill(separator)<<obj[i].pro_date.month;
    cout<<"/";
    cout<<setw(dateWidth)<<setfill(separator)<<obj[i].pro_date.year;
    cout<<endl<<endl;
    int n=man_numberofproducts-1;
    while(n--)
    {
     i++;
     cout<<setw(nameWidth)<<setfill(separator)<<obj[i].pro_code;
     cout<<setw(nameWidth)<<setfill(separator)<<obj[i].pro_name;
     cout<<setw(nameWidth)<<setfill(separator)<<obj[i].pro_quantity;
     cout<<setw(nameWidth)<<setfill(separator)<<obj[i].pro_cost;
     cout<<setw(dateWidth)<<setfill(separator)<<obj[i].pro_date.day;
     cout<<"/";
     cout<<setw(dateWidth)<<setfill(separator)<<obj[i].pro_date.month;
     cout<<"/";
     cout<<setw(dateWidth)<<setfill(separator)<<obj[i].pro_date.year;
     cout<<endl<<endl;
    }
    cout<<endl;}
    f++;
   }
  }
  if(f==0)
  {
   cout<<"Sorry no Manufacturer details available"<<endl;
  }
  file.close();
  cout<<"Press '1' for menu"<<endl;
  while(1)
  {
   cin>>f;
   if(f==1)
   return;
  }
}
 
void manufacturer::func()
{ clrscr();
  char line[7][50]=
  {
   "--------------------------------------------------",
   "|                   Menu                         |",
   "|      1) To View Manufacturer Stock details     |",
   "|      2) To Enter New Manufacturer details      |",
   "|      3) To Update details                      |",
   "|      4) To Return back to Main Menu            |",
   "--------------------------------------------------" };
  for(int i=0;i<7;i++)
  { centrify_output(line[i]);
    cout<<endl;
  }
  int choice;
  cin>>choice;
  clrscr();
  switch(choice)
  { case 1: this->get();
break;
    case 2: this->put();
break;
    case 3: this->update();
break;
    case 4: controlling();
break;
    default: cout<<"You have entered wrong choice please re-enter"<<endl;
break;
  }
  func();
}
 
void manufacturer::quantity()
{ manufacturer temp;
  cout<<"Enter the name of the manufacturer"<<endl;
  cin>>temp.man_name;
  cout<<"Enter the number of the mnufacturer"<<endl;
  cin>>temp.man_number;
  cout<<"Enter the Product Name to add more:quantity"<<endl;
  cin>>temp.obj[0].pro_name;
  cout<<"Enter number of products to add"<<endl;
  cin>>temp.obj[0].pro_quantity;
  update2(temp);
}
 
void manufacturer::add()
{ int newproducts;
  manufacturer temp;
  cout<<"Enter Manufacturer Name:"<<endl;
  cin>>temp.man_name;
  cout<<"Enter Manufacturer Contact Number:"<<endl;
  cin>>temp.man_number;
  cout<<"Enter number of products you want to add:"<<endl;
  cin>>newproducts;
  int saver=newproducts;
  int s=0;
  int found=0,valid=1;
  fstream file;
  file.open("man.dat",ios::in | ios:: out );
  file.seekg(0);
  int found1=0,found2=0;
  file.read((char*)&man,sizeof(man));
  int n=file.tellg();
  while(!file.eof())
  {
   if((strcmp(man.man_name,temp.man_name)==0)&&(man.man_number==temp.man_number))
   {
    while(newproducts--)
    {valid=1;
     cout<<"Enter Details of next product"<<endl<<endl;
     cout<<"Enter Product Code"<<endl;
     cin>>man.obj[man.man_numberofproducts+s].pro_code;
     cout<<"Enter Product name"<<endl;
     cin>>man.obj[man.man_numberofproducts+s].pro_name;
     cout<<"Enter Product cost"<<endl;
     cin>>man.obj[man.man_numberofproducts+s].pro_cost;
     cout<<"Enter Product Quantity"<<endl;
     cin>>man.obj[man.man_numberofproducts+s].pro_quantity;
     while(valid!=0)
     {
      cout<<"Enter Current Date(dd/mm/yyyy): ";
      cin>>current_date.day>>ch>>current_date.month>>ch>>current_date.year;
      valid=((current_date.day<0)||(current_date.day>31)||(current_date.month>12)||(current_date.month<=0)||(current_date.year<1998));
      if(valid!=0)
      cout<<"!!!! Invalid date"<<endl;
      cout<<endl;
     }
     man.obj[man.man_numberofproducts+s].pro_date=current_date;
     s++;
   }
   found=1;
   man.man_numberofproducts=man.man_numberofproducts+saver;
   file.seekp(n-sizeof(man),ios::beg);
   file.write((char*)&man,sizeof(man));
  }
  if(found)
  break;
  file.read((char*)&man,sizeof(man));
  n=file.tellg();
 }
 file.close();
 if(found==0)
 {
  cout<<"!!! Sorry No Manufacturer available"<<endl<<endl;
 }
}
 
void manufacturer::update()
{ clrscr();
  char line[6][50]=
  { "------------------------------------------------",
    "|                 Menu                         |",
    "|    1) To add new product details             |",
    "|    2) To add quantity to existing product    |",
    "|    3) To Return back to Manufacturer Menu    |",
    "------------------------------------------------",
  };
  for(int i=0;i<6;i++)
  {
   centrify_output(line[i]);
   cout<<endl;
  }
  int choice;
  cin>>choice;
  clrscr();
  switch(choice)
  { case 1:  this->add();
break;
    case 2:  this->quantity();
break;
    case 3:  this->func();
break;
    default:cout<<"You have entered wrong choice please re-enter"<<endl;
break;
  }
  update();
}
 
void manufacturer::update2(manufacturer temp)
{ fstream file;
  file.open("man.dat",ios::in | ios:: out );
  file.seekg(0);
  int found1=0,found2=0;
  file.read((char*)&man,sizeof(man));
  int n=file.tellg();
  while(!file.eof())
  {
   if((strcmp(man.man_name,temp.man_name)==0)&&
      (man.man_number==temp.man_number))
   {
    int products=man.man_numberofproducts;
    int i=0;
    while(products--)
    {if(strcmp(man.obj[i].pro_name,temp.obj[0].pro_name)==0)
     {
      man.obj[i].pro_quantity=temp.obj[0].pro_quantity+man.obj[i].pro_quantity;
      file.seekp(n-sizeof(man),ios::beg);
      file.write((char*)&man,sizeof(man));
      found1=1;
     }
     i++;
     if(found1)
     break;
    }
    if(found1==0)
    { cout<<"Sorry No Product available with name "<<temp.obj[0].pro_name<<endl<<endl;
    }
    found2=1;
   }
   file.read((char*)&man,sizeof(man));
   n=file.tellg();
  }
  file.close();
  if(found2==0)
  {
  cout<<"!!!!!!!! Sorry No Manufacturer available"<<endl<<endl;
  }
}
 
class distributor
{ public:
  char dis_name[30];
  char dis_address[30];
  long long int dis_number;
  int numberofproducts;
  struct dis_pro
  {
   int pro_code;
   double pro_cost;
   double pro_quantity;
   date pro_date;
   char pro_name[30];
  };
  dis_pro obj[10];
  void func();
  void put();
  void buy();
  void get();
}dis;
 
void distributor::buy()
{ clrscr();
  char name[30],productname[30];
  int number,found=0;
  cout<<"Enter Distributor Name"<<endl;
  cin>>name;
  cout<<"Enter number"<<endl;
  cin>>number;
  cout<<"Checking For Distributor............"<<endl;
  fstream file;
  file.open("dis.dat",ios::in);
  while(file.read((char*)this,sizeof(distributor)))
  {
   if((strcmp(name,dis_name)==0)&&(dis_number==number))
   found=1;
   if(found)
   {
    cout<<"!!!!!!!! Distributor Found"<<endl;
    break;
   }
  }
  file.close();
  if(found==0)
  {
   cout<<"Sorry No Distributor with such details is available"<<endl;
   return;
  }
  if(found)
  {
   int manfound=0;
   cout<<"Enter the Product Name to buy"<<endl;
   cin>>productname;
   //give list of manufacturer with their names and product cost
   fstream file2;
   file2.open("man.dat",ios::in);
   while(file2.read((char*)&man,sizeof(manufacturer)))
   {
    int n=man.man_numberofproducts;
    int i=0;
    while(n--)
    {
     if(strcmp(man.obj[i].pro_name,productname)==0)
     {cout<<setw(manWidth2)<<setfill(separator)<<"Manufacturer Name    ";
      cout<<setw(manWidth2)<<setfill(separator)<<"product cost      ";
      cout<<setw(manWidth2)<<setfill(separator)<<"product quantity(stock)";
      cout<<endl;
      cout<<setw(manWidth2)<<setfill(separator)<<man.man_name;
      cout<<setw(manWidth2)<<setfill(separator)<<man.obj[i].pro_name;
      cout<<setw(manWidth2)<<setfill(separator)<<man.obj[i].pro_cost;
      cout<<setw(manWidth2)<<setfill(separator)<<man.obj[i].pro_quantity;
      cout<<endl;
      manfound=1;
     }
     i++;
    }
   }
   file2.close();
   if(manfound)
   {
    char manname[30];
    int productnumber,manfound2=0;
    cout<<"Enter the Manufacturer to buy "<<productname<<endl;
    cin>>manname;
    cout<<"Enter the Number of Products you want to buy"<<endl;
    cin>>productnumber;
    fstream file3;
    file3.open("man.dat",ios::in | ios::out);
    file3.seekg(0);
    int num;
    while(file3.read((char*)&man,sizeof(manufacturer)))
    {
     num=file3.tellg();
     if(strcmp(man.man_name,manname)==0)
     {
      int m=man.man_numberofproducts;
      int i=0;
      while(m--)
      {
       if(strcmp(man.obj[i].pro_name,productname)==0)
       {
if(man.obj[i].pro_quantity>=productnumber)
{
cout<<"Sales can be done !!!!!!!!!!"<<endl;
man.obj[i].pro_quantity=man.obj[i].pro_quantity-productnumber;
file3.seekp(num-sizeof(man),ios::beg);
file3.write((char*)&man,sizeof(man));
fstream file4;
file4.open("dis.dat",ios::out | ios::in);
file4.read((char*)&dis,sizeof(distributor));
int mnum=file4.tellg();
int productalreadyexists=0;
while(!file4.eof())
{ if(strcmp(dis.dis_name,name)==0)
 {
  cout<<"Saving at distiributor.......... "<<name<<endl;
  dis.obj[dis.numberofproducts].pro_code=man.obj[i].pro_code;
  dis.obj[dis.numberofproducts].pro_date=man.obj[i].pro_date;
  strcpy(dis.obj[dis.numberofproducts].pro_name,productname);
  cout<<"Enter the cost you want to quote this product"<<endl;
  cin>>dis.obj[dis.numberofproducts].pro_cost;
  int j=0;
  int o=dis.numberofproducts;
  while(o--)
  {
   if(strcmp(dis.obj[j].pro_name,productname)==0)
   {
    cout<<"Product already Exists"<<endl;
    dis.obj[j].pro_quantity=dis.obj[j].pro_quantity+productnumber;
    productalreadyexists=1;
   }
   j++;
  }
  if(productalreadyexists==0)
  {
   dis.obj[dis.numberofproducts].pro_quantity=productnumber;
   dis.numberofproducts++;
  }
  file4.seekp(mnum-sizeof(dis));
  file4.write((char*)&dis,sizeof(dis));
 }
 file4.read((char*)&dis,sizeof(distributor));
 mnum=file4.tellg();
}
file4.close();
}
else
{
cout<<"Sorry this much amount is not available"<<endl;
cout<<man.man_name<<" have ony "<<man.obj[i].pro_quantity<<" of "<<productname<<endl;
}
       }
       i++;
      }
      manfound2=1;
     }
     num=file3.tellg();
    }
    if(manfound2!=1)
    cout<<"!!!!!! Wrong Manufacturer"<<endl;
    file3.close();
   }
   else
   cout<<"!!!! Sorry this Product is not available with any manufacturer"<<"\n";
  }
}
 
void distributor::put()
{ fstream file;
  clrscr();
  cout<<"------------Enter Distributor details-----------"<<"\n";
  cout<<"Enter Distributor Name ";
  cin>>dis_name;
  cout<<"Enter Distributor address"<<"\n";
  cin>>dis_address;
  cout<<"Enter Distributor Number"<<"\n";
  cin>>dis_number;
  numberofproducts=0;
  file.open("dis.dat",ios::out|ios::app);
  file.write((char *)this,sizeof(distributor));
  file.close();
  cout<<"!!!!!! Distributor Enrolled Successfully"<<endl<<endl;
}
 
void distributor::func()
{  clrscr();
 char line[7][50]=
 {  "--------------------------------------------------",
    "|                       Menu                     |",
    "|      1) To Enter New Distributor details       |",
    "|      2) To Buy Products from Manufacturer      |",
    "|      3) To view Distributor stock details      |",
    "|      4) To return back to main Menu            |",
    "--------------------------------------------------",
 };
 cout<<endl;
 for(int i=0;i<7;i++)
 { centrify_output(line[i]);
   cout<<endl;
 }
 int choice;
 cin>>choice;
 switch(choice)
 { case 1: clrscr();
  this->put();
  break;
   case 2: clrscr();
  this->buy();
  break;
   case 3: clrscr();
  this->get();
  break;
   case 4: clrscr();
  controlling();
  break;
   default:cout<<"You have entered wrong choice please re-enter";
  break;
 }
 func();
}
 
void distributor::get()
{ clrscr();
  char name[30];
  int number;
  fstream file;
  file.open("dis.dat",ios::in);
  file.seekg(0,ios::beg);
  cout<<"Enter the Distributor Name"<<endl;
  cin>>name;
  cout<<"Enter number"<<endl;
  cin>>number;
  int found2=0,f;
  while(file.read((char*)this,sizeof(distributor)))
  {
   if((strcmp(name,dis_name)==0)&&(dis_number==number))
   {
    cout<<"----------Distributor Details are as follows--------"<<endl;
    cout<<"-------------------------------------------------"<<endl<<endl;
    cout<<setw(disWidth)<<setfill(separator)<<"Distributor Name            ";
    cout<<setw(disWidth)<<setfill(separator)<<"Distributor Address         ";
    cout<<setw(disWidth)<<setfill(separator)<<"distributor number          ";
    cout<<endl;
    cout<<setw(disWidth)<<setfill(separator)<<dis_name;
    cout<<setw(disWidth)<<setfill(separator)<<dis_address;
    cout<<setw(disWidth)<<setfill(separator)<<dis_number;
    cout<<endl<<endl;
    cout<<"--------------Product Details----------"<<endl;
    int n = numberofproducts;
    if(n==0)
    cout<<"!!!!!!! Sorry No Products are Available"<<endl;
    int i=0;
    while(n--)
    {
     if(i==0)
     {
       cout<<setw(nameWidth)<<setfill(separator)<<"Product Code ";
       cout<<setw(nameWidth)<<setfill(separator)<<"Product Name";
       cout<<setw(nameWidth)<<setfill(separator)<<"Product Quantity";
       cout<<setw(nameWidth)<<setfill(separator)<<"Product cost";
       cout<<setw(nameWidth)<<setfill(separator)<<"Product date";
       cout<<endl<<endl;
       cout<<setw(nameWidth)<<setfill(separator)<<obj[i].pro_name;
       cout<<setw(nameWidth)<<setfill(separator)<<obj[i].pro_cost;
       cout<<setw(dateWidth)<<setfill(separator)<<obj[i].pro_date.day;
       cout<<"/";
       cout<<setw(dateWidth)<<setfill(separator)<<obj[i].pro_date.month;
       cout<<"/";
       cout<<setw(dateWidth)<<setfill(separator)<<obj[i].pro_date.year;
       i++;
       cout<<endl<<endl;
     }
     found2=1;
    }
   if(found2)
   break;
   }
   }
  if(found2==0)
  cout<<"!!!!!!!! No Distributor Available"<<endl;
  file.close();
  cout<<"Press '1' for menu"<<endl;
  while(1)
  {
  cin>>f;
  if(f==1)
  return;
  }
 
}
 
void centrify_output(char str[50])
{
 int padding_left=15;
 for(int i = 0; i < padding_left; ++i)
 { cout<<" ";
 }
 for(int j=0;j<50;j++)
 cout<<str[j];
}
 
void stock()
{// clrscr();
  int choice;
  cout<<"Enter 1) To check stock details of manufacturer and"<<endl;
  cout<<"Enter 2) To check stock details of Distributor"<<endl;
  cout<<"Enter 3) To go back"<<endl;
  cin>>choice;
  if(choice==3)
  {
   clrscr();
   controlling();
  }
  if(choice==1)
  {
   manufacturer m;
   fstream file;
   file.open("man.dat",ios::in | ios::out);
   file.read((char *)&m,sizeof(manufacturer));
   cout<<"-----------------Stock Details Are-----------------"<<endl;
   while(!file.eof())
   {
    cout<<setw(manWidth)<<setfill(separator)<<"Manufacturer Name ";
    cout<<endl;
    cout<<setw(manWidth)<<setfill(separator)<<m.man_name;
    int n=m.man_numberofproducts;
    cout<<endl;
    int i=0;
    while(n--)
    {
     if(i==0)
     {
      cout<<setw(nameWidth)<<setfill(separator)<<"Product code";
      cout<<setw(nameWidth)<<setfill(separator)<<"Product name";
      cout<<setw(nameWidth)<<setfill(separator)<<"Product Quantity";
      cout<<setw(nameWidth)<<setfill(separator)<<"Product Cost";
      cout<<setw(nameWidth)<<setfill(separator)<<"Product date ";
      cout<<endl<<endl;
     }
     cout<<setw(nameWidth)<<setfill(separator)<<m.obj[i].pro_code;
     cout<<setw(nameWidth)<<setfill(separator)<<m.obj[i].pro_name;
     cout<<setw(nameWidth)<<setfill(separator)<<m.obj[i].pro_quantity;
     cout<<setw(nameWidth)<<setfill(separator)<<m.obj[i].pro_cost;
     cout<<setw(dateWidth)<<setfill(separator)<<m.obj[i].pro_date.day;
     cout<<"/";
     cout<<setw(dateWidth)<<setfill(separator)<<m.obj[i].pro_date.month;
     cout<<"/";
     cout<<setw(dateWidth)<<setfill(separator)<<m.obj[i].pro_date.year;
     cout<<endl<<endl;
     i++;
    }
    file.read((char *)&m,sizeof(manufacturer));
   }
   file.close();
  }
  else if (choice==2)
  {
   //print all distributor details
   fstream file;
   file.open("dis.dat",ios::in | ios::out);
   file.read((char*)&dis,sizeof(dis));
   cout<<"----------Stock details are-----------"<<endl;
   while(!file.eof())
   {
    cout<<"Distributor Name "<<endl;
    cout<<dis.dis_name<<endl;
    int i=0;
    int n=dis.numberofproducts;
    while(n--)
    {
     if(i==0)
     {
      cout<<setw(nameWidth)<<setfill(separator)<<"Product code";
      cout<<setw(nameWidth)<<setfill(separator)<<"Product name";
      cout<<setw(nameWidth)<<setfill(separator)<<"Product quantity";
      cout<<setw(nameWidth)<<setfill(separator)<<"Product cost";
      cout<<setw(nameWidth)<<setfill(separator)<<"Product date";
      cout<<endl<<endl;}
      cout<<setw(nameWidth)<<setfill(separator)<<dis.obj[i].pro_code;
      cout<<setw(nameWidth)<<setfill(separator)<<dis.obj[i].pro_name;
      cout<<setw(nameWidth)<<setfill(separator)<<dis.obj[i].pro_quantity;
      cout<<setw(nameWidth)<<setfill(separator)<<dis.obj[i].pro_cost;
      cout<<setw(dateWidth)<<setfill(separator)<<dis.obj[i].pro_date.day;
      cout<<"/";
      cout<<setw(dateWidth)<<setfill(separator)<<dis.obj[i].pro_date.month;
      cout<<"/";
      cout<<setw(dateWidth)<<setfill(separator)<<dis.obj[i].pro_date.year;
      i++;
      cout<<endl<<endl;
     }
     file.read((char*)&dis,sizeof(dis));
    }
    file.close();
  }
  else
  cout<<"!!!!! Wrong Choice"<<endl;
  stock();
}
 
void controlling()
{
  clrscr();
  char line[8][50]=
  {
"--------------------------------------------------",
"|                   Menu                         |",
"|      1) To view/enter product details          |",
"|      2) To Manufacturer Menu                   |",
"|      3) To Distributor Menu                    |",
"|      4) To check stock details                 |",
"|      5) To exit                                |",
"--------------------------------------------------",
  };
  cout<<"\n";
  for(int i=0;i<8;i++)
  {
   centrify_output(line[i]);
   cout<<"\n";
  }
  product s1;
  manufacturer s2;
  distributor s3;
  int choice;
  cin>>choice;
  clrscr();
  switch(choice)
  { case 1: clrscr();
   s1.func();
   break;
    case 2: clrscr();
   s2.func();
   break;
    case 3: clrscr();
   s3.func();
   break;
    case 4: clrscr();
   stock();
   break;
   case 5: exit(0);
   break;
   default: cout<<"You have entered wrong choice please re-enter";
  }
}
 
int main()
{ clrscr();
  while(1)
  controlling();
  getch();
  return 0;
}
