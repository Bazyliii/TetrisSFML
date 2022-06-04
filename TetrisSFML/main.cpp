#include "Window.h"
#include <Windows.h>
using namespace std;



int main(void) 
{
	//ShowWindow(GetConsoleWindow(), SW_HIDE);
	AppWindow appWindow;
	appWindow.appLoop();
}