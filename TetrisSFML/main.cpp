#include "Window.h"
#include "Sounds.h"

using namespace std;

int main(void) 
{
	Sounds::init();
	Sounds::playmusic();
	AppWindow appWindow;
	while(appWindow.appLoop());
}