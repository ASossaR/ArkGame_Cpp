#ifndef SDLPROJECT_TEXTURE_H
#define SDLPROJECT_TEXTURE_H

#include <string>
//#include <SDL2/SDL.h>
//#include <SDL_render.h>

class Texture {
public:
	Texture(std::string path, SDL_Renderer *renderer);

	void Init();

	void Realease();

	void SetSourceRect(const SDL_Rect *rect);

	void Render(const SDL_Rect *_rect_dest);

private:
	std::string _path;
	SDL_Renderer *_renderer;
	SDL_Rect _rect_sourse;

	SDL_Texture *_texture;
	
};


#endif //SDLPROJECT_TEXTURE_H