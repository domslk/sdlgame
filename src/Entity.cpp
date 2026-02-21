#include "SDL3/SDL.h"

class Entity {
    
    protected:
    float x, y, w, h, health, speed;
    
    SDL_Texture *entityUp, *entityDown, *entityLeft, *entityRight;

    Entity(float posX, float posY, float width, float height) {
        x = posX;
        y = posY;
        w = width;
        h = height;
    }

    public:
    void update();
    void render();

};

class Player: public Entity {

    SDL_Texture *playerBoatUp, *playerBoatDown, *playerBoatLeft, *playerBoatRight;

    public:
    Player(float x, float y, float w, float h): Entity(x,y,w,h) {}
};

class Enemy: public Entity {
    float moveTimer;
    int dirX, dirY;

    public:
    Enemy(float x, float y, float w, float h): Entity(x,y,w,h) {}
};

