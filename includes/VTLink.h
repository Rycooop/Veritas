#ifndef VERITAS_LINK_H
#define VERITAS_LINK_H

#include <Windows.h>
#include <VTObject.h>
#include <VTWindow.h>
#include <VTText.h>


class VTLink : public VTObject {
public:
	VTLink(float x, float y, float maxwidth, float maxheight, float textsize, std::string text, const std::string url, D3DCOLOR color);

	void Init(LPDIRECT3DDEVICE9 _dev) override;
	void Render() override;

private:
	VTText* m_Text;
	std::string text;
	std::string m_Url;

	static void OpenUrl(const std::string& url);
};

#endif //VERITAS_DIVIDER_H