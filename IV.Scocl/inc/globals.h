#pragma once

// This struct is related to G_U91 global variable in GTA IV 
typedef struct _Phone
{
	int m_dwPhoneState;			// 0x0
	int _f4[8];
	int m_dwPhoneTextureType;	// 0x28
	int _f2C[3];
	int m_dwCurrentAction;		// 0x3C
	int _f40[9];
	int m_dwPhoneCalling;		// 0x68
//	int _f6C[4];
//	int m_szWhatNumber;			// 0x80
	int _f2[97];
	int m_dwPhoneCheatsCalling;	// 0x1F8
	int m_dwUnkForCalling;		// 0x1FC
	int _f3[5];
//	int m_aCheats;				// 0x218
} TPhone;

// Globals setup. See globals.dat for more infromation.
TPhone	g_phonePointer;
int		g_phoneCallHash;