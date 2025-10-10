#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    int id;
    std::string fullName;
    std::string account;
    std::string password;
    int age;
    std::string* address;

    enum Gender { Male, Female };

public:
    User(){}
    User() { address = new std::string; }
    ~User(){ delete address;}

    int getId() const { return id; }
    std::string getFullName() const { return fullName; }

    void setId(int newId) { id = newId; }
    void setFullName(const std::string& name) { fullName = name; }
};

#endif
