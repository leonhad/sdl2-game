#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "constants.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

SDL_bool initialize_window(void)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error initializing SDL.\n");
        return SDL_FALSE;
    }

    window = SDL_CreateWindow
    (
        NULL, // Title
        SDL_WINDOWPOS_CENTERED, // X pos
        SDL_WINDOWPOS_CENTERED, // Y pos
        WINDOW_WIDTH, // Width
        WINDOW_HEIGHT, // Height
        SDL_WINDOW_BORDERLESS
    );

    if (!window)
    {
        fprintf(stderr, "Error creating SQL Window.\n");
        return SDL_FALSE;
    }

    renderer = SDL_CreateRenderer
    (
        window, // The window instance
        -1, // Default driver
        0   // Flags
    );

    if (!renderer)
    {
        fprintf(stderr, "Error creating SQL Renderer.\n");
        return SDL_FALSE;
    }

    return SDL_TRUE;
}

int main(int argc, char *argv[])
{
    initialize_window();

    return EXIT_SUCCESS;
}
