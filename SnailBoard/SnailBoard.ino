#include "define.h"
#include "KeyboardManager.h"
#include "Key.h"
#include "Layout.h"

KeyboardManager kbManager;

void setup()
{
	unsigned char rows[LAYOUT_ROW_COUNT] = {17, 16, 15, 14, 23, 22, 21, 20 };
	unsigned char cols[LAYOUT_COL_COUNT] = { 7, 8, 9, 10, 11, 12 };

	//Serial.begin(9600);
	kbManager = KeyboardManager(rows, cols);
}

void loop()
{
	kbManager.Tick();
	
	delay(10);
}
