#ifndef VERITAS_IMAGE_H
#define VERITAS_IMAGE_H

#include <string>
#include <VTObject.h>


class VTImage : public VTObject {
public:
	VTImage(float x, float y, float w, float h, bool inMemory, D3DCOLOR color, std::string path, std::uint8_t* memorybuffer = nullptr, std::size_t size = 0);

	void Init(LPDIRECT3DDEVICE9 _dev) override;
	void Render() override;

private:
	LPDIRECT3DTEXTURE9 m_ImageTex;
	LPD3DXSPRITE m_Sprite;

	D3DXVECTOR3 m_Pos;

	bool m_InMemory;
	std::uint8_t* m_PTex;
	std::size_t m_TexSize;
	std::string m_Path;
};

#endif //VERITAS_IMAGE_H