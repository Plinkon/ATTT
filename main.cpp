#include <iostream>
#include <vector>
#include <string>
#include "ATTT.hpp"

int main() {
    std::vector<std::string> commands = {
        "help",
        "about",
        "exit"
    };

    std::vector<std::string> users = {
        "admin"
    };

    std::vector<std::string> passwords = {
        ""
    };

    ATTT::AccountToolConfig config;
    ATTT::AccountTool accountTool(commands, users, passwords, config);

    std::string input = "";

    while (true) {
        std::cout << "Users: \n";

        for (int i = 0; i < users.size(); i++) {
            std::cout << users.at(i) << "\n";
        }
    
        std::cout << "Please enter a username to login to: ";
        std::getline(std::cin, input); // using getline incase if username has space and to handle incorrect inputs better
    
        if (!accountTool.authUser(input, "")) { // if user doesn't exist in list
            std::cout << "[Error]: user not in list.\nPress enter to retry.";
            getchar();
        }

        if (accountTool.authUser(input, "")) {
            std::cout << "Successfully logged in!\nPress enter to continue.";
            getchar();
            break;
        }
    }

    std::string username = input;
    input = "";

    while (true) { // loop once user is logged in
        clearScreen();
    
        input = "";
    
        std::cout << "Welcome, type \"help\" for more info\n";
        accountTool.printIdentifier(username);
    
        std::getline(std::cin, input);
    
        if (accountTool.checkInput(input, "help")) {
            std::cout << "\nhelp menu\n";
            std::cout << "commands:\nhelp\nabout\nexit\n";
            std::cout << "Press enter to continue...";
            getchar();
            clearScreen();
        } else if (accountTool.checkInput(input, "about")) {
            std::cout << "\nidk\n";
            std::cout << "Press enter to continue...";
            getchar();
            clearScreen();
        } else if (accountTool.checkInput(input, "exit")) {
            std::cout << "\nPress enter to exit..";
            getchar();
            break;
        } else {
            std::cout << "Unknown command. Type \"help\" to see all commands.\n";
            std::cout << "Press enter to continue...";
            getchar();
            clearScreen();
        }
    }
    

    return 0;
}