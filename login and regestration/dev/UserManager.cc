#include "UserManager.h"

UserManager::UserManager() {
    loadUsers();
}

void UserManager::loadUsers() {
    ifstream inputFile("users.txt");
    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            User user;
            inputFile >> user.username >> user.password;
            if (!user.username.empty() && !user.password.empty()) {
                users.push_back(user);
            }
        }
        inputFile.close();
    }
}

void UserManager::saveUsers() {
    ofstream outputFile("users.txt");
    for (const auto& user : users) {
        outputFile << user.username << " " << user.password << endl;
    }
    outputFile.close();
}

bool UserManager::registerUser(const User& newUser) {
    for (const auto& user : users) {
        if (user.username == newUser.username) {
            cout << "Username already exists. Please choose another username.\n";
            return false;
        }
    }
    users.push_back(newUser);
    saveUsers();
    cout << "Registration successful.\n";
    return true;
}

bool UserManager::loginUser(const User& loginUser) {
    for (const auto& user : users) {
        if (user.username == loginUser.username && user.password == loginUser.password) {
            cout << "Login successful. Welcome, " << loginUser.username << "!\n";
            return true;
        }
    }
    cout << "Invalid username or password. Please try again.\n";
    return false;
}
