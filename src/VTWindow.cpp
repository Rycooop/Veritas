#include <VTWindow.h>


VTWindow::VTWindow() {
	this->m_Window = NULL;
	this->m_WindowWidth = 800;
	this->m_WindowHeight = 600;
}

void VTWindow::Create() {
	const HINSTANCE hInstance = GetModuleHandle(NULL);

	if (!this->RegisterWindowClass(hInstance, "VTWindowClass")) {
		//Log
		std::cout << "[-] Failed to create window class" << std::endl;
		return;
	}

	this->m_Renderer = new VTRenderer();

	std::thread(&VTWindow::CreateWindowWithThread, this, hInstance).detach();
}

LRESULT VTWindow::MessageProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message)
	{
		case WM_DESTROY: {
			ExitProcess(0);
			return 0;
		}
		break;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}

bool VTWindow::RegisterWindowClass(const HINSTANCE hInstance, const std::string& className) {
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpfnWndProc = VTWindow::MessageProc;
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);
	wc.hInstance = hInstance;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpszClassName = className.c_str();

	return RegisterClassEx(&wc);
}

bool VTWindow::CreateWindowWithThread(HINSTANCE hInstance) {
	this->m_Window = CreateWindowEx(NULL, "VTWindowClass", "Veritas", WS_OVERLAPPEDWINDOW, 0, 0, this->m_WindowWidth, this->m_WindowHeight, NULL, NULL, hInstance, NULL);
	ShowWindow(this->m_Window, 10);

	this->m_Renderer->SetWindow(this->m_Window);
	if (!this->m_Renderer->Init()) {
		return false;
	}

	MSG msg;
	while (true) {
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (msg.message == WM_QUIT) break;
	}

	return false;
}
