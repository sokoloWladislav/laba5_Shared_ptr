#ifndef CONTACT_H
#define CONTACT_H

typedef enum userStatus {online, offline} userStatus;
typedef bool property;

class Contact
{
public:
    virtual void show();
};

class ContactOnline:public Contact
{
    char *name;
    userStatus status;
public:
    ContactOnline();
    void show();
};

class ContactBanned:public Contact
{
    char *name;
    property ban;
public:
    ContactBanned();
    void show();
};

#endif // CONTACT_H
