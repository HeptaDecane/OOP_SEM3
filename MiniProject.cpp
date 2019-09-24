#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<fstream>
using namespace std;
class product{
	int pno;
	char name[50];
	float price,qty,tax,dis;
	public:
		void create_product()
		{
			cout<<"\nPlease Enter the product no. of the product ";
			cin>>pno;
			cout<<"\nPlease enter the name of the product ";
			cin>>name;
			cout<<"\nPlease enter the price of the product ";
			cin>>price;
			cout<<"\nPlease enter the discount(%) ";
			cin>>dis;
		}
		void show_product()
		{
			cout<<"\nThe Product no. of the product :" <<pno;
			cout<<"\nThe Name of the product : ";
			cout<<name;
			cout<<"\nThe price of the product :"<<price;
			cout<<"\nDiscount: "<<dis;
		}
		int retpno()
		{
			return pno;
		}
		float retprice(){
			return price;
		}
		char* retname()
		{
			return name;
		}
		int retdis(){
			return dis;
		}
};
fstream fp;
product pr;
void write_product()
{
	fp.open("Shop.dat",ios::out|ios::app);
	pr.create_product();
	fp.write((char*)&pr,sizeof(product));
	fp.close();
	cout<<"\n\nThe Product Has been Created";
}
void display_all()
{
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	fp.open("Shop.dat",ios::in);
	while(fp.read((char*)&pr,sizeof(product)))
	{
		pr.show_product();
		cout<<"\n\n================================\n";
	}
	fp.close();
}
void display_sp(int n)
{
	int flag=0;
	fp.open("Shop.dat",ios::in);
	while(fp.read((char*)&pr,sizeof(product)))
	{
		if(pr.retpno()==n)
		{
			pr.show_product();
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
	{
		cout<<"\n\nRecord not exist";
	}
}
void modify_product()
{
	int no,found=0;
	cout<<"\n\n\tTo Modify ";
	cout<<"\n\n\tPlease Enter The product no. of the product ";
	cin>>no;
	fp.open("Shop.dat",ios::in|ios::out);
	while(fp.read((char*)&pr,sizeof(product))&&found==0)
	{
		if(pr.retpno()==no)
		{
			pr.show_product();
			cout<<"\nPlease enter new details of the product";
			pr.create_product();
			int pos=-1*sizeof(pr);
			fp.seekg(pos,ios::cur);
			fp.write((char*)&pr,sizeof(product));
			cout<<"\n\n\t Record updated";
			found=1;
		}
	}
	fp.close();
	if(found==0)
	{
		cout<<"\n\n\ Record not found";
	}
	
}
void delete_product()
{
	int no;
	cout<<"\n\n\n\t Delete product";
	cout<<"\n\nPlease enter the product no. of the product you  want to delete";
	cin>>no;
	fp.open("Shop.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&pr,sizeof(product)))
	{
		if(pr.retpno()!=no)
		{
			fp2.write((char*)&pr,sizeof(product));
		}
	}
	fp2.close();
	fp.close();
	remove("Shop.dat");
	rename("Temp.dat","Shop.dat");
	cout<<"\n\n\tRecord Deleted.";
}
void menu()
{
	fp.open("Shop.dat",ios::in);
	if(!fp)
	{
		cout<<"ERROR!! FILE COULD NOT BE OPEN\n\n\nGO to admin menu to create file";
		cout<<"\n\n\nProgram is closing...";
		exit(0); 
	}
	cout<<"\n\n\tProduct MENU\n\n";
	cout<<"================================================================\n";
	cout<<"P.NO.\t\tNAME\t\tPRICE\n";
	cout<<"================================================================\n";
	while(fp.read((char*)&pr,sizeof(product)))
	{
		cout<<pr.retpno()<<"\t\t"<<pr.retname()<<"\t\t"<<pr.retprice()<<endl;
	}
	fp.close();
}
void place_order()
{
	int order_arr[50],quan[50],c=0;
	float amt,damt,total=0;
	char ch;
	menu();
	cout<<"\n==============================";
	cout<<"\nPlace your order";
	cout<<"\n==============================";
	do{
		cout<<"\n\nEnter The product no. of the product :";
		cin>>order_arr[c];
		cout<<"\nQuantity in number: ";
		cin>>quan[c];
		c++;
		cout<<"\nDo you want to order another product? (y/n)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	cout<<"\n\nThank You for Placing the order";
	cout<<"\n\n*************************************YOUR BILL****************************************\n";
	cout<<"\nPr no.\tPr Name\tQuantity\tPrice\tAmount\tAmount after discount\n";
	for(int x=0;x<=c;x++)
	{
		fp.open("Shop.dat",ios::in);
		fp.read((char*)&pr,sizeof(product));
		while(!fp.eof())
		{
			if(pr.retpno()==order_arr[x])
			{
				amt=pr.retprice()*quan[x];
				damt=amt-(amt*pr.retdis()/100);
				cout<<"\n"<<order_arr[x]<<"\t"<<pr.retname()<<"\t"<<quan[x]<<"\t\t"<<pr.retprice()<<"\t"<<amt<<"\t\t"<<damt;
				total+=damt;
			}
			fp.read((char*)&pr,sizeof(product));
		}
		fp.close();
	}
	cout<<"\n\n\tTOTAL = "<<total;
}
void intro()
{
	cout<<"SUPER MARKET\n";
	cout<<"BILLING PROJECT";
	cout<<"..WELCOME..";
}
void admin_menu()
{
	int n1;
	cout<<"\n\n\n\tADMIN MENU";
	cout<<"\n\n\t1.CREATE PRODUCT";
	cout<<"\n\n\t2.DISPLAY ALL PRODUCTS";
	cout<<"\n\n\t3.QUERY";
	cout<<"\n\n\t4.MODIFY PRODUCT";
	cout<<"\n\n\t5.DELETE PRODUCT";
	cout<<"\n\n\t6.VIEW PRODUCT MENU";
	cout<<"\n\n\t7.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease enter your choice(1-7)";
	cin>>n1;
	switch(n1){
		case 1:
			write_product();
			break;
		case 2:
			display_all();
			break;
		case 3:
			int num;
			cout<<"\n\n\tPlease Enter The Product No.";
			cin>>num;
			display_sp(num);
			break;
		case 4:
			modify_product();
			break;
		case 5:
			delete_product();
			break;
		case 6:
			menu();
		case 7:
			break;
		default:cout<<"\a";
		admin_menu();
	}
}
int main()
{
	int n;
	intro();
	do{
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. CUSTOMER";
		cout<<"\n\n\t02. ADMINISTRATION";
		cout<<"\n\n\t03. EXIT";
		cout<<"\n\n\tPlease Select Your Option(1-3)";
		cin>>n;
		switch(n){
			case 1:
				place_order();
				break;
			case 2:
				admin_menu();
				break;
			case 3:
				exit(0);
			default:
				cout<<"\a";
		}
	}while(n!=0);
}
