#include "map.h"
#include "snake.h"
#include "apple.h"

char event(float delay) {
    char key = ' ';
    halfdelay(delay);
    key = getch();
    return key;
}

void events(char key, Snake *snake, Apple *apple, Map *map) {
    switch (key) {
    case 'q':
        snake->stop_game();
        break;
    case 'w':
        snake->get_head()->set_way(key);
        break;

    case 's':
        snake->get_head()->set_way(key);
        break;
    
    case 'a':
        snake->get_head()->set_way(key);
        break;

    case 'd':
        snake->get_head()->set_way(key);
        break;
    
    default:
        break;
    }

    if (
        snake->get_head()->get_xpos() == apple->get_xpos() && 
        snake->get_head()->get_ypos() == apple->get_ypos()
    ) {
        apple->replace(map->get_width(), map->get_height());
        snake->eat();
    };
}