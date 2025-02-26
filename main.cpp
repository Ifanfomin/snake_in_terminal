#include <iostream>
#include <cmath>
#include <ncurses.h>
#include "src/map.h"
#include "src/snake.h"


int main(int, char**){
    Map map = Map(11, 11);
    Snake snake = Snake(map.get_width(), map.get_height());
    map.update_map(snake.get_xpos(), snake.get_ypos());
    map.print_map();
}
