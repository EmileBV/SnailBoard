#include "Layout.h"

Key* Layout::m_layout[LAYOUT_ROW_COUNT][LAYOUT_COL_COUNT];

void Layout::Initialize()
{
	for (unsigned char row = 0; row < LAYOUT_ROW_COUNT; row++)
		for (unsigned char col = 0; col < LAYOUT_COL_COUNT; col++)
		{
			KeyNormal k(KEY_SPACE);
			m_layout[row][col] = &k;
		}
}

void Layout::GetBaseLayout()
{

	//LEFT
	KeyNormal k0_0(KEY_TAB); m_layout[0][0] = &k0_0;
	KeyNormal k0_1(KEY_Q); m_layout[0][1] = &k0_1;
	KeyNormal k0_2(KEY_W); m_layout[0][2] = &k0_2;
	KeyNormal k0_3(KEY_E); m_layout[0][3] = &k0_3;
	KeyNormal k0_4(KEY_R); m_layout[0][4] = &k0_4;
	KeyNormal k0_5(KEY_T); m_layout[0][5] = &k0_5;

	KeyNormal k1_0(KEY_ESC); m_layout[1][0] = &k1_0;
	KeyNormal k1_1(KEY_A); m_layout[1][1] = &k1_1;
	KeyNormal k1_2(KEY_S); m_layout[1][2] = &k1_2;
	KeyNormal k1_3(KEY_D); m_layout[1][3] = &k1_3;
	KeyNormal k1_4(KEY_F); m_layout[1][4] = &k1_4;
	KeyNormal k1_5(KEY_G); m_layout[1][5] = &k1_5;

	KeyNormal k2_0(KEY_LEFT_SHIFT); m_layout[2][0] = &k2_0;
	KeyNormal k2_1(KEY_Z); m_layout[2][1] = &k2_1;
	KeyNormal k2_2(KEY_X); m_layout[2][2] = &k2_2;
	KeyNormal k2_3(KEY_C); m_layout[2][3] = &k2_3;
	KeyNormal k2_4(KEY_V); m_layout[2][4] = &k2_4;
	KeyNormal k2_5(KEY_B); m_layout[2][5] = &k2_5;

	KeyNormal k3_0(KEY_LEFT_GUI); m_layout[3][0] = &k3_0;
	KeyNormal k3_1(KEY_LEFT_CTRL); m_layout[3][1] = &k3_1;
	KeyNormal k3_2(KEY_LEFT_ALT); m_layout[3][2] = &k3_2;
	KeyNormal k3_3(KEY_RIGHT_ALT); m_layout[3][3] = &k3_3;
	KeyLayerModifier k3_4(GetLayer1); m_layout[3][4] = &k3_4;
	KeyNormal k3_5(KEY_SPACE); m_layout[3][5] = &k3_5;

	//RIGHT
	KeyNormal k4_0(KEY_Y); m_layout[4][0] = &k4_0;
	KeyNormal k4_1(KEY_U); m_layout[4][1] = &k4_1;
	KeyNormal k4_2(KEY_I); m_layout[4][2] = &k4_2;
	KeyNormal k4_3(KEY_O); m_layout[4][3] = &k4_3;
	KeyNormal k4_4(KEY_P); m_layout[4][4] = &k4_4;
	KeyNormal k4_5(KEY_BACKSPACE); m_layout[4][5] = &k4_5;

	KeyNormal k5_0(KEY_H); m_layout[5][0] = &k5_0;
	KeyNormal k5_1(KEY_J); m_layout[5][1] = &k5_1;
	KeyNormal k5_2(KEY_K); m_layout[5][2] = &k5_2;
	KeyNormal k5_3(KEY_L);	  m_layout[5][3] = &k5_3;
	KeyNormal k5_4(KEY_SEMICOLON); m_layout[5][4] = &k5_4;
	KeyNormal k5_5(KEY_TILDE); m_layout[5][5] = &k5_5;

	KeyNormal k6_0(KEY_N); m_layout[6][0] = &k6_0;
	KeyNormal k6_1(KEY_M); m_layout[6][1] = &k6_1;
	KeyNormal k6_2(KEY_M); m_layout[6][2] = &k6_2;
	KeyNormal k6_3(KEY_COMMA);  m_layout[6][3] = &k6_3;
	KeyNormal k6_4(KEY_PERIOD); m_layout[6][4] = &k6_4;
	KeyNormal k6_5(KEY_ENTER); m_layout[6][5] = &k6_5;

	KeyNormal k7_0(KEY_SPACE); m_layout[7][0] = &k7_0;
	KeyLayerModifier k7_1(GetLayer2); m_layout[7][1] = &k7_1;
	KeyNormal k7_2(KEY_LEFT); m_layout[7][2] = &k7_2;
	KeyNormal k7_3(KEY_DOWN);  m_layout[7][3] = &k7_3;
	KeyNormal k7_4(KEY_UP); m_layout[7][4] = &k7_4;
	KeyNormal k7_5(KEY_RIGHT); m_layout[7][5] = &k7_5;

}

void Layout::GetLayer1()
{
	Keyboard.press(KEY_1);
	Keyboard.release(KEY_1);
}

void Layout::GetLayer2()
{
	Keyboard.press(KEY_2);
	Keyboard.release(KEY_2);
}

void Layout::GetLayer3()
{
}
