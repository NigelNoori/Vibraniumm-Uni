#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

class PasswordManager {
public:
    PasswordManager();
    void run();

private:
    struct Credential {
        std::string website;
        std::string username;
        std::string password;
    };

    std::vector<Credential> credentials;
    std::string masterPassword;

    void loadCredentials();
    void saveCredentials();
    void printMenu();
    void addCredential();
    void viewCredentials();
    void updateCredential();
    void deleteCredential();
    bool authenticate();
};

#endif // PASSWORDMANAGER_H
