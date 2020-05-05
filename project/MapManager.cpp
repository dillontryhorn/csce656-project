#include "MapManager.hpp"

#include "sdl_utils.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

const int ROW_MAP = 20;
const int COL_MAP = 25;

MapManager::MapManager(std::string file_name)
{
    MapManager::change_map(file_name);

    MapManager::load_map();

    src.x = src.y = 0;
    src.w = dest.w = 32;
    src.h = dest.h = 32;
    dest.x = dest.y = 0;

    grass = sdl_utils::load_texture("../assets/images/grass.png");
    dirt = sdl_utils::load_texture("../assets/images/dirt.png");
    water = sdl_utils::load_texture("../assets/images/water.png");
}

MapManager::~MapManager()
{
}

std::string MapManager::get_map_name()
{
    return map_name;
}

void MapManager::load_map()
{
    int map_in[ROW_MAP][COL_MAP];
    std::ifstream f;
    f.open(map_name);   /* open file with filename as argument */
    if (!f.is_open()) {    /* validate file open for reading */
        std::cerr << "Error: file open failed '" << map_name << "'.\n";
        exit(1);
    }

    std::string line, val;
    int row = 0, col = 0;
    while(std::getline (f, line)) {
        std::stringstream s(line);
        col = 0;
        s >> map[row][col];
        col++;
        while(getline (s, val, ','))
        {
            s >> map[row][col];
            col++;
        }
        getline(s,val);
        s >> map[row][col];
        row++;
    }
}

void MapManager::draw_map()
{
    int type = 0;

    for(int row = 0; row < ROW_MAP; row++)
    {
        for(int col = 0; col < COL_MAP; col++)
        {
            type = map[row][col];

            dest.x = col * 32;
            dest.y = row * 32;
            
            switch(type)
            {
                case 21:
                    sdl_utils::draw(water, &src, &dest, SDL_FLIP_NONE);
                    break;
                case 13:
                    sdl_utils::draw(dirt, &src, &dest, SDL_FLIP_NONE);
                    break;
                case 8:
                    sdl_utils::draw(grass, &src, &dest, SDL_FLIP_NONE);
                    break;
                default:
                    break;
            }
        }
    }
}

void MapManager::change_map(std::string file_name)
{
    map_name = file_name;
}

void MapManager::print_map_values()
{
    for(int row = 0; row < ROW_MAP; row++)
    {
        for(int col = 0; col < COL_MAP; col++)
        {
            std::cout << map[row][col] << " ";
        }
        std::cout << std::endl;
    }
}