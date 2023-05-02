#ifndef VERITAS_TEXT_H
#define VERITAS_TEXT_H

#include <VTObject.h>
#include <string>

class VTText : public VTObject {
public:
	VTText(float x, float y, float size, const std::string& text, bool alignCenter, D3DCOLOR color);

	void Init(LPDIRECT3DDEVICE9 _dev) override;
	void Render() override;

private:
	ID3DXFont* m_Font;
	RECT m_FontRect;
	std::string m_Text;
	bool m_Center;
};

#endif //VERITAS_TEXT_H