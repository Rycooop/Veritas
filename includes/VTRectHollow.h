#ifndef VERITAS_VTRECTHOLLOW_H
#define VERITAS_VTRECTHOLLOW_H

#include "VTObject.h"
#include "VTRect.h"


class VTRectHollow : public VTObject {
public:
	VTRectHollow(float x, float y, float width, float height, float thickness, D3DCOLOR color);

	void Init(LPDIRECT3DDEVICE9 _dev) override;
	void Render() override;

private:
	LPDIRECT3DVERTEXBUFFER9 m_Buffer;

	float m_Thickness;
	std::vector<VTRect*>* m_Sides;
};

#endif //VERITAS_VTRECTHOLLOW_H