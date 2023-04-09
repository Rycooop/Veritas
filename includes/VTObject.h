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
	virtual void Render(const LPDIRECT3DDEVICE9 d3ddev) = 0;

	float m_X;
	float m_Y;
	float m_Width;
	float m_Height;
	D3DCOLOR m_Color;

protected:
	LPDIRECT3DDEVICE9 m_d3ddev;
};

#endif //VERITAS_OBJECT_H