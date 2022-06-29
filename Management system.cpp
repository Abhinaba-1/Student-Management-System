#include<iostream>  
#include<stdio.h>  
#include<conio.h>  
#include<fstream>  
#include<stdlib.h>   
using namespace std;  
void create_rec();  
void disp_rec();  
void search_rec();  
void update_rec();   
void delete_rec();  
  
class student  
{  
int roll;   
char sub[10] ;   
int marks;   
public:  
void accept()  
{  
cout<<"Enter the Roll no: ";  
cin>>roll;  
cout<<"Enter the subject: ";  
cin>>sub;             
cout<<"Enter the marks: ";  
cin>>marks;  
}  
  
void disp()  
{  
cout<<roll<<"\t\t";  
cout<<sub<<"\t\t";  
cout<<marks<<endl;  
}  
  
int getRoll()  
{  
    return roll;  
}  
};  
  
  
student s;   
main()  
{  
int a,b,c,choice;  
do  
{   
    cout<<"Create new record : 1\nDisp1ay all student record:2\nSearch for student:3\nUpdate student record:4\nDe1ete student record:5\nExit:6"<<endl;  
    cin>>choice;  
    switch(choice)  
    {  
    case 1:  
        create_rec();  
        break;  
    case 2:  
        disp_rec( );  
        break;  
    case 3:  
        search_rec();  
        break;  
    case 4:  
        update_rec() ;  
        break;  
    case 5:  
        delete_rec();  
        break;  
    case 6:  
        exit(0);  
    }  
}  
while (choice!=6);  
}  
  
void create_rec()  
{  
ofstream fout;  
char ans;  
fout.open("sdata.dat",ios::binary|ios::app);  
    do  
    {  
    s.accept( );  
    fout.write((char*)&s,sizeof (s));  
    cout<<"To Add new record press Y";  
    cin>>ans;  
    }  
    while(ans=='y'||ans=='Y');  
fout.close();  
}  
  
  
void disp_rec()  
{  
ifstream fin;  
fin.open("sdata.dat",ios::binary);  
  
    cout<<endl<<endl<<"Roll no\t\tSubject\t\tMarks"<<endl;  
    while(fin.read((char*) &s,sizeof(s)))  
        {  
        s.disp();  
        }  
    cout<<endl<<"File position:"<<fin.tellg();  
getch();  
fin.close();  
}  
  
  
void search_rec()  
{  
    int r,found=0;  
    ifstream fin;  
    fin.open("sdata.dat",ios::binary);  
    cout<<"Enter the roll no to search....";  
    cin>>r;  
    while(fin.read((char*) &s,sizeof(s)))  
        {  
        if(r==s.getRoll())  
            {  
            s.disp();  
            found=1;  
            }  
        }  
        if(found==0)  
        cout<<"Roll no not found....";  
getch();  
fin.close();  
}  
  
  
void update_rec()  
{  
int r,found=0,pos=0,count=0;  
fstream f;  
f.open("sdata.dat",ios::binary|ios::in|ios::out);  
cout<<"Enter the roll no to update :";  
cin>>r;  
    while(f.read((char*) &s,sizeof(s)))  
    {  
        if(r==s.getRoll())  
        {  
        cout<<"Enter the new details ::"<<endl<<endl;  
        s.accept();  
          
        pos=count*sizeof(s);  
        f.seekp(pos,ios::beg);  
        f.write((char*) &s,sizeof(s));  
        found=1;  
        }  
          
    count++;  
    }  
    if(found==0)  
        cout<<"Record not found";  
}  
void delete_rec()  
{  
int r;  
fstream f;  
ofstream tfile;  
  
f.open("sdata.dat",ios::binary|ios::in|ios::out);  
tfile.open("temp",ios::binary);  
  
cout<<"Enter the roll no delete : ";  
cin>>r;  
  
    while(f.read((char*) &s,sizeof(s)))  
        {  
        if(r!=s.getRoll())  
            {  
            tfile.write((char*) &s,sizeof(s));  
            }  
        }  
    f.close();  
    tfile.close();  
    remove("sdata.dat");  
    rename("temp","sdata.dat");  
}    
  
/*f.read((char*) &s2,sizeof(s2)); 
s2.disp(); 
f.read((char*) &s2,sizeof(s2)); 
s2.disp(); 
f.read((char*) &s2,sizeof(s2));  
s2.disp();*/  
//getch();  
//getch();  
//} 