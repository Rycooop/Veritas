#ifndef VERITAS_BUTTON_H
#define VERITAS_BUTTON_H

#include <string>
#include <VTWindow.h>
#include <VTObject.h>
#include <VTRect.h>
#include <VTText.h>
#include <functional>


class VTButton : public VTObject {
public:
	VTButton(float x, float y, float width, float height, std::string text, void(*Func)(), D3DCOLOR color);

	void Init(LPDIRECT3DDEVICE9 _dev) override;
	void Render() override;

private:
	VTRect* m_Obj;
	VTText* m_Text;

	void(*m_ClickHandler)();
	std::string m_ButtonText;
};

#endif //VERITAS_BUTTON_H