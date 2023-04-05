#include <iostream>
#include <VTWindow.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR nCmdLine, int nCmdShow) {
	VTWindow window = VTWindow();
	window.Create();
	
	while (true) {
	}

	std::cout << "Hi";
}