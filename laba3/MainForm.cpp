#include "MainForm.h"

System::Void laba3::MainForm::MainForm_Shown(System::Object^  sender, System::EventArgs^  e)
{
	Dictionary<String^,String^> ^settings;
	try { settings = Settings::ReadFile("settings.set"); }
	catch(Exception ^e) { MessageBox::Show(e->Message); Environment::Exit(1); return; }
	try
	{
		DESKey = Convert::FromBase64String(settings["des_key"]);
		DESIV = Convert::FromBase64String(settings["des_iv"]);
		if(DESKey->Length != 8 || DESIV->Length != 8)
		{
			MessageBox::Show("Секретный ключ или вектор инициализации должны быть длиной 8.");
			DESKey = nullptr;
			DESIV = nullptr;
		}
	}
	catch(...)
	{
		MessageBox::Show("Секретный ключ или вектор инициализации задан неверно в файле конфигурации.");
		DESKey = nullptr;
		DESIV = nullptr;
	}

	cipher = gcnew DESCipher(DESKey, DESIV);
	DESKey = cipher->GetKey();
	DESIV = cipher->GetIV();
	Print();
	Save();

	tbMain->Text = L"qwerty123☭";
}
System::Void laba3::MainForm::tbMain_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	tbMainBytes->Clear();
	tbEncryptedBytes->Clear();
	tbDecryptedBytes->Clear();

	String ^tmp = "";
	array<Byte>^ bytes = ConvertF::StringToBytes(tbMain->Text);
	for(int i=0; i<bytes->Length; i+=2)
		tmp += bytes[i].ToString("X2")+"-"+bytes[i+1].ToString("X2")+" ";
	tbMainBytes->Text = tmp;

	tmp = "";
	array<Byte>^ encryptedBytes = cipher->Encrypt(bytes);
	tbEncrypted->Text = ConvertF::BytesToString(encryptedBytes);
	for(int i=0; i<encryptedBytes->Length; i+=2)
		tmp += encryptedBytes[i].ToString("X2")+"-"+encryptedBytes[i+1].ToString("X2")+" ";
	tbEncryptedBytes->Text = tmp;

	tmp = "";
	array<Byte>^ decryptedBytes = cipher->Decrypt(encryptedBytes);
	tbDecrypted->Text = ConvertF::BytesToString(decryptedBytes);
	for(int i=0; i<decryptedBytes->Length; i+=2)
		tmp += decryptedBytes[i].ToString("X2")+"-"+decryptedBytes[i+1].ToString("X2")+" ";
	tbDecryptedBytes->Text = tmp;
}
System::Void laba3::MainForm::pbMain_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
	ofgOpenImage->ShowDialog();
}
System::Void laba3::MainForm::ofgOpenImage_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
{
	pbMain->Image = Image::FromFile(ofgOpenImage->FileName);

	array<Byte> ^bytes = ConvertF::BitmapToBytes((Bitmap^)pbMain->Image->Clone());
	array<Byte> ^encryptedBytes = cipher->Encrypt(bytes);
	pbEncrypted->Image = (Image^)ConvertF::BytesToBitmap(encryptedBytes, pbMain->Image->Size);
	pbDecrypted->Image = (Image^)ConvertF::BytesToBitmap(cipher->Decrypt(encryptedBytes), pbMain->Image->Size);
}
System::Void laba3::MainForm::bGenerate_Click(System::Object^  sender, System::EventArgs^  e)
{
	cipher->Generate();
	DESKey = cipher->GetKey();
	DESIV = cipher->GetIV();
	Save();
	Print();
}
void laba3::MainForm::Save()
{
	Dictionary<String^,String^> ^s = gcnew Dictionary<String^,String^>();
	s->Add("des_key", Convert::ToBase64String(DESKey));
	s->Add("des_iv", Convert::ToBase64String(DESIV));
	Settings::WriteFile("settings.set", s);
}
void laba3::MainForm::Print()
{
	String ^strKey = "";
	for(int i=0; i<DESKey->Length; i++)
		strKey += DESKey[i].ToString("X2")+" ";
	strKey = strKey->TrimEnd(gcnew array<wchar_t>{' '});
	tbDESKey->Text = strKey;
	String ^strIV = "";
	for(int i=0; i<DESIV->Length; i++)
		strIV += DESIV[i].ToString("X2")+" ";
	strIV = strIV->TrimEnd(gcnew array<wchar_t>{' '});
	tbDESIV->Text = strIV;
}
System::Void laba3::MainForm::bSource2Encrypted_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(File::Exists("source.png"))
	{
		Bitmap ^image = (Bitmap^)Image::FromFile("source.png");
		array<Byte> ^encryptedBytes = cipher->Encrypt(ConvertF::BitmapToBytes(image));
		((Image^)ConvertF::BytesToBitmap(encryptedBytes, image->Size))->Save("encrypted.png");
	}
	else
		MessageBox::Show("source.png не существует");
}
System::Void laba3::MainForm::bEncrypted2Decrypted_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(File::Exists("encrypted.png"))
	{
		Bitmap ^image = (Bitmap^)Image::FromFile("encrypted.png");
		array<Byte> ^decryptedBytes = cipher->Decrypt(ConvertF::BitmapToBytes(image));
		((Image^)ConvertF::BytesToBitmap(decryptedBytes, image->Size))->Save("decrypted.png");
	}
	else
		MessageBox::Show("encrypted.png не существует");
}