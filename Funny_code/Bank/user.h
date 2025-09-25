#ifndef USER_H 
#define USER_H

#include <string>

class User {
private:
    int Id;
    std::string Full_Name;
    std::string Account;
    std::string Password;
    int age;
    std::string Address;
    enum gender {Male, Famale};

public:

    User(int id, const std::string& name) : Id(id), Full_Name(name) {}

    int getId() const { return Id; }
    std::string getFullName() const { return Full_Name; }

    void setId(int id) { Id = id; }
    void setFullName(const std::string& name) { Full_Name = name; }
};

#endif
