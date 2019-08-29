//============================================================================
// Name        : Complex.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Complex{
	float real, img;
	public:
	Complex(){
		real=0;
		img=0;
	}
	void setData(float a,float b);
	void display();
	void menu();
	Complex operator +(Complex &c);
	Complex operator -(Complex &c);
	Complex operator *(Complex &c);
	Complex operator /(Complex &c);
};
void Complex::menu(){
	cout<<"--------COMPLEX NUMBER OPERATIONS----------"<<endl;
	cout<<"Press + for Sum"<<endl;
	cout<<"Press - for Difference"<<endl;
	cout<<"Press * for Product"<<endl;
	cout<<"Press / for Quotient"<<endl<<endl;
}
void Complex::setData(float a,float b){
	real=a;
	img=b;
}
void Complex::display(){
	if(img>=0)
		cout<<"\t="<<real<<" + "<<img<<"i";
	else
		cout<<"\t="<<real<<" - "<<(-1)*img<<"i";
}
Complex Complex::operator +(Complex &c1){
	Complex c;
	c.real=real+c1.real;
	c.img=img+c1.img;
	return c;
}
Complex Complex::operator -(Complex &c1){
	Complex c;
	c.real=real-c1.real;
	c.img=img-c1.img;
	return c;
}
Complex Complex::operator *(Complex &c1){
	Complex c;
	c.real=(real*c1.real)-(img*c1.img);
	c.img=(real*c1.img)+(img*c1.real);
	return c;
}
Complex Complex::operator /(Complex &c1){
	Complex c;
	if((c1.real*c1.real+c1.img*c1.img)!=0){
	c.real=((real*c1.real)+(img*c1.img))/(c1.real*c1.real+c1.img*c1.img);
	c.img=((img*c1.real)-(real*c1.img))/(c1.real*c1.real+c1.img*c1.img);
	return c;
	}
	else{
	cout<<"!! Can't Divide By Zero !!";
	return c;
	}
}
int main() {
	Complex c1,c2,c;
	float a,b,x,y;
	char i,op,ch;
	c.menu();
	ch='1';
	cout<<"Status: ON"<<endl;
	cout<<"Enter First Complex No.: ";
	cin>>a>>b>>i;
	cout<<"Enter Second Complex No.: ";
	cin>>x>>y>>i;
	label:
	cout<<"Enter Operator:";
	cin>>op;
	c1.setData(a,b);
	c2.setData(x,y);
	//cout<<a<<b<<i<<op<<x<<y<<i;
	switch(op){
			case '+': c=c1+c2;c.display();break;
			case '-': c=c1-c2;c.display();break;
			case '*': c=c1*c2;c.display();break;
			case '/':c=c1/c2;c.display();break;
			default : cout<<"!! Invalid operator "<<op<<" !!";
	}
	cout<<endl<<"Do You Want to Continue?(1/0): ";
		cin>>ch;
		cout<<endl;
		if(ch!='0'){
			//clrscr();
			goto label;
		}
		else{
			//clrscr();
			cout<<"Status: OFF";
			return 0;
		}

	return 0;
}

