#include "text.h"

int chapterOne(Player player, int page) {
    std::cout << awaken(player, page).str();
    int inp;
    std::cin >> inp;

    if (std::cin.fail()) {
        std::cout << "Sorry, please only use numbers\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else if (inp == 1) {
        std::cout << "Looking around, ...\n";
    } else if (inp == 2) {
        std::cout << "Heading towards the structure, ...\n";
    } else {
        std::cout << "Choice not available\n";
    };

    return 0;
}
