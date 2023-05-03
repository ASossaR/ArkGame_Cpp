#include <stdio.h>
#include <SDL2/SDL.h>
#include "Game.h"
#include "Engine/Texture.h"
#include <chrono>
//#include <exception>



int main(int argc, char *args[]) {
    Game game = Game();
    //try {
        game.Init();

        InitTimeFrame();
        
        while (game.IsRunning()) {
            
            StartTimeFrame();

            game.HandleEvents();

            while (LagGame()){
                game.Update();
            }

            game.Render();

            FinishTimeFrame();
        }

        game.Release();
    //} catch (std::exception &exception) {
        //fprintf(stderr, exception.what());
        //SDL_Quit();
      //  return -1;
    //}

    return 0;
}

