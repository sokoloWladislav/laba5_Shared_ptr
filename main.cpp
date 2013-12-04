#include <iostream>
#include <list>
#include <Windows.h>
#include "contact.h"
#include "sharedpointer.h"

using namespace std;

void menu();
void output();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int k;
    list<SharedPointer<Contact> > allContacts;
    list<SharedPointer<Contact> > onlineContacts;
    list<SharedPointer<Contact> > bannedContacts;
    while(k)
    {
        system("cls");
        cout << "choise desirable action, please: " << endl;
        cout << "1 - add new contact" << endl;
        cout << "2 - show all contacts " << endl;
        cout << "3 - show online contacts " << endl;
        cout << "0 - exite " << endl;
        cin >> k;
        switch(k)
        {
        case 1:
        {
            SharedPointer<Contact> a(new Contact);
            allContacts.push_back(a);
            break;
        }
        case 2:
        {
            list<SharedPointer<Contact> >::iterator i;
            for(i=allContacts.begin; i!=allContacts.end; ++i)
                i->show;
            break;
        }
        case 3:
        {
            list<SharedPointer<Contact> >::iterator i;
            for(i=allContacts.begin; i!=allContacts.end; ++i)
                if(i->isOnline)
                    i->show;
            break;
        }
        case 0:
            break;
        }
    }
}

void output()
{

}
