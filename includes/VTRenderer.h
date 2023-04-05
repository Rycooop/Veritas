#ifndef VERITAS_RENDERER_H
#define VERITAS_RENDERER_H

#include <Windows.h>

#include <d3d9.h>
#include <d3dx9.h>


class VTRenderer {
public:
	VTRenderer();

	void SetWindow(HWND hwnd);

	bool Init();
	bool RenderFrame();
	void Clean();

private:
	LPDIRECT3D9 m_d3d;
	LPDIRECT3DDEVICE9 m_d3ddev;
	HWND m_DeviceWindow;
};

#endif //VERITAS_RENDERER_H