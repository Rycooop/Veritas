#include <VTWindow.h>


VTWindow::VTWindow() {
	this->m_Window = NULL;
	this->m_Screen = NULL;
	this->m_Initialized = false;
}

std::vector<VTObject*>* VTWindow::ClickableObjects = new std::vector<VTObject*>();

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

void VTWindow::SetMenu(VTMenu& menu) {
	this->m_Renderer->SetMenu(menu);
}

void VTWindow::SetRenderTargets(std::vector<VTObject*>* targets) {
	this->m_Renderer->SetRenderTargets(targets);
}

void VTWindow::NotifyClickableObjects(const POINT p) {
	for (const auto& curr : *VTWindow::ClickableObjects) {
		if (curr->m_Clicked) continue;

		if ((p.x >= curr->m_X && p.x <= curr->m_X + curr->m_Width) && (p.y >= curr->m_Y && p.y <= curr->m_Y + curr->m_Height)) {
			curr->m_Clicked = true;
		}
	}
}

bool VTWindow::RegisterClickableObject(VTObject* object) {
	if (object->m_Width && object->m_Height) {
		VTWindow::ClickableObjects->push_back(object);
		return true;
	}
	else return false;
}

//---------------------------------------------------------------------------------------------------------------

LRESULT VTWindow::MessageProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	DWORD procID;
	GetWindowThreadProcessId(hwnd, &procID);

	switch (message) {
		case WM_DESTROY: {
			ExitProcess(0);
			return 0;
		}
		case WM_KEYDOWN: {
			return 0;
		}
		case WM_NCLBUTTONDOWN: {
			POINT MouseCoordinates = {};
			MouseCoordinates.x = GET_X_LPARAM(lParam);
			MouseCoordinates.y = GET_Y_LPARAM(lParam);

			if (ScreenToClient(hwnd, &MouseCoordinates)) {
				VTWindow::NotifyClickableObjects(MouseCoordinates);
			}
		}
		case WM_NCHITTEST: {
			LRESULT hit = DefWindowProc(hwnd, message, wParam, lParam);
			if (hit == HTCLIENT) {
				hit = HTCAPTION;
			}
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
	wc.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
	wc.lpfnWndProc = VTWindow::MessageProc;
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);
	wc.hInstance = hInstance;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpszClassName = className.c_str();

	return RegisterClassEx(&wc);
}

bool VTWindow::CreateWindowWithThread() {
	this->m_Window = CreateWindowEx(NULL, "VTWindowClass", "Veritas", WS_POPUP, this->m_Screen->ScreenX, this->m_Screen->ScreenY, this->m_Screen->ScreenWidth, this->m_Screen->ScreenHeight, NULL, NULL, this->hInstance, NULL);
	
	SetLayeredWindowAttributes(this->m_Window, RGB(0, 0, 0), NULL, LWA_COLORKEY);
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
