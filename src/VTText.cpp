#include <VTText.h>


VTText::VTText(float x, float y, float maxwidth, float maxheight, float size, const std::string& text, bool alignCenter, D3DCOLOR color) {
	this->m_X = x;
	this->m_Y = y;
	this->m_Width = maxwidth;
	this->m_Height = maxheight;
	this->m_Size = size;
	this->m_Text = text;
	this->m_Center = alignCenter;
	this->m_Color = color;
	
	SetRect(&this->m_FontRect, this->m_X, this->m_Y, this->m_X + this->m_Width, this->m_Y + this->m_Height);
}

void VTText::Init(LPDIRECT3DDEVICE9 _dev) {
	D3DXCreateFontA(_dev, (int)this->m_Size, 0, FW_NORMAL, -1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY | PROOF_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &this->m_Font);
}

void VTText::Render() {
	if (this->m_Center) {
		this->m_Font->DrawTextA(NULL, this->m_Text.c_str(), -1, &this->m_FontRect, DT_CENTER, this->m_Color);
	}
	else this->m_Font->DrawTextA(NULL, this->m_Text.c_str(), -1, &this->m_FontRect, DT_LEFT, this->m_Color);
}