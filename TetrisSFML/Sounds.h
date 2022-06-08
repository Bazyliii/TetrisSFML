#pragma once
#include "Sounds.h"
#include <SFML/Audio.hpp>
#include <SFML/Main.hpp>

class Sounds {
private:
	static sf::Music backgroundmusic;
	static sf::SoundBuffer fall;
	static sf::Sound falls;
	static sf::SoundBuffer gameoversound;
public:
	static void init();
	static void playmusic();
	static void fallen();
	static void gameover();
};