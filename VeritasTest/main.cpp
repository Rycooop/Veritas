#include <iostream>
#include <VTWindow.h>
#include <VTRenderer.h>
#include <VTRect.h>
#include <VTCircle.h>
#include <VTLine.h>
#include <VTDefs.h>
#include <VTButton.h>
#include <VTRoundedRect.h>
#include <VTCheckbox.h>
#include <VTRectHollow.h>
#include <VTInputBox.h>
#include <VTText.h>
#include <VTMenu.h>
#include <VTDivider.h>
#include <VTLink.h>
#include <vector>


void clicked() {
	std::cout << "CLicked";
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR nCmdLine, int nCmdShow) {
	AllocConsole();
	FILE* f;
	freopen_s(&f, "conout$", "w", stdout);

	VTScreen* screen;
	screen->ScreenHeight = 600;
	screen->ScreenWidth = 400;
	screen->ScreenX = 300;
	screen->ScreenY = 300;

	VTWindow window = VTWindow();
	if (window.Create()) {
	std::cout << "Created Window" << std::endl;
	}

	// VTText add = VTText(300, 300, 40, "HIIII", D3DCOLOR_ARGB(255, 200, 200, 200));
	// VTRect r1 = VTRect(10.0, 20.0, 40.0, 40.0, D3DCOLOR_ARGB(100, 233, 20, 40));
	//VTRect r2 = VTRect(100.0, 100.0, 200.0, 100.0, D3DCOLOR_ARGB(255, 0, 255, 0));
	//VTLine l1 = VTLine(10.0, 10.0, 100.0, 100.0, 20, D3DCOLOR_ARGB(20, 255, 0, 255));
	//VTText t1 = VTText(150.0, 150.0, 30.0, "Test Text", D3DCOLOR_ARGB(255, 0, 0, 0));
	//VTText titleText = VTText(450, 120, 50, "Veritas", D3DCOLOR_ARGB(255, 255, 255, 255));
	// VTCircle circ = VTCircle(150, 400, 50, 600, D3DCOLOR_ARGB(255, 255, 255, 0));
	VTRoundedRect rr = VTRoundedRect(350, 350, 260, 160, 12, true, D3DCOLOR_ARGB(255, 255, 100, 100));
	//VTRectHollow rh = VTRectHollow(100, 100, 200, 80, 9, D3DCOLOR_ARGB(255, 200, 100, 100));

	VTText title = VTText(300, 100, 200, 1000, 60, "Recon", true, D3DCOLOR_ARGB(255, 240, 240, 240));
	VTButton but = VTButton(350, 500, 100, 50, "Button", clicked, D3DCOLOR_ARGB(255, 255, 10, 20));

	VTMenu menu = VTMenu("Hello", D3DCOLOR_ARGB(255, 255, 255, 255));

	std::string username = "";
	std::string password = "";
	VTInputBox inputUsername = VTInputBox(300, 250, 250, 50, "Username", username, D3DCOLOR_ARGB(100, 90, 90, 90), D3DCOLOR_ARGB(255, 255, 255, 255));
	VTInputBox inputPassword = VTInputBox(300, 350, 250, 50, "Password", password, D3DCOLOR_ARGB(100, 90, 90, 90), D3DCOLOR_ARGB(255, 255, 255, 255));

	// VTDivider div = VTDivider(100, 100, 400, 3, D3DCOLOR_ARGB(255, 100, 100, 100));
	VTLink link = VTLink(20, 20, 100, 30, 20, "This is a link", "www.google.com", D3DCOLOR_ARGB(255, 100, 255, 100));

	bool isChecked;
	VTCheckbox check = VTCheckbox(150, 70, 20, 15, isChecked, CHECKBOX_STYLE::CHECKBOX_ROUNDED, D3DCOLOR_ARGB(255, 100, 100, 100), D3DCOLOR_ARGB(255, 90, 155, 203));


	std::vector<VTObject*>* targs = new std::vector<VTObject*>();
	//targs->push_back(&rr);
	//targs->push_back(&rh);
	targs->push_back(&title);
	//targs->push_back(&but);
	targs->push_back(&inputUsername);
	targs->push_back(&inputPassword);
	// targs->push_back(&div);
	targs->push_back(&link);
	targs->push_back(&check);
	targs->push_back(&rr);

	window.SetRenderTargets(targs);
	
	while (1) {
		if (GetAsyncKeyState(VK_SPACE) & 1) {
			window.SetRenderTargets(targs);
		}
	}

}