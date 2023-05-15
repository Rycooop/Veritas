#include <VTDivider.h>


VTDivider::VTDivider(float x, float y, float width, float height, D3DCOLOR color) {
	this->m_X = x - (this->m_Width / 2);
	this->m_Y = y;
	this->m_Width = width;
	this->m_Height = height;
	this->m_Color = color;
}

void VTDivider::Init(LPDIRECT3DDEVICE9 _dev) {
	this->m_DividerRect = new VTRect(this->m_X + (this->m_Width / 2), this->m_Y, this->m_Width, this->m_Height, this->m_Color);
	this->m_DividerRect->Init(_dev);

	float radius = this->m_Height / 2;
	this->m_Edges[0] = new VTCircle(this->m_X + radius, this->m_Y + radius, radius, 100, this->m_Color);
	this->m_Edges[1] = new VTCircle(this->m_X + this->m_Width + radius, this->m_Y + radius, radius, 100, this->m_Color);
	
	this->m_Edges[0]->Init(_dev);
	this->m_Edges[1]->Init(_dev);
}
void VTDivider::Render() {
	this->m_DividerRect->Render();
	this->m_Edges[0]->Render();
	this->m_Edges[1]->Render();
}