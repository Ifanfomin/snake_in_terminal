#pragma once
#include <cmath>
#include <vector>

class Snake {
public:
    class Head {              /// Head ///
    public:
        void set_pos(size_t map_width, size_t map_height) {
            xpos = floor(map_width / 2);
            ypos = floor(map_height / 2);
        }

        void set_way(size_t input_way) {
            way = input_way;
        }

        void move(size_t FPS) {
            if (tick == floor(FPS / speed)) {
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
        size_t xpos = 0;
        size_t ypos = 0;
        char way = 'd';
        size_t tick = 0; 
    };                   /// Head end ///

    class Tail {
    public:
        void set_pos(size_t x_pos, size_t y_pos) {
            xpos = x_pos;
            ypos = y_pos;
        }

        void set_way(size_t input_way) {
            way = input_way;
        }

        void move(size_t FPS) {
            if (tick == floor(FPS / speed)) {
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
    private:
        size_t xpos = 0;
        size_t ypos = 0;
        char way = 'd';
        size_t tick = 0; 
    };
    
    explicit Snake(size_t map_width, size_t map_height) {
        head.set_pos(map_width, map_height);
    }

    void eat() {}

    void move(size_t FPS) {
        head.move(FPS);
    }

    Head* get_head() {
        return &head;
    }

    void stop_game() {
        run = false;
    }

    bool game_running() {
        return run;
    }

private:
    Head head = Head();
    std::vector<Tail> tail;
    static const size_t speed = 10;
    size_t len = 0;
    bool run = true;
};
    