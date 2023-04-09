#include <VTWindow.h>


VTWindow::VTWindow() {
	this->m_Window = NULL;
	this->m_Screen = NULL;
	this->m_Initialized = false;
}

bool VTWindow::Create() {
	this->hInstance = GetModuleHandle(NULL);

	this->m_Screen = new VTScreen();
	this->m_Screen->ScreenWidth = 800;
	this->m_Screen->ScreenHeight = 600;
	this->m_Screen->ScreenX = 100;
	this->m_Screen->ScreenY = 100;

	if (!this->RegisterWindowClass(this->hInstance, "VTWindowClass")) {
		//Log
		std::cout << "[-] Failed to create window class" << std::endl;
		return false;
	}

	std::thread(&VTWindow::CreateWindowWithThread, this).detach();

	while (!this->m_Initialized) {
		Sleep(1);
	}

	return true;
}

void VTWindow::SetRenderTargets(std::vector<VTObject*>* targets) {
	this->m_Renderer->SetRenderTargets(targets);
}

//---------------------------------------------------------------------------------------------------------------

LRESULT VTWindow::MessageProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
		case WM_DESTROY: {
			ExitProcess(0);
			return 0;
			}
		case WM_NCHITTEST: {
			LRESULT hit = DefWindowProc(hwnd, message, wParam, lParam);
			if (hit == HTCLIENT) hit = HTCAPTION;
			return hit;
		}

		default:
			break;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}

bool VTWindow::RegisterWindowClass(const HINSTANCE hInstance, const std::string& className) {
	if (!this->m_Screen) return false;

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

bool VTWindow::CreateWindowWithThread() {
	this->m_Window = CreateWindowEx(NULL, "VTWindowClass", "Veritas", NULL, this->m_Screen->ScreenX, this->m_Screen->ScreenY, this->m_Screen->ScreenWidth, this->m_Screen->ScreenHeight, NULL, NULL, this->hInstance, NULL);
	ShowWindow(this->m_Window, SW_SHOW);

	this->m_Renderer = new VTRenderer(this->m_Window);
	this->m_Renderer->SetScreen(this->m_Screen);
	if (!this->m_Renderer->Init()) {
		return false;
	}
	this->m_Initialized = true;

	MSG msg;
	while (true) {
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		this->m_Renderer->RenderFrame();
	}

	return false;
}
