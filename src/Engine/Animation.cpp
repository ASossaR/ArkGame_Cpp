#include "Animation.h"

Animation::Animation(std::string path, SDL_Renderer *renderer, int frames, float duration, int frameHeight, int frameWidth): _texture(new Texture(std::move(path), renderer)), _frames(frames), _duration(duration), _currentTime(0.0f), _rect_sourse(), _frameHeight(frameHeight), _frameWidth(frameWidth){

}

void Animation::Init(){
	_texture->Init();
    _rect_sourse.w = _frameWidth;
    _rect_sourse.h = _frameHeight;
}

void Animation::Update(double elapset_time_seconds_frame_double){
	_currentTime += elapset_time_seconds_frame_double;

	if(_currentTime > _duration){
		_currentTime -= _duration;
	}
	double frameDuration = _duration / _frames;
	int frameIndex = int((_currentTime / _duration)*10);

	_rect_sourse.x = frameIndex * _frameWidth;
	_texture->SetSourceRect(&_rect_sourse);

}

void Animation::Render(const SDL_Rect *_rect_dest){
	_texture->Render(_rect_dest);

}