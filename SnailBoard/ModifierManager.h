#ifndef MODIFIERMANAGER_H__
#define MODIFIERMANAGER_H__

#include "Arduino.h"

class ModifierManager
{
public:
	static void AddModifier(const unsigned short &modifier);
	static void RemoveModifier(const unsigned short &modifier);
	static const bool IsModifierPressed(const unsigned short &modifier);
	static void ClearModifiers();

	static const unsigned short GetModifiers();

	static void SetKeyPressed(const bool &isKeyPressed);
	static const char WasKeyPressed();
	static void ClearKeyPressCount();

private:
	ModifierManager();

private:
	static unsigned short m_modifiers;
	static char m_keyPressedCount;
};

#endif // !MODIFIERMANAGER_H__
