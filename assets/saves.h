#include <string>
#include <sstream>

std::ostringstream splash_printer(
    std::string name1,
    std::string name2,
    std::string name3,
    std::string name4) {
        return std::ostringstream{}
            << "\n=============================================================\n"
            << "╔══════════════════════╗╔══════════════════════╗\n"
            << "║ Save 1               ║║ Save 2               ║\n"
            << "║ " << name1 << std::string(21 - name1.size(), ' ') << "║"
            << "║ " << name2 << std::string(21 - name2.size(), ' ') << "║\n"
            << "╚══════════════════════╝╚══════════════════════╝\n"
            << "╔══════════════════════╗╔══════════════════════╗\n"
            << "║ Save 3               ║║ Save 4               ║\n"
            << "║ " << name3 << std::string(21 - name3.size(), ' ') << "║"
            << "║ " << name4 << std::string(21 - name4.size(), ' ') << "║\n"
            << "╚══════════════════════╝╚══════════════════════╝\n"
            << "Select a save ---------------------------{ (1-4)"
            << "\nCreate new save -------------------------{ (N)"
            << "\nDelete save -----------------------------{ (D)"
            << "\nQuit ------------------------------------{ (Q)\n> ";
}

std::string genderSelect = "How would you like your character to be described?"
                           "\nMale ------------------------------------{ (1)"
                           "\nFemale ----------------------------------{ (2)"
                           "\nOther -----------------------------------{ (3)\n> ";
