#ifndef VERITAS_LINE_H
#define VERITAS_LINE_H

#include <VTObject.h>


class VTLine : public VTObject {
public:
	VTLine(float x1, float y1, float x2, float y2, std::uint16_t thickness, D3DCOLOR color) {
		this->m_X1 = x1;
		this->m_Y1 = y1;
		this->m_X2 = x2;
		this->m_Y2 = y2;
		this->m_Thickness = thickness;
		this->m_Color = color;
	}

	void Init(LPDIRECT3DDEVICE9 _dev) override;
	void Render() override;

private:
	float m_X1;
	float m_Y1;
	float m_X2;
	float m_Y2;
	std::uint16_t m_Thickness;
	D3DCOLOR m_Color;

	ID3DXLine* m_Line;
	D3DXVECTOR2 m_LineVertex[2];
};

#endif //VERITAS_LINE_H