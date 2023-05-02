#ifndef VERITAS_INPUTBOX_H
#define VERITAS_INPUTBOX_H

#include <VTObject.h>
#include <VTRect.h>
#include <VTText.h>
#include <string>

class VTInputBox : public VTObject {
public:
	VTInputBox(float x, float y, float width, float height, std::string placeholder, std::string& output, D3DCOLOR backgroundColor, D3DCOLOR textColor);

	void Init(LPDIRECT3DDEVICE9 _dev) override;
	void Render() override;

private:
	D3DCOLOR m_TextColor;
	D3DCOLOR m_BackgroundColor;

	std::string* m_PlaceholderText;
	std::string* m_ValueText;

	VTText* m_Placeholder;
	VTText* m_Value;
	VTRect* m_Frame;
};

#endif //VERITAS_INPUTBOX_H
