#include <VTButton.h>


VTButton::VTButton(float x, float y, float width, float height, float rounding, std::string text, void(*buttonClicked)() , D3DCOLOR color) {
	this->m_X = x - (width / 2);
	this->m_Y = y;
	this->m_Width = width;
	this->m_Height = height;
	this->m_Rounding = rounding;
	this->m_ButtonText = text;
	this->m_Clicked = false;
	this->m_ClickHandler = buttonClicked;
	this->m_Color = color;
}

void VTButton::Init(LPDIRECT3DDEVICE9 _dev) {
	this->m_d3ddev = _dev;

	this->m_Frame = new VTRoundedRect(this->m_X + (this->m_Width / 2), this->m_Y, this->m_Width, this->m_Height, this->m_Rounding, false, this->m_Color);
	this->m_Frame->Init(_dev);

	this->m_Text = new VTText(this->m_X + (this->m_Width / 2), this->m_Y + ((this->m_Height / 2.f) / 2), this->m_Width, this->m_Height, this->m_Height / 2, "Arial", this->m_ButtonText, true, D3DCOLOR_ARGB(255, 255, 255, 255));
	this->m_Text->Init(_dev);

	VTWindow::RegisterClickableObject(this);
}

void VTButton::Render() {
	this->m_Frame->Render();
	this->m_Text->Render();

	if (this->m_Clicked) {
		this->m_ClickHandler();
		this->m_Clicked = false;
	}
}

void VTButton::OnHover() const {

}