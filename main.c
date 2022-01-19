
#include <SDL2/SDL.h>
#include "global.h"

#include "main-function.h"
#include "event.h"
int main() {
    CreatePlayWindow();
    CreateMyPlane();
    event();
    Destroy();
    return 0;
}
