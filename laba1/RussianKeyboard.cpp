#include "RussianKeyboard.h"
using namespace laba1;

Char^ RussianKeyboard::GetFromKeyCode(int code)
{
	switch(code)
	{
	case 70: return L'�';
	case 188: return L'�';
	case 68: return L'�';
	case 85: return L'�';
	case 76: return L'�';
	case 84: return L'�';
	case 192: return L'�';
	case 186: return L'�';
	case 80: return L'�';
	case 66: return L'�';
	case 81: return L'�';
	case 82: return L'�';
	case 75: return L'�';
	case 86: return L'�';
	case 89: return L'�';
	case 74: return L'�';
	case 71: return L'�';
	case 72: return L'�';
	case 67: return L'�';
	case 78: return L'�';
	case 69: return L'�';
	case 65: return L'�';
	case 219: return L'�';
	case 87: return L'�';
	case 88: return L'�';
	case 73: return L'�';
	case 79: return L'�';
	case 221: return L'�';
	case 83: return L'�';
	case 77: return L'�';
	case 222: return L'�';
	case 190: return L'�';
	case 90: return L'�';
	default: return nullptr;
	}
}