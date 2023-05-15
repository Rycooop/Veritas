#include <VTCheckbox.h>


VTCheckbox::VTCheckbox(float x, float y, float w, float h, bool& checked, CHECKBOX_STYLE style, D3DCOLOR background, D3DCOLOR checkedcolor) {
	this->m_X = x - (w / 2);
	this->m_Y = y;
	this->m_Width = w;
	this->m_Height = h;
	this->m_Style = style;
	this->m_Color = background;
	this->m_Checkedcolor = checkedcolor;
}

void VTCheckbox::Init(LPDIRECT3DDEVICE9 _dev) {
	const float RADIUS = this->m_Height / 3;

	if (this->m_Style == CHECKBOX_STYLE::CHECKBOX_ROUNDED) {
		this->m_Outerbox = new VTRoundedRect(this->m_X + (this->m_Width / 2), this->m_Y, this->m_Width, this->m_Height, RADIUS, false, this->m_Color);
		this->m_Innerbox = new VTRoundedRect(this->m_X + (this->m_Width / 2), this->m_Y + ((this->m_Height - this->m_Height / 1.2) / 2), this->m_Width / 1.2, this->m_Height / 1.2, RADIUS, false, this->m_Checkedcolor);
	}
	else if (this->m_Style == CHECKBOX_STYLE::CHECKBOX_SQUARED) {

	}

	this->m_Outerbox->Init(_dev);
	this->m_Innerbox->Init(_dev);

	VTWindow::RegisterClickableObject(this);
}

void VTCheckbox::Render() {
	this->m_Outerbox->Render();
	this->m_Innerbox->Render();

	if (this->m_Clicked) {
	}
}