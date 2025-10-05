#include <map>

#include "../include/types.hpp"
#include "entity.hpp"

#pragma once

class Player : public Entity {
    private:
        Gender gender;
        std::string name;
        std::map<std::string, int> inventory;
    public:
        Player():
            gender(Gender::Other),
            name("DEFAULT"),
            inventory( { {"Clothes on your back", 1} } )
        {}

        void setName(const std::string n) { name = n; }
        void setGender(const Gender g) { gender = g; }

        std::string getName() const { return name; }
        std::map<std::string, int> getInventory() const { return inventory; }
        Gender getGender() const { return gender; }

};
