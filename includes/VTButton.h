#ifndef VERITAS_BUTTON_H
#define VERITAS_BUTTON_H

#include <VTWindow.h>
#include <VTObject.h>
#include <VTRect.h>
#include <functional>


class VTButton : public VTObject {
public:
	VTButton(float x, float y, float width, float height, void(*Func)(), D3DCOLOR color);

	void Init(LPDIRECT3DDEVICE9 _dev) override;
	void Render() override;

private:
	VTRect* m_Obj;
	void(*m_ClickHandler)();
};

#endif //VERITAS_BUTTON_H