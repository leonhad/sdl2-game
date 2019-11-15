#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "constants.h"

int game_is_running = SDL_FALSE;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

struct ball
{
    float x;
    float y;
    float width;
    float height;
} ball;

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

void process_input()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type)
    {
        case SDL_QUIT:
            game_is_running = SDL_FALSE;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                game_is_running = SDL_FALSE;
            }
            break;
    }
}

void setup()
{
    ball.x = 20;
    ball.y = 20;
    ball.width = 15;
    ball.height = 15;
}

void update()
{
    ball.x++;
    ball.y++;
}

void render()
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw a rectangle
    SDL_Rect ball_rect = 
    {
        (int)ball.x,
        (int)ball.y,
        (int)ball.width,
        (int)ball.height
    };

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &ball_rect);

    SDL_RenderPresent(renderer);
}

void destroy_window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char *argv[])
{
    game_is_running = initialize_window();

    setup();

    while(game_is_running)
    {
        process_input();
        update();
        render();
    }

    destroy_window();

    return EXIT_SUCCESS;
}
