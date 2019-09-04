//============================================================================
// Name        : Assignment.cpp
// Author      : Near
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
template<typename T>
T selectionSort(T a[],int size){
	int i,j,loc;
	T temp,min;
	for(i=0;i<size-1;i++){
		min=a[i];
		loc=i;
		for(j=i+1;j<size;j++){
			if(min>a[j]){
				min=a[j];
				loc=j;
			}
		}
		temp=a[i];
		a[i]=a[loc];
		a[loc]=temp;
	}
	return 0;
}
template<class T>
T print(T a[],int size){
	for(int i=0;i<size;i++)cout<<a[i]<<" ";
	return 0;
}
template<class T>
int binarySearch(T a[],int size){
	selectionSort(a,size);
	int mid,start,end;
	T ele;
	start=0;
	end=size;
	cout<<"Enter Element to be Searched: ";
	cin>>ele;
	while(end>=start){
		mid=start+(end-1)/2;
		mid=(start+end)/2;
		if(a[mid]==ele)
			return mid;
		else if(a[mid]>ele)
			end=mid-1;
		else
			start=mid+1;
	}
	return -1;
}
void menu1(){
	cout<<endl;
	cout<<"--------------------------------------------"<<endl;
	cout<<"|	Press 1: <int> Array               |"<<endl;
	cout<<"|	Press 2: <float> Array             |"<<endl;
	cout<<"|	Press 0: Exit                      |"<<endl;
	cout<<"--------------------------------------------"<<endl;
	cout<<"Enter Choice: ";
}
void menu2(){
	cout<<endl;
	cout<<"--------------------------------------------"<<endl;
	cout<<"|	Press 1: Sort the Array            |"<<endl;
	cout<<"|	Press 2: Search an Element         |"<<endl;
	cout<<"|	Press 0: Exit                      |"<<endl;
	cout<<"--------------------------------------------"<<endl;
	cout<<"Enter Choice: ";
}
void intArray(){
	int size,ch,flag;
	cout<<"Enter Size: ";
	cin>>size;
	int a[size];
	cout<<"Enter Array Elements: ";
	for(int i=0;i<size;i++)cin>>a[i];
	menu2();
	cin>>ch;
	while(ch!=0){
		switch(ch){
			case 1: selectionSort(a,size);
				cout<<"Sorted array: ";
				print(a,size);cout<<endl;
				break;
			case 2: flag=binarySearch(a,size-1);
				if(flag==-1)
					cout<<"Element Not Found"<<endl;
				else
					cout<<"Element Found at index "<<flag<<" in Sorted Array"<<endl;
				break;
			default: cout<<"!--Wrong Choice--!";
		}
		menu2();
		cin>>ch;
	}
}
void floatArray(){
	int size,ch,flag;
	cout<<"Enter Size: ";
	cin>>size;
	float a[size];
	cout<<"Enter Array Elements: ";
	for(int i=0;i<size;i++)cin>>a[i];
	menu2();
	cin>>ch;
	while(ch!=0){
		switch(ch){
			case 1: selectionSort(a,size);
				cout<<"Sorted array: ";
				print(a,size);cout<<endl;
				break;
			case 2: flag=binarySearch(a,size-1);
				if(flag==-1)
					cout<<"Element Not Found"<<endl;
				else
					cout<<"Element Found at index "<<flag<<" in Sorted Array"<<endl;
				break;
			default: cout<<"!--Wrong Choice--!";
		}
		menu2();
		cin>>ch;
	}
}
int main(){
	int ch;
	menu1();
	cin>>ch;
	while(ch!=0){
		switch(ch){
			case 1: intArray();
				break;
			case 2: floatArray();
				break;
			default: cout<<"!--Wrong Choice--!";
		}
		menu1();
		cin>>ch;
	}
	cout<<"---------------------END--------------------"<<endl;
	return 0;
}
