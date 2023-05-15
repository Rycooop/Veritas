#ifndef VERITAS_WINDOW_H
#define VERITAS_WINDOW_H

#include <Windows.h>
#include <windowsx.h>
#include <cstdint>
#include <thread>
#include <iostream>
#include <string>
#include <atomic>

#include <VTRenderer.h>
#include <VTObject.h>
#include <VTTypeableObject.h>
#include <VTMenu.h>


class VTWindow {
public:
	VTWindow();
	VTWindow(VTScreen* screen);

	bool Create();
	inline bool IsInitialized() { return this->m_Initialized; }

	void SetMenu(VTMenu& menu);
	void SetRenderTargets(std::vector<VTObject*>* targets);

	static void RegisterTypeableObject(VTTypeableObject* object);
	static void RegisterKeystroke(char c);

	static void NotifyClickableObjects(const POINT p);
	static bool RegisterClickableObject(VTObject* object);

private:
	static LRESULT MessageProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	bool RegisterWindowClass(const HINSTANCE hInstance, const std::string& className);
	bool CreateWindowWithThread();

	static std::vector<VTObject*>* ClickableObjects;
	static std::vector<VTTypeableObject*>* TypeableObjects;

	HWND m_Window;
	HINSTANCE hInstance;

	VTScreen* m_Screen;
	VTRenderer* m_Renderer;
	std::unique_ptr<VTMenu> m_Menu;

	static std::atomic<bool> m_Initialized;
};


#endif //VERITAS_WINDOW_H