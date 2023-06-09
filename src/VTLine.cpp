#include <VTLine.h>
#include <iostream>

void VTLine::Init(LPDIRECT3DDEVICE9 _dev) {
	this->m_d3ddev = _dev;

	D3DXCreateLine(_dev, &this->m_Line);

	this->m_LineVertex[0] = D3DXVECTOR2(this->m_X1, this->m_Y1);
	this->m_LineVertex[1] = D3DXVECTOR2(this->m_X2, this->m_Y2);
	this->m_Line->SetWidth(this->m_Thickness);
}

void VTLine::Render() {
	this->m_Line->Draw(this->m_LineVertex, 2, this->m_Color);
}

void VTLine::AddHoverEffect(VTHoverEffect* effect) {
	bool registered = this->effect != NULL;
	this->effect = effect;

	if (!registered) {
		VTWindow::RegisterHoverableObject(this);
	}
}