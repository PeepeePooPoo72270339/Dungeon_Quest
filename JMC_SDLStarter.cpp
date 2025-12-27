
#define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include "Player.h"
#include "DungeonGame.h"
#include "Tile.h"
#include <iostream>
using namespace std;
Tile* tile;

const int resX = 1000;
const int resY = 1000;
const int GridSizeX = 10;
const int GridSizeY = 10;
const float TileSize = resY / GridSizeX;
static Uint64 now;
static Uint64 last;

//bmp file for player png

//texture

//global tile sizes
static const int TileWidth = resX;
static const int TileHeight = resY;
static const Player* player;

//The hero rectangle

//clamp the height and width




 /* We will use this renderer to draw into this window every frame. */
static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;
static SDL_Texture* texture = NULL;

static const char* ProjectName = "JMC Starter Project";

static DungeonGame* Game;



/* This function runs once at startup. */
SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{     
    SDL_SetAppMetadata(ProjectName, "1.0", "");

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer(ProjectName, resX, resY, 0, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    Game = new DungeonGame(TileSize, TileSize, GridSizeX, GridSizeY, renderer);




    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/* This function runs when a new event (mouse input, keypresses, etc) occurs. */
SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{

    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
    }
    
    if (event->type == SDL_EVENT_KEY_DOWN)
    {

        // keyboard events    
        if (event->key.scancode == SDL_SCANCODE_W)
        {
            Game->HandleInput(North);
        }
        if (event->key.scancode == SDL_SCANCODE_S)
        {
            Game->HandleInput(South);
        }
        if (event->key.scancode == SDL_SCANCODE_A)
        {
            Game->HandleInput(West);
        }
        if (event->key.scancode == SDL_SCANCODE_D)
        {
            Game->HandleInput(East);
        }
        if (event->key.scancode == SDL_SCANCODE_K) 
        {
            //Runs the script for minotaur pathfinding

        }



    }

    
    

    return SDL_APP_CONTINUE;  /* carry on with the program! */
    
}

/*  This function runs once per frame, and is the heart of the program.
    Think of this like Unity's Update() loop */
SDL_AppResult SDL_AppIterate(void* appstate)
{


    // get the tile from above, check if walkable


    /* as you can see from this, rendering draws over whatever was drawn before it. */
    SDL_SetRenderDrawColor(renderer, 33, 33, 33, SDL_ALPHA_OPAQUE);  /* dark gray, full alpha */
    SDL_RenderClear(renderer);  /* start with a blank canvas. */

    // Your Update code goes here.

    //Delta Time stuff (might need some fixing though)
    last = now;
    now = SDL_GetPerformanceCounter();
    double deltaTime = (double)((now - last) / (double)SDL_GetPerformanceFrequency());
    Game->Update(deltaTime);

    SDL_RenderPresent(renderer);  /* put it all on the screen! */

    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void* appstate, SDL_AppResult result)
{    

    /* SDL will clean up the window/renderer for us. */
}

