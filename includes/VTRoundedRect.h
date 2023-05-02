#ifndef VERITAS_ROUNDEDRECT_H
#define VERITAS_ROUNDEDRECT_H

#include <VTObject.h>
#include <VTCircle.h>
#include <VTLine.h>


class VTRoundedRect : public VTObject {
public:
	VTRoundedRect(float x, float y, float w, float h, float rounding, bool hasShadow, D3DCOLOR color);

	void Init(LPDIRECT3DDEVICE9 _dev) override;
	void Render() override;

private:
	LPDIRECT3DVERTEXBUFFER9 m_Buffer, m_OverlapBuffer;
	VTCircle* m_Edges[4];
	VTRoundedRect* m_Shadow;

	bool m_HasShadow;
	float m_Rounding;
};


#endif //VERITAS_ROUNDEDRECT_H