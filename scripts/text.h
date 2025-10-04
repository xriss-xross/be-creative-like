#include <sstream>

#include "../assets/sun.h"

#include "types.h"
#include "player.h"

std::ostringstream awaken(Player player, int page){
    Pronouns p = pronouns(player.getGender());
    
    switch (page) {
        case 1:
            return std::ostringstream{}
                << "\n============================================================="
                << SUN << "Everything ached. As the sun roused " << p.obj << " from " << p.pos
                << " sleep,\n" << p.sub << " barely had enough energy to even register "
                << p.pos << "\nsurroundings - seagulls seemed to laugh at " << p.obj << " as "
                << p.sub << "\nslowly took them in. Trees stretched across the horizon,"
                << "\nbackdropped against darkening clouds, and at " << p.pos << " back,\n"
                << "waves, rushing, swathing.\n\n"
                << "1: Take a look around\n> ";
        case 2:
            return std::ostringstream{}
                << "Absolutely nothing remarkable to be seen. " << player.getName() 
                << " could\nonly be thankful that " << p.sub << " had the clothes on "
                << p.pos << " back.\nIn the distance an unnatural shape juts out from" 
                << " under the palms.\n" << "+1 simple clothes\n\n1: Take a look around\n"
                << "2: Head towards structure\n> ";
        default:
            break;
    }

}
