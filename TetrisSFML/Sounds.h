#pragma once
#include "Sounds.h"
#include <SFML/Audio.hpp>
#include <SFML/Main.hpp>

class Sounds {
private:
	static sf::Music backgroundmusic;
	static sf::SoundBuffer buffer;
	static sf::Sound soundthing;
public:
	static void init();
	static void playmusic();
	static void playsound(std::string soundlocation);
};