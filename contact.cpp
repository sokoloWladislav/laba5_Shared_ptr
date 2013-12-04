#include "contact.h"
#include <iostream>

using namespace std;

Contact::Contact()
{
    name=new char[20];
    cout << "Enter the user name: " << endl;
    cin >> name;
    status=offline;
    ban=false;
}

Contact::~Contact()
{
    delete name;
    name=0;
}

void Contact::show()
{
    cout.width(20);
    cout << name << ' ';
    if(status==offline)
        cout << "offline" << endl;
    else
        cout << "online" << endl;
}

bool Contact::isOnline()
{
    if(status==online)
        return true;
    else
        return false;
}

bool Contact::isBanned()
{
    if(ban)
        return true;
    else
        return false;
}
