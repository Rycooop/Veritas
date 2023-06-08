#include <VTCircle.h>


VTCircle::VTCircle(float x, float y, float radius, float res, D3DCOLOR color) {
	this->m_X = x - radius;
	this->m_Y = y;
	this->m_Radius = radius;
	this->m_Res = res;
	this->m_Color = color;
}

void VTCircle::Init(LPDIRECT3DDEVICE9 _dev) {
	this->m_d3ddev = _dev;

	std::vector<Vertex> vertices(this->m_Res);

	for (int i = 0; i < this->m_Res; i++) {
		vertices[i].x = this->m_X + this->m_Radius * cos(D3DX_PI * (i / (this->m_Res / 2.0f)));
		if (vertices[i].x <= this->m_X - this->m_Radius) vertices[i].x++;

		vertices[i].y = this->m_Y + this->m_Radius * sin(D3DX_PI * (i / (this->m_Res / 2.0f)));
		vertices[i].z = 0;
		vertices[i].rhw = 1;
		vertices[i].color = this->m_Color;
	}

	this->m_Vertices = vertices;
}

void VTCircle::Render() {
	this->m_d3ddev->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, this->m_Res - 1, this->m_Vertices.data(), sizeof(Vertex));
}

void VTCircle::AddHoverEffect(VTHoverEffect* effect) {
	bool registered = this->effect != NULL;
	this->effect = effect;

	if (!registered) {
		VTWindow::RegisterHoverableObject(this);
	}
}