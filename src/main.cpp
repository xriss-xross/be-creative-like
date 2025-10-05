#include <iostream>
#include <limits>
#include <thread>
#include <chrono>

#include "../assets/logo.hpp"

#include "../scripts/player.hpp"
#include "../include/types.hpp"
#include "../scripts/splash.hpp"

int main() {
    // opening the .exe file messes up the special chars so have to be explicit
    std::setlocale(LC_ALL, ".UTF-8");

    std::cout << LOGO;

    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    // runtime loop starts here
    bool status = true;
    while (status) {
        splash_screen();

        status = false;
    }

    return 0;
}
