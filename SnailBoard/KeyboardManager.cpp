#include "KeyboardManager.h"

KeyboardManager::KeyboardManager()
{
}

KeyboardManager::KeyboardManager(unsigned char pRowPins[LAYOUT_ROW_COUNT], unsigned char pColPins[LAYOUT_COL_COUNT])
{
	for (unsigned char i = 0; i < LAYOUT_ROW_COUNT; i++)
	{
		pinMode(pRowPins[i], INPUT_PULLDOWN);
		m_rowPins[i] = pRowPins[i];
	}
	for (unsigned char i = 0; i < LAYOUT_COL_COUNT; i++)
	{
		pinMode(pColPins[i], OUTPUT);
		m_colPins[i] = pColPins[i];
	}

	Layout::Initialize(m_keys);
	Layout::GetBaseLayout();

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
	for (unsigned char col = 0; col < LAYOUT_COL_COUNT; col++)
	{
		digitalWrite(m_colPins[col], HIGH);
		for (unsigned char row = 0; row < LAYOUT_ROW_COUNT; row++)
		{
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
		delayMicroseconds(1);
		digitalWrite(m_colPins[col], LOW);
	}
}

void KeyboardManager::PressKeys()
{
	unsigned char pressedCount = 0;

	for (unsigned char row = 0; row < LAYOUT_ROW_COUNT; row++)
		for (unsigned char col = 0; col < LAYOUT_COL_COUNT; col++)
		{
			if (m_inputs[row][col] && !m_lastInputs[row][col])
			{
				pressedCount++;
				m_keys[row][col]->Press();
				//Serial.println("Pressed");
			}
			else if (m_inputs[row][col] && m_lastInputs[row][col])
			{
				m_keys[row][col]->Hold();
				//Serial.println("Held");
			}
			else if (!m_inputs[row][col] && m_lastInputs[row][col])
			{
				pressedCount--;
				m_keys[row][col]->Release();
				//Serial.println("Released");
			}

			m_lastInputs[row][col] = m_inputs[row][col];
		}

	//Serial.println((int)pressedCount);
	if (pressedCount == 0)
		ModifierManager::ClearKeyPressCount();
}
