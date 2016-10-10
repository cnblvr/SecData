#include "DESCipher.h"

DESCipher::DESCipher()
{
	des = gcnew DESCryptoServiceProvider;
	des->GenerateKey();
	des->GenerateIV();
}
array<Byte>^ DESCipher::Encrypt(array<Byte> ^data)
{
	MemoryStream ^fin = gcnew MemoryStream(data, false);
	MemoryStream ^fout = gcnew MemoryStream();
	fout->SetLength(0);
	CryptoStream ^encStream = gcnew CryptoStream(fout, des->CreateEncryptor(des->Key, des->IV), CryptoStreamMode::Write);
	array<Byte> ^tmp = gcnew array<Byte>(100);
	long totlen = (long)fin->Length;
	long wrlen = 0;
	while(wrlen < totlen)
	{
		long len = fin->Read(tmp, 0, 100);
		encStream->Write(tmp, 0, len);
		wrlen += len;
	}
	encStream->Close();
	array<Byte> ^res = fout->ToArray();
	fout->Close();
	fin->Close();
	return res;
}
array<Byte>^ DESCipher::Decrypt(array<Byte> ^data)
{
	MemoryStream ^fin = gcnew MemoryStream(data, false);
	MemoryStream ^fout = gcnew MemoryStream();
	fout->SetLength(0);
	CryptoStream ^encStream = gcnew CryptoStream(fout, des->CreateDecryptor(des->Key, des->IV), CryptoStreamMode::Write);
	array<Byte> ^tmp = gcnew array<Byte>(100);
	long totlen = (long)fin->Length;
	long wrlen = 0;
	while(wrlen < totlen)
	{
		long len = fin->Read(tmp, 0, 100);
		encStream->Write(tmp, 0, len);
		wrlen += len;
	}
	encStream->Close();
	array<Byte> ^res = fout->ToArray();
	fout->Close();
	fin->Close();
	return res;
}