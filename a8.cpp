//============================================================================
// Name        : Assignment.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
void menuStack(){
	cout<<"\n Press 1: Push Element into Stack";
	cout<<"\n Press 2: Pop Element from Stack";
	cout<<"\n Press 3: Find Stack Size";
	cout<<"\n Press 4: Display Stack Elements";
	cout<<"\n Press 5: Display Top";
	cout<<"\n Press 6: Show Menu";
	cout<<"\n Press 0: Exit Program";
}
void menuQ(){
	cout<<"\n Press 1: Push Element into Queue";
	cout<<"\n Press 2: Pop Element from Queue";
	cout<<"\n Press 3: Find Queue Size";
	cout<<"\n Press 4: Display Queue";
	cout<<"\n Press 5: Display Front";
	cout<<"\n Press 6: Show Menu";
	cout<<"\n Press 0: Exit Program";
}
void displayStack(stack <int> a){
	cout<<"\nStack: ";
	while(!a.empty()){
			cout<<"\n"<<a.top();
			a.pop();
		}
}
void displayQ(queue <int> a){
	cout<<"\n Queue: ";
    while (!a.empty()){
        cout<<a.front()<<" ";
        a.pop();
    }
}
void _stack(){
	stack <int> a;
	menuStack();
	int ch,element;
	do{
		cout<<"\n------------------------------------";
		cout<<"\n Enter Choice From Menu [0-Exit]: ";
		cin>>ch;
		switch(ch){
			case 1: cout<<"\n Enter Element: ";cin>>element;
					a.push(element);
					break;
			case 2: a.pop();
					break;
			case 3: cout<<"Size: "<<a.size();
					break;
			case 4: displayStack(a);
					break;
			case 5: cout<<"\n Top: "<<a.top();
					break;
			case 6: menuStack();
					break;
			case 0: break;
			default: cout<<"\n Wrong Choice!";
		}
	}while(ch);
}
void _que(){
	queue <int> a;
	menuQ();
	int ch,element;
	do{
		cout<<"\n------------------------------------";
		cout<<"\n Enter Choice From Menu [0-Exit]: ";
		cin>>ch;
		switch(ch){
			case 1: cout<<"\n Enter Element: ";cin>>element;
					a.push(element);
					break;
			case 2: a.pop();
					break;
			case 3: cout<<"Size: "<<a.size();
					break;
			case 4: displayQ(a);
					break;
			case 5: cout<<"\n Front: "<<a.front();
					break;
			case 6: menuQ();
					break;
			case 0: break;
			default: cout<<"\n Wrong Choice!";
		}
	}while(ch);
}
int main() {
	int ch;
	cout<<"\n Press: 1 for Stack";
	cout<<"\n Press: 2 for Queue";
	cout<<"\n Enter Choice: ";cin>>ch;
	if(ch==1)_stack();
	else if(ch==2)_que();
	cout<<"Terminated!";
	return 0;
}
