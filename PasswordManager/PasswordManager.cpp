#include "PasswordManager.h"

PasswordManager::PasswordManager() {
    if (authenticate()) {
        loadCredentials();
    } else {
        std::cout << "Authentication failed. Exiting.\n";
        exit(EXIT_FAILURE);
    }
}

void PasswordManager::run() {
    while (true) {
        printMenu();

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addCredential();
                break;
            case 2:
                viewCredentials();
                break;
            case 3:
                updateCredential();
                break;
            case 4:
                deleteCredential();
                break;
            case 5:
                saveCredentials();
                std::cout << "Exiting Password Manager.\n";
                exit(EXIT_SUCCESS);
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void PasswordManager::loadCredentials() {
    std::ifstream inputFile("credentials.txt");
    if (inputFile.is_open()) {
        Credential credential;
        while (inputFile >> credential.website >> credential.username >> credential.password) {
            credentials.push_back(credential);
        }
        inputFile.close();
    }
}

void PasswordManager::saveCredentials() {
    std::ofstream outputFile("credentials.txt");
    for (const auto& credential : credentials) {
        outputFile << credential.website << " " << credential.username << " " << credential.password << std::endl;
    }
    outputFile.close();
}

void PasswordManager::printMenu() {
    std::cout << "\nPassword Manager Menu:\n";
    std::cout << "1. Add Credential\n";
    std::cout << "2. View Credentials\n";
    std::cout << "3. Update Credential\n";
    std::cout << "4. Delete Credential\n";
    std::cout << "5. Exit\n";
}

void PasswordManager::addCredential() {
    Credential newCredential;
    std::cout << "Enter website: ";
    std::cin.ignore();
    std::getline(std::cin, newCredential.website);
    std::cout << "Enter username: ";
    std::getline(std::cin, newCredential.username);
    std::cout << "Enter password: ";
    std::getline(std::cin, newCredential.password);

    credentials.push_back(newCredential);
    std::cout << "Credential added successfully.\n";
}

void PasswordManager::viewCredentials() {
    if (credentials.empty()) {
        std::cout << "No credentials to display.\n";
    } else {
        std::cout << "\nCredentials:\n";
        std::cout << std::left << std::setw(20) << "Website" << std::setw(20) << "Username" << "Password\n";
        for (const auto& credential : credentials) {
            std::cout << std::left << std::setw(20) << credential.website
                      << std::setw(20) << credential.username
                      << credential.password << std::endl;
        }
    }
}

void PasswordManager::updateCredential() {
    if (credentials.empty()) {
        std::cout << "No credentials to update.\n";
        return;
    }

    std::cout << "Enter the website to update: ";
    std::string website;
    std::cin.ignore();
    std::getline(std::cin, website);

    auto it = std::find_if(credentials.begin(), credentials.end(),
                           [website](const Credential& c) { return c.website == website; });

    if (it != credentials.end()) {
        std::cout << "Enter new username: ";
        std::getline(std::cin, it->username);
        std::cout << "Enter new password: ";
        std::getline(std::cin, it->password);
        std::cout << "Credential updated successfully.\n";
    } else {
        std::cout << "Credential not found.\n";
    }
}

void PasswordManager::deleteCredential() {
    if (credentials.empty()) {
        std::cout << "No credentials to delete.\n";
        return;
    }

    std::cout << "Enter the website to delete: ";
    std::string website;
    std::cin.ignore();
    std::getline(std::cin, website);

    auto it = std::remove_if(credentials.begin(), credentials.end(),
                             [website](const Credential& c) { return c.website == website; });

    if (it != credentials.end()) {
        credentials.erase(it, credentials.end());
        std::cout << "Credential deleted successfully.\n";
    } else {
        std::cout << "Credential not found.\n";
    }
}

bool PasswordManager::authenticate() {
    std::cout << "Enter master password: ";
    std::cin >> masterPassword;

    // Perform authentication logic here (e.g., check against a stored master password)
    // For simplicity, this example always returns true. In a real application, you would
    // implement secure authentication mechanisms.

    return true;
}
