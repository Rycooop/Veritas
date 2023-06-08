#ifndef VERITAS_CHECKBOX_H
#define VERITAS_CHECKBOX_H

#include <VTObject.h>
#include <VTWindow.h>
#include <VTRoundedRect.h>


enum class CHECKBOX_STYLE {
	//A checkbox that has a border radius around the edges, the unchecked state is to the left and the checked
	//state is to the right
	CHECKBOX_ROUNDED,

	//Similar to the rounded option, however the checkbox has an unscaled border radius
	CHECKBOX_SQUARED,

	//A checkbox with a small border radius that is unscalable, however the checked state consists of the inner 
	//box appearing, while unchecked it is empty.
	CHECKBOX_STATIC,
};

class VTCheckbox : public VTObject {
public:
	VTCheckbox(float x, float y, float w, float h, bool& checked, CHECKBOX_STYLE style, D3DCOLOR background, D3DCOLOR checkedcolor);

	void Init(LPDIRECT3DDEVICE9 _dev) override;
	void Render() override;

	void AddHoverEffect(VTHoverEffect* effect);

private:
	CHECKBOX_STYLE m_Style;

	VTRoundedRect* m_Outerbox;
	VTRoundedRect* m_Innerbox;
	VTCircle* m_Innerboxrounded;

	D3DCOLOR m_Checkedcolor;
};


#endif // VERITAS_CHECKBOX_H