#ifndef __TextureManager_HPP__
#define __TextureManager_HPP__

#include "Game.hpp"

class TextureManager
{
    public:
        static SDL_Texture* load_texture(const char* filename);
        static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};

#endif