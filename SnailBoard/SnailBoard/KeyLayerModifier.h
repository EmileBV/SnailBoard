#ifndef KEYLAYERMODIFIER_H__
#define KEYLAYERMODIFIER_H__

#include "Arduino.h"
#include "Key.h"
#include "Keyboard.h"
#include "ModifierManager.h"
#include "Callback.h"

class KeyLayerModifier : public Key
{
public:
	KeyLayerModifier();
	KeyLayerModifier(Callback layout);
	~KeyLayerModifier();
	virtual void Press();
	virtual void Hold();
	virtual void Release();
};


#endif // !KEYLAYERMODIFIER_H__
