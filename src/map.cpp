#include <iostream>
#include <vector>
#include <ncurses.h>

#include "snake.h"
#include "map.h"

Map::Map() {
    width = 5;
    height = 5;
}

Map::Map(size_t user_width ,size_t user_height) {
    width = user_width;
    height = user_height;
}

void Map::print_map(
    size_t snake_xpos, size_t snake_ypos, 
    std::vector<Snake::Tail> tail, 
    size_t apple_xpos, size_t apple_ypos
) {
    clear();
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            piece_drow = false;
            for (auto& piece : tail) {
                if (piece.get_ypos() == i && piece.get_xpos() == j) {
                    printw("%c", 'o');
                    piece_drow = true;
                    break;
                }
            }
            if (snake_ypos == i && snake_xpos == j && !piece_drow) {
                printw("%c", 'o');
            } else if (apple_ypos == i && apple_xpos == j && !piece_drow) {
                printw("%c", 'a');
            } else if (!piece_drow) {
                printw("%c", ' ');
            };
        }
        printw("\n");
    }
    refresh();
}

size_t Map::get_width() {
    return width;
}

size_t Map::get_height() {
    return height;
}
