#include "UserManager.h"

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
