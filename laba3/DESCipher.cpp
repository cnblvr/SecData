#include "DESCipher.h"

DESCipher::DESCipher()
{
	des = gcnew DESCryptoServiceProvider;
	des->Mode = CipherMode::CBC;
	des->Padding = PaddingMode::Zeros;
	des->GenerateKey();
	des->GenerateIV();
}
array<Byte>^ DESCipher::Encrypt(array<Byte> ^data)
{
	MemoryStream ^fin = gcnew MemoryStream(data, false);
	MemoryStream ^fout = gcnew MemoryStream();
	CryptoStream ^encStream = gcnew CryptoStream(fout, des->CreateEncryptor(des->Key, des->IV), CryptoStreamMode::Write);
	encStream->Write(data, 0, fin->Length);
	encStream->FlushFinalBlock();
	return fout->ToArray();
}
array<Byte>^ DESCipher::Decrypt(array<Byte> ^data)
{
	MemoryStream ^fin = gcnew MemoryStream(data, false);
	MemoryStream ^fout = gcnew MemoryStream();
	CryptoStream ^encStream = gcnew CryptoStream(fout, des->CreateDecryptor(des->Key, des->IV), CryptoStreamMode::Write);
	encStream->Write(data, 0, fin->Length);
	encStream->FlushFinalBlock();
	return fout->ToArray();
}