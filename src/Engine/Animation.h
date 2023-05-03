#ifndef SDLPROJECT_ANIMATION_H
#define SDLPROJECT_ANIMATION_H

#include <string>
//#include <SDL2/SDL.h>


#include "Texture.h"

class Animation {
public:
	Animation(std::string path, SDL_Renderer *renderer, int _frames, float _duration, int frameWidth, int frameHeight);

	void Init();

	//void Release();

	void Update(double elapset_time_seconds_frame_double);

	void Render(const SDL_Rect *_rect_dest);

private:
	Texture *_texture;
	int _frames;
	float _duration;
	double _currentTime;
	SDL_Rect _rect_sourse;
	int _frameHeight;
	int _frameWidth;
};


#endif //SDLPROJECT_ANIMATION_H