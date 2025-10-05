#include "text.hpp"

int chapterOne(Player player, int page) {
    std::cout << awaken(player, page).str();
    int inp;
    std::cin >> inp;

    if (std::cin.fail()) {
        std::cout << "Sorry, please only use numbers\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else if (inp == 1) {
        std::cout << awaken(player, 2).str();
    } else {
        std::cerr << "Error: choice not available";
    }

    return 0;
}
