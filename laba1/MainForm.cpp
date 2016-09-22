#include "MainForm.h"
using namespace laba1;

System::Void MainForm::MainForm_Shown(System::Object^  sender, System::EventArgs^  e)
{
	b_Check_Click(nullptr, nullptr);
}
System::Void MainForm::MainForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
	if(e->KeyCode == Keys::Escape)
		Application::Exit();
}
System::Void MainForm::b_Check_Click(System::Object^  sender, System::EventArgs^  e)
{
	core = gcnew Frequency("russian");
	double pr;
	Double::TryParse(tb_Precision->Text, pr);
	core->CheckText(rtb_Encoded->Text, pr);
	core->PrintFrequency(dgv_Frequency);
	b_Decode->Enabled = true;
}
System::Void MainForm::b_Decode_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(core != nullptr)
	{
		for(int i=0; i<dgv_Frequency->Rows->Count; i++)
			core->SetReplacement(((String^)dgv_Frequency->Rows[i]->Cells["dgv_c_Letter"]->Value)[0],
				((String^)dgv_Frequency->Rows[i]->Cells["dgv_c_Replacement"]->Value)[0]);
		rtb_Decoded->Text = core->Decode();
	}
}
System::Void MainForm::rtb_Encoded_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	b_Decode->Enabled = false;
}
System::Void MainForm::dgv_Frequency_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
	if(e->KeyCode == Keys::Escape)
		Application::Exit();
	Char ^ch = RussianKeyboard::GetFromKeyCode(e->KeyValue);
	if(ch != nullptr)
		for(int i=0; i<dgv_Frequency->Rows->Count; i++)
			if((String^)dgv_Frequency->Rows[i]->Cells["dgv_c_Letter"]->Value == ch->ToString())
			{
				dgv_Frequency->CurrentCell = dgv_Frequency->Rows[i]->Cells["dgv_c_Letter"];
				break;
			}
}