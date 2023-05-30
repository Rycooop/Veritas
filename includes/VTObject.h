#ifndef VERITAS_OBJECT_H
#define VERITAS_OBJECT_H

#include <cstdint>
#include <d3d9.h>
#include <d3dx9.h>
#include <vector>

#define CUSTOM_FVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)


struct Vertex {
	float x, y, z, rhw;
	DWORD color;
};


class VTObject {
public:
	VTObject() = default;

	virtual void Init(LPDIRECT3DDEVICE9 _dev) = 0;
	virtual void Render() = 0;

	float m_X;
	float m_Y;
	float m_Width;
	float m_Height;
	D3DCOLOR m_Color;

	bool m_Clicked;

protected:
	LPDIRECT3DDEVICE9 m_d3ddev;
};

class HoverEffect {
public:
	D3DCOLOR color;
	int ms;
};

#endif //VERITAS_OBJECT_H