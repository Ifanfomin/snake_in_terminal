#pragma once
#include <random>
#include <cmath>
#include <ctime>

class Apple {
public:
    Apple(size_t width, size_t hieght) {
        srand(time(0));
        xpos = floor(rand() % (width + 1));
        ypos = floor(rand() % (hieght + 1));
    }

    void replace(size_t snake_xpos, size_t snake_ypos, size_t width, size_t hieght) {
        if (snake_xpos == xpos && snake_ypos == ypos) {
            xpos = floor(rand() % width);
            ypos = floor(rand() % hieght);
        };
    }

    size_t get_xpos() {
        return xpos;
    }

    size_t get_ypos() {
        return ypos;
    }
private:
    size_t xpos = 0;
    size_t ypos = 0;
};