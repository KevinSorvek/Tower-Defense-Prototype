#include "SpriteLoader.hpp"

SpriteLoader::SpriteLoader() {
}

SDL_Surface* SpriteLoader::loadPNG(char* File) {
    // Create 2 pointers for surfaces
    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Return = NULL;

    // Load image in Surf_Temp
    if((Surf_Temp = IMG_Load(File)) == NULL) {
        printf("%s", IMG_GetError());
        return NULL;
    }

    // Switch image to display PixelFormat
    Surf_Return = SDL_DisplayFormatAlpha(Surf_Temp);
    SDL_FreeSurface(Surf_Temp);

    return Surf_Return;
}

SDL_Surface* SpriteLoader::loadBMP(char* File) {
    // Create 2 pointers for surfaces
    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Return = NULL;

    // Load image in Surf_Temp
    if((Surf_Temp = SDL_LoadBMP(File)) == NULL) {
        printf("%s", IMG_GetError());
        return NULL;
    }

    // Switch image to display PixelFormat
    Surf_Return = SDL_DisplayFormat(Surf_Temp);
    SDL_FreeSurface(Surf_Temp);

    return Surf_Return;
}

bool SpriteLoader::render(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y) {
    if(Surf_Dest == NULL || Surf_Src == NULL) {
        return false;
    }

    SDL_Rect DestR;

    DestR.x = X;
    DestR.y = Y;

    // Blit src on dest
    SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);

    return true;
}

bool SpriteLoader::render(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H) {
    if(Surf_Dest == NULL || Surf_Src == NULL) {
        return false;
    }

    SDL_Rect DestR;

    DestR.x = X;
    DestR.y = Y;

    SDL_Rect SrcR;

    SrcR.x = X2;
    SrcR.y = Y2;
    SrcR.w = W;
    SrcR.h = H;

    SDL_BlitSurface(Surf_Src, &SrcR, Surf_Dest, &DestR);

    return true;
}

bool SpriteLoader::makeTransparent(SDL_Surface* Surf_Dest, int R, int G, int B) {
    if(Surf_Dest == NULL) {
        return false;
    }

    SDL_SetColorKey(Surf_Dest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(Surf_Dest->format, R, G, B));
    return true;
}
