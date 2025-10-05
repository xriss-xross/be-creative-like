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

Gender getGenderEnum(std::string player_gender) {
    if (player_gender == "Male") {
        return Gender::Male;
    } else if (player_gender == "Female") {
        return Gender::Female;
    } else {
        return Gender::Other;
    }
}
        
std::string getGenderString(Gender player_gender) { 
    switch (player_gender){
        case Gender::Male:
            return "Male";
        case Gender::Female:
            return "Female";
        case Gender::Other:
            return "Other";
        default:
            return "Undefined";
    }
}
