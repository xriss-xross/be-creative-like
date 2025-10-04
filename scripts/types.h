#include <string>

#pragma once

enum class Gender {
    Male,
    Female,
    Other
};

struct Pronouns {
    std::string sub;
    std::string obj;
    std::string pos;
};

Pronouns pronouns(Gender player_gender) {
    switch (player_gender) {
        case Gender::Male:
            return {"he", "him", "his"};
        case Gender::Female:
            return {"she", "her", "her"};
        default:
            return {"they", "them", "their"};
    }
}
