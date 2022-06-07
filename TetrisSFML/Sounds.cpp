#include "Sounds.h"

sf::Music Sounds::backgroundmusic;


void Sounds::init()
{
	backgroundmusic.openFromFile("sounds\\backgroundmusic.wav");
}

void Sounds::playmusic() {
	backgroundmusic.setLoop(true);
	backgroundmusic.play();
	backgroundmusic.setVolume(20);
}
