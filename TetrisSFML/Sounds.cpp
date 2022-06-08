#include "Sounds.h"

sf::Music Sounds::backgroundmusic;
sf::SoundBuffer Sounds::fall;
sf::SoundBuffer Sounds::gameoversound;
sf::Sound Sounds::falls;

void Sounds::init()
{
	fall.loadFromFile("sounds\\fall.wav");
	gameoversound.loadFromFile("sounds\\gameover.wav");
	backgroundmusic.openFromFile("sounds\\backgroundmusic.wav");
}

void Sounds::playmusic() {
	backgroundmusic.setLoop(true);
	backgroundmusic.play();
	backgroundmusic.setVolume(10);
}

void Sounds::fallen() {
	falls.setBuffer(fall);
	falls.play();
	falls.setVolume(20);
}

void Sounds::gameover() {
	falls.setBuffer(gameoversound);
	falls.play();
	falls.setVolume(10);
}