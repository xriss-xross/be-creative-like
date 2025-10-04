#include <string>
#include <sstream>
#pragma once

std::ostringstream splash_printer(
    std::string name1,
    std::string name2,
    std::string name3,
    std::string name4) {
        return std::ostringstream{}
            << "\n"
            << "╔══════════════════════╗╔══════════════════════╗\n"
            << "║ Save 1               ║║ Save 2               ║\n"
            << "║ " << name1 << std::string(21 - name1.size(), ' ') << "║"
            << "║ " << name2 << std::string(21 - name2.size(), ' ') << "║\n"
            << "╚══════════════════════╝╚══════════════════════╝\n"
            << "╔══════════════════════╗╔══════════════════════╗\n"
            << "║ Save 3               ║║ Save 4               ║\n"
            << "║ " << name3 << std::string(21 - name3.size(), ' ') << "║"
            << "║ " << name4 << std::string(21 - name4.size(), ' ') << "║\n"
            << "╚══════════════════════╝╚══════════════════════╝\n";
}
