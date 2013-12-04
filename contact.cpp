#include "contact.h"
#include <iostream>

using namespace std;

/*Contact::Contact()
{
    name=new char[20];
    cout << "Enter the user name: " << endl;
    cin >> name;
}*/

/*Contact::~Contact()
{
    delete name;
    name=0;
}*/

ContactOnline::ContactOnline()
{
    name=new char[20];
    cout << "Enter the user name: " << endl;
    cin >> name;
    status=online;
}

ContactBanned::ContactBanned()
{
    name=new char[20];
    cout << "Enter the user name: " << endl;
    cin >> name;
    ban=false;
}

void ContactOnline::show()
{
    cout.width(20);
    cout << name << ' ' << status << endl;
}

void ContactBanned::show()
{
    cout.width(20);
    cout << name << ' ';
    if(ban)
        cout << "banned" << endl;
    else
        cout << "unbanned" << endl;
}
