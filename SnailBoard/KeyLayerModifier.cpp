#include "KeyLayerModifier.h"

KeyLayerModifier::KeyLayerModifier()
{
}

KeyLayerModifier::KeyLayerModifier(Callback layout) : m_layout(layout)
{
}

KeyLayerModifier::~KeyLayerModifier()
{
}

void KeyLayerModifier::Press()
{
	m_layout.CallFunction();
}

void KeyLayerModifier::Hold()
{
}

void KeyLayerModifier::Release()
{
}
