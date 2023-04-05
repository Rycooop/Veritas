#include <VTRenderer.h>


VTRenderer::VTRenderer() {
	this->m_DeviceWindow = NULL;
}

void VTRenderer::SetWindow(HWND hwnd) { this->m_DeviceWindow = hwnd; }

bool VTRenderer::Init() {
	if (!this->m_DeviceWindow) return false;

	LPDIRECT3D9 d3d = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;
	d3dpp.Windowed = true;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = this->m_DeviceWindow;

	HRESULT DevCreated = d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, this->m_DeviceWindow, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &this->m_d3ddev);
	if (DevCreated != S_OK) {
		return false;
	}
	else return true;
}