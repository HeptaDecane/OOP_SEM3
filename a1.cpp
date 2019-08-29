#include<bits/stdc++.h>
using namespace std;
class Calculator{
	float a,b;
	public:
	void setData(float,float);
	void add();
	void substract();
	void multiply();
	void divide();
};
void Calculator::setData(float x,float y){
	a=x;
	b=y;
}
void Calculator::add(){
	cout<<"\t = "<<a+b;
}
void Calculator::substract(){
	cout<<"\t = "<<a-b;
}
void Calculator::multiply(){
	cout<<"\t = "<<a*b;
}
void Calculator::divide(){
	if(b)
		cout<<"\t = "<<a/b;
	else
		cout<<"\t!! Can't Divide by Zero !!";
}
int main(){
	float a,b;
	char op,ch;
	Calculator ob;
	label:
	ch='1';
   cout<<"Status: ON"<<endl;
	cout<<"Expression: ";
	cin>>a>>op>>b;
	ob.setData(a,b);
	switch(op){
		case '+': ob.add();break;
		case '-': ob.substract();break;
		case '*': ob.multiply();break;
		case '/': ob.divide();break;
		default : cout<<"!! Invalid operator "<<op<<" !!";
	}
	cout<<endl<<"Do You Want to Continue?(1/0): ";
	cin>>ch;
	cout<<endl;
	if(ch!='0'){
		goto label;
	}
	else{
		cout<<"Status: OFF";
		return 0;
	}
}


