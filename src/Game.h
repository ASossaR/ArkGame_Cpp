#ifndef SDLPROJECT_GAME_H
#define SDLPROJECT_GAME_H

#define w_window 720
#define h_window 720

#include <SDL2/SDL.h>

class Texture;
class Animation;

class Game {
public:
    void Init();

    void HandleEvents();

    void Update();

    void Render();

    void Release();

    bool IsRunning();

private:
    void InitSDL();

    void CreateWindowAndRender();

private:
    bool _isRunning;

    SDL_Window *_window;
    SDL_Renderer *_renderer;


    //Logo
    Texture *_Logo_texture;
    SDL_Rect _Logo_rect_dest;   // Creamos rectangulo destino del Hero

    
    //Hero
    Animation *_Hero_Animation;
    SDL_Rect _Hero_rect_dest;   // Creamos rectangulo destino del Hero
    int _Hero_frame_w = 588;
    float _Hero_frame_position_x;
    float _Hero_frame_speed_x;
    
};

void InitTimeFrame();
void StartTimeFrame();
void FinishTimeFrame();
bool LagGame();


#endif //SDLPROJECT_GAME_H
