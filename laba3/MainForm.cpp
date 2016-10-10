#include "MainForm.h"

System::Void laba3::MainForm::MainForm_Shown(System::Object^  sender, System::EventArgs^  e)
{
	cipher = gcnew DESCipher();
	button1_Click(nullptr, nullptr);
}
System::Void laba3::MainForm::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	richTextBox2->Text = Encoding::Default->GetString(cipher->Encrypt(Encoding::Default->GetBytes(richTextBox1->Text)));
	richTextBox3->Text = Encoding::Default->GetString(cipher->Decrypt(Encoding::Default->GetBytes(richTextBox2->Text)));
}