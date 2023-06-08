#ifndef VERITAS_CIRCLE_H
#define VERITAS_CIRCLE_H

#include <VTObject.h>
#include <VTWindow.h>


class VTCircle : public VTObject {
public:
	VTCircle(float x, float y, float radius, float res, D3DCOLOR color);

	void Init(LPDIRECT3DDEVICE9 _dev) override;
	void Render() override;

	void AddHoverEffect(VTHoverEffect* effect);

private:
	std::vector<Vertex> m_Vertices;
	float m_Radius;
	std::uint16_t m_Res;
};

#endif //VERITAS_CIRCLE_H