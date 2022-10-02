#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
struct emp
{
string name;
string empc;
int day;
int month;
int year;
int byear;
int age;
};
bool checkpangram(string& str);
void insert(emp*,int &,int);
void del(emp*,int &,int);
void modification(emp*,int &,int);
void s_name(emp*,int);
void s_reg(emp*,int);
void s_date(emp*,int);
int main()
{
emp e[100];
int i,n,op1,op2,cyear;
char ch1;
cout<<"Number of employees: ";
cin>>n;
cout<<"enter current year: ";
cin>>cyear;
for(i=0;i<n;i++)
{
cout<<"enter details For Employee"<<i+1<<endl;
cout<<"Name: ";
cin.sync();    //to clear buffer
getline(cin,e[i].name);
cout<<"Employee id: ";
cin>>e[i].empc;
while(checkpangram(e[i].empc)==false)
{
	cout<<"enter input in valid format as two alphabets followed by four digits "<<endl;
	cout<<"Employee id: ";
    cin>>e[i].empc;
}
cout<<"enter employees date of joining: ";
cin>>e[i].day;
cin>>e[i].month;
cin>>e[i].year;
while((e[i].day>31||e[i].day<01)||(e[i].month>12||e[i].month<01)||(e[i].year>cyear||e[i].year<1000))
{
cout<<"invalid input. enter again the valid input in the format of dd<space>mm<space>yyyy :"<<endl;
cin>>e[i].day;
cin>>e[i].month;
cin>>e[i].year;
}
cout<<"enter employee's birth year: ";
cin>>e[i].byear;
while(e[i].byear>cyear||e[i].byear<1000)
{
	cout<<"invalid input. enter valid birth year in format yyyy: ";
	cin>>e[i].byear;
}
e[i].age=cyear-e[i].byear;
if(e[i].age>=60)
{
	cout<<"employees age is greater than 60. so he/she is terminated and total no.of employees reduced by 1."<<endl;
	i--;
	n--;
}
}
cout<<"Before modifying:"<<endl;
cout<<setiosflags(ios::left)<<endl;
cout<<setw(24)<<"Name"<<setw(10)<<"Number"<<setw(15)<<"Date of join"<<setw(6)<<"age"<<endl;
cout<<setw(55)<<setfill('*')<<"*"<<endl;
cout<<setw(55)<<setfill(' ')<<" "<<endl;
for(i=0;i<n;i++)
{
cout<<setw(24)<<e[i].name<<setw(10)<<e[i].empc<<setw(2)<<e[i].day<<"/"<<setw(2)<<e[i].month<<"/"<<setw(9)<<e[i].year<<setw(6)<<e[i].age<<endl;
}
do{
cout<<"Press\n1.To insert data\n2.To delete data\n3.To modify data\n";
cin>>op1;
switch(op1)
{
case 1:
insert(e,n,cyear);
break;
case 2:
del(e,n,cyear);
break;
case 3:
modification(e,n,cyear);
break;
default:
cout<<"invalid. Check your input:";
}
cout<<"Do you want to continue(y/n)? ";
cin>>ch1;
}while(ch1!='n');
cout<<"Press\n1.To sort with name\n2.To sort with employee id\n3.To sort with date of joining"<<endl;
cin>>op2;
switch(op2)
{
case 1:
s_name(e,n);
break;
case 2:
s_reg(e,n);
break;
case 3:
s_date(e,n);
break;
default:
cout<<"invalid. Check your input";
}
cout<<"After modyfying:"<<endl;
cout<<setiosflags(ios::left)<<endl;
cout<<setw(24)<<"Name"<<setw(10)<<"Number"<<setw(15)<<"Date of join"<<setw(6)<<"age"<<endl;
cout<<setw(55)<<setfill('*')<<"*"<<endl;
cout<<setw(55)<<setfill(' ')<<" "<<endl;
for(i=0;i<n;i++)
{
cout<<setw(24)<<e[i].name<<setw(10)<<e[i].empc<<setw(2)<<e[i].day<<"/"<<setw(2)<<e[i].month<<"/"<<setw(9)<<e[i].year<<setw(6)<<e[i].age<<endl;
}
}


bool checkpangram(string& str)
{
	if(str.length()==6)
	{
	vector<bool>mark(26,false);
	int index;
	
	for(int i=0;i<2;i++)
	{
		if('A' <= str[i] && str[i] <= 'Z')
		{
			index=i;
			mark[index]=true;
		}
		else if('a' <= str[i] && str[i] <= 'z')
		{
			index=i;
			mark[index]=true;
		}
	}
	for(int i=2;i<6;i++)
	{
		if(str[i]<='9')
		{
			index=i;
			mark[index]=true;
		}
	}
	
	for(int i=0;i<6;i++)
	{
	if(mark[i]==false)
	return (false);
    }
    return(true);
}
else
return(false);
}


void insert(emp e1[],int &n1,int cyear)
{int i;
	for(i=0;i<n1;i++)
	{
		e1[i]=e1[i];
	}
cout<<"enter employees data to be inserted "<<endl;
cout<<"Name: ";
cin.sync();  //to clear buffer
getline(cin,e1[n1].name);
cout<<"Employee number: ";
cin>>e1[n1].empc;
while(checkpangram(e1[n1].empc)==false)
{
	cout<<"enter input in valid format as two alphabets followed by four digits "<<endl;
	cout<<"Employee id: ";
    cin>>e1[n1].empc;
}
cout<<"enter employees date of joining: ";
cin>>e1[n1].day;
cin>>e1[n1].month;
cin>>e1[n1].year;
while((e1[n1].month>12||e1[n1].month<01)||(e1[n1].day>31||e1[n1].day<01)||(e1[n1].year>cyear||e1[n1].year<1000))
{
cout<<"invalid input. enter again the valid input in the format of dd<space>mm<space>yyyy :"<<endl;
cin>>e1[n1].day;
cin>>e1[n1].month;
cin>>e1[n1].year;
}
cout<<"enter employee's birth year: ";
cin>>e1[n1].byear;
while(e1[n1].byear>cyear||e1[n1].byear<1000)
{
	cout<<"invalid input. enter valid birth year in format yyyy: ";
	cin>>e1[n1].byear;
}
e1[n1].age=cyear-e1[n1].byear;
if(e1[n1].age>=60)
{
	cout<<"employees age is greater than 60. so it is ivalid"<<endl;
	n1--;
}
n1++;
}

void modification(emp e6[],int &n6,int cyear)
{
emp temp,t;	
int i,pos;
cout<<"Enter the employee_id of employee to be modified ";
cin>>temp.empc;
for(i=0;i<n6;i++)
{
if(e6[i].empc==temp.empc)
{
	pos=i;
}
}
if(e6[pos].empc==temp.empc)
{
cout<<"enter the details to be modified"<<endl;
cout<<"Name: ";
cin.sync();    //to clear buffer
getline(cin,t.name);
cout<<"Employee number: ";
cin>>t.empc;
while(checkpangram(t.empc)==false)
{
	cout<<"enter input in valid format as two alphabets followed by four digits "<<endl;
	cout<<"Employee id: ";
    cin>>t.empc;
}
cout<<"enter employees date of joining: ";
cin>>t.day;
cin>>t.month;
cin>>t.year;
while((t.month>12||t.month<01)||(t.day>31||t.day<01)||(t.year>cyear||t.year<1000))
{
cout<<"invalid input. enter again the valid input in the format of dd<space>mm<space>yyyy : "<<endl;
cin>>t.day;
cin>>t.month;
cin>>t.year;
} 
cout<<"enter employee's birth year: ";
cin>>t.byear;
while(t.byear>cyear||t.byear<1000)
{
	cout<<"invalid input. enter valid birth year in format yyyy: ";
	cin>>t.byear;
}
t.age=cyear-t.byear;
if(t.age>=60)
{
	cout<<"employees age is greater than 60. so it is invalid "<<endl;
} 
else
e6[pos]=t; 
}
else
cout<<"employee id not found."<<endl;
}
	
void del(emp e2[],int &n2,int cyear)
{
emp temp;	
int i,j,count;
cout<<"Enter the employee_id of employee to be deleted ";
cin>>temp.empc;
for(i=0;i<n2;i++)
{
if(e2[i].empc==temp.empc)
{
for(j=i;j<n2-1;j++)
e2[j]=e2[j+1];
i--;
n2--;
count++;
}
}
}
void s_name(emp e3[],int n3)
{
int i,j;
emp temp;
for(j=1;j<n3;j++)
{ 
temp=e3[j];
i=j-1;
while(i>=0&&(e3[i].name>temp.name))
{
e3[i+1]=e3[i];
i=i-1;
}
e3[i+1]=temp;
}
}
void s_reg(emp e4[],int n4)
{
int j,i;
emp temp;
for(j=1;j<n4;j++)
{ 
temp=e4[j];
i=j-1;
while(i>=0&&e4[i].empc>temp.empc)
{
e4[i+1]=e4[i];
i=i-1;
}
e4[i+1]=temp;
}
}
void s_date(emp e5[],int n5)
{
int i,j;
emp temp;
for(j=1;j<n5;j++)
{ 
temp=e5[j];
i=j-1;
while(i>=0&&((e5[i].year>temp.year)||(e5[i].year==temp.year&&e5[i].month>temp.month)||(e5[i].year==temp.year&&e5[i].month==temp.month&&e5[i].day>temp.day)))
{
e5[i+1]=e5[i];
i=i-1;
}
e5[i+1]=temp;
}
}
