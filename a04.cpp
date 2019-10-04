//============================================================================
// Name        : Assignment4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
class Student{
	private:
		int roll;
		string name;
		string class_;
		string division;
		string dob;
		string bloodGroup;
		string telephone;
		string address;
		string license;
		static int count;												//Static Data Member
		friend class DataBase;											//Friend Class
	public:
		Student();														//Default Constructor
		static int getCount();											//Static Member Function
		void getData();
		void display();
		~Student();														//Destructor
};
Student::Student(){
	count++;
}
int Student::count=0;
int Student::getCount(){
	return count;
}
void Student::getData(){
	cout<<"Roll No:";cin>>roll;
	cout<<"Name:";cin>>name;
	cout<<"Class:";cin>>class_;
	cout<<"Division:";cin>>division;
	cout<<"Date Of Birth:";cin>>dob;
	cout<<"Blood Group:";cin>>bloodGroup;
	cout<<"TelePhhone No:";cin>>telephone;
	cout<<"Address:";cin>>address;
	cout<<"Driving License No:";cin>>license;
}
inline void Student::display(){											//inline Member Function
	cout<<"Roll No                :"<<roll<<endl;
	cout<<"Name                   :"<<name<<endl;
	cout<<"Class                  :"<<class_<<endl;
	cout<<"Division               :"<<division<<endl;
	cout<<"Date Of Birth          :"<<dob<<endl;
	cout<<"Blood Group            :"<<bloodGroup<<endl;
	cout<<"TelePhhone No          :"<<telephone<<endl;
	cout<<"Address                :"<<address<<endl;
	cout<<"Driving License No     :"<<license<<endl;
}
Student::~Student(){
	count--;
}
class DataBase{
	private:
		int n;
		Student *s;
	public:
		DataBase();														//Default Constructor
		DataBase(int);													//Parameterised Constructor
		DataBase(DataBase&);											//Copy Constructor
		void getData();
		void display();
		int getCount();
		~DataBase();													//Destructor
};
DataBase::DataBase(){
	n=0;
	s=NULL;
}
DataBase::DataBase(int i){
	n=i;
	s=new Student[n];													//Dynamic Memory Allocation of n Students (new)
}
DataBase::DataBase(DataBase &obj){
	n=obj.n;
	s=new Student[n];													//Dynamic Memory Allocation of n Students (new)
	for(int i=0;i<n;i++){
		s[i]=obj.s[i];
		s[i].count--;
	}
}
void DataBase::getData(){
	for(int i=0;i<n;i++){
		cout<<"Enter Details For Student "<<i+1<<endl;
		s[i].getData();
	}
}
void DataBase::display(){
	for(int i=0;i<n;i++){
		cout<<endl;
		this->s[i].display();											//.this pointer
	}
}
int DataBase::getCount(){
	return Student::getCount();
}
DataBase::~DataBase(){
	delete[] s;															//DeAllocation of Dynamic Array (delete)
}
int main() {
	int n;
	DataBase obj0();                                                    //Default Constructor Call;
	cout<<"Enter Number of Students: ";
	cin>>n;
	DataBase *obj1;														
	obj1=new DataBase(n);												//Dynamic Allocation with Parameterised Constructor Call;
	obj1->getData();
	DataBase obj2=*obj1;												//Copy Constuctor Call;
	obj2.display();
	cout<<"Total Students in DataBase = "<<obj1->getCount()<<endl;
	delete obj1;														//DeAllocation of obj1 (delete)
	return 0;
}


