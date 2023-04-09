#ifndef VERITAS_WINDOW_H
#define VERITAS_WINDOW_H

#include <Windows.h>
#include <cstdint>
#include <thread>
#include <iostream>
#include <string>
#include <atomic>

#include <VTRenderer.h>


class VTWindow {
public:
	VTWindow();

	bool Create();
	inline bool IsInitialized() { return this->m_Initialized; }

	void SetRenderTargets(std::vector<VTObject*>* targets);

private:
	static LRESULT MessageProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	bool RegisterWindowClass(const HINSTANCE hInstance, const std::string& className);
	bool CreateWindowWithThread();

	HWND m_Window;
	HINSTANCE hInstance;
	VTScreen* m_Screen;
	VTRenderer* m_Renderer;

	bool m_Initialized;
};


#endif //VERITAS_WINDOW_H