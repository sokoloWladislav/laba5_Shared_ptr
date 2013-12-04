#ifndef CONTACT_H
#define CONTACT_H

typedef enum userStatus {online, offline} userStatus;
typedef bool property;

class Contact
{
    char *name;
    userStatus status;
    property ban;
    Contact(const Contact& other);
    Contact& operator = (const Contact& other);
public:
    Contact();
    ~Contact();
    void show();
    bool isOnline();
    bool isBanned();
};

#endif // CONTACT_H
