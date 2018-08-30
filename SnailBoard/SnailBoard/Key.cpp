#include "Key.h"

Key::Key() : m_character(KEY_ESC)
{
}

Key::Key(unsigned short character) : m_character(character)
{
}

Key::~Key()
{
}