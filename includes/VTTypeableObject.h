#ifndef VERITAS_TYPEABLEOBJECT_H
#define VERITAS_TYPEABLEOBJECT_H

#include <VTObject.h>

class VTTypeableObject : public VTObject {
public:
	VTTypeableObject() : m_CaptureEnabled(false) {}

	bool m_CaptureEnabled;

	std::shared_ptr<std::string> m_OutputBuffer;
};

#endif //VERITAS_TYPEABLEOBJECT_H