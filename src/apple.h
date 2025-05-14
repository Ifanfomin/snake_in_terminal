#ifndef APPLE_H
#define APPLE_H

class Apple {
public:
    Apple(size_t width, size_t hieght);
    
    void replace(size_t width, size_t hieght);

    size_t get_xpos();
    
    size_t get_ypos();

private:
    size_t xpos = 0;
    size_t ypos = 0;
};

#endif