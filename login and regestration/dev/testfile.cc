#include "UserManager.h"

int main() {
    UserManager userManager;

    // Test user registration
    User testUser1 = {"testuser1", "testpassword1"};
    userManager.registerUser(testUser1);

    // Test user login
    User testUser2 = {"testuser2", "testpassword2"};
    userManager.registerUser(testUser2);

    User loginAttempt = {"testuser2", "testpassword2"};
    userManager.loginUser(loginAttempt);

    return 0;
}
