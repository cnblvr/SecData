#pragma once

using namespace System;
using namespace System::Security::Cryptography;
using namespace System::IO;

ref class DESCipher
{
	DES ^des;
public:
	DESCipher();
	array<unsigned char>^ Encrypt(array<unsigned char> ^data);
	array<unsigned char>^ Decrypt(array<unsigned char> ^data);
};

