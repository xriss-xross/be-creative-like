#include <sstream>

#include "types.h"
#include "player.h"

std::ostringstream awaken(Player player, int page){
    Pronouns p = pronouns(player.getGender());
    
    switch (page)
    {
    case 1:
        return std::ostringstream{}
            << "Everything ached. As the sun roused " << p.obj << " from " << p.pos
            << " sleep,\n" << p.sub << " barely had enough energy to even register "
            << p.pos << "\nsurroundings - seagulls seemed to laugh at " << p.obj << " as "
            << p.sub << "\nslowly took them in. Trees stretched across the horizon,"
            << "\nbackdropped against darkening clouds, and at " << p.pos << " back,\n"
            << "waves, rushing, swathing.\n\n"
            << "1: Take a look around\n"
            << "2: Head towards distant structure\n";
    default:
        return std::ostringstream{} << "Coming soon!";
    }

}
