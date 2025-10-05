#include <string>
#include <fstream>
#include "json.hpp"


using json = nlohmann::ordered_json;

json readSaveFile(int slot) {
    std::string savePath = "../saves/";
    savePath += std::to_string(slot);
    savePath += ".json";

    std::ifstream file(savePath);
                
    if (!file.is_open()) {
        std::cerr << "Error: failed to read save data\n" + savePath + "\n";
        return 1;
    }

    json j;
    file >> j;
    return j;
}

void createNewSave(int slot) {
    if (slot < 1 || slot > 4) {
        std::cerr << "Error: only saves 1-4 exist\nGot:" + std::to_string(slot) + "\n";
    } else {
        json j = readSaveFile(slot);

        if (!j["player"]["empty"]) {
            std::cout << "Player slot already full. Please chose another";
        } else {
            // name
            std::cout << "What is your name, wanderer?\n> ";
            std::string name_inp;
            std::cin >> name_inp;

            // gender
            int genderSelect;
            std::cout << genderSelect;

            int gender_inp;
            std::cin >> gender_inp;
            if (std::cin.fail()) {
                std::cerr << "Error: failed to read a valid input\nPlease ensure that you use integers only\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if (gender_inp < 1 || gender_inp > 3) {
                std::cerr << "Error: you can only pick from genders 1-3\nGot:" + std::to_string(gender_inp) + "\n";
            } else {
                std::string savePath = "../saves/" + std::to_string(slot) + ".json";

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
                }

                outFile << j.dump(4);
            }
        }
    }
}

void deleteSaveData(int slot) {
    if (slot < 1 || slot > 4) {
        std::cerr << "Error: only saves 1-4 exist\nGot:" + std::to_string(slot) + "\n";
    } else {
        std::string savePath = "../saves/" + std::to_string(slot) + ".json";
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
            return;
        }

        outFile << j.dump(4);
    }
}

int intGuard(int inp) {
    if (std::cin.fail()) {
        std::cerr << "Error: failed to read a valid input\nPlease ensure that you use integers only\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
    } else {
        return 0;
    }
}

