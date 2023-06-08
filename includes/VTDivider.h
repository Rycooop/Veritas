#ifndef VERITAS_DIVIDER_H
#define VERITAS_DIVIDER_H

#include <VTObject.h>
#include <VTCircle.h>
#include <VTRect.h>


class VTDivider : public VTObject {
public:
	VTDivider(float x, float y, float width, float height, D3DCOLOR color);

	void Init(LPDIRECT3DDEVICE9 _dev) override;
	void Render() override;

	void AddHoverEffect(VTHoverEffect* effect);

private:
	VTRect* m_DividerRect;
	VTCircle* m_Edges[2];
};

#endif //VERITAS_DIVIDER_H