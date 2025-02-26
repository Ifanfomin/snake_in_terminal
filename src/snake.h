#pragma once
#include <cmath>

class Snake {
public:
    explicit Snake(size_t map_width, size_t map_height) {
        xpos = floor(map_width / 2);
        ypos = floor(map_height / 2);
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
    size_t len = 0;
    size_t vec = 0; // 0 - up, 3 - right, 6 - down, 9 - left
};
    