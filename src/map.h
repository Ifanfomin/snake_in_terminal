#pragma once
#include <iostream>

class Map {
public:
    Map() {
        width = 5;
        height = 5;
        // create_map_();
    }

    explicit Map(size_t user_width, size_t user_height)
    : width(user_width), height(user_height) {
        // create_map_();
    }

    // void update_map(size_t snake_xpos, size_t snake_ypos) {
    //     for (size_t i = 0; i < height; i++) {
    //         for (size_t j = 0; j < width; j++) {
    //             if (snake_ypos == i && snake_xpos == j) {
    //                 map[i][j] = 'o';
    //             }
    //         }
    //     }
    // }

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
                // printw("%c", map[i][j]);
            }
            printw("\n");
            // printw(map[i]);
            // std::cout << map[i] << std::endl;
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
    char** map = nullptr;
    size_t width = 0;
    size_t height = 0;

    // void create_map_() {
    //     clear_();
    //     map = new char*[height];
    //     for (size_t i = 0; i < height; i++) {
    //         map[i] = new char[width];
    //         for (size_t j = 0; j < width; j++) {
    //             map[i][j] = '.';
    //         }
    //     }
    // }

    void clear_() {
        delete[] map;
    }
};