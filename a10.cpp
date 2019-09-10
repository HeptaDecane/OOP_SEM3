#include<bits/stdc++.h>
using namespace std;
class Item{
	string name,code;
	int quantity,cost;
public:
	Item(){
		name[0]='\0';
		code[0]='\0';
		quantity=0;
		cost=0;
	}
	bool operator ==(const Item &i);
	int remove(vector<Item>&);
	void display(vector<Item>);
	void display();
	void insert(vector<Item>&);
	int search(vector<Item>);
	void menu();
	friend bool compare(Item &i1,Item &i2);
};

// function for aiding p=find(list.begin(),list.end(),i) 
bool Item::operator ==(const Item &i){
	return code==i.code;
}

// function aiding sort(list.begin(),list.end(),compare)
bool compare(Item &i1,Item &i2){
	return (i1.cost<i2.cost);
}

void Item::insert(vector <Item> &list){
	Item i;
	cout<<"\nEnter Item Code: ";cin>>i.code;
	cout<<"Enter Item Name: ";cin>>i.name;
	cout<<"Enter Unit Price: ";cin>>i.cost;
	cout<<"Enter stock Quantity: ";cin>>i.quantity;
	list.push_back(i);
}

void Item::display(vector <Item> list){
	cout<<"\nItem Code\tItem Name\tQuantity\tUnit Price";
	cout<<"\n-----------------------------------------------------------";
	for(int i=0;i<list.size();i++){
		list[i].display();
	}
}

void Item::display(){
	cout<<"\n"<<code<<"\t\t"<<name<<"\t\t"<<quantity<<"\t\t"<<cost;
}

int Item::remove(vector<Item> &list){
	vector<Item>::iterator p;
	Item i;
	cout<<"Enter Item Code to Delete: ";
	cin>>i.code;
	p=find(list.begin(),list.end(),i);
	if(p==list.end())
		return 0;
	list.erase(p);
	return 1;
}

int Item::search(vector <Item> list){
	Item i;
	vector <Item>::iterator p;
	cout<<"\nEnter Item Code to Search: ";
	cin>>i.code;
	p=find(list.begin(),list.end(),i);
	return distance(list.begin(),p);
}

void Item::menu(){
	cout<<"\n------------------INVENTORY MANAGEMENT---------------------";
	cout<<"\n|\tPress 1  : Add Item                               |";
	cout<<"\n|\tPress 2  : Display Inventory                      |";
	cout<<"\n|\tPress 3  : Search an Item (by Item Code)          |";
	cout<<"\n|\tPress 4  : Sort by Unit Price (High-->Low)        |";
	cout<<"\n|\tPress 5  : Remove an Item                         |";
	cout<<"\n|\tPress 99 : Show Menu                              |";
}
int main(){
	vector <Item> list;
	Item inventory;
	int ch,index;
	inventory.menu();
	do{
		cout<<"\n-----------------------------------------------------------";
		cout<<"\nEnter Choice [0-exit]: ";
		cin>>ch;
		switch (ch){
			case 1:	inventory.insert(list);
					break;
			case 2: inventory.display(list);
					break;
			case 3: index=inventory.search(list);
					if(index==list.size())
						cout<<"\nItem Not Found";
					else{
						cout<<"\nFound at Position: "<<index+1<<"\n";
						inventory.display(list);
					}
					break;
			case 4: sort(list.begin(),list.end(),compare);
					cout<<"\nSorted on Unit Price [High-->Low]\n";
					inventory.display(list);
					break;
			case 5:if(!inventory.remove(list))
						cout<<"\nInvalid Item Code!";
					else
						cout<<"\nItem Deleted!";
					break;
			case 6: inventory.menu();
					break;
			case 0: cout<<"\nEND...\n";
					break;
			default: cout<<"\nInvalid Choice!";		
		}
	}while(ch);
	return 0;
}

