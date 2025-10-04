#include <limits>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

#include "../include/json.hpp"

#include "../assets/saves.h"

#include "scene.h"

using json = nlohmann::ordered_json;

int splash_screen() {
    std::vector<std::string> names;
    for (int i = 1; i <= 4; i++) {
        std::string savePath = "../saves/";
        savePath += std::to_string(i);
        savePath += ".json";

        std::ifstream file(savePath);
        if (!file.is_open()) {
            std::cerr << "Error: failed to read save data\n" + savePath + "\n";
            return 1;
        }

        json j;
        file >> j;
        names.push_back(j["player"]["name"]);

        file.close();
    }

    std::string splash_print =
        splash_printer(names[0], names[1], names[2], names[3]).str()
            + "\nSelect a save ---------------------------{ (1-4)"
            + "\nCreate new save -------------------------{ (N)"
            + "\nDelete save -----------------------------{ (D)"
            + "\nQuit ------------------------------------{ (Q)\n\n";

    bool status = true;
    while (status) {
        std::cout << splash_print;

        char inp;
        std::cin >> inp;

        switch (inp) {
            case '1':
            case '2':
            case '3':
            case '4': {
                Player player;

                std::string savePath = "../saves/";
                savePath += inp;
                savePath += ".json";

                std::ifstream file(savePath);
                if (!file.is_open()) {
                    std::cerr << "Error: failed to read save data\n";
                    return 1;
                }
                json j;
                file >> j;

                player.setName(j["player"]["name"]);
                player.setGender(getGenderEnum(j["player"]["gender"]));
                int chapter = j["player"]["progress"]["chapter"];
                int page = j["player"]["progress"]["page"];

                file.close();

                scene(player, chapter, page);
                break;
            }
            case 'N':
                break;
            case 'D':
                std::cout << "Which save would you like to delete? ----{ (1-4)\n";
                int inp;
                std::cin >> inp;

                if (std::cin.fail()) {
                    std::cout << "Error: failed to read a valid input\nPlease ensure that you use integers only\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                } else if (inp < 1 || inp > 4) {
                    std::cout << "Error: only saves 1-4 exist\nGot:" + std::to_string(inp);

                } else {
                    std::string savePath = "../saves/" + std::to_string(inp) + ".json";

                    json j;
                    j["player"]["name"]                = "Empty";
                    j["player"]["gender"]              = "Other";
                    j["player"]["inventory"]           = json::object();
                    j["player"]["health"]              = 100;
                    j["player"]["progress"]["chapter"] = 1;
                    j["player"]["progress"]["page"]    = 1;

                    std::ofstream outFile(savePath, std::ios::trunc);
                    if (!outFile.is_open()) {
                        std::cerr << "Error: failed to write save data\n";
                        break;
                    }
                    outFile << j.dump(4);
                    outFile.close();
                }

                break;
            case 'Q':
                break;
            default:
                break;
            }
            status = false;
    }
    return 0;
}