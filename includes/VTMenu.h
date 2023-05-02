#ifndef VERITAS_MENU_H
#define VERITAS_MENU_H

#include <d3d9.h>
#include <d3dx9.h>
#include <string>


class VTMenu {
public:
	VTMenu(const std::string& title, D3DCOLOR color) {
		this->m_Title = title;
		this->m_Color = color;
	}
		
	std::string m_Title;
	D3DCOLOR m_Color;
};

#endif //VERITAS_MENU_H