#include <SDL2/SDL.h>
#include "Game.h"
#include <chrono>
//#include "Exceptions/SDL_Exception.h"
#include "Engine/Texture.h"
#include "Engine/Animation.h"

//Globals
const double MS_PER_UPDATE = 0.00016;


std::chrono::system_clock:: time_point last_time_frame;
std::chrono::system_clock:: time_point current_time_frame;
std::chrono::duration<double> elapset_time_seconds_frame;
double elapset_time_seconds_frame_double;
double delay_time_frame;
double lagGame;

void Game::Init() {
    InitSDL();
    CreateWindowAndRender();
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);


    //Logo
    _Logo_texture = new Texture("/home/sossa/Documentos/GameC++/Resourses/logo.bmp", _renderer);
    _Logo_texture->Init();

    _Logo_rect_dest.x = 0;
    _Logo_rect_dest.y = 300; 
    _Logo_rect_dest.w = 300;
    _Logo_rect_dest.h = 300;


    //Hero    
    _Hero_Animation = new Animation("/home/sossa/Documentos/GameC++/Resourses/hero_walk.bmp", _renderer, 10, 3, 707, 588);
    _Hero_Animation->Init();
    _Hero_rect_dest.x = 0;
    _Hero_rect_dest.y = 0; 
    _Hero_rect_dest.w = 300;
    _Hero_rect_dest.h = 300;


    _isRunning = true;    
}

void Game::InitSDL() {
    auto isInitialized = SDL_Init(SDL_INIT_VIDEO) >= 0;

    if (!isInitialized) {
        //throw SDL_Exception(SDL_GetError());
    }
}

void Game::CreateWindowAndRender() {
    SDL_CreateWindowAndRenderer(w_window, h_window, SDL_WINDOW_SHOWN, &_window, &_renderer);

    if (_window == NULL || _renderer == NULL) {
        //throw SDL_Exception(SDL_GetError());
    }
}


void Game::HandleEvents() {
    SDL_Event event;

    //check for new events every frame
    SDL_PumpEvents();
    const Uint8 *keystate = SDL_GetKeyboardState(NULL);
    if (keystate[SDL_SCANCODE_ESCAPE]){
        _isRunning = false;
    }


    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            _isRunning = false;
        }
    }
}

void Game::Update() {
    
    _Hero_Animation->Update(elapset_time_seconds_frame_double);
    _Hero_frame_speed_x = 30;
    _Hero_frame_position_x += _Hero_frame_speed_x*elapset_time_seconds_frame_double;
    _Hero_rect_dest.x = int(_Hero_frame_position_x)%(720+int(_Hero_frame_w*0.4))- int(_Hero_frame_w*0.4); //Cambia con forme el tiempo, clocks
}

void Game::Render() {
    SDL_RenderClear(_renderer);

    // renderizar imagenes, etc.
    _Logo_texture->Render(&_Logo_rect_dest);
    _Hero_Animation->Render(&_Hero_rect_dest);

    SDL_RenderPresent(_renderer);
}

void Game::Release() {
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

bool Game::IsRunning() {
    return _isRunning;
}


void InitTimeFrame(){
    last_time_frame = std::chrono::system_clock::now();
    lagGame = 0.0; 
}

void StartTimeFrame(){
    current_time_frame = std::chrono::system_clock::now();
    elapset_time_seconds_frame = current_time_frame - last_time_frame;
    elapset_time_seconds_frame_double = elapset_time_seconds_frame.count();
    lagGame += elapset_time_seconds_frame_double;
    //printf("%f\t", elapset_time_seconds_frame_double);
}


void FinishTimeFrame(){
    last_time_frame = current_time_frame;
    
}

bool LagGame(){

    if(lagGame >= MS_PER_UPDATE){
        lagGame -= MS_PER_UPDATE;
        return true;
    }
    else{
        return false;
    }


}
