#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
#include<fstream>

using namespace std;

// Global variables
string fname, lname, phone_number;

bool check_digits(string x){
    if(x.length()==10)
    return true;
    else
    return false;
        
}

bool check_num(string x){
    bool check = true;

    for(int i=0; i<x.length(); i++){
        if(!(int(x[i])>=48 && int(x[i])<=57)){
            check=false;
            break;
        }
    }
    if(check==true)
    return true;
    if(check==false)
    return false;

}

void addContact(){
    ofstream phone("number.txt", ios::app);

    // system("cls");
    cout<<"\n\n\tEnter First Name: ";
    cin>>fname;
    cout<<"\n\tEnter Last Name: ";
    cin>>lname;
    cout<<"\n\tEnter 10-Digit Phone Number: ";
    cin>>phone_number;

    if(check_digits(phone_number) == true){
        if(check_num(phone_number) == true){
            if(phone.is_open()){
                phone << fname <<" "<<  lname <<" "<< phone_number <<endl;
                cout<<"\n\tContact saved successfully!"<<endl;

            }else{
                cout<<"\n\tError opening file!"<<endl;
            }
        }else{
            cout<<"\nA Phone numbers must contain numbers only."<<endl;
        }

    }else{
        cout<<"\n\nA Phone number must contain 10-Digit Number."<<endl;
    }
    phone.close();

}
void searchContact(){
    bool found=false;
    fstream myFile("number.txt");
    string keyWord;
    cout<<"\n\tEnter name to search: ";
    cin>>keyWord;
    while(myFile >> fname >>lname >> phone_number){
        if(keyWord==fname || keyWord == lname){
            system("cls");
            cout<<"\n\tContact Details..";
            cout<<"\n\n\tFirst Name : "<< fname;
            cout<<"\n\tLast Name: "<< lname;
            cout<<"\n\tPhone Number: "<<phone_number;
            found == true;
            break;
        }
    }
    if(found==false)
    cout<<"\n\tNo such contact found."<<endl;
    
}
void help(){
    cout<<"This display help:)";

}
void self_exit(){
    cout<<"\n\n\t\tThank you for using!"<<endl;
    exit(1);

}

int main()
{
    short int choice;
    // system("cls");
    // system("color 0A");
    cout<<"\n\n\n\t\t\tContact Management.";
    cout<<"\n\n\t1. Add Contact"<<endl;
    cout<<"\t2. Search Contact"<<endl;
    cout<<"\t3. Help"<<endl;
    cout<<"\t4. Exit"<<endl;
    cin>>choice;
    switch(choice){

        case 1:
            addContact();
            break;
        case 2:
            searchContact();
            break;
        case 3:
            help();
        case 4:
            self_exit();
        default:
            cout<<"\n\n\tInvalid Input !";
            cout<<"\nPress any key to continue."<<endl;
    }
    addContact();
    self_exit();
    searchContact();

    return 0;
}