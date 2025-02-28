#pragma once
#include <iostream>

class Map {
public:
    Map() {
        width = 5;
        height = 5;
    }

    explicit Map(size_t user_width, size_t user_height)
    : width(user_width), height(user_height) {}
    void print_map(size_t snake_xpos, size_t snake_ypos, size_t apple_xpos, size_t apple_ypos) {
        clear();
        for (size_t i = 0; i < height; i++) {
            for (size_t j = 0; j < width; j++) {
                if (snake_ypos == i && snake_xpos == j) {
                    printw("%c", 'o');
                } else if (apple_ypos == i && apple_xpos == j) {
                    printw("%c", 'a');
                } else {
                    printw("%c", ' ');
                };
            }
            printw("\n");
        }
        refresh();
    }

    size_t get_width() {
        return width;
    }

    size_t get_height() {
        return height;
    }
private:
    size_t width = 0;
    size_t height = 0;
};