#pragma once
#include "DESCipher.h"

namespace laba3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text;

	/// <summary>
	/// —водка дл€ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	protected:
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::RichTextBox^  richTextBox3;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 12);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(318, 123);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"qwerty123";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(12, 141);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(318, 123);
			this->richTextBox2->TabIndex = 1;
			this->richTextBox2->Text = L"";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(336, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// richTextBox3
			// 
			this->richTextBox3->Location = System::Drawing::Point(12, 270);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(318, 123);
			this->richTextBox3->TabIndex = 3;
			this->richTextBox3->Text = L"";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(512, 432);
			this->Controls->Add(this->richTextBox3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Shown += gcnew System::EventHandler(this, &MainForm::MainForm_Shown);
			this->ResumeLayout(false);

		}
#pragma endregion
		DESCipher ^cipher;
		private: System::Void MainForm_Shown(System::Object^  sender, System::EventArgs^  e);
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
	};
}
