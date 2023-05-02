#ifndef VERITAS_RENDERER_H
#define VERITAS_RENDERER_H

#include <Windows.h>
#include <cstdint>
#include <vector>
#include <string>
#include <mutex>
#include <shared_mutex>

#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>
#include <VTObject.h>
#include <VTMenu.h>


struct VTScreen {
	std::uint16_t ScreenX;
	std::uint16_t ScreenY;
	std::uint16_t ScreenWidth;
	std::uint16_t ScreenHeight;
};

class VTRenderer {
public:
	VTRenderer(HWND hwnd);

	bool Init();
	void RenderFrame();
	void Clean();

	void SetScreen(VTScreen* screen);
	void SetMenu(VTMenu& menu);
	void SetRenderTargets(std::vector<VTObject*>* targets);

	VTScreen* GetScreen() const { return this->m_Screen; }
	
private:
	std::mutex mut;

	LPDIRECT3D9 m_d3d;
	LPDIRECT3DDEVICE9 m_d3ddev;
	LPDIRECT3DVERTEXBUFFER9 m_vb;
	HWND m_DeviceWindow;
	VTScreen* m_Screen;
	VTMenu* m_Menu;

	std::vector<VTObject*>* m_RenderTargets;

};

#endif //VERITAS_RENDERER_H