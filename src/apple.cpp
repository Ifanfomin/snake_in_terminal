#include <random>
#include <cmath>
#include <ctime>

#include "apple.h"

Apple::Apple(size_t width, size_t hieght) {
    srand(time(0));
    xpos = floor(rand() % (width));
    ypos = floor(rand() % (hieght));
}

void Apple::replace(size_t width, size_t hieght) {
    xpos = floor(rand() % width);
    ypos = floor(rand() % hieght);
}

size_t Apple::get_xpos() {
    return xpos;
}


size_t Apple::get_ypos() {
    return ypos;
}

