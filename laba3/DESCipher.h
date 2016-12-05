#pragma once

using namespace System;
using namespace System::Security::Cryptography;
using namespace System::IO;
using namespace System::Windows::Forms;

ref class DESCipher
{
	DES ^des;
public:
	DESCipher(array<Byte> ^key, array<Byte> ^iv);
	array<Byte>^ GetKey();
	array<Byte>^ GetIV();
	void Generate();
	array<unsigned char>^ Encrypt(array<unsigned char> ^data);
	array<unsigned char>^ Decrypt(array<unsigned char> ^data);
};

