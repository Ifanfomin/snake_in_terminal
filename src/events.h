#include "map.h"
#include "snake.h"

char event(float delay) {
    char key = ' ';
    halfdelay(delay);
    key = getch();
    return key;
}

void events(char key, Snake *snake) {
    switch (key) {
    case 'q':
        snake->stop_game();
        break;
    case 'w':
        snake->set_way(key);
        break;

    case 's':
        snake->set_way(key);
        break;
    
    case 'a':
        snake->set_way(key);
        break;

    case 'd':
        snake->set_way(key);
        break;
    
    default:
        break;
    }
}