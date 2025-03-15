#include <iostream>
#include <vector>
#include <string>

void clearScreen() {
    std::cout << "\033[H";
}

bool find(std::vector<std::string> data, std::string searchStr) { // a simple searching algorithm
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == searchStr) return true;
    }

    return false;
}

int main() {
    std::vector<std::string> users = {
        "admin",
        "bob",
        "user2"
    };

    while (true) {
        std::cout << "Users: \n";

        for (int i = 0; i < users.size(); i++) {
            std::cout << users.at(i) << "\n";
        }
    
        std::cout << "Please enter a username to login to: ";
    
        std::string input = "";
        std::getline(std::cin, input); // using getline incase if username has space and to handle incorrect inputs better
    
        if (!find(users, input)) { // if user doesn't exist in list
            std::cout << "[Error]: user not in list.\nPress any button to retry.";
            getchar();
        }

        if (find(users, input)) {
            std::cout << "Successfully logged in!\nPress any button to continue.";
            getchar();
            break;
        }
    }

    while (true) { // loop once user is logged in
        clearScreen();
    }

    return 0;
}