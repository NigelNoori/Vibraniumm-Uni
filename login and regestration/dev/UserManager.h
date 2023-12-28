#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct User {
    string username;
    string password;
};

class UserManager {
private:
    vector<User> users;

public:
    UserManager();
    void loadUsers();
    void saveUsers();
    bool registerUser(const User& newUser);
    bool loginUser(const User& loginUser);
};

#endif // USERMANAGER_H
