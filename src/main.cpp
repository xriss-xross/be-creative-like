#include <iostream>
#include <limits>
#include <thread>
#include <chrono>

#include "../assets/logo.h"

#include "../scripts/player.h"
#include "../scripts/types.h"
#include "../scripts/splash.h"

int main() {
    // opening the .exe file messes up the special chars so have to be explicit
    std::setlocale(LC_ALL, ".UTF-8");

    std::cout << LOGO;

    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    // runtime loop starts here
    bool status = true;
    while (status) {
        splash_screen("Killian", "Empty", "Empty", "Empty");

        // TEST CODE TO PREVENT EXIT
        std::cout << "Enter any character to exit";
        int inp;
        std::cin >> inp;
        status = false;
    }

    return 0;
}
