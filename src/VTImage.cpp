#include <VTImage.h>


VTImage::VTImage(float x, float y, float w, float h, bool inMemory, D3DCOLOR color, std::string path, std::uint8_t* memorybuffer, std::size_t size) {
	this->m_InMemory = inMemory;
	
	if (!this->m_InMemory) {
		this->m_Path = path;
	}
	else this->m_PTex = memorybuffer;

	this->m_X = x;
	this->m_Y = y;
	this->m_Width = w;
	this->m_Height = h;

	this->m_TexSize = size;
	this->m_Pos = D3DXVECTOR3(this->m_X - (w / 2), this->m_Y - (h / 2), 0.f);
	this->m_Color = color;
}

void VTImage::Init(LPDIRECT3DDEVICE9 _dev) {
	if (this->m_InMemory) {
		HRESULT TexCreated = D3DXCreateTextureFromFileInMemoryEx(_dev, this->m_PTex, this->m_TexSize, this->m_Width, this->m_Height, -1, D3DUSAGE_RENDERTARGET, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &this->m_ImageTex);
	}

	D3DXCreateSprite(_dev, &this->m_Sprite);
}

void VTImage::Render() {
	this->m_Sprite->Begin(D3DXSPRITE_ALPHABLEND);
	this->m_Sprite->Draw(this->m_ImageTex, NULL, NULL, &this->m_Pos, this->m_Color);
	this->m_Sprite->End();
}

void VTImage::AddHoverEffect(VTHoverEffect* effect) {
	bool registered = this->effect != NULL;
	this->effect = effect;

	if (!registered) {
		VTWindow::RegisterHoverableObject(this);
	}
}