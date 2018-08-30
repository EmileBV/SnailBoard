#ifndef KEYMODIFIER_H__
#define KEYMODIFIER_H__

#include "Arduino.h"
#include "Key.h"
#include "Keyboard.h"
#include "ModifierManager.h"

class KeyModifier : public Key
{
public:
	KeyModifier();
	KeyModifier(unsigned short character, unsigned short modifier);
	~KeyModifier();
	virtual void Press();
	virtual void Hold();
	virtual void Release();
private:
	unsigned short m_modifier;
	bool m_isModifier;
};

#endif // !KEYMODIFIER_H__
