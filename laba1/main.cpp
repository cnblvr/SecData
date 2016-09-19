#include "MainForm.h"

[System::STAThread]
void Main(array<System::String^>^ args) {
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);

	laba1::MainForm form;
	System::Windows::Forms::Application::Run(%form);
}
