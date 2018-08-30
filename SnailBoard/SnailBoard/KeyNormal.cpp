#include "KeyNormal.h"

KeyNormal::KeyNormal() : Key()
{
}

KeyNormal::KeyNormal(unsigned short character) : Key(character)
{
}

KeyNormal::~KeyNormal()
{
}

void KeyNormal::Press()
{
	Keyboard.press(m_character);
	ModifierManager::SetKeyPressed(true);
}

void KeyNormal::Hold()
{
}

void KeyNormal::Release()
{
	Keyboard.release(m_character);
}
