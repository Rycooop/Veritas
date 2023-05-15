#include <VTLink.h>


VTLink::VTLink(float x, float y, float maxwidth, float maxheight, float textsize, std::string text, const std::string url, D3DCOLOR color) {
	this->m_X = x - (maxwidth / 2);
	this->m_Y = y;
	this->m_Width = maxwidth;
	this->m_Height = maxheight;
	this->m_Color = color;
	this->m_Clicked = false;

	this->m_Url = url;
	this->text = text;
	this->m_Text = new VTText(this->m_X + (maxwidth / 2), this->m_Y, this->m_Width, this->m_Height, textsize, this->text, true, color);
}

void VTLink::Init(LPDIRECT3DDEVICE9 _dev) {
	this->m_Text->Init(_dev);

	VTWindow::RegisterClickableObject(this);
}

void VTLink::Render() {
	this->m_Text->Render();

	if (this->m_Clicked) {
		this->OpenUrl(this->m_Url);
		this->m_Clicked = false;
	}
}

void VTLink::OpenUrl(const std::string& url) {
	ShellExecute(0, 0, url.c_str(), 0, 0, SW_SHOW);
}