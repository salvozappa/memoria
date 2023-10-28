// Sound and music example. The code is public domain, the
// wav file is from Warcraft 2 audio setup, the midi file
// is from Simon the Sorcerer, the mus file is from Doom.
//      /Mattias Gustavsson

#include "dos.h"

int main( int argc, char* argv[] ) {

    cputs( "HELLO WORLD!" );
    // cursoff();
    while( !shuttingdown() ) {
        if( keystate( KEY_ESCAPE ) )  break;
    }

    return 0;
}
