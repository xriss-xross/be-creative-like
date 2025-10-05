#pragma once

class Entity {
    protected:
        int health;
    public:
        void setHealth(int h) { health = h; }

        int getHealth() const { return health; }
};
