#include "ConvertF.h"

array<Byte>^ ConvertF::StringToBytes(String ^string)
{
	return Encoding::Default->GetBytes(string);
}
String^ ConvertF::BytesToString(array<Byte> ^bytes)
{
	return Encoding::Default->GetString(bytes);
}
array<Byte>^ ConvertF::BitmapToBytes(Bitmap ^bitmap)
{
	BitmapData ^bmpData = bitmap->LockBits(Rectangle(0, 0, bitmap->Width, bitmap->Height),
		ImageLockMode::ReadWrite, bitmap->PixelFormat);
	int bytes = bmpData->Stride * bmpData->Height;
	array<Byte> ^rgbValues = gcnew array<Byte>(bytes);
	Runtime::InteropServices::Marshal::Copy(bmpData->Scan0, rgbValues, 0, bytes);
	bitmap->UnlockBits(bmpData);
	return rgbValues;
}
Bitmap^ ConvertF::BytesToBitmap(array<Byte> ^bytes, Size ^size)
{
	Bitmap ^bmp = gcnew Bitmap(size->Width, size->Height, PixelFormat::Format24bppRgb);
	BitmapData ^bmpData = bmp->LockBits(Rectangle(0, 0, bmp->Width, bmp->Height), ImageLockMode::WriteOnly, bmp->PixelFormat);
	System::Runtime::InteropServices::Marshal::Copy(bytes, 0, bmpData->Scan0, bytes->Length);
	bmp->UnlockBits(bmpData);
	return bmp;
}