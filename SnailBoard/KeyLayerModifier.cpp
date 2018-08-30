#include "KeyLayerModifier.h"

KeyLayerModifier::KeyLayerModifier()
{
}

KeyLayerModifier::KeyLayerModifier(unsigned char layer) : m_layer(layer)
{
}

KeyLayerModifier::~KeyLayerModifier()
{
}

void KeyLayerModifier::Press()
{
	Layout::GetLayer(m_layer);
}

void KeyLayerModifier::Hold()
{
}

void KeyLayerModifier::Release()
{
}
