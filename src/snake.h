#ifndef SNAKE_H
#define SNAKE_H

#include <cmath>
#include <vector>

class Snake {
public:
    class Cell {
    public:
        virtual void set_pos(size_t x_pos, size_t y_pos);

        virtual void set_way(size_t input_way);

        virtual void move(size_t FPS);

        virtual size_t get_xpos();

        virtual size_t get_ypos();

        virtual char get_way();

    private:
        size_t xpos = 0;
        size_t ypos = 0;
        char way = 'd';
        size_t tick = 0; 
        size_t run = 0;
    };
    
    class Head : public Cell {
    public:
        void set_pos(size_t map_width, size_t map_height) override;

    private:
        size_t run = 1;
        size_t xpos = 0;
        size_t ypos = 0;
    };

    class Tail : public Cell {
    public:
        Tail();

        // Tail(size_t x, size_t y, char w);
        
    private:
        size_t xpos = 0;
        size_t ypos = 0;
        char way = 'd';
    };
    
    explicit Snake(size_t map_width, size_t map_height);

    void eat();

    void move(size_t FPS);
    
    Head* get_head();

    std::vector<Tail> get_tail();

    void stop_game();

    bool game_running();

private:
    Head head = Head();
    Tail tail_piece = Tail();
    std::vector<Tail> tail;
    static const size_t speed = 10;
    size_t len = 0;
    bool run = true;
};

#endif
