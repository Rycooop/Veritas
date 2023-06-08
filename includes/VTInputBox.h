#ifndef VERITAS_INPUTBOX_H
#define VERITAS_INPUTBOX_H

#include <VTWindow.h>
#include <VTTypeableObject.h>
#include <VTRect.h>
#include <VTRoundedRect.h>
#include <VTText.h>
#include <string>


class VTInputBox : public VTTypeableObject {
public:
	VTInputBox(float x, float y, float width, float height, float rounding, const char* font, std::string placeholder, std::string& output, D3DCOLOR backgroundColor, D3DCOLOR textColor);

	void Init(LPDIRECT3DDEVICE9 _dev) override;
	void Render() override;

	void AddHoverEffect(VTHoverEffect* effect);

private:
	D3DCOLOR m_TextColor;
	D3DCOLOR m_BackgroundColor;

	std::string* m_PlaceholderText;

	std::string m_FontFamily;
	VTText* m_Placeholder;
	VTText* m_Text;
	VTRect* m_Frame;
	VTRoundedRect* m_FrameR;

	float m_Rounding;
};

#endif //VERITAS_INPUTBOX_H
