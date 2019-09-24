#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int main(){
	fstream file;
	string str1,str2;
	file.open("sample.txt",ios::out|ios::app);
	if(!file){
		cout<<"File Error!";
		return 0;
	}
	cout<<"File Entry: ";
	cin>>str1;
	file<<str1;
	file.close();
	file.open("sample.txt",ios::in);
	if(!file){
		cout<<"File Error!";
		return 0;
	}
	getline(file,str2);
	cout<<str2;
	return 0;
}
