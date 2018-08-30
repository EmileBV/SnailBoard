#ifndef KEYNORMAL_H__
#define KEYNORMAL_H__

#include "Arduino.h"
#include "Key.h"
#include "Keyboard.h"
#include "ModifierManager.h"

class KeyNormal : public Key
{
public:
	KeyNormal();
	KeyNormal(unsigned short character);
	~KeyNormal();
	virtual void Press();
	virtual void Hold();
	virtual void Release();
};

#endif // !KEYNORMAL_H__
