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

    bool splash_status = true;
    while (splash_status) {
            std::vector<std::string> names = {};

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

            std::string splash_print = "\nBE CREATIVE LIKE MAIN MENU" +
                splash_printer(names[0], names[1], names[2], names[3]).str()
                    + "Select a save ---------------------------{ (1-4)"
                    + "\nCreate new save -------------------------{ (N)"
                    + "\nDelete save -----------------------------{ (D)"
                    + "\nQuit ------------------------------------{ (Q)\n> ";

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
                    break;
                }

                json j;
                file >>j;
                file.close();

                if (j["player"]["empty"]) {
                    std::cerr << "Error: no save data available\n";
                    break;
                }

                player.setName(j["player"]["name"]);
                player.setGender(getGenderEnum(j["player"]["gender"]));
                int chapter = j["player"]["progress"]["chapter"];
                int page = j["player"]["progress"]["page"];


                scene(player, chapter, page);
                break;
            }
            case 'N':
                std::cout << "Which save would you like to use? -------{ (1-4)\n> ";
                int inp;
                std::cin >> inp;

                if (std::cin.fail()) {
                    std::cerr << "Error: failed to read a valid input\nPlease ensure that you use integers only\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                } else if (inp < 1 || inp > 4) {
                    std::cerr << "Error: only saves 1-4 exist\nGot:" + std::to_string(inp) + "\n";

                } else {
                    std::string savePath = "../saves/";
                    savePath += std::to_string(inp);
                    savePath += ".json";

                    std::ifstream file(savePath);
                    if (!file.is_open()) {
                        std::cerr << "Error: failed to read save data\n" + savePath + "\n";
                        return 1;
                    }

                    json j;
                    file >> j;
                    file.close();
                                        
                    if (!j["player"]["empty"]) {
                        std::cout << "Player slot already full. Please chose another";
                    } else {
                        std::cout << "What is your name, wanderer?\n> ";
                        std::string name_inp;
                        std::cin >> name_inp;
                        std::cout << "How would you like your character to be described?"
                                << "\nMale ------------------------------------{ (1)"
                                << "\nFemale ----------------------------------{ (2)"
                                << "\nOther -----------------------------------{ (3)\n> ";
                        int gender_inp;
                        std::cin >> gender_inp;
                        if (std::cin.fail()) {
                            std::cerr << "Error: failed to read a valid input\nPlease ensure that you use integers only\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        } else if (gender_inp < 1 || gender_inp > 3) {
                            std::cerr << "Error: you can only pick from genders 1-3\nGot:" + std::to_string(inp) + "\n";
                        } else {
                            std::string savePath = "../saves/" + std::to_string(inp) + ".json";

                            json j;
                            j["player"]["empty"]               = false;
                            j["player"]["name"]                = name_inp;
                            
                            switch (gender_inp) {
                                case 1:
                                    j["player"]["gender"] = "Male";
                                    break;
                                case 2:
                                    j["player"]["gender"] = "Female";
                                    break;
                                case 3:
                                    j["player"]["gender"] = "Other";
                                    break;
                                default:
                                    break;
                            }

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
                    }
                }
                break;
            case 'D':
                std::cout << "Which save would you like to delete? ----{ (1-4)\n> ";
                std::cin >> inp;

                if (std::cin.fail()) {
                    std::cerr << "Error: failed to read a valid input\nPlease ensure that you use integers only\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                } else if (inp < 1 || inp > 4) {
                    std::cerr << "Error: only saves 1-4 exist\nGot:" + std::to_string(inp) + "\n";

                } else {
                    std::string savePath = "../saves/" + std::to_string(inp) + ".json";

                    json j;
                    j["player"]["empty"]               = true;
                    j["player"]["name"]                = "Empty";
                    j["player"]["gender"]              = "Other";
                    j["player"]["inventory"]           = json::object();
                    j["player"]["health"]              = 0;
                    j["player"]["progress"]["chapter"] = 0;
                    j["player"]["progress"]["page"]    = 0;

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
                splash_status = false;
                break;
            default:
                std::cerr << "Error: invalid option\n";
                break;
            }
    }
    return 0;
}