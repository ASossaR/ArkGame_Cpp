Compilador:
	g++ Game.cpp -c
	g++ Engine/Texture.cpp -c 
	g++ Engine/Animation.cpp -c Engine/Texture.h Game.h
	g++ main.cpp Game.o Texture.o Animation.o `pkg-config --cflags --libs sdl2` -std=c++11 -o main
	./main

