#include <VTRenderer.h>


VTRenderer::VTRenderer(HWND hwnd) {
	this->m_DeviceWindow = hwnd;
	this->m_RenderTargets = new std::vector<VTObject*>(0);
}


bool VTRenderer::Init() {
	if (!this->m_DeviceWindow || !this->m_Screen) {
		return false;
	}

	LPDIRECT3D9 d3d = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed			= true;
	d3dpp.SwapEffect		= D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow		= this->m_DeviceWindow;
	d3dpp.BackBufferFormat	= D3DFMT_A8R8G8B8;
	d3dpp.BackBufferWidth	= this->m_Screen->ScreenWidth;
	d3dpp.BackBufferHeight	= this->m_Screen->ScreenHeight;

	HRESULT DevCreated = d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, this->m_DeviceWindow, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &this->m_d3ddev);
	if (DevCreated != S_OK) {
		return false;
	}

	// this->m_d3ddev->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);

	return true;
}

void VTRenderer::RenderFrame() {
	this->m_d3ddev->Clear(0, 0, D3DCLEAR_TARGET, D3DCOLOR_ARGB(255, 30, 30, 30), 1.0f, 0);
	this->m_d3ddev->BeginScene();

	this->m_d3ddev->SetFVF(CUSTOM_FVF);

	this->mut.lock();
	for (const auto curr : *this->m_RenderTargets) {
		curr->Render();
	}
	this->mut.unlock();

	this->m_d3ddev->EndScene();
	this->m_d3ddev->Present(NULL, NULL, NULL, NULL);
}

void VTRenderer::Clean() {
	this->m_vb->Release();
	this->m_d3ddev->Release();
	this->m_d3d->Release();
}

void VTRenderer::SetScreen(VTScreen* screen) { this->m_Screen = screen; }

void VTRenderer::SetMenu(VTMenu& menu) {
	this->m_Menu = &menu;
}


void VTRenderer::SetRenderTargets(std::vector<VTObject*>* targets) {
	std::lock_guard<std::mutex> _(this->mut);

	this->m_RenderTargets->resize(targets->size());
	std::copy(targets->begin(), targets->end(), this->m_RenderTargets->begin());

	for (auto curr : *this->m_RenderTargets) {
		curr->Init(this->m_d3ddev);
	}
}

