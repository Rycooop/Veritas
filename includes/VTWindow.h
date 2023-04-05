#ifndef VERITAS_WINDOW_H
#define VERITAS_WINDOW_H

#include <Windows.h>
#include <cstdint>
#include <thread>
#include <iostream>
#include <string>

#include <VTRenderer.h>


struct VTScreen {
	std::uint16_t ScreenX;
	std::uint16_t ScreenY;
	std::uint16_t ScreenWidth;
	std::uint16_t ScreenHeight;
};

class VTWindow {
public:
	VTWindow();

	void Create();

private:
	static LRESULT MessageProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	bool RegisterWindowClass(const HINSTANCE hInstance, const std::string& className);
	bool CreateWindowWithThread(const HINSTANCE hInstance);

	HWND m_Window;
	VTScreen* m_Screen;
	VTRenderer* m_Renderer;
	std::uint16_t m_WindowWidth;
	std::uint16_t m_WindowHeight;
};


#endif //VERITAS_WINDOW_H