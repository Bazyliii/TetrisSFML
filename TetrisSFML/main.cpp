#include "Window.h"
#include "Sounds.h"
using namespace std;

int main(void) 
{
	Sounds::init();
	Sounds::playmusic();
	//ShowWindow(GetConsoleWindow(), SW_HIDE);
	AppWindow appWindow;
	while(appWindow.appLoop());
}