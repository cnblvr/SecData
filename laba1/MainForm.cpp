#include "MainForm.h"
using namespace laba1;

System::Void MainForm::MainForm_Shown(System::Object^  sender, System::EventArgs^  e)
{
	Frequency ^core = gcnew Frequency("russian");
	core->CheckText(rtb_Encoded->Text);
	core->PrintFrequency(dgv_Frequency);
	core->Decode();
}
System::Void MainForm::MainForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
	if(e->KeyCode == Keys::Escape)
		Application::Exit();
}