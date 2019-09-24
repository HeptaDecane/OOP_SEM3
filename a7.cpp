//============================================================================
// Name        : Assignment.cpp
// Author      : Near
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
using namespace std;

class Data{
	int age;
	int income;
	int no;
	string city;
	string vehicle;
public:
	class Error{};
	Data();
	void getData();
	void display();
};
Data::Data(){
	age=0;
	income=0;
	no=0;
	city="NULL";
	vehicle="NULL";
}
void Data::getData(){
	cout<<"Enter Age: ";
	cin>>age;
	cout<<"Enter Income: ";
	cin>>income;
	cout<<"Enter City: ";
	cin>>city;
	cout<<"Enter Vehicle: ";
	cin>>no>>vehicle;
	if(age<18||age>55) throw Error();
	if(!(city=="Pune"||city=="Bangalore"||city=="Mumbai"||city=="Chennai")) throw Error();
	if(income<50000||income>100000) throw Error();
	if(no!=4) throw Error();
}
void Data::display(){
	cout<<"Age     :  "<<age<<endl;
	cout<<"income  :  "<<income<<endl;
	cout<<"City    :  "<<city<<endl;
	cout<<"Vehicle :  "<<no<<"-Wheeler"<<endl;
}
int main(){
	Data obj;
	try{
		obj.getData();
	}
	catch(Data::Error &){
		cout<<"\n!! Criteria didn't Match !!"<<endl;
	}
	cout<<endl;
	obj.display();
	return 0;
}
