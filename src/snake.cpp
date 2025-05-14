#include <cmath>
#include <vector>

#include "snake.h"

// Cell //
void Snake::Cell::set_pos(size_t x_pos, size_t y_pos) {
    xpos = x_pos;
    ypos = y_pos;
}

void Snake::Cell::set_way(size_t input_way) {
    way = input_way;
}

void Snake::Cell::move(size_t FPS) {
    if (tick == floor(FPS / speed)) {
        if (run == 1) {
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
            ++run;
        }
    } else {
        ++tick;
    }
}

size_t Snake::Cell::get_xpos() {
    return xpos;
}

size_t Snake::Cell::get_ypos() {
    return ypos;
}

char Snake::Cell::get_way() {
    return way;
}

// Head //
void Snake::Head::set_pos(size_t map_width, size_t map_height) {
    xpos = floor(map_width / 2);
    ypos = floor(map_height / 2);
}

// Tail //
Snake::Tail::Tail() = default;

Snake::Tail::Tail(size_t x, size_t y, char w) {
    xpos = x;
    ypos = y;
    way = w;
}

// Snake //
Snake::Snake(size_t map_width, size_t map_height) {
    head.set_pos(map_width, map_height);
}

void Snake::eat() {
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

void Snake::move(size_t FPS) {
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

Snake::Head* Snake::get_head() {
    return &head;
}

std::vector<Snake::Tail> Snake::get_tail() {
    return tail;
}

void Snake::stop_game() {
    run = false;
}

bool Snake::game_running() {
    return run;
}
