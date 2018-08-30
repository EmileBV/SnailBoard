#include "ModifierManager.h"

unsigned short ModifierManager::m_modifiers = 0;
char ModifierManager::m_keyPressedCount = 0;

void ModifierManager::AddModifier(const unsigned short & modifier)
{
	m_modifiers = m_modifiers | modifier;
	Keyboard.set_modifier(m_modifiers);
	Keyboard.send_now();
}

void ModifierManager::RemoveModifier(const unsigned short & modifier)
{
	m_modifiers ^= IsModifierPressed(modifier) ? modifier : 0;
	m_modifiers |= m_modifiers == 0 ? 0 : 0xE000;
	Keyboard.set_modifier(m_modifiers);
	Keyboard.send_now();

	//press alt a second time to exit menu mode on most apps
	if (modifier == MODIFIERKEY_ALT)
	{
		Keyboard.set_modifier(m_modifiers | modifier);
		Keyboard.send_now();
		Keyboard.set_modifier(m_modifiers);
		Keyboard.send_now();
	}
}

const bool ModifierManager::IsModifierPressed(const unsigned short & modifier)
{
	return ((m_modifiers & modifier) ^ (m_modifiers == 0 ? 0 : 0xE000)) != 0;
}

void ModifierManager::ClearModifiers()
{
	m_modifiers = 0;
}

const unsigned short ModifierManager::GetModifiers()
{
	return m_modifiers;
}

void ModifierManager::SetKeyPressed(const bool & isKeyPressed)
{
	m_keyPressedCount += isKeyPressed ? 1 : -1;

	if (m_keyPressedCount < 0)
		m_keyPressedCount = 0;
}

const char ModifierManager::WasKeyPressed()
{
	return m_keyPressedCount;
}

void ModifierManager::ClearKeyPressCount()
{
	//Serial.println((int)m_keyPressedCount);
	m_keyPressedCount = 0;
}
