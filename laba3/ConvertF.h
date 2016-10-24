#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Text;
using namespace System::Drawing::Imaging;
static ref class ConvertF
{
public:
	static array<Byte>^ StringToBytes(String ^string);
	static String^ BytesToString(array<Byte> ^bytes);
	static array<Byte>^ BitmapToBytes(Bitmap ^bitmap);
	static Bitmap^ BytesToBitmap(array<Byte> ^bytes, Size ^size);
};

