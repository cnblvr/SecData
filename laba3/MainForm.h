#pragma once
#include "DESCipher.h"
#include "ConvertF.h"

namespace laba3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text;
	using namespace System::Drawing::Imaging;

	/// <summary>
	/// Сводка для MainForm
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
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  gbTask1;
	private: System::Windows::Forms::TextBox^  tbSource;
	protected:

	private: System::Windows::Forms::TextBox^  tbDecrypted;
	private: System::Windows::Forms::Button^  bEncryptString;

	private: System::Windows::Forms::TextBox^  tbEncrypted;
	private: System::Windows::Forms::Button^  bDecryptString;

	private: System::Windows::Forms::GroupBox^  gbTask2;
	private: System::Windows::Forms::PictureBox^  pbDecrypted;

	private: System::Windows::Forms::PictureBox^  pbEncrypted;
	private: System::Windows::Forms::PictureBox^  pbSource;


	private: System::Windows::Forms::Button^  bEncryptImage;
	private: System::Windows::Forms::Button^  bDecryptImage;




	private: System::Windows::Forms::OpenFileDialog^  ofgOpenImage;
	private: System::Windows::Forms::SplitContainer^  splitContainer2;
	private: System::Windows::Forms::SplitContainer^  splitContainer3;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;

	protected:












	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->gbTask1 = (gcnew System::Windows::Forms::GroupBox());
			this->tbSource = (gcnew System::Windows::Forms::TextBox());
			this->tbDecrypted = (gcnew System::Windows::Forms::TextBox());
			this->bEncryptString = (gcnew System::Windows::Forms::Button());
			this->tbEncrypted = (gcnew System::Windows::Forms::TextBox());
			this->bDecryptString = (gcnew System::Windows::Forms::Button());
			this->gbTask2 = (gcnew System::Windows::Forms::GroupBox());
			this->pbDecrypted = (gcnew System::Windows::Forms::PictureBox());
			this->pbEncrypted = (gcnew System::Windows::Forms::PictureBox());
			this->pbSource = (gcnew System::Windows::Forms::PictureBox());
			this->bEncryptImage = (gcnew System::Windows::Forms::Button());
			this->bDecryptImage = (gcnew System::Windows::Forms::Button());
			this->ofgOpenImage = (gcnew System::Windows::Forms::OpenFileDialog());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainer3 = (gcnew System::Windows::Forms::SplitContainer());
			this->gbTask1->SuspendLayout();
			this->gbTask2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbDecrypted))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbEncrypted))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbSource))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->BeginInit();
			this->splitContainer3->Panel1->SuspendLayout();
			this->splitContainer3->Panel2->SuspendLayout();
			this->splitContainer3->SuspendLayout();
			this->SuspendLayout();
			// 
			// gbTask1
			// 
			this->gbTask1->Controls->Add(this->splitContainer2);
			this->gbTask1->Location = System::Drawing::Point(3, 3);
			this->gbTask1->Name = L"gbTask1";
			this->gbTask1->Size = System::Drawing::Size(300, 350);
			this->gbTask1->TabIndex = 8;
			this->gbTask1->TabStop = false;
			this->gbTask1->Text = L"Задание 1";
			// 
			// tbSource
			// 
			this->tbSource->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbSource->Location = System::Drawing::Point(3, 3);
			this->tbSource->Multiline = true;
			this->tbSource->Name = L"tbSource";
			this->tbSource->Size = System::Drawing::Size(208, 104);
			this->tbSource->TabIndex = 5;
			// 
			// tbDecrypted
			// 
			this->tbDecrypted->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbDecrypted->Location = System::Drawing::Point(3, 3);
			this->tbDecrypted->Multiline = true;
			this->tbDecrypted->Name = L"tbDecrypted";
			this->tbDecrypted->ReadOnly = true;
			this->tbDecrypted->Size = System::Drawing::Size(208, 102);
			this->tbDecrypted->TabIndex = 7;
			// 
			// bEncryptString
			// 
			this->bEncryptString->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->bEncryptString->Location = System::Drawing::Point(216, 3);
			this->bEncryptString->Name = L"bEncryptString";
			this->bEncryptString->Size = System::Drawing::Size(75, 23);
			this->bEncryptString->TabIndex = 2;
			this->bEncryptString->Text = L"encrypt";
			this->bEncryptString->UseVisualStyleBackColor = true;
			this->bEncryptString->Click += gcnew System::EventHandler(this, &MainForm::bEncryptString_Click);
			// 
			// tbEncrypted
			// 
			this->tbEncrypted->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbEncrypted->Location = System::Drawing::Point(3, 5);
			this->tbEncrypted->Multiline = true;
			this->tbEncrypted->Name = L"tbEncrypted";
			this->tbEncrypted->ReadOnly = true;
			this->tbEncrypted->Size = System::Drawing::Size(208, 102);
			this->tbEncrypted->TabIndex = 6;
			// 
			// bDecryptString
			// 
			this->bDecryptString->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->bDecryptString->Location = System::Drawing::Point(216, 5);
			this->bDecryptString->Name = L"bDecryptString";
			this->bDecryptString->Size = System::Drawing::Size(75, 23);
			this->bDecryptString->TabIndex = 4;
			this->bDecryptString->Text = L"decrypt";
			this->bDecryptString->UseVisualStyleBackColor = true;
			this->bDecryptString->Click += gcnew System::EventHandler(this, &MainForm::bDecryptString_Click);
			// 
			// gbTask2
			// 
			this->gbTask2->Controls->Add(this->pbDecrypted);
			this->gbTask2->Controls->Add(this->pbEncrypted);
			this->gbTask2->Controls->Add(this->pbSource);
			this->gbTask2->Controls->Add(this->bEncryptImage);
			this->gbTask2->Controls->Add(this->bDecryptImage);
			this->gbTask2->Location = System::Drawing::Point(94, 153);
			this->gbTask2->Name = L"gbTask2";
			this->gbTask2->Size = System::Drawing::Size(298, 344);
			this->gbTask2->TabIndex = 9;
			this->gbTask2->TabStop = false;
			this->gbTask2->Text = L"Задание 2";
			// 
			// pbDecrypted
			// 
			this->pbDecrypted->Location = System::Drawing::Point(6, 231);
			this->pbDecrypted->Name = L"pbDecrypted";
			this->pbDecrypted->Size = System::Drawing::Size(200, 100);
			this->pbDecrypted->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pbDecrypted->TabIndex = 12;
			this->pbDecrypted->TabStop = false;
			// 
			// pbEncrypted
			// 
			this->pbEncrypted->Location = System::Drawing::Point(6, 125);
			this->pbEncrypted->Name = L"pbEncrypted";
			this->pbEncrypted->Size = System::Drawing::Size(200, 100);
			this->pbEncrypted->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pbEncrypted->TabIndex = 11;
			this->pbEncrypted->TabStop = false;
			// 
			// pbSource
			// 
			this->pbSource->Location = System::Drawing::Point(6, 19);
			this->pbSource->Name = L"pbSource";
			this->pbSource->Size = System::Drawing::Size(200, 100);
			this->pbSource->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pbSource->TabIndex = 10;
			this->pbSource->TabStop = false;
			this->pbSource->Click += gcnew System::EventHandler(this, &MainForm::pbSource_Click);
			// 
			// bEncryptImage
			// 
			this->bEncryptImage->Location = System::Drawing::Point(212, 19);
			this->bEncryptImage->Name = L"bEncryptImage";
			this->bEncryptImage->Size = System::Drawing::Size(75, 23);
			this->bEncryptImage->TabIndex = 2;
			this->bEncryptImage->Text = L"encrypt";
			this->bEncryptImage->UseVisualStyleBackColor = true;
			this->bEncryptImage->Click += gcnew System::EventHandler(this, &MainForm::bEncryptImage_Click);
			// 
			// bDecryptImage
			// 
			this->bDecryptImage->Location = System::Drawing::Point(212, 125);
			this->bDecryptImage->Name = L"bDecryptImage";
			this->bDecryptImage->Size = System::Drawing::Size(75, 23);
			this->bDecryptImage->TabIndex = 4;
			this->bDecryptImage->Text = L"decrypt";
			this->bDecryptImage->UseVisualStyleBackColor = true;
			this->bDecryptImage->Click += gcnew System::EventHandler(this, &MainForm::bDecryptImage_Click);
			// 
			// ofgOpenImage
			// 
			this->ofgOpenImage->FileName = L"openFileDialog1";
			this->ofgOpenImage->Filter = L"Images|*.png;*.jpg;*bmp";
			this->ofgOpenImage->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MainForm::ofgOpenImage_FileOk);
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->gbTask1);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->gbTask2);
			this->splitContainer1->Size = System::Drawing::Size(1117, 631);
			this->splitContainer1->SplitterDistance = 558;
			this->splitContainer1->TabIndex = 10;
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->Location = System::Drawing::Point(3, 16);
			this->splitContainer2->Name = L"splitContainer2";
			this->splitContainer2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->bEncryptString);
			this->splitContainer2->Panel1->Controls->Add(this->tbSource);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->splitContainer3);
			this->splitContainer2->Size = System::Drawing::Size(294, 331);
			this->splitContainer2->SplitterDistance = 110;
			this->splitContainer2->TabIndex = 9;
			// 
			// splitContainer3
			// 
			this->splitContainer3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer3->Location = System::Drawing::Point(0, 0);
			this->splitContainer3->Name = L"splitContainer3";
			this->splitContainer3->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer3.Panel1
			// 
			this->splitContainer3->Panel1->Controls->Add(this->bDecryptString);
			this->splitContainer3->Panel1->Controls->Add(this->tbEncrypted);
			// 
			// splitContainer3.Panel2
			// 
			this->splitContainer3->Panel2->Controls->Add(this->tbDecrypted);
			this->splitContainer3->Size = System::Drawing::Size(294, 217);
			this->splitContainer3->SplitterDistance = 110;
			this->splitContainer3->TabIndex = 10;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1117, 631);
			this->Controls->Add(this->splitContainer1);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Shown += gcnew System::EventHandler(this, &MainForm::MainForm_Shown);
			this->gbTask1->ResumeLayout(false);
			this->gbTask2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbDecrypted))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbEncrypted))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbSource))->EndInit();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel1->PerformLayout();
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			this->splitContainer3->Panel1->ResumeLayout(false);
			this->splitContainer3->Panel1->PerformLayout();
			this->splitContainer3->Panel2->ResumeLayout(false);
			this->splitContainer3->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->EndInit();
			this->splitContainer3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	DESCipher ^cipher;
	array<Byte> ^stringBuff;
	array<Byte> ^imageBuff;
	System::Void MainForm_Shown(System::Object^  sender, System::EventArgs^  e);
	System::Void bEncryptString_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void bDecryptString_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void pbSource_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void ofgOpenImage_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e);
	System::Void bEncryptImage_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void bDecryptImage_Click(System::Object^  sender, System::EventArgs^  e);
};
}
