#pragma once
#include "DESCipher.h"
#include "ConvertF.h"
#include "Settings.h"

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


	protected:




















	private: System::Windows::Forms::OpenFileDialog^  ofgOpenImage;
	private: System::Windows::Forms::TabControl^  tcTasks;
	private: System::Windows::Forms::TabPage^  tpTask1;
	private: System::Windows::Forms::SplitContainer^  sc1_1;
	private: System::Windows::Forms::SplitContainer^  sc1_a1;


	private: System::Windows::Forms::SplitContainer^  sc1_2;
	private: System::Windows::Forms::SplitContainer^  sc1_a2;


	private: System::Windows::Forms::SplitContainer^  sc1_a3;


	private: System::Windows::Forms::TabPage^  tpTask2;
	private: System::Windows::Forms::TabPage^  tpTask3;
	private: System::Windows::Forms::TextBox^  tbMain;
	private: System::Windows::Forms::TextBox^  tbMainBytes;

	private: System::Windows::Forms::TextBox^  tbEncrypted;
	private: System::Windows::Forms::TextBox^  tbEncryptedBytes;

	private: System::Windows::Forms::TextBox^  tbDecrypted;
	private: System::Windows::Forms::TextBox^  tbDecryptedBytes;




	private: System::Windows::Forms::SplitContainer^  sc2_1;
	private: System::Windows::Forms::PictureBox^  pbMain;
	private: System::Windows::Forms::SplitContainer^  sc2_2;
	private: System::Windows::Forms::PictureBox^  pbEncrypted;

	private: System::Windows::Forms::PictureBox^  pbDecrypted;
	private: System::Windows::Forms::Label^  lDESIV;

	private: System::Windows::Forms::TextBox^  tbDESIV;
	private: System::Windows::Forms::Label^  lDESKey;


	private: System::Windows::Forms::TextBox^  tbDESKey;
	private: System::Windows::Forms::Button^  bGenerate;
	private: System::Windows::Forms::Button^  bEncrypted2Decrypted;
	private: System::Windows::Forms::Button^  bSource2Encrypted;













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
			this->ofgOpenImage = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tcTasks = (gcnew System::Windows::Forms::TabControl());
			this->tpTask1 = (gcnew System::Windows::Forms::TabPage());
			this->sc1_1 = (gcnew System::Windows::Forms::SplitContainer());
			this->sc1_a1 = (gcnew System::Windows::Forms::SplitContainer());
			this->tbMain = (gcnew System::Windows::Forms::TextBox());
			this->tbMainBytes = (gcnew System::Windows::Forms::TextBox());
			this->sc1_2 = (gcnew System::Windows::Forms::SplitContainer());
			this->sc1_a2 = (gcnew System::Windows::Forms::SplitContainer());
			this->tbEncrypted = (gcnew System::Windows::Forms::TextBox());
			this->tbEncryptedBytes = (gcnew System::Windows::Forms::TextBox());
			this->sc1_a3 = (gcnew System::Windows::Forms::SplitContainer());
			this->tbDecrypted = (gcnew System::Windows::Forms::TextBox());
			this->tbDecryptedBytes = (gcnew System::Windows::Forms::TextBox());
			this->tpTask2 = (gcnew System::Windows::Forms::TabPage());
			this->sc2_1 = (gcnew System::Windows::Forms::SplitContainer());
			this->pbMain = (gcnew System::Windows::Forms::PictureBox());
			this->sc2_2 = (gcnew System::Windows::Forms::SplitContainer());
			this->pbEncrypted = (gcnew System::Windows::Forms::PictureBox());
			this->pbDecrypted = (gcnew System::Windows::Forms::PictureBox());
			this->tpTask3 = (gcnew System::Windows::Forms::TabPage());
			this->bGenerate = (gcnew System::Windows::Forms::Button());
			this->lDESIV = (gcnew System::Windows::Forms::Label());
			this->tbDESIV = (gcnew System::Windows::Forms::TextBox());
			this->lDESKey = (gcnew System::Windows::Forms::Label());
			this->tbDESKey = (gcnew System::Windows::Forms::TextBox());
			this->bSource2Encrypted = (gcnew System::Windows::Forms::Button());
			this->bEncrypted2Decrypted = (gcnew System::Windows::Forms::Button());
			this->tcTasks->SuspendLayout();
			this->tpTask1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sc1_1))->BeginInit();
			this->sc1_1->Panel1->SuspendLayout();
			this->sc1_1->Panel2->SuspendLayout();
			this->sc1_1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sc1_a1))->BeginInit();
			this->sc1_a1->Panel1->SuspendLayout();
			this->sc1_a1->Panel2->SuspendLayout();
			this->sc1_a1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sc1_2))->BeginInit();
			this->sc1_2->Panel1->SuspendLayout();
			this->sc1_2->Panel2->SuspendLayout();
			this->sc1_2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sc1_a2))->BeginInit();
			this->sc1_a2->Panel1->SuspendLayout();
			this->sc1_a2->Panel2->SuspendLayout();
			this->sc1_a2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sc1_a3))->BeginInit();
			this->sc1_a3->Panel1->SuspendLayout();
			this->sc1_a3->Panel2->SuspendLayout();
			this->sc1_a3->SuspendLayout();
			this->tpTask2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sc2_1))->BeginInit();
			this->sc2_1->Panel1->SuspendLayout();
			this->sc2_1->Panel2->SuspendLayout();
			this->sc2_1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbMain))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sc2_2))->BeginInit();
			this->sc2_2->Panel1->SuspendLayout();
			this->sc2_2->Panel2->SuspendLayout();
			this->sc2_2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbEncrypted))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbDecrypted))->BeginInit();
			this->tpTask3->SuspendLayout();
			this->SuspendLayout();
			// 
			// ofgOpenImage
			// 
			this->ofgOpenImage->FileName = L"openFileDialog1";
			this->ofgOpenImage->Filter = L"Images|*.png;*.jpg;*bmp";
			this->ofgOpenImage->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MainForm::ofgOpenImage_FileOk);
			// 
			// tcTasks
			// 
			this->tcTasks->Controls->Add(this->tpTask1);
			this->tcTasks->Controls->Add(this->tpTask2);
			this->tcTasks->Controls->Add(this->tpTask3);
			this->tcTasks->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tcTasks->Location = System::Drawing::Point(0, 0);
			this->tcTasks->Name = L"tcTasks";
			this->tcTasks->SelectedIndex = 0;
			this->tcTasks->Size = System::Drawing::Size(483, 488);
			this->tcTasks->TabIndex = 11;
			// 
			// tpTask1
			// 
			this->tpTask1->Controls->Add(this->sc1_1);
			this->tpTask1->Location = System::Drawing::Point(4, 22);
			this->tpTask1->Name = L"tpTask1";
			this->tpTask1->Padding = System::Windows::Forms::Padding(3);
			this->tpTask1->Size = System::Drawing::Size(475, 462);
			this->tpTask1->TabIndex = 0;
			this->tpTask1->Text = L"Задание 1";
			this->tpTask1->UseVisualStyleBackColor = true;
			// 
			// sc1_1
			// 
			this->sc1_1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->sc1_1->Location = System::Drawing::Point(3, 3);
			this->sc1_1->Name = L"sc1_1";
			this->sc1_1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// sc1_1.Panel1
			// 
			this->sc1_1->Panel1->Controls->Add(this->sc1_a1);
			// 
			// sc1_1.Panel2
			// 
			this->sc1_1->Panel2->Controls->Add(this->sc1_2);
			this->sc1_1->Size = System::Drawing::Size(469, 456);
			this->sc1_1->SplitterDistance = 152;
			this->sc1_1->TabIndex = 0;
			// 
			// sc1_a1
			// 
			this->sc1_a1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->sc1_a1->Location = System::Drawing::Point(0, 0);
			this->sc1_a1->Name = L"sc1_a1";
			// 
			// sc1_a1.Panel1
			// 
			this->sc1_a1->Panel1->Controls->Add(this->tbMain);
			// 
			// sc1_a1.Panel2
			// 
			this->sc1_a1->Panel2->Controls->Add(this->tbMainBytes);
			this->sc1_a1->Size = System::Drawing::Size(469, 152);
			this->sc1_a1->SplitterDistance = 234;
			this->sc1_a1->TabIndex = 0;
			// 
			// tbMain
			// 
			this->tbMain->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tbMain->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbMain->Location = System::Drawing::Point(0, 0);
			this->tbMain->Multiline = true;
			this->tbMain->Name = L"tbMain";
			this->tbMain->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->tbMain->Size = System::Drawing::Size(234, 152);
			this->tbMain->TabIndex = 0;
			this->tbMain->TextChanged += gcnew System::EventHandler(this, &MainForm::tbMain_TextChanged);
			// 
			// tbMainBytes
			// 
			this->tbMainBytes->BackColor = System::Drawing::Color::Gainsboro;
			this->tbMainBytes->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tbMainBytes->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbMainBytes->Location = System::Drawing::Point(0, 0);
			this->tbMainBytes->Multiline = true;
			this->tbMainBytes->Name = L"tbMainBytes";
			this->tbMainBytes->ReadOnly = true;
			this->tbMainBytes->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->tbMainBytes->Size = System::Drawing::Size(231, 152);
			this->tbMainBytes->TabIndex = 0;
			// 
			// sc1_2
			// 
			this->sc1_2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->sc1_2->Location = System::Drawing::Point(0, 0);
			this->sc1_2->Name = L"sc1_2";
			this->sc1_2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// sc1_2.Panel1
			// 
			this->sc1_2->Panel1->Controls->Add(this->sc1_a2);
			// 
			// sc1_2.Panel2
			// 
			this->sc1_2->Panel2->Controls->Add(this->sc1_a3);
			this->sc1_2->Size = System::Drawing::Size(469, 300);
			this->sc1_2->SplitterDistance = 152;
			this->sc1_2->TabIndex = 0;
			// 
			// sc1_a2
			// 
			this->sc1_a2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->sc1_a2->Location = System::Drawing::Point(0, 0);
			this->sc1_a2->Name = L"sc1_a2";
			// 
			// sc1_a2.Panel1
			// 
			this->sc1_a2->Panel1->Controls->Add(this->tbEncrypted);
			// 
			// sc1_a2.Panel2
			// 
			this->sc1_a2->Panel2->Controls->Add(this->tbEncryptedBytes);
			this->sc1_a2->Size = System::Drawing::Size(469, 152);
			this->sc1_a2->SplitterDistance = 234;
			this->sc1_a2->TabIndex = 0;
			// 
			// tbEncrypted
			// 
			this->tbEncrypted->BackColor = System::Drawing::Color::Gainsboro;
			this->tbEncrypted->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tbEncrypted->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbEncrypted->Location = System::Drawing::Point(0, 0);
			this->tbEncrypted->Multiline = true;
			this->tbEncrypted->Name = L"tbEncrypted";
			this->tbEncrypted->ReadOnly = true;
			this->tbEncrypted->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->tbEncrypted->Size = System::Drawing::Size(234, 152);
			this->tbEncrypted->TabIndex = 0;
			// 
			// tbEncryptedBytes
			// 
			this->tbEncryptedBytes->BackColor = System::Drawing::Color::Gainsboro;
			this->tbEncryptedBytes->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tbEncryptedBytes->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbEncryptedBytes->Location = System::Drawing::Point(0, 0);
			this->tbEncryptedBytes->Multiline = true;
			this->tbEncryptedBytes->Name = L"tbEncryptedBytes";
			this->tbEncryptedBytes->ReadOnly = true;
			this->tbEncryptedBytes->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->tbEncryptedBytes->Size = System::Drawing::Size(231, 152);
			this->tbEncryptedBytes->TabIndex = 0;
			// 
			// sc1_a3
			// 
			this->sc1_a3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->sc1_a3->Location = System::Drawing::Point(0, 0);
			this->sc1_a3->Name = L"sc1_a3";
			// 
			// sc1_a3.Panel1
			// 
			this->sc1_a3->Panel1->Controls->Add(this->tbDecrypted);
			// 
			// sc1_a3.Panel2
			// 
			this->sc1_a3->Panel2->Controls->Add(this->tbDecryptedBytes);
			this->sc1_a3->Size = System::Drawing::Size(469, 144);
			this->sc1_a3->SplitterDistance = 234;
			this->sc1_a3->TabIndex = 0;
			// 
			// tbDecrypted
			// 
			this->tbDecrypted->BackColor = System::Drawing::Color::Gainsboro;
			this->tbDecrypted->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tbDecrypted->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbDecrypted->Location = System::Drawing::Point(0, 0);
			this->tbDecrypted->Multiline = true;
			this->tbDecrypted->Name = L"tbDecrypted";
			this->tbDecrypted->ReadOnly = true;
			this->tbDecrypted->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->tbDecrypted->Size = System::Drawing::Size(234, 144);
			this->tbDecrypted->TabIndex = 0;
			// 
			// tbDecryptedBytes
			// 
			this->tbDecryptedBytes->BackColor = System::Drawing::Color::Gainsboro;
			this->tbDecryptedBytes->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tbDecryptedBytes->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbDecryptedBytes->Location = System::Drawing::Point(0, 0);
			this->tbDecryptedBytes->Multiline = true;
			this->tbDecryptedBytes->Name = L"tbDecryptedBytes";
			this->tbDecryptedBytes->ReadOnly = true;
			this->tbDecryptedBytes->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->tbDecryptedBytes->Size = System::Drawing::Size(231, 144);
			this->tbDecryptedBytes->TabIndex = 0;
			// 
			// tpTask2
			// 
			this->tpTask2->Controls->Add(this->sc2_1);
			this->tpTask2->Location = System::Drawing::Point(4, 22);
			this->tpTask2->Name = L"tpTask2";
			this->tpTask2->Padding = System::Windows::Forms::Padding(3);
			this->tpTask2->Size = System::Drawing::Size(475, 462);
			this->tpTask2->TabIndex = 1;
			this->tpTask2->Text = L"Задание 2";
			this->tpTask2->UseVisualStyleBackColor = true;
			// 
			// sc2_1
			// 
			this->sc2_1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->sc2_1->Location = System::Drawing::Point(3, 3);
			this->sc2_1->Name = L"sc2_1";
			this->sc2_1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// sc2_1.Panel1
			// 
			this->sc2_1->Panel1->Controls->Add(this->pbMain);
			// 
			// sc2_1.Panel2
			// 
			this->sc2_1->Panel2->Controls->Add(this->sc2_2);
			this->sc2_1->Size = System::Drawing::Size(469, 456);
			this->sc2_1->SplitterDistance = 152;
			this->sc2_1->TabIndex = 0;
			// 
			// pbMain
			// 
			this->pbMain->BackColor = System::Drawing::SystemColors::Control;
			this->pbMain->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pbMain->Location = System::Drawing::Point(0, 0);
			this->pbMain->Name = L"pbMain";
			this->pbMain->Size = System::Drawing::Size(469, 152);
			this->pbMain->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pbMain->TabIndex = 0;
			this->pbMain->TabStop = false;
			this->pbMain->DoubleClick += gcnew System::EventHandler(this, &MainForm::pbMain_DoubleClick);
			// 
			// sc2_2
			// 
			this->sc2_2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->sc2_2->Location = System::Drawing::Point(0, 0);
			this->sc2_2->Name = L"sc2_2";
			this->sc2_2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// sc2_2.Panel1
			// 
			this->sc2_2->Panel1->Controls->Add(this->pbEncrypted);
			// 
			// sc2_2.Panel2
			// 
			this->sc2_2->Panel2->Controls->Add(this->pbDecrypted);
			this->sc2_2->Size = System::Drawing::Size(469, 300);
			this->sc2_2->SplitterDistance = 152;
			this->sc2_2->TabIndex = 0;
			// 
			// pbEncrypted
			// 
			this->pbEncrypted->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pbEncrypted->Location = System::Drawing::Point(0, 0);
			this->pbEncrypted->Name = L"pbEncrypted";
			this->pbEncrypted->Size = System::Drawing::Size(469, 152);
			this->pbEncrypted->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pbEncrypted->TabIndex = 0;
			this->pbEncrypted->TabStop = false;
			// 
			// pbDecrypted
			// 
			this->pbDecrypted->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pbDecrypted->Location = System::Drawing::Point(0, 0);
			this->pbDecrypted->Name = L"pbDecrypted";
			this->pbDecrypted->Size = System::Drawing::Size(469, 144);
			this->pbDecrypted->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pbDecrypted->TabIndex = 0;
			this->pbDecrypted->TabStop = false;
			// 
			// tpTask3
			// 
			this->tpTask3->Controls->Add(this->bEncrypted2Decrypted);
			this->tpTask3->Controls->Add(this->bSource2Encrypted);
			this->tpTask3->Controls->Add(this->bGenerate);
			this->tpTask3->Controls->Add(this->lDESIV);
			this->tpTask3->Controls->Add(this->tbDESIV);
			this->tpTask3->Controls->Add(this->lDESKey);
			this->tpTask3->Controls->Add(this->tbDESKey);
			this->tpTask3->Location = System::Drawing::Point(4, 22);
			this->tpTask3->Name = L"tpTask3";
			this->tpTask3->Size = System::Drawing::Size(475, 462);
			this->tpTask3->TabIndex = 2;
			this->tpTask3->Text = L"Задание 3";
			this->tpTask3->UseVisualStyleBackColor = true;
			// 
			// bGenerate
			// 
			this->bGenerate->Location = System::Drawing::Point(8, 57);
			this->bGenerate->Name = L"bGenerate";
			this->bGenerate->Size = System::Drawing::Size(159, 23);
			this->bGenerate->TabIndex = 4;
			this->bGenerate->Text = L"Сгенерировать";
			this->bGenerate->UseVisualStyleBackColor = true;
			this->bGenerate->Click += gcnew System::EventHandler(this, &MainForm::bGenerate_Click);
			// 
			// lDESIV
			// 
			this->lDESIV->AutoSize = true;
			this->lDESIV->Location = System::Drawing::Point(5, 34);
			this->lDESIV->Name = L"lDESIV";
			this->lDESIV->Size = System::Drawing::Size(124, 13);
			this->lDESIV->TabIndex = 3;
			this->lDESIV->Text = L"Вектор инициализации";
			// 
			// tbDESIV
			// 
			this->tbDESIV->Location = System::Drawing::Point(135, 31);
			this->tbDESIV->Name = L"tbDESIV";
			this->tbDESIV->Size = System::Drawing::Size(332, 20);
			this->tbDESIV->TabIndex = 2;
			// 
			// lDESKey
			// 
			this->lDESKey->AutoSize = true;
			this->lDESKey->Location = System::Drawing::Point(5, 8);
			this->lDESKey->Name = L"lDESKey";
			this->lDESKey->Size = System::Drawing::Size(91, 13);
			this->lDESKey->TabIndex = 1;
			this->lDESKey->Text = L"Секретный ключ";
			// 
			// tbDESKey
			// 
			this->tbDESKey->Location = System::Drawing::Point(135, 5);
			this->tbDESKey->Name = L"tbDESKey";
			this->tbDESKey->Size = System::Drawing::Size(332, 20);
			this->tbDESKey->TabIndex = 0;
			// 
			// bSource2Encrypted
			// 
			this->bSource2Encrypted->Location = System::Drawing::Point(8, 124);
			this->bSource2Encrypted->Name = L"bSource2Encrypted";
			this->bSource2Encrypted->Size = System::Drawing::Size(278, 23);
			this->bSource2Encrypted->TabIndex = 5;
			this->bSource2Encrypted->Text = L"Шифровать source.png в encrypted.png";
			this->bSource2Encrypted->UseVisualStyleBackColor = true;
			this->bSource2Encrypted->Click += gcnew System::EventHandler(this, &MainForm::bSource2Encrypted_Click);
			// 
			// bEncrypted2Decrypted
			// 
			this->bEncrypted2Decrypted->Location = System::Drawing::Point(8, 153);
			this->bEncrypted2Decrypted->Name = L"bEncrypted2Decrypted";
			this->bEncrypted2Decrypted->Size = System::Drawing::Size(278, 23);
			this->bEncrypted2Decrypted->TabIndex = 6;
			this->bEncrypted2Decrypted->Text = L"Расшифровать encrypted.png в decrypted.png";
			this->bEncrypted2Decrypted->UseVisualStyleBackColor = true;
			this->bEncrypted2Decrypted->Click += gcnew System::EventHandler(this, &MainForm::bEncrypted2Decrypted_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(483, 488);
			this->Controls->Add(this->tcTasks);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Shown += gcnew System::EventHandler(this, &MainForm::MainForm_Shown);
			this->tcTasks->ResumeLayout(false);
			this->tpTask1->ResumeLayout(false);
			this->sc1_1->Panel1->ResumeLayout(false);
			this->sc1_1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sc1_1))->EndInit();
			this->sc1_1->ResumeLayout(false);
			this->sc1_a1->Panel1->ResumeLayout(false);
			this->sc1_a1->Panel1->PerformLayout();
			this->sc1_a1->Panel2->ResumeLayout(false);
			this->sc1_a1->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sc1_a1))->EndInit();
			this->sc1_a1->ResumeLayout(false);
			this->sc1_2->Panel1->ResumeLayout(false);
			this->sc1_2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sc1_2))->EndInit();
			this->sc1_2->ResumeLayout(false);
			this->sc1_a2->Panel1->ResumeLayout(false);
			this->sc1_a2->Panel1->PerformLayout();
			this->sc1_a2->Panel2->ResumeLayout(false);
			this->sc1_a2->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sc1_a2))->EndInit();
			this->sc1_a2->ResumeLayout(false);
			this->sc1_a3->Panel1->ResumeLayout(false);
			this->sc1_a3->Panel1->PerformLayout();
			this->sc1_a3->Panel2->ResumeLayout(false);
			this->sc1_a3->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sc1_a3))->EndInit();
			this->sc1_a3->ResumeLayout(false);
			this->tpTask2->ResumeLayout(false);
			this->sc2_1->Panel1->ResumeLayout(false);
			this->sc2_1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sc2_1))->EndInit();
			this->sc2_1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbMain))->EndInit();
			this->sc2_2->Panel1->ResumeLayout(false);
			this->sc2_2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sc2_2))->EndInit();
			this->sc2_2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbEncrypted))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbDecrypted))->EndInit();
			this->tpTask3->ResumeLayout(false);
			this->tpTask3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	DESCipher ^cipher;
	array<Byte> ^DESKey;
	array<Byte> ^DESIV;
	System::Void MainForm_Shown(System::Object^  sender, System::EventArgs^  e);
	//System::Void bEncryptString_Click(System::Object^  sender, System::EventArgs^  e);
	//System::Void bDecryptString_Click(System::Object^  sender, System::EventArgs^  e);
	//System::Void pbSource_Click(System::Object^  sender, System::EventArgs^  e);
	//System::Void bEncryptImage_Click(System::Object^  sender, System::EventArgs^  e);
	//System::Void bDecryptImage_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void tbMain_TextChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void pbMain_DoubleClick(System::Object^  sender, System::EventArgs^  e);
	System::Void ofgOpenImage_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e);
	System::Void bGenerate_Click(System::Object^  sender, System::EventArgs^  e);
	void Print();
	void Save();
	System::Void bSource2Encrypted_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void bEncrypted2Decrypted_Click(System::Object^  sender, System::EventArgs^  e);
};
}
