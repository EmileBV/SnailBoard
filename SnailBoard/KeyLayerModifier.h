#ifndef KEYLAYERMODIFIER_H__
#define KEYLAYERMODIFIER_H__

#include "Arduino.h"
#include "Key.h"
#include "Keyboard.h"
#include "ModifierManager.h"
#include "Layout.h"

class KeyLayerModifier : public Key
{
public:
	KeyLayerModifier();
	KeyLayerModifier(unsigned char layerIndex);
	~KeyLayerModifier();
	virtual void Press();
	virtual void Hold();
	virtual void Release();

private:
	unsigned char m_layerIndex;
};


#endif // !KEYLAYERMODIFIER_H__
