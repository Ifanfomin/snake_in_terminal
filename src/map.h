#ifndef MAP_H
#define MAP_H

#include <vector>
#include "snake.h"

class Map {
public:
    Map();
    explicit Map(size_t user_width ,size_t user_height);
    void print_map(
        size_t snake_xpos, size_t snake_ypos, 
        std::vector<Snake::Tail> tail, 
        size_t apple_xpos, size_t apple_ypos
    );
    
    size_t get_width();

    size_t get_height();

private:
    size_t width = 0;
    size_t height = 0;
    bool piece_drow = false;
};

#endif
