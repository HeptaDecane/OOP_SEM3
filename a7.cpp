/*
 * Assignment7.cpp
 *
 *  Created on: Aug 21, 2019
 *      Author: SE
 */
#include<bits/stdc++.h>
using namespace std;
/*
int main(){
	int a,b,c;
	cin>>a>>b;
	try{
		if(!b){
			throw b;
		}
		else{
			cout<<a/b;
		}
	}
	catch(int i){
		cout<<"divisor can't be zero";
	}
	return 0;
}
*/
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
