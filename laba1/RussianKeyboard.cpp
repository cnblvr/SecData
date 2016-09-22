#include "RussianKeyboard.h"
using namespace laba1;

Char^ RussianKeyboard::GetFromKeyCode(int code)
{
	switch(code)
	{
	case 70: return L'à';
	case 188: return L'á';
	case 68: return L'â';
	case 85: return L'ã';
	case 76: return L'ä';
	case 84: return L'å';
	case 192: return L'¸';
	case 186: return L'æ';
	case 80: return L'ç';
	case 66: return L'è';
	case 81: return L'é';
	case 82: return L'ê';
	case 75: return L'ë';
	case 86: return L'ì';
	case 89: return L'í';
	case 74: return L'î';
	case 71: return L'ï';
	case 72: return L'ğ';
	case 67: return L'ñ';
	case 78: return L'ò';
	case 69: return L'ó';
	case 65: return L'ô';
	case 219: return L'õ';
	case 87: return L'ö';
	case 88: return L'÷';
	case 73: return L'ø';
	case 79: return L'ù';
	case 221: return L'ú';
	case 83: return L'û';
	case 77: return L'ü';
	case 222: return L'ı';
	case 190: return L'ş';
	case 90: return L'ÿ';
	default: return nullptr;
	}
}