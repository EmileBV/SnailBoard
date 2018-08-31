#include "KeyLayerModifier.h"

KeyLayerModifier::KeyLayerModifier()
{
}

KeyLayerModifier::KeyLayerModifier(unsigned char layerIndex) : m_layerIndex(layerIndex)
{
}

KeyLayerModifier::~KeyLayerModifier()
{
}

void KeyLayerModifier::Press()
{
	Layout::GetLayer(m_layerIndex);
}

void KeyLayerModifier::Hold()
{
}

void KeyLayerModifier::Release()
{
}
