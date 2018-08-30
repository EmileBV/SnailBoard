#include "KeyModifier.h"

KeyModifier::KeyModifier() : Key(), m_modifier(KEY_LEFT_SHIFT), m_isModifier(false)
{

}
KeyModifier::KeyModifier(unsigned short character, unsigned short modifier) :
	Key(character), m_modifier(modifier), m_isModifier(false)
{
}

KeyModifier::~KeyModifier()
{
}

void KeyModifier::Press()
{
	if (ModifierManager::IsModifierPressed(m_modifier))
	{
		Keyboard.press(m_character);
		m_isModifier = false;
		ModifierManager::SetKeyPressed(true);
	}
	else
	{
		ModifierManager::AddModifier(m_modifier);
		m_isModifier = true;
	}
}

void KeyModifier::Hold()
{
}

void KeyModifier::Release()
{
	if (m_isModifier)
	{
		ModifierManager::RemoveModifier(m_modifier);
	
		if (!ModifierManager::WasKeyPressed())
		{
			Keyboard.press(m_character);
			Keyboard.release(m_character);
		}
	}
	else
	{
		Keyboard.release(m_character);
	}

	m_isModifier = false;
}
