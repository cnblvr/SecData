#include "DESCipher.h"

DESCipher::DESCipher(array<Byte> ^key, array<Byte> ^iv)
{
	des = gcnew DESCryptoServiceProvider;
	des->Mode = CipherMode::CBC;
	des->Padding = PaddingMode::Zeros;
	if(key == nullptr)
		des->GenerateKey();
	else
		des->Key = key;
	if(iv == nullptr)
		des->GenerateIV();
	else
		des->IV = iv;
}
array<Byte>^ DESCipher::GetKey()
{
	return des->Key;
}
array<Byte>^ DESCipher::GetIV()
{
	return des->IV;
}
void DESCipher::Generate()
{
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