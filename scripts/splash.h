#include <limits>

#include "../assets/saves.h"

#include "scene.h"

int splash_screen(
    std::string name1,
    std::string name2,
    std::string name3,
    std::string name4) {
        std::string splash_print =
            splash_printer(name1, name2, name3, name4).str()
                + "\nSelect a save -------{ (1-4)"
                + "\nCreate new save -----{ (N)"
                + "\nDelete save ---------{ (D)"
                + "\nQuit ----------------{ (Q)\n\n";

        bool status = true;

        std::cout << splash_print;

        Player player;

        while (status) {
            char inp;
            std::cin >> inp;

            switch (inp) {
                case '1':
                    player.setGender(Gender::Male);
                    player.setName("Killian");
                    scene(player, 1, 1);
                case '2':
                    break;
                case '3':
                    break;
                case '4':
                    break;
                case 'N':
                    break;
                case 'D':
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