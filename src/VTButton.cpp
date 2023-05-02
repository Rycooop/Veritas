#include <VTButton.h>


VTButton::VTButton(float x, float y, float width, float height, void(*buttonClicked)() , D3DCOLOR color) {
	this->m_X = x;
	this->m_Y = y;
	this->m_Width = width;
	this->m_Height = height;
	this->m_Clicked = false;
	this->m_ClickHandler = buttonClicked;
	this->m_Color = color;
}

void VTButton::Init(LPDIRECT3DDEVICE9 _dev) {
	this->m_d3ddev = _dev;

	this->m_Obj = new VTRect(this->m_X, this->m_Y, this->m_Width, this->m_Height, this->m_Color);
	this->m_Obj->Init(_dev);

	VTWindow::RegisterClickableObject(this);
}

void VTButton::Render() {
	this->m_Obj->Render();

	if (this->m_Clicked) {
		this->m_ClickHandler();
		this->m_Clicked = false;
	}
}