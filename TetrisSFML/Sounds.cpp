#include "Sounds.h"
sf::Music Sounds::backgroundmusic;
sf::SoundBuffer Sounds::buffer;
sf::Sound Sounds::soundthing;

void Sounds::init()
{
	backgroundmusic.openFromFile("sounds\\backgroundmusic.wav");
}

void Sounds::playmusic() {
	backgroundmusic.setLoop(true);
	backgroundmusic.play();
	backgroundmusic.setVolume(10);
}
void Sounds::playsound(std::string soundlocation) {
	buffer.loadFromFile(soundlocation);
	soundthing.setBuffer(buffer);
	soundthing.play();
	soundthing.setVolume(20);
}