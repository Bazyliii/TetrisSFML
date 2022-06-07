#pragma once
#include "Sounds.h"
#include <SFML/Audio.hpp>
#include <SFML/Main.hpp>

class Sounds {
private:
	static sf::Music backgroundmusic;
public:
	static void init();
	static void playmusic();
};