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

        char get_way() {
            return way;
        }

    private:
        size_t xpos = 0;
        size_t ypos = 0;
        char way = 'd';
        size_t tick = 0; 
    };                   /// Head end ///

    class Tail {
    public:
        Tail() = default;
        Tail(size_t x, size_t y, char w) {
            xpos = x;
            ypos = y;
            way = w;
        }
        
        void set_pos(size_t x_pos, size_t y_pos) {
            xpos = x_pos;
            ypos = y_pos;
        }

        void set_way(size_t input_way) {
            way = input_way;
        }

        void move(size_t FPS) {
            if (tick == floor(FPS / speed)) {
                if (run == 0) {
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
                    --run;
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

        char get_way() {
            return way;
        }

    private:
        size_t xpos = 0;
        size_t ypos = 0;
        char way = 'd';
        size_t tick = 0; 
        size_t run = 1;
    };
    
    explicit Snake(size_t map_width, size_t map_height) {
        head.set_pos(map_width, map_height);
    }

    void eat() {
        size_t tail_size = tail.size();
        if (tail_size == 0) {
            tail_piece = Tail(
                head.get_xpos(), 
                head.get_ypos(), 
                head.get_way()
            );
        } else {
            tail_piece = Tail(
                tail[tail_size - 1].get_xpos(), 
                tail[tail_size - 1].get_ypos(), 
                tail[tail_size - 1].get_way()
            );
        }
        tail.push_back(tail_piece);
    }

    void move(size_t FPS) {
        head.move(FPS);
        size_t tail_size = tail.size();
        if (tail_size > 0) {
            for (int index = tail_size - 1; index >= 0; --index) {
                if (index == 0) {
                    tail[index].move(FPS);
                    tail[index].set_way(head.get_way());
                } else {
                    tail[index].move(FPS);
                    tail[index].set_way(tail[index - 1].get_way());
                }
            }
        }
    }
// 0, 1, 2, 3, 4, 5, 6
    Head* get_head() {
        return &head;
    }

    std::vector<Tail> get_tail() {
        return tail;
    }

    void stop_game() {
        run = false;
    }

    bool game_running() {
        return run;
    }

private:
    Head head = Head();
    Tail tail_piece = Tail();
    std::vector<Tail> tail;
    static const size_t speed = 10;
    size_t len = 0;
    bool run = true;
};
    