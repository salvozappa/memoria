#include "system.h"

int main( int argc, char* argv[] ) {

    cputs( "HELLO WORLD!" );
    // cursoff();
    while( !shuttingdown() ) {
        if( keystate( KEY_ESCAPE ) )  break;
    }

    return 0;
}
