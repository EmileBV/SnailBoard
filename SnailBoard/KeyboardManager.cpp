#include "KeyboardManager.h"

KeyboardManager::KeyboardManager()
{
}

KeyboardManager::KeyboardManager(unsigned char pRowPins[LAYOUT_ROW_COUNT], unsigned char pColPins[LAYOUT_COL_COUNT])
{
	//Set all rows as pulldown inputs
	for (unsigned char i = 0; i < LAYOUT_ROW_COUNT; i++)
	{
		pinMode(pRowPins[i], INPUT_PULLDOWN);
		m_rowPins[i] = pRowPins[i];
	}

	//Set all columns as outputs
	for (unsigned char i = 0; i < LAYOUT_COL_COUNT; i++)
	{
		pinMode(pColPins[i], OUTPUT);
		m_colPins[i] = pColPins[i];
	}

	//Initialize the layout
	Layout::Initialize();
	//Set current layer to base layer
	Layout::GetLayer(0);

	for (unsigned char row = 0; row < LAYOUT_ROW_COUNT; row++)
		for (unsigned char col = 0; col < LAYOUT_COL_COUNT; col++)
		{
			m_inputs[row][col] = false;
			m_lastInputs[row][col] = false;
		}

	ModifierManager::ClearModifiers();
	Keyboard.begin();
}

KeyboardManager::~KeyboardManager()
{
}

void KeyboardManager::Tick()
{
	ScanMatrix();
	PressKeys();
}

void KeyboardManager::ScanMatrix()
{
	//Go through each columns of the array
	for (unsigned char col = 0; col < LAYOUT_COL_COUNT; col++)
	{
		//Set the output signal of current column to HIGH
		digitalWrite(m_colPins[col], HIGH);

		//Small delay to allow the pin to change state
		delayMicroseconds(1);

		//Iterate through the rows
		for (unsigned char row = 0; row < LAYOUT_ROW_COUNT; row++)
		{
			//Check if the corresponding row sends a signal 
			//or not, meaning the corresponding key is pressed
			bool isPressed = digitalRead(m_rowPins[row]);

			if (!m_inputs[row][col] && isPressed)
			{
				m_inputs[row][col] = true;
			}
			else if (m_inputs[row][col] && !isPressed)
			{
				m_inputs[row][col] = false;
			}
		}

		//Small delay to allow the pin to change state
		delayMicroseconds(1);

		//Turn off the column
		digitalWrite(m_colPins[col], LOW);
	}
}

void KeyboardManager::PressKeys()
{
	unsigned char pressedCount = 0;

	//Iterate through all inputs
	for (unsigned char row = 0; row < LAYOUT_ROW_COUNT; row++)
		for (unsigned char col = 0; col < LAYOUT_COL_COUNT; col++)
		{
			//Press
			if (m_inputs[row][col] && !m_lastInputs[row][col])
			{
				pressedCount++;
				Layout::m_layout[row][col]->Press();
			}
			//Hold
			else if (m_inputs[row][col] && m_lastInputs[row][col])
			{
				Layout::m_layout[row][col]->Hold();
			}
			//Release
			else if (!m_inputs[row][col] && m_lastInputs[row][col])
			{
				pressedCount--;
				Layout::m_layout[row][col]->Release();
			}

			m_lastInputs[row][col] = m_inputs[row][col];
		}

	//Serial.println((int)pressedCount);
	if (pressedCount == 0)
		ModifierManager::ClearKeyPressCount();
}
