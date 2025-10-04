#include "../assets/map.h"
#include "../scripts/opening.h"


int scene(Player player, int chapter, int page) {
    switch(chapter) {
        case 1:
            chapterOne(player, page);
            break;
        case 2:
            std::cout << MAP_B;
            break;
        default:
            std::cout << "Error: failed to read valid chapter code\nGot: " << chapter;
            break;      
    }

    return 0;
}
