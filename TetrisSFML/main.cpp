#include "Window.h"
using namespace std;


int main(void) 
{
	//ShowWindow(GetConsoleWindow(), SW_HIDE);
	AppWindow appWindow;
	while(appWindow.appLoop());
}