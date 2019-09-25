#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int main(int argc,char *argv[]){
	fstream file;
	string replace_data=" ";
	file.open(argv[1],ios::in);
	if(argc<4){
		cout<<"Invalid arguments";
		return 0;
	}
	if(!file){
		cout<<"File Error!";
		return 0;
	}
	string s2=argv[2];
	string data;
	int found;
	while(file){
		getline(file,data);
		found=data.find(s2);
		while(data.find(s2)<500){
			data.replace(found,s2.size(),argv[3]);
			found=data.find(s2);
		}
		replace_data=replace_data+data+"\n";
	}
	file.close();
	file.open(argv[1],ios::out|ios::trunc);
	if(!file){
		cout<<"File Error!";
		return 0;
	}	
	file<<replace_data;
	return 0;
}

