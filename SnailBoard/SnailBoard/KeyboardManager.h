#ifndef KEYBOARD_MANAGER_H__
#define KEYBOARD_MANAGER_H__

#include <typeinfo>

#include "Key.h"
#include "Layout.h"
#include "KeyModifier.h"
#include "ModifierManager.h"

class KeyboardManager
{
public:
	KeyboardManager();
	KeyboardManager(unsigned char pRowPins[LAYOUT_ROW_COUNT], unsigned char pColPins[LAYOUT_COL_COUNT]);
	~KeyboardManager();
	void Tick();

private:
	void ScanMatrix();
	void PressKeys();
private:
	Key* m_keys[LAYOUT_ROW_COUNT][LAYOUT_COL_COUNT];
	bool m_inputs[LAYOUT_ROW_COUNT][LAYOUT_COL_COUNT];
	bool m_lastInputs[LAYOUT_ROW_COUNT][LAYOUT_COL_COUNT];
	unsigned char m_rowPins[LAYOUT_ROW_COUNT];
	unsigned char m_colPins[LAYOUT_COL_COUNT];
};

#endif // !KEYBOARD_MANAGER_H__
