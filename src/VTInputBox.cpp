#include <VTInputBox.h>


VTInputBox::VTInputBox(float x, float y, float width, float height, std::string placeholder, std::string& output, D3DCOLOR backgroundColor, D3DCOLOR textColor) {
	this->m_X = x;
	this->m_Y = y;
	this->m_Width = width;
	this->m_Height = height;
	this->m_BackgroundColor = backgroundColor;
	this->m_TextColor = textColor;

	this->m_PlaceholderText = new std::string(placeholder);
	this->m_ValueText = &output;
}

void VTInputBox::Init(LPDIRECT3DDEVICE9 _dev) {
	this->m_d3ddev = _dev;

	D3DCOLOR PlaceholderColor = D3DCOLOR_ARGB(255, 0, 0, 0);
	PlaceholderColor |= (std::uint8_t)((this->m_TextColor & 0xff) * .7f);
	PlaceholderColor |= (std::uint8_t)(((this->m_TextColor >> 8) & 0xff) * .7f) << 8;
	PlaceholderColor |= (std::uint8_t)(((this->m_TextColor >> 16) & 0xff) * .7f) << 16;
	PlaceholderColor |= (std::uint8_t)(((this->m_TextColor >> 24) & 0xff) * .7f) << 24;

	this->m_Placeholder = new VTText(this->m_X, this->m_Y + (this->m_Height / 3.f), this->m_Height / 2.3, *this->m_PlaceholderText, false, PlaceholderColor);
	this->m_Placeholder->Init(_dev);

	this->m_Frame = new VTRect(this->m_X, this->m_Y, this->m_Width, this->m_Height, this->m_BackgroundColor);
	this->m_Frame->Init(_dev);
}

void VTInputBox::Render() {
	this->m_Frame->Render();
	this->m_Placeholder->Render();
}