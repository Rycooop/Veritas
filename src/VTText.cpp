#include <VTText.h>


VTText::VTText(float x, float y, float size, const std::string& text, D3DCOLOR color) {
	this->m_X = x;
	this->m_Y = y;
	this->m_Height = size;
	this->m_Text = text;
	this->m_Color = color;
	
	SetRect(&this->m_FontRect, this->m_X, this->m_Y, this->m_X, this->m_Y);
}

void VTText::Init(LPDIRECT3DDEVICE9 _dev) {
	D3DXCreateFontA(_dev, (int)this->m_Height, 0, FW_NORMAL, -1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY | PROOF_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Calibri", &this->m_Font);
}

void VTText::Render(const LPDIRECT3DDEVICE9 _dev) {
	this->m_Font->DrawTextA(NULL, this->m_Text.c_str(), -1, &this->m_FontRect, DT_CENTER | DT_NOCLIP, this->m_Color);
}