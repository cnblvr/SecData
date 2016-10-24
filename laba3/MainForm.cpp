#include "MainForm.h"

System::Void laba3::MainForm::MainForm_Shown(System::Object^  sender, System::EventArgs^  e)
{
	tbSource->Text = "qwerty123";
	cipher = gcnew DESCipher();
}
System::Void laba3::MainForm::bEncryptString_Click(System::Object^  sender, System::EventArgs^  e)
{
	stringBuff = cipher->Encrypt(ConvertF::StringToBytes(tbSource->Text));
	tbEncrypted->Text = ConvertF::BytesToString(stringBuff);
}
System::Void laba3::MainForm::bDecryptString_Click(System::Object^  sender, System::EventArgs^  e) {
	tbDecrypted->Text = ConvertF::BytesToString(cipher->Decrypt(stringBuff));
}
System::Void laba3::MainForm::pbSource_Click(System::Object^  sender, System::EventArgs^  e)
{
	ofgOpenImage->ShowDialog();
}
System::Void laba3::MainForm::ofgOpenImage_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
{
	pbSource->Image = Image::FromFile(((OpenFileDialog^)sender)->FileName);
}
System::Void laba3::MainForm::bEncryptImage_Click(System::Object^  sender, System::EventArgs^  e)
{
	array<Byte> ^bytes = ConvertF::BitmapToBytes((Bitmap^)pbSource->Image->Clone());
	imageBuff = cipher->Encrypt(bytes);
	pbEncrypted->Image = (Image^)ConvertF::BytesToBitmap(imageBuff, pbSource->Image->Size);
}
System::Void laba3::MainForm::bDecryptImage_Click(System::Object^  sender, System::EventArgs^  e)
{

}