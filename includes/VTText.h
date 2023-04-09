#ifndef VERITAS_TEXT_H
#define VERITAS_TEXT_H

#include <VTObject.h>
#include <string>

class VTText : public VTObject {
public:
	VTText(float x, float y, float size, const std::string& text, D3DCOLOR color);

	void Init(LPDIRECT3DDEVICE9 _dev) override;
	void Render(const LPDIRECT3DDEVICE9 _dev) override;

private:
	ID3DXFont* m_Font;
	RECT m_FontRect;
	std::string m_Text;
};

#endif //VERITAS_TEXT_H