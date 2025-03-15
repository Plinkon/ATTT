#ifndef ATT_HPP
#define ATT_HPP

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include "colors.hpp"

void clearScreen() {
    std::cout << "\033c\033[2J\033[H";
}

namespace ATTT {

    class AccountToolConfig {
    public:
        std::string prefix = "@"; // character before name
        std::string suffix = ": "; // character after name
        std::string searchChar = "$"; // search character, default is '$'
        std::string usernameColor = Colorify::codes[Colorify::getColorIndex("Green (FG)")];
        std::string prefixColor = Colorify::codes[Colorify::getColorIndex("Meadow Green (FG)")];
        std::string suffixColor = Colorify::codes[Colorify::getColorIndex("Meadow Green (FG)")];
        std::string searchColor = Colorify::codes[Colorify::getColorIndex("Reset All")];
        std::string commandColor = Colorify::codes[Colorify::getColorIndex("Reset All")];
    };

    class AccountTool {
    private:
        std::vector<std::string> users;
        std::vector<std::string> passwords;
        std::vector<std::string> commands;
        AccountToolConfig config;

        // Now takes the vector and string by const reference to avoid unnecessary copies
        bool find(const std::vector<std::string>& data, const std::string& searchStr) { 
            for (const auto& item : data) {
                if (item == searchStr) return true;
            }
            return false;
        }
    public:
        AccountTool(std::vector<std::string> commands, std::vector<std::string> users, std::vector<std::string> passwords, AccountToolConfig& config)
            : commands(commands), users(users), passwords(passwords), config(config) {}

        ~AccountTool() = default;

        // Case-insensitive full string comparison using standard library
        bool checkInput(std::string input, std::string compare) {
            std::transform(input.begin(), input.end(), input.begin(), ::tolower);
            std::transform(compare.begin(), compare.end(), compare.begin(), ::tolower);
            return input == compare;
        }

        bool authUser(std::string name, std::string pass) {
            // Note: This simple authentication just checks if the username exists
            // and the password exists somewhere in the passwords list.
            return find(users, name) && find(passwords, pass);
        } 

        void printIdentifier(std::string username) {
            std::cout << config.prefixColor + config.prefix 
                      << config.usernameColor + username 
                      << config.suffixColor + config.suffix 
                      << config.searchColor + config.searchChar 
                      << config.commandColor;
        }

        bool isCommand(std::string input) {
            for (const auto& cmd : commands) {
                if (checkInput(input, cmd)) return true;
            }
            return false;
        }
    };
};

#endif // ATT_HPP
