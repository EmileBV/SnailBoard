#ifndef KEY_H__
#define KEY_H__

#include "Arduino.h"

class Key
{
public:
	Key();
	Key(unsigned short character);
	~Key();
	virtual void Press() = 0;
	virtual void Hold() = 0;
	virtual void Release() = 0;
protected:
	unsigned short m_character;
};
#endif // !KEY_H__
