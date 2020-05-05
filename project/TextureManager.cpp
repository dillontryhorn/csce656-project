#include "TextureManager.hpp"
#include "SDL2/SDL_image.h"

SDL_Texture* TextureManager::load_texture(const char* texture)
{
    SDL_Surface* temp_surface = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, temp_surface);
    SDL_FreeSurface(temp_surface);

    return tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}