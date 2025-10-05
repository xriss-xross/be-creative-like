#include "../include/json.hpp"
#include "../include/save_utils.hpp"

#include "../assets/saves.hpp"

#include "scene.hpp"

using json = nlohmann::ordered_json;

int splash_screen() {
    bool splash_status = true;
    while (splash_status) {
        std::vector<std::string> names = {};

        for (int i = 1; i <= 4; i++) {
            json j = readSaveFile(i);
            names.push_back(j["player"]["name"]);
        }
        
        std::string splash_print = "\nBE CREATIVE LIKE MAIN MENU" +
            splash_printer(names[0], names[1], names[2], names[3]).str();

        std::cout << splash_print;

        char inp;
        std::cin >> inp;

        switch (inp) {
            case '1':
            case '2':
            case '3':
            case '4': {
                Player player;

                int inpI = inp - '0';
                json j = readSaveFile(inpI);

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

                createNewSave(inp);

                break;
            case 'D':
                std::cout << "Which save would you like to delete? ----{ (1-4)\n> ";
                std::cin >> inp;

                if (intGuard(inp) == 1) {
                    break;
                }
                
                deleteSaveData(inp);
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