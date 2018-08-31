#ifndef LAYOUT_H__
#define LAYOUT_H__

#include "Key.h"
#include "KeyModifier.h"
#include "KeyNormal.h"
#include "KeyLayerModifier.h"
#include "define.h"
#include "Arduino.h"

class Layout
{
public:
	static void Initialize(/*Key* layout[LAYOUT_ROW_COUNT][LAYOUT_COL_COUNT]*/);
	static void GetBaseLayout();
	static void GetLayer1();
	static void GetLayer2();
	static void GetLayer3();

public:
	static Key * m_layout[LAYOUT_ROW_COUNT][LAYOUT_COL_COUNT];

private:
	Layout();

private:
};

#endif // !LAYOUT_H__
