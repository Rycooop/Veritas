#include <VTRoundedRect.h>


VTRoundedRect::VTRoundedRect(float x, float y, float w, float h, float rounding, bool hasShadow, D3DCOLOR color) {
	this->m_X = x - (w / 2);
	this->m_Y = y;
	this->m_Width = w;
	this->m_Height = h;
	this->m_Rounding = rounding;
	this->m_HasShadow = hasShadow;
	this->m_Color = color;
}

void VTRoundedRect::Init(LPDIRECT3DDEVICE9 _dev) {
	this->m_d3ddev = _dev;

	std::vector<Vertex> vertices, vertices2;
	float roundingEffect = (this->m_Width / 100.f) + this->m_Rounding;

	vertices = {
		{this->m_X, this->m_Y + this->m_Height, 0.5, 1.0, this->m_Color},
		{this->m_X, this->m_Y, 0.5, 1.0, this->m_Color},
		{this->m_X + this->m_Width, this->m_Y + this->m_Height, 0.5, 1.0, this->m_Color},
		{this->m_X + this->m_Width, this->m_Y, 0.5, 1.0, this->m_Color},
	};

	vertices2 = {
		{this->m_X - roundingEffect, this->m_Y + this->m_Height - roundingEffect, 0.5, 1.0, this->m_Color},
		{this->m_X - roundingEffect, this->m_Y + roundingEffect, 0.5, 1.0, this->m_Color},
		{this->m_X + this->m_Width + roundingEffect, this->m_Y + this->m_Height - roundingEffect, 0.5, 1.0, this->m_Color},
		{this->m_X + this->m_Width + roundingEffect, this->m_Y + roundingEffect, 0.5, 1.0, this->m_Color},
	};

	_dev->CreateVertexBuffer(vertices.size() * sizeof(Vertex), 0, CUSTOM_FVF, D3DPOOL_MANAGED, &this->m_Buffer, NULL);
	_dev->CreateVertexBuffer(vertices2.size() * sizeof(Vertex), 0, CUSTOM_FVF, D3DPOOL_MANAGED, &this->m_OverlapBuffer, NULL);

	VOID* pVoid;
	this->m_Buffer->Lock(0, 0, (void**)&pVoid, 0);
	memcpy(pVoid, vertices.data(), vertices.size() * sizeof(Vertex));
	this->m_Buffer->Unlock();

	this->m_OverlapBuffer->Lock(0, 0, (void**)&pVoid, 0);
	memcpy(pVoid, vertices2.data(), vertices2.size() * sizeof(Vertex));
	this->m_OverlapBuffer->Unlock();

	D3DCOLOR c = D3DCOLOR_ARGB(255, 255, 100, 100);
	if (this->m_Width >= 300) {
		this->m_Edges[0] = new VTCircle(this->m_X + roundingEffect - 1, this->m_Y + roundingEffect - 1, roundingEffect, 100, this->m_Color);
		this->m_Edges[1] = new VTCircle(this->m_X + roundingEffect - 1, this->m_Y + this->m_Height - roundingEffect, roundingEffect, 100, this->m_Color);
	}
	else {
		this->m_Edges[0] = new VTCircle(this->m_X + roundingEffect, this->m_Y + roundingEffect - 1, roundingEffect, 100, this->m_Color);
		this->m_Edges[1] = new VTCircle(this->m_X + roundingEffect, this->m_Y + this->m_Height - roundingEffect, roundingEffect, 100, this->m_Color);
	}
	
	this->m_Edges[2] = new VTCircle(this->m_X + this->m_Width + roundingEffect, this->m_Y + roundingEffect - 1, roundingEffect, 100, this->m_Color);
	this->m_Edges[3] = new VTCircle(this->m_X + this->m_Width + roundingEffect, this->m_Y + this->m_Height - roundingEffect, roundingEffect, 100, this->m_Color);

	for (const auto& curr : this->m_Edges) {
		curr->Init(_dev);
	}

	float shadowOffset = this->m_Height * .05f;

	//Take the same color for the shadow but .15 times the brightness
	D3DCOLOR ShadowColor = D3DCOLOR_ARGB(0, 0, 0, 0);
	ShadowColor |= (std::uint8_t)((this->m_Color & 0xff) * .15);
	ShadowColor |= (std::uint8_t)(((this->m_Color >> 8) & 0xff) * .15) << 8;
	ShadowColor |= (std::uint8_t)(((this->m_Color >> 16) & 0xff) * .15) << 16;
	ShadowColor |= (std::uint8_t)(((this->m_Color >> 24) & 0xff) * .15) << 24;

	if (this->m_HasShadow) {
		this->m_Shadow = new VTRoundedRect(this->m_X + shadowOffset + (this->m_Width / 2), this->m_Y + shadowOffset, this->m_Width, this->m_Height, this->m_Rounding, false, ShadowColor);
		this->m_Shadow->Init(_dev);
	}
}

void VTRoundedRect::Render() {
	//Render Shadow before object so it is underneath
	if (this->m_HasShadow) {
		this->m_Shadow->Render();
	}

	this->m_d3ddev->SetStreamSource(0, this->m_Buffer, 0, sizeof(Vertex));
	this->m_d3ddev->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
	this->m_d3ddev->SetStreamSource(0, this->m_OverlapBuffer, 0, sizeof(Vertex));
	this->m_d3ddev->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

	for (const auto& curr : this->m_Edges) {
		curr->Render();
	}
}