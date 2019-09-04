//============================================================================
// Name        : Assignment.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
void show(deque <int> a){
	while(!a.empty()){
		cout<<a.back()<<" ";
		a.pop_back();
	}
}
void menu(){
	cout<<"\n Press 1: Insert From Front";
	cout<<"\n Press 2: Insert From Back";
	cout<<"\n Press 3: Remove From Front";
	cout<<"\n Press 4: Remove From Back";
	cout<<"\n Press 5: Display Deque";
	cout<<"\n Press 6: Find Size of Deque";
	cout<<"\n Press 7: Display Front";
	cout<<"\n Press 8: Display Back";
	cout<<"\n Press 9: Show Menu";
	cout<<"\n Press 0: Exit Program";
}
int main() {
	deque <int> a;
	menu();
	int ch,element;
	do{
		cout<<"\n------------------------------------";
		cout<<"\n Enter Choice From Menu [0-Exit]: ";
		cin>>ch;
		switch(ch){
			case 1: cout<<"\n Enter Element: ";cin>>element;
					a.push_front(element);
					break;
			case 2: cout<<"\n Enter Element: ";cin>>element;
					a.push_back(element);
					break;
			case 3: a.pop_front();
					break;
			case 4: a.pop_back();
					break;
			case 5: show(a);
					break;
			case 6: cout<<"\n No. of Elements in Deque: "<<a.size();
					break;
			case 7: cout<<"\n Front: "<<a.front();
					break;
			case 8: cout<<"\n Back: "<<a.back();
					break;
			case 9: menu();
					break;
			case 0: cout<<"Exiting...";
					break;
			default: cout<<"\n Wrong Choice!";
		}
	}while(ch);
	return 0;
}
