#ifndef __MapManager_HPP__
#define __MapManager_HPP__

#include "Game.hpp"

#include <string>

class MapManager 
{
public:
    MapManager(std::string file_name);
    ~MapManager();

    void load_map();
    void draw_map();
    void change_map(std::string file_name);

    std::string get_map_name();

    void print_map_values();
    
private:
    SDL_Rect src, dest;

    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;

    int map[20][25];

    std::string map_name;
};

#endif