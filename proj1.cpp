#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot(); 

int main()
{
    int c;
    cout<<"\t\t\t_________________________________________________\n\n\n";
    cout<<"\t\t\t           welcome to the login page              \n\n\n";
    cout<<"                                                         \n\n";
    cout<<"\t|press 1 to login                |"<<endl;
    cout<<"\t|press 2 to register             |"<<endl;
    cout<<"\t|press 3 if you forgot password  |"<<endl;
    cout<<"\t|press 4 to exit                 |"<<endl;
    cout<<"\n\t\t\t please enter your choice :";
    cin>>c;
    cout<<endl;

    switch(c)
    {
        case 1:
        login();
        break;

        case 2:
        registration();
        break;

        case 3:
        forgot();
        break;

        case 4:
        cout<<"\t\t\t thank you! \n\n";
        break;
        default:
        system("cls");
        cout<<"\t\t\t please select from the option given above \n"<<endl;
        main();
    }
}

void login()
{
    int count;
    string userId,password,id,pass;
    system("cls");
    cout<<"\t\t\t please enter the username and password : "<<endl;
    cout<<"\t\t\t username";
    cin>>userId;
    cout<<"\t\t\t password";
    cin>>password;

    ifstream input("records.txt");

    while(input>>id>>pass)
    {
        if(id==userId && pass==password)
        {
            count=1;
            system("cls");
        }
    }
    input.close();

    if(count==1){
        cout<<userId<<"\n your login is successfull \n Thanks for logging in ! \n ";
        main();
    }
    else{
        cout<<"\n login error \n please check your username and password\n";
        main();
    }
    
}
void registration()
{
    string  ruserId,rpassword,rid,rpass;
    system("cls");
    cout<<"\t\t\t Enter the username :";
    cin>>ruserId;
    cout<<"\t\t\t Enter the password :";
    cin>>rpassword;

    ofstream f1("records.txt",ios::app);
    f1<<ruserId;
    system("cls");
    cout<<"\n\t\t\t Registration is successfull ! \n";
    main(); 
}
void forgot()
{
    int option;
    system("cls");
    cout<<"\t\t\t you forgot the password? \n";
    cout<<"press 1 to search your id by username"<<endl;
    cout<<"press 2 to go back to main menu"<<endl;
    cout<<"\t\t\t enter your choice :";
    cin>>option;
    switch(option)
    {
        case 1:
        {
            int count = 0;
            string suserid,sid,spass;
            cout<<"\n\t\t\t Enter the username which you remembered :";
            cin>>suserid;

            ifstream f2("records.txt");
            while(f2>>sid>>spass)
            {
                if(sid==suserid)
                {
                    count=1;
                }
            }
            f2.close();
            if(count==1)
            {
                cout<<"\n\n your account is found ! \n";
                cout<<"\n\n your password is :"<<spass;
                main();
            }
            else{
                cout<<"\n\t sorry we dont found your account! \n";
                main();
            }
            break;

        }
        case 2:
        {
            main();
        }
        default:
        cout<<"\t\t\t wrong choice ! please try again"<<endl;
        forgot();

    }
}



