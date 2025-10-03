#include <string>
#include <iostream>

using std::cout;

class Entity {
    protected:
        int health;
    public:
        Entity(int h) : health(h) {}
        int getHealth() const { return health; }
};

class Player : public Entity {
    private:
        std::string name;
    public:
        Player(std::string n, int h) : Entity(h), name(n) {}
        
        std::string getName() const { return name; }
};

int main() {
    Player killian {"Killian", 100};
    cout << killian.getName() << " is on " << killian.getHealth() << " HP\n";
};
