#include "Window.h"
#include "Sounds.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

using namespace std;

int main(void) 
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	Sounds::init();
	Sounds::playmusic();
	AppWindow appWindow;
	while(appWindow.appLoop());
}