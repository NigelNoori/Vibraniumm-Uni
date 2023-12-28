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
    UserManager() {
        loadUsers();
    }

    void loadUsers() {
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

    void saveUsers() {
        ofstream outputFile("users.txt");
        for (const auto& user : users) {
            outputFile << user.username << " " << user.password << endl;
        }
        outputFile.close();
    }

    bool registerUser(const User& newUser) {
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

    bool loginUser(const User& loginUser) {
        for (const auto& user : users) {
            if (user.username == loginUser.username && user.password == loginUser.password) {
                cout << "Login successful. Welcome, " << loginUser.username << "!\n";
                return true;
            }
        }
        cout << "Invalid username or password. Please try again.\n";
        return false;
    }
};

int main() {
    UserManager userManager;

    while (true) {
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                User newUser;
                cout << "Enter username: ";
                cin >> newUser.username;
                cout << "Enter password: ";
                cin >> newUser.password;
                userManager.registerUser(newUser);
                break;
            }
            case 2: {
                User loginUser;
                cout << "Enter username: ";
                cin >> loginUser.username;
                cout << "Enter password: ";
                cin >> loginUser.password;
                if (userManager.loginUser(loginUser)) {
                    // Successfully logged in, perform any additional actions here
                }
                break;
            }
            case 3:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
