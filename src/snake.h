#pragma once
#include <cmath>

class Snake {
public:
    explicit Snake(size_t map_width, size_t map_height) {
        xpos = floor(map_width / 2);
        ypos = floor(map_height / 2);
    }

    void stop_game() {
        run = false;
    }

    bool game_running() {
        return run;
    }

    void set_way(size_t input_way) {
        way = input_way;
    }

    void move(size_t FPS) {
        if (tick == floor(FPS / 3)) {
            tick = 0;
            switch (way) {
                case 'w':
                    ypos -= 1;
                    break;
            
                case 's':
                    ypos += 1;
                    break;
                
                case 'a':
                    xpos -= 1;
                    break;
            
                case 'd':
                    xpos += 1;
                    break;
                
                default:
                    break;
            }
        } else {
            tick++;
        }
    }

    size_t get_xpos() {
        return xpos;
    }

    size_t get_ypos() {
        return ypos;
    }
private:
    size_t tick = 0; 
    size_t xpos = 0;
    size_t ypos = 0;
    size_t len = 0;
    char way = 'd';
    bool run = true;
};
    