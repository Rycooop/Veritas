#ifndef VERITAS_RECT_H
#define VERITAS_RECT_H

#include <VTObject.h>
#include <VTWindow.h>


class VTRect : public VTObject {
public:
	VTRect(float x, float y, float width, float height, D3DCOLOR color);

	void Init(LPDIRECT3DDEVICE9 _dev) override;
	void Render() override;

	void AddHoverEffect(VTHoverEffect* effect);
	
private:
	LPDIRECT3DVERTEXBUFFER9 m_Buffer;
};

#endif //VERITAS_RECT_H