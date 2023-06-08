#include <VTRectHollow.h>


VTRectHollow::VTRectHollow(float x, float y, float width, float height, float thickness, D3DCOLOR color) {
	this->m_X = x - (width / 2);
	this->m_Y = y;
	this->m_Width = width;
	this->m_Height = height;
	this->m_Color = color;
	this->m_Sides = new std::vector<VTRect*>();
	this->m_Thickness = thickness;
	this->m_Buffer = NULL;
}

void VTRectHollow::Init(LPDIRECT3DDEVICE9 _dev) {
	this->m_d3ddev = _dev;

	VTRect* c1 = new VTRect(this->m_X, this->m_Y, this->m_Width, this->m_Thickness, this->m_Color);
	VTRect* c2 = new VTRect(this->m_X + this->m_Width, this->m_Y, this->m_Thickness, this->m_Height, this->m_Color);
	VTRect* c3 = new VTRect(this->m_X, this->m_Y, this->m_Thickness, this->m_Height, this->m_Color);
	VTRect* c4 = new VTRect(this->m_X, this->m_Y + this->m_Height, this->m_Width + this->m_Thickness, this->m_Thickness, this->m_Color);

	this->m_Sides->push_back(c1);
	this->m_Sides->push_back(c2);
	this->m_Sides->push_back(c3);
	this->m_Sides->push_back(c4);

	for (const auto& curr : *this->m_Sides) curr->Init(_dev);
}

void VTRectHollow::Render() {
	for (const auto& curr : *this->m_Sides) {
		curr->Render();
	}
}

void VTRectHollow::AddHoverEffect(VTHoverEffect* effect) {
	bool registered = this->effect != NULL;
	this->effect = effect;

	if (!registered) {
		VTWindow::RegisterHoverableObject(this);
	}
}