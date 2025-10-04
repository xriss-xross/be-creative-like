#include <iostream>
#include <limits>
#include <thread>
#include <chrono>

#include "../assets/logo.h"
#include "../scripts/scene.h"
#include "../scripts/player.h"
#include "../scripts/types.h"

int main() {
    // opening the .exe file messes up the special chars so have to be explicit
    std::setlocale(LC_ALL, ".UTF-8");

    std::cout << LOGO;

    // TEST CODE
    Player player;
    player.setGender(Gender::Female);
    player.setName("Misha");
    // TEST CODE

    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "\n=============================================================\n\n";

    // runtime loop starts here
    bool status = true;
    while (status) {
        scene(player, 1, 1);

        // TEST CODE TO PREVENT EXIT
        std::cout << "Enter any character to exit";
        int inp;
        std::cin >> inp;
        status = false;
    }

    return 0;
}
