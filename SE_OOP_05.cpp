//============================================================================
// Name        : Assignment5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
class Personal{
	private:
		string name;
		int age;
		string mobile;
		string address;
	public:
		Personal();
		void getData();
		void putData();
		~Personal();
};
Personal::Personal(){
	cout<<"//Initialising Personal Details"<<endl;
}
void Personal::getData(){
	cout<<"Enter Name: ";cin>>name;
	cout<<"Enter Age: ";cin>>age;
	cout<<"Enter Mobile Number: ";cin>>mobile;
	cout<<"Enter Residential Address: ";cin>>address;
}
void Personal::putData(){
	cout<<"-------------------------------------------------------------------------------"<<endl;
	cout<<"			PERSONAL DETAILS"<<endl;
	cout<<"-------------------------------------------------------------------------------"<<endl;
	cout<<"\tName                  : "<<name<<endl;
	cout<<"\tAge                   : "<<age<<endl;
	cout<<"\tMobile Number         : "<<mobile<<endl;
	cout<<"\tResidential Address   : "<<address<<endl<<endl;
}
Personal::~Personal(){
	cout<<"//De-Initialising Personal Details"<<endl;
}
class Professional{
	private:
		int n,m;
		string jobExperience[10][3];
		string specialization;
		string internExperience[10][3];
	public:
		Professional();
		void getData();
		void putData();
		~Professional();
};
Professional::Professional(){
	cout<<"//Initialising Professional Details"<<endl;
}
void Professional::getData(){
	cout<<"Enter No. of Job Experiences: ";cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Enter Company Name: ";cin>>jobExperience[i][0];
		cout<<"Enter Post: ";cin>>jobExperience[i][1];
		cout<<"Enter Time Span: ";cin>>jobExperience[i][2];
	}
	cout<<"Enter No. of InternShip Experiences: ";cin>>m;
	for(int i=0;i<m;i++){
			cout<<"Enter Company Name: ";cin>>internExperience[i][0];
			cout<<"Enter Post: ";cin>>internExperience[i][1];
			cout<<"Enter Time Span: ";cin>>internExperience[i][2];
		}
	cout<<"Enter Field Of Specialization: ";cin>>specialization;
}
Professional::~Professional(){
	cout<<"//De-Initialising Professional Details"<<endl;
}
void Professional::putData(){
	cout<<"-------------------------------------------------------------------------------"<<endl;
	cout<<"			PROFESSIONAL DETAILS"<<endl;
	cout<<"-------------------------------------------------------------------------------"<<endl;
	cout<<"\tWORK EXPERIENCE: "<<endl;
	for(int i=0;i<n;i++){
		cout<<"\t"<<i+1<<". @"<<jobExperience[i][0]<<" as "<<jobExperience[i][1]<<" for "<<jobExperience[i][2]<<endl;
	}
	cout<<"\tINTERNSHIPS: "<<endl;
	for(int i=0;i<m;i++){
		cout<<"\t"<<i+1<<". @"<<internExperience[i][0]<<" as "<<internExperience[i][1]<<" for "<<internExperience[i][2]<<endl;
	}
}
class Academics{
	private:
		string hsc;
		float hscPercentile;
		string ssc;
		float sscPercentile;
		string graduation;
		string graduationInstitute;
		float graduationPercentile;
		string postGraduation;
		string postGraduationInstitute;
		float postGraduationPercentile;
	public:
		Academics();
		void getData();
		void putData();
		~Academics();

};
Academics::Academics(){
	cout<<"//Initialising Academic Details"<<endl;
}
void Academics::getData(){
	cout<<"Enter SSC Board: ";cin>>ssc;
	cout<<"Enter Percentile Scored: ";cin>>sscPercentile;
	cout<<"Enter HSC Board: ";cin>>hsc;
	cout<<"Enter Percentile Scored: ";cin>>hscPercentile;
	cout<<"Enter Graduation Degree: ";cin>>graduation;
	cout<<"Enter Graduation Institute: ";cin>>graduationInstitute;
	cout<<"Enter Percentile Scored: ";cin>>graduationPercentile;
	cout<<"Enter PostGraduation Degree: ";cin>>postGraduation;
	cout<<"Enter PostGraduation Institute: ";cin>>postGraduationInstitute;
	cout<<"Enter Percentile Scored: ";cin>>postGraduationPercentile;
}
void Academics::putData(){
	cout<<"-------------------------------------------------------------------------------"<<endl;
	cout<<"			ACADEMICS DETAILS"<<endl;
	cout<<"-------------------------------------------------------------------------------"<<endl;
	cout<<"\t1. SSC Board "<<ssc<<" with "<<sscPercentile<<" percentile"<<endl;
	cout<<"\t2. HSC Board "<<hsc<<" with "<<hscPercentile<<" percentile"<<endl;
	cout<<"\t3. Grauation degree "<<graduation<<" from "<<graduationInstitute<<" with "<<graduationPercentile<<" percentile"<<endl;
	cout<<"\t4. PostGrauation degree "<<postGraduation<<" from "<<postGraduationInstitute<<" with "<<postGraduationPercentile<<" percentile"<<endl;	
}
Academics::~Academics(){
	cout<<"//De-Initialising Academic Details"<<endl;
}
class Record:public Personal,public Professional,public Academics{
	private:
		string enrolmentNo;
	public:
		Record();
		void getData();
		void putData();
		~Record();
};
Record::Record(){
	cout<<"//Initialising Resume"<<endl;
}
void Record::getData(){
	 cout<<"Enter Enrolment Number: ";cin>>enrolmentNo;
	 Personal::getData();
	 Professional::getData();
	 Academics::getData();
}
void Record::putData(){
	 cout<<endl<<"\tEnrolment Number: "<<enrolmentNo<<endl;
	 Personal::putData();
	 Professional::putData();
	 Academics::putData();
}
Record::~Record(){
	cout<<"//De-Initialising Resume"<<endl;
}
int main() {
	Record resume;
	cout<<endl;
	cout<<"-------------------------------------------------------------------------------"<<endl;
	resume.getData();
	resume.putData();
	cout<<endl;
	cout<<"-------------------------------------------------------------------------------"<<endl;
	return 0;
}


