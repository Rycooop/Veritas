#include <VTRect.h>


VTRect::VTRect(float x, float y, float width, float height, D3DCOLOR color) {
	this->m_X = x;
	this->m_Y = y;
	this->m_Width = width;
	this->m_Height = height;
	this->m_Color = color;
	this->m_Buffer = NULL;

}

void VTRect::Init(LPDIRECT3DDEVICE9 _dev) {
	this->m_d3ddev = _dev;

	std::vector<Vertex> vertices = {
		{this->m_X, this->m_Y + this->m_Height, 0.5, 1.0, this->m_Color},
		{this->m_X, this->m_Y, 0.5, 1.0, this->m_Color},
		{this->m_X + this->m_Width, this->m_Y + this->m_Height, 0.5, 1.0, this->m_Color},
		{this->m_X + this->m_Width, this->m_Y, 0.5, 1.0, this->m_Color},
	};

	this->m_d3ddev->CreateVertexBuffer(vertices.size() * sizeof(Vertex), 0, CUSTOM_FVF, D3DPOOL_MANAGED, &this->m_Buffer, NULL);

	VOID* pVoid;
	this->m_Buffer->Lock(0, 0, (void**)&pVoid, 0);
	memcpy(pVoid, vertices.data(), sizeof(Vertex) * vertices.size());
	this->m_Buffer->Unlock();
}

void VTRect::Render(const LPDIRECT3DDEVICE9 d3ddev) {
	d3ddev->SetStreamSource(0, this->m_Buffer, 0, sizeof(Vertex));
	d3ddev->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}