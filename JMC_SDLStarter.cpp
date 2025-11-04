
#define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include "Player.h"
#include "DungeonGame.h"
using namespace std;

const int resX = 800;
const int resY = 600;
const int GridSizeX = 10;
const int GridSizeY = 10;
const float TileSize = resY / GridSizeX;

//bmp file for player png
static const char* heroPath = "Textures/Hero_no_sword.png";
//texture
static SDL_Texture* heroTexture;
//global tile sizes
static const int TileWidth = resX / 10;
static const int TileHeight = resY / 10;
static const Player* player;

//The hero rectangle
static SDL_FRect heroRect{ 0, 0, TileWidth, TileHeight };
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

    Game = new DungeonGame(TileSize, TileSize);
    Game->LoadTextures(renderer);




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
            Game->Hero->MoveUp(TileSize);
        }
        if (event->key.scancode == SDL_SCANCODE_S)
        {
            Game->Hero->MoveDown(TileSize);
        }
        if (event->key.scancode == SDL_SCANCODE_A)
        {
            heroRect.x -= TileWidth;
        }
        if (event->key.scancode == SDL_SCANCODE_D)
        {
            heroRect.x += TileWidth;
        }

    }

    
    

    return SDL_APP_CONTINUE;  /* carry on with the program! */
    
}

/*  This function runs once per frame, and is the heart of the program.
    Think of this like Unity's Update() loop */
SDL_AppResult SDL_AppIterate(void* appstate)
{


    /* as you can see from this, rendering draws over whatever was drawn before it. */
    SDL_SetRenderDrawColor(renderer, 33, 33, 33, SDL_ALPHA_OPAQUE);  /* dark gray, full alpha */
    SDL_RenderClear(renderer);  /* start with a blank canvas. */

    // Your Update code goes here.
   
    //Draw the tiles here
    for (int x = 0; x < GridSizeX; x++) 
    {
        for (int y = 0; y < GridSizeY; y++) 
        {
            SDL_RenderTexture(renderer, Game->Tiles[x][y].Texture, NULL, &Game->Tiles[x][y].Rect);
        


        }
    


    }
    SDL_RenderTexture(renderer, heroTexture, NULL, &heroRect);
    // should fetch every single game object and render them depending on sprite


    SDL_RenderPresent(renderer);  /* put it all on the screen! */

    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void* appstate, SDL_AppResult result)
{    

    /* SDL will clean up the window/renderer for us. */
}

