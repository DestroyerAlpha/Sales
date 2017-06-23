
//Simple File Handling Program for twelfth class CBSE Project to understand the basic file handling operations
//Language:c++
//Compiler:g++
//@author: Prakher Tayal


//-----------------------------------------------------------------------------------------

//Functionality
/*
	Manufacturer:
	1)New manufacturer can registor
	2)Can list its Products
	3)Can view its Products
	4)Can update its contents
	5)Can add new Products
	
	Distributor:
	1)New Distributor can Registor
	2)Can buy Products from Manufacturer
	3)Can view its stock
	
	Stock Details:
	1) User can view stock details of every Manufacturer
	2) User can view stock details of every Distributor

*/


//-----------------------------------------------------------------------------------------

//Header Files
#include<iostream>
//#include<conio.h> 
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
//#include<fstream.h>
#include<vector>
#include<string.h>
#include<bits/stdc++.h>
#include<iomanip>

using namespace std;

//prototypes of utility Functions
void controlling(void);
void centerify_output(string );

//global variables
//structure to record date
struct date
{
	int day;
	int month;
	int year;
}current_date;


char ch;
const char separator    = ' ';
const int nameWidth     = 25;
const int dateWidth     = 0;
const int manWidth	= 50;
const int disWidth	= 60;
const int manWidth2	= 35;

//template
template<typename T> void printElement(T t, const int& width)
{
    cout << left << setw(width) << setfill(separator) << t;
}

//class to show basic functioning of file imput/output
class product
{
	
	private:
	int pro_code;
	double pro_cost;
	double pro_quantity;
	char pro_name[30];
	date pro_date;
	protected:
	int n;
	public:
	product()
	{
		pro_code=0;
		pro_cost=0.0;
		pro_quantity=0;
		memset(pro_name,0,30);
	}
	void put();
	void get();
	void func();
	void putc(){
	
		cout<<"Enter Number of Products "<<endl;
		cin>>n;
		for(int i=0;i<n;i++)
			this->put();
	}
}; 

//baisc function to read out data from file
void product::get()
{
		fstream file;
		file.open("pro.dat",ios::in);
   		file.seekg(0,ios::beg);	
   		int f=0;
   		cout<<"Product Details are as follows"<<endl;
   		cout<<"------------------------------"<<endl<<endl;
		while(file.read((char *)this,sizeof(product)))
		{
			if(f==0)
			{
			printElement("Product Code",nameWidth);
			printElement("Product Name",nameWidth);
			printElement("Product Quantity",nameWidth);
			printElement("Product Cost",nameWidth);
			printElement("Product Date",nameWidth);
			cout<<endl<<endl;
			}
			printElement(pro_code,nameWidth);
			printElement(pro_name,nameWidth);
			printElement(pro_quantity,nameWidth);
			printElement(pro_cost,nameWidth);
			printElement(pro_date.day,dateWidth);cout<<"/";
			printElement(pro_date.month,dateWidth);cout<<"/";
			printElement(pro_date.year,dateWidth);
			cout<<endl<<endl;
			f++;
		}
		if(f==0)
		{
			cout<<"Sorry no product details available"<<endl;
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


//basic function to show the write data into a file
void product::put()
  {
   //clrscr();
   int valid=1;
   system ("clear");
   fstream file;
   cout<<"Enter New Product details"<<endl;
   cout<<"-------------------------"<<endl;
   cout<<"Enter Product Code:  "<<endl;
   cin>>pro_code;
   cout<<"Enter Product cost: "<<endl;
   cin>>pro_cost;
   cout<<"Enter Product Quantity: "<<endl;
   cin>>pro_quantity;
   while(valid!=0)
   {
   cout<<"Enter Current Date(dd/mm/yyyy): ";
   cin>>current_date.day>>ch>>current_date.month>>ch>>current_date.year;
   valid=((current_date.day<0)||(current_date.day>31)||(current_date.month>12)||(current_date.month<=0)||(current_date.year<1998));
   if(valid!=0)
   cout<<"Invalid date"<<endl;
   cout<<endl;
   }
   pro_date=current_date;
   cout<<"Enter Product Name: "<<endl;
   cin>>pro_name;
   cout<<"Thank you for entering details"<<endl;
   file.open("pro.dat",ios::out|ios::app);
// file.seekp(0,ios::beg);
   file.write((char *)this,sizeof(product));
   file.close();
  }

//utility function to control product controls
void product::func()
{
		 
		 string line[9]= {
		"------------------------------------------------------",
		"|                       Menu                         |",
		"|          1) To View product details                |",
		"|          2) To Enter Product details               |",
		"|          3) To Return back to Main Menu            |",
		"------------------------------------------------------",
	  	 };
	  	 
	  	for(int i=0;i<9;i++){
	    		centerify_output(line[i]);
	    		cout<<endl;
	    	}	
			
		int choice;
	  	cin>>choice;
	    	system("clear");
	    	switch(choice){
	    	
	    	case 1: this->get();
	    		break;
	    	case 2: this->putc();
	    		break;
	    	case 3: controlling();
	    		break;
	    	default: cout<<"You have entered wrong choice please re-enter"<<endl;
	    		break;	
	    	
	    	}
	    	func();		
	}



//class for manufacturer
//all function and data variables are made public;can be private
class manufacturer
{

	public:
	char man_name[20];
	char man_address[20];
	long long int man_number;
	int man_numberofproducts;
	struct man_pro{
		int pro_code;
		double pro_cost;
		double pro_quantity;
		date pro_date;
		char pro_name[30];
	};
	man_pro obj[10];//limiting the number of products
	void put();
	void get();
	void func();
	void update();
	void update2(manufacturer);
	void quantity();
	void add();
}man;

//function to show entry of variable number of products
void manufacturer::put(){

	//clrsrc();
	int n,valid=1;
	system("clear");
	fstream file;
	cout<<"Enter New Manufacturer details"<<endl;
	cout<<"Enter Manufacturer Name"<<endl;
	cin>>man_name;
	cout<<"Enter Manufacturer address"<<endl;
	cin>>man_address;
	cout<<"Enter Manufacturer Contact"<<endl;
	cin>>man_number;
	cout<<"Number of Products Manufacturer Holds"<<endl;
	cin>>man_numberofproducts;
	n=man_numberofproducts;
	int i=0;
	
	while(n--)
	{
	
		cout<<"Enter Product Details"<<endl;
		cout<<"Enter Product Code"<<endl;
		cin>>obj[i].pro_code;
		cout<<"Enter Product Cost"<<endl;
		cin>>obj[i].pro_cost;
		cout<<"Enter Product Quantity"<<endl;
		cin>>obj[i].pro_quantity;
		while(valid!=0)
		   {
		   cout<<"Enter Current Date(dd/mm/yyyy): ";
		   cin>>current_date.day>>ch>>current_date.month>>ch>>current_date.year;
		   valid=((current_date.day<0)||(current_date.day>31)||(current_date.month>12)||(current_date.month<=0)||(current_date.year<1998));
		   if(valid!=0)
		   cout<<"Invalid date"<<endl;
		   cout<<endl;
		   }
		   obj[i].pro_date=current_date;
		cout<<"Enter Product Name"<<endl;
		cin>>obj[i].pro_name;
		cout<<endl;
		cout<<"Thank you for entering details"<<endl<<endl;	
		i++;
		valid=1;
	}

  	 file.open("man.dat",ios::out|ios::app);
  	 file.write((char *)this,sizeof(manufacturer));
  	 file.close();
}
//basic function to retrieve data from man.dat file
void manufacturer::get()
{

		fstream file;
		file.open("man.dat",ios::in);
   		file.seekg(0,ios::beg);	
   		int f=0;
   		char name[30];
   		long long int number;
   		cout<<"Enter the Name of the Manufacturer"<<endl;
   		cin>>name;
   		cout<<"Enter contact Number of the Manufacturer"<<endl;
   		cin>>number;
		while(file.read((char *)this,sizeof(manufacturer)))
		{
			if(strcmp(man_name,name)==0&&number==man_number)
			{
				cout<<"Manufacturer Details are as follows"<<endl;
				printElement("Manufacturer Name",manWidth);
				printElement("Manufacturer Address",manWidth);
				printElement("Manufacturer Number",manWidth);
				cout<<endl<<endl;
				printElement(man_name,manWidth);
				printElement(man_address,manWidth);
				printElement(man_number,manWidth);
				cout<<endl<<endl;
				
				cout<<"Product details"<<endl<<endl;
				int i=0;
				printElement("Product Code",nameWidth);
				printElement("Product Name",nameWidth);
				printElement("Product Quantity",nameWidth);
				printElement("Product Cost",nameWidth);
				printElement("Product Date",nameWidth);
				cout<<endl<<endl;
				printElement(obj[i].pro_code,nameWidth);
				printElement(obj[i].pro_name,nameWidth);
				printElement(obj[i].pro_quantity,nameWidth);
				printElement(obj[i].pro_cost,nameWidth);
				printElement(obj[i].pro_date.day,dateWidth);cout<<"/";
				printElement(obj[i].pro_date.month,dateWidth);cout<<"/";
				printElement(obj[i].pro_date.year,dateWidth);
				cout<<endl<<endl;
				int n=man_numberofproducts-1;
				while(n--)
				{
					i++;
					
					printElement(obj[i].pro_code,nameWidth);
					printElement(obj[i].pro_name,nameWidth);
					printElement(obj[i].pro_quantity,nameWidth);
					printElement(obj[i].pro_cost,nameWidth);
					printElement(obj[i].pro_date.day,dateWidth);cout<<"/";
					printElement(obj[i].pro_date.month,dateWidth);cout<<"/";
					printElement(obj[i].pro_date.year,dateWidth);
					cout<<endl<<endl;
					
				}
			
				cout<<endl;
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
//basic function to show overwriting of data in a file
void manufacturer::update2(manufacturer temp)
{
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
   					
   					int products=man.man_numberofproducts;
   					int i=0;
   					while(products--)
   					{
   						
   						if(strcmp(man.obj[i].pro_name,temp.obj[0].pro_name)==0)
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
   					{
   						cout<<"Sorry No Product available with name "<<temp.obj[0].pro_name<<endl<<endl;
   					}
   					found2=1;
   				}
   				file.read((char*)&man,sizeof(man));
   				n=file.tellg();
   			
   		}
   		file.close();
   		if(found2==0)
   			{
   				cout<<"Sorry No Manufacturer available"<<endl<<endl;
   			}


}

//utility function
void manufacturer::quantity(){

	manufacturer temp;
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
//to add new data in a file :not appending
void manufacturer::add()
{
	int newproducts;
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
	//adding product to existing manufacturer
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
   					{	valid=1;
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
						   cout<<"Invalid date"<<endl;
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
   				cout<<"Sorry No Manufacturer available"<<endl<<endl;
   			}
	
}

//control function for manufacturer
void manufacturer::update()
{

	string line[9]= {
		"------------------------------------------------------",
		"|                       Menu                         |",
		"|          1) To add new product details             |",
		"|          2) To add quantity to existing product    |",
		"|          3) To Return back to Manufacturer Menu    |",
		"------------------------------------------------------",
	  	 };
	  	 
	  	for(int i=0;i<9;i++){
	    		centerify_output(line[i]);
	    		cout<<endl;
	    	}	
			
		int choice;
	  	cin>>choice;
	    	system("clear");
	    	
	    	switch(choice){
	    	
	    	case 1:  this->add();
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
//control function for manufacturer
void manufacturer::func()
{
		 
		 string line[9]= {
		"------------------------------------------------------",
		"|                       Menu                         |",
		"|          1) To View Manufacturer Stock details     |",
		"|          2) To Enter New Manufacturer details      |",
		"|          3) To Update details                      |",
		"|          4) To Return back to Main Menu            |",
		"------------------------------------------------------",
	  	 };
	  	 
	  	for(int i=0;i<9;i++){
	    		centerify_output(line[i]);
	    		cout<<endl;
	    	}	
			
		int choice;
	  	cin>>choice;
	    	system("clear");
	    	
	    	
	    	
	    	switch(choice){
	    	
	    	case 1: this->get();
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


//class for distributor

class distributor
{

	public:
	char dis_name[30];
	char dis_address[30];
	long long int dis_number;
	int numberofproducts;
	struct dis_pro{
	
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

//distributor functions

void distributor::buy()
{
	system("clear");
	char name[30],productname[30];
	int number,found=0;
	cout<<"Enter Distributor Name"<<endl;
	cin>>name;
	cout<<"Enter number"<<endl;
	cin>>number;
	cout<<"Checking For Distributor"<<endl;
	fstream file;
	file.open("dis.dat",ios::in);
	while(file.read((char*)this,sizeof(distributor)))
	{
	
		if((strcmp(name,dis_name)==0)&&(dis_number==number))
		found=1;
		if(found)
		{
			cout<<"Distributor Found"<<endl;
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
		fstream file2;
		file2.open("man.dat",ios::in);
		while(file2.read((char*)&man,sizeof(manufacturer)))
		{
			int n=man.man_numberofproducts;
			int i=0;
			while(n--)
			{
				if(strcmp(man.obj[i].pro_name,productname)==0)
				{
					printElement("Manufacturer Name",manWidth2);
					printElement("Product Name",manWidth2);
					printElement("Product Cost",manWidth2);
					printElement("Product Quantity(Stock)",manWidth2);
					cout<<endl;
					printElement(man.man_name,manWidth2);
					printElement(man.obj[i].pro_name,manWidth2);
					printElement(man.obj[i].pro_cost,manWidth2);
					printElement(man.obj[i].pro_quantity,manWidth2);
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
							        //sales can be done
								cout<<"Sales can be done"<<endl;
								man.obj[i].pro_quantity=man.obj[i].pro_quantity-productnumber;
								file3.seekp(num-sizeof(man),ios::beg);
								file3.write((char*)&man,sizeof(man));
								
								fstream file4;
								file4.open("dis.dat",ios::out | ios::in);
								file4.read((char*)&dis,sizeof(distributor));
								int mnum=file4.tellg();
								int productalreadyexists=0;
								while(!file4.eof())
								{
								
									if(strcmp(dis.dis_name,name)==0)
									{
										cout<<"Saving at distir "<<name<<endl;
										dis.obj[dis.numberofproducts].pro_code=man.obj[i].pro_code;
										
										dis.obj[dis.numberofproducts].pro_date=man.obj[i].pro_date;
										strcpy(dis.obj[dis.numberofproducts].pro_name,productname);
										cout<<"Enter the cost you want to quote this product"<<endl;
										cin>>dis.obj[dis.numberofproducts].pro_cost;
										//if already exists add to previous count
										//checking
										int j=0;
										int o=dis.numberofproducts;
										while(o--)
										{
											
											if(strcmp(dis.obj[j].pro_name,productname)==0)
											{
												//product already exist
												cout<<"Product already Exists"<<endl;
												dis.obj[j].pro_quantity=dis.obj[j].pro_quantity+productnumber;
												productalreadyexists=1;
											}	
											j++;
										} 
										if(productalreadyexists==0)
										{
										dis.obj[dis.numberofproducts].pro_quantity=productnumber;
										//if this product does not exist
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
			cout<<"Wrong Manufacturer"<<endl;
			file3.close();
		
		}
		else
		cout<<"Sorry this Product is not available with any manufacturer"<<endl;
	}
}

void distributor::get()
{
	system("clear");
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
   			
   			cout<<"Distributor Deatils are as follows"<<endl<<endl;
   			printElement("Distributor Name",disWidth);
   			printElement("Distributor Address",disWidth);
   			printElement("Distributor Number",disWidth);
   			cout<<endl;
   			
   			printElement(dis_name,disWidth);
   			printElement(dis_address,disWidth);
   			printElement(dis_number,disWidth);
   			cout<<endl<<endl;
   			cout<<"Product Details"<<endl;
   			int n = numberofproducts;
   			if(n==0)
   			cout<<"Sorry No Products are Available"<<endl;
   			int i=0;
   			while(n--)
   			{
   				if(i==0){
   				printElement("Product Code",nameWidth);
				printElement("Product Name",nameWidth);
				printElement("Product Quantity",nameWidth);
				printElement("Product Cost",nameWidth);
				printElement("Product Date",nameWidth);
				cout<<endl<<endl;}
				printElement(obj[i].pro_code,nameWidth);
				printElement(obj[i].pro_name,nameWidth);
				printElement(obj[i].pro_quantity,nameWidth);
				printElement(obj[i].pro_cost,nameWidth);
				printElement(obj[i].pro_date.day,dateWidth);cout<<"/";
				printElement(obj[i].pro_date.month,dateWidth);cout<<"/";
				printElement(obj[i].pro_date.year,dateWidth);
				i++;
				cout<<endl<<endl;
				
   			}
   		found2=1;	
   		}
   		if(found2)
   		break;
   		
   	}
   	if(found2==0)
   	cout<<"No Distributor Available"<<endl;
   	file.close();
   	cout<<"Press '1' for menu"<<endl;
		while(1)
		{
			cin>>f;
			if(f==1)
			return;
		}


}
void distributor::put()
{
	fstream file;
	system("clear");
	cout<<"Enter Distributor details"<<endl<<endl;
	cin>>dis_name;
	cout<<"Enter Distributor address"<<endl;
	cin>>dis_address;
	cout<<"Enter Distributor Number"<<endl;
	cin>>dis_number;
	numberofproducts=0;
	file.open("dis.dat",ios::out|ios::app);
  	file.write((char *)this,sizeof(distributor));
  	file.close();
  	cout<<"Distributor Enrolled Successfully"<<endl<<endl;
}

void distributor::func()
{
 string line[9]= {
		"------------------------------------------------------",
		"|                       Menu                         |",
		"|          1) To Enter New Distributor details       |",
		"|          2) To Buy Products from Manufacturer      |",
		"|          3) To view Distributor stock details      |",
		"|          4) To return back to main Menu            |",
		"------------------------------------------------------",
	    };
	    
	    cout<<endl;
	    
	    
	    for(int i=0;i<9;i++){
	    	centerify_output(line[i]);
	    	cout<<endl;
	    }
	    int choice;
	    cin>>choice;
	    
	    switch(choice){
	    	
	    	case 1: system("clear");
	    		this->put();
	    		break;
	    	case 2: system("clear");
	    		this->buy();
	    		break;
	    	case 3: system("clear");
	    		this->get();
	    		break;
	    	case 4: system("clear");
	    		controlling();
	    		break;
	    	default:cout<<"You have entered wrong choice please re-enter";
	    		break;
	    }
	    func();
	    
}


//utility functions

void centerify_output(string str) {
    // Calculate left padding
    //int padding_left = (num_cols / 2) - (str.size() / 2);
    int padding_left=45;
    // Put padding spaces
    for(int i = 0; i < padding_left; ++i) cout<<" ";

    // Print the message
    cout<<str;
}
void stock()
{
	int choice;
	cout<<"Enter 1) To check stock details of manufacturer and 2) To check stock details of Distributor"<<endl<<endl;
	cout<<"Enter 3) To go back"<<endl;
	cin>>choice;
	if(choice==3)
	{
	system("clear");
	controlling();
	}
	if(choice==1)
	{
		//print all manufacturer details
		manufacturer m;
		fstream file;
		file.open("man.dat",ios::in | ios::out);
		file.read((char *)&m,sizeof(manufacturer));
		cout<<"Stock Details Are"<<endl;
		while(!file.eof())
		{
			printElement("Manufacturer Name",manWidth);
			cout<<endl;
			printElement(m.man_name,manWidth);
			int n=m.man_numberofproducts;
			cout<<endl;
			int i=0;
			while(n--)
			{
				if(i==0)
				{
				printElement("Product Code",nameWidth);
				printElement("Product Name",nameWidth);
				printElement("Product Quantity",nameWidth);
				printElement("Product Cost",nameWidth);
				printElement("Product Date",nameWidth);
				cout<<endl<<endl;
				}
				printElement(m.obj[i].pro_code,nameWidth);
				printElement(m.obj[i].pro_name,nameWidth);
				printElement(m.obj[i].pro_quantity,nameWidth);
				printElement(m.obj[i].pro_cost,nameWidth);
				printElement(m.obj[i].pro_date.day,dateWidth);cout<<"/";
				printElement(m.obj[i].pro_date.month,dateWidth);cout<<"/";
				printElement(m.obj[i].pro_date.year,dateWidth);
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
		cout<<"Stock details are"<<endl;
		while(!file.eof())
		{
			cout<<"Distributor Name"<<endl;
			cout<<dis.dis_name<<endl;
			int i=0;
			int n=dis.numberofproducts;
			while(n--)
			{
				if(i==0){
   				printElement("Product Code",nameWidth);
				printElement("Product Name",nameWidth);
				printElement("Product Quantity",nameWidth);
				printElement("Product Cost",nameWidth);
				printElement("Product Date",nameWidth);
				cout<<endl<<endl;}
				printElement(dis.obj[i].pro_code,nameWidth);
				printElement(dis.obj[i].pro_name,nameWidth);
				printElement(dis.obj[i].pro_quantity,nameWidth);
				printElement(dis.obj[i].pro_cost,nameWidth);
				printElement(dis.obj[i].pro_date.day,dateWidth);cout<<"/";
				printElement(dis.obj[i].pro_date.month,dateWidth);cout<<"/";
				printElement(dis.obj[i].pro_date.year,dateWidth);
				i++;
				cout<<endl<<endl;		
			}
			file.read((char*)&dis,sizeof(dis));
		}
		file.close();
		
	}
	else
	cout<<"Wrong Choice"<<endl;
	stock();
	
}
void controlling(){
		
	        string line[8]= {
		"------------------------------------------------------",
		"|                       Menu                         |",
		"|          1) To view/enter product details          |",
		"|          2) To Manufacturer Menu                   |",
		"|          3) To Distributor Menu                    |",
		"|          4) To check stock details                 |",
		"|          5) To exit                                |",
		"------------------------------------------------------",
	    };
	    
	    cout<<endl;
	    
	    
	    for(int i=0;i<8;i++){
	    	centerify_output(line[i]);
	    	cout<<endl;
	    }
	    


	    product s1;
	    manufacturer s2;
	    distributor s3;
	    
	    int choice;
	    cin>>choice;
	    system("clear"); // for turbo C use clrscr();
	    
	    
	   
	    switch(choice){
	    
	    case 1: system("clear");
	    	    s1.func();
	    		break;
	    case 2: system("clear");
	    	    s2.func();
	    		break;
	    case 3: system("clear");
	    	    s3.func();
	    		break;
	    case 4: system("clear");
	    	    stock();
	    		break;
	    case 5: exit(0);
	    		break;
	    default: cout<<"You have entered wrong choice please re-enter";
	    }


}

//main function
int main()
{
	system("clear");
	while(1)
	    controlling();
// for turbo C use getch()
return 0;
}

