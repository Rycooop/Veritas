#ifndef VERITAS_BUTTON_H
#define VERITAS_BUTTON_H

#include <string>
#include <VTWindow.h>
#include <VTObject.h>
#include <VTRoundedRect.h>
#include <VTRect.h>
#include <VTText.h>
#include <functional>


class VTButton : public VTObject {
public:
	VTButton(float x, float y, float width, float height, float rounding, std::string text, void(*Func)(), D3DCOLOR color);

	void Init(LPDIRECT3DDEVICE9 _dev) override;
	void Render() override;

	void AddHoverEffect(VTHoverEffect* effect);

private:
	VTRect* m_Obj;
	VTRoundedRect* m_Frame;
	VTText* m_Text;

	void(*m_ClickHandler)();
	std::string m_ButtonText;

	float m_Rounding;
};

#endif //VERITAS_BUTTON_H