#include <iostream>
#include <cmath>
#include <ncurses.h>
#include "src/map.h"
#include "src/snake.h"
#include "src/apple.h"
#include "src/events.h"

int main(int, char**){
    // Загрузка
    Map map = Map(40, 20);
    Snake snake = Snake(map.get_width(), map.get_height());
    Apple apple = Apple(map.get_width(), map.get_height());
    char key = ' ';
    bool run = true;
    int FPS = 10;
    int second = 10;

    initscr();
    raw();
    noecho();

    while (snake.game_running()) {

        /// Действия ///
        events(event(second / FPS), &snake, &apple, &map);
        snake.move(FPS);

        /// Отрисовка ///
        map.print_map(
            snake.get_head()->get_xpos(), snake.get_head()->get_ypos(), 
            apple.get_xpos(), apple.get_ypos()
        );    
    }
    endwin();
}
