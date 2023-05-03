#ifndef VERITAS_TYPEABLEOBJECT_H
#define VERITAS_TYPEABLEOBJECT_H

#include <VTObject.h>

class VTTypeableObject : public VTObject {
public:
	VTTypeableObject() = default;

	bool m_CaptureEnabled;

	std::string* m_OutputBuffer;
};

#endif //VERITAS_TYPEABLEOBJECT_H