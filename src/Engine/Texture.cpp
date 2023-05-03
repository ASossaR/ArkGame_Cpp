#include "Texture.h"


Texture:: Texture(std::string path, SDL_Renderer *renderer): _path(std::move(path)), _renderer(renderer), _rect_sourse(), _texture(nullptr){

}

void Texture::Init(){
	SDL_Surface *SurfaceTemp = SDL_LoadBMP(_path.c_str()); //
    _texture = SDL_CreateTextureFromSurface(_renderer, SurfaceTemp);
    SDL_QueryTexture(_texture, NULL, NULL, &_rect_sourse.w ,&_rect_sourse.h);
    SDL_FreeSurface(SurfaceTemp); //Una vez echo la textura, no necesitamos el surface, asi que liberamos memoria
}


void Texture::SetSourceRect(const SDL_Rect *rect){
    _rect_sourse.x = rect->x;
    _rect_sourse.y = rect->y;
    _rect_sourse.w = rect->w;
    _rect_sourse.h = rect->h;
}

void Texture::Render(const SDL_Rect *_rect_dest){

	SDL_RenderCopy(_renderer, _texture, &_rect_sourse, _rect_dest);

 
}
