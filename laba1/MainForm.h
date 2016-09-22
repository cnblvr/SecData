#pragma once
#include "Frequency.h"
#include "RussianKeyboard.h"

namespace laba1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::SplitContainer^  sc_rtbs;
	protected:

	protected:
	private: System::Windows::Forms::Label^  l_Encoded;
	private: System::Windows::Forms::RichTextBox^  rtb_Encoded;

	private: System::Windows::Forms::Label^  l_Decoded;
	private: System::Windows::Forms::RichTextBox^  rtb_Decoded;


	private: System::Windows::Forms::DataGridView^  dgv_Frequency;





	private: System::Windows::Forms::Button^  b_Decode;
	private: System::Windows::Forms::Button^  b_Check;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dgv_c_Letter;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dgv_c_Quantity;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dgv_c_Frequency;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  dgv_c_Replacement;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dgv_c_Maybe;
	private: System::Windows::Forms::TextBox^  tb_Precision;
	private: System::Windows::Forms::SplitContainer^  sc_Main;































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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->sc_rtbs = (gcnew System::Windows::Forms::SplitContainer());
			this->l_Encoded = (gcnew System::Windows::Forms::Label());
			this->rtb_Encoded = (gcnew System::Windows::Forms::RichTextBox());
			this->l_Decoded = (gcnew System::Windows::Forms::Label());
			this->rtb_Decoded = (gcnew System::Windows::Forms::RichTextBox());
			this->dgv_Frequency = (gcnew System::Windows::Forms::DataGridView());
			this->dgv_c_Letter = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgv_c_Quantity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgv_c_Frequency = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgv_c_Replacement = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->dgv_c_Maybe = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->b_Decode = (gcnew System::Windows::Forms::Button());
			this->b_Check = (gcnew System::Windows::Forms::Button());
			this->tb_Precision = (gcnew System::Windows::Forms::TextBox());
			this->sc_Main = (gcnew System::Windows::Forms::SplitContainer());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sc_rtbs))->BeginInit();
			this->sc_rtbs->Panel1->SuspendLayout();
			this->sc_rtbs->Panel2->SuspendLayout();
			this->sc_rtbs->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_Frequency))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sc_Main))->BeginInit();
			this->sc_Main->Panel1->SuspendLayout();
			this->sc_Main->Panel2->SuspendLayout();
			this->sc_Main->SuspendLayout();
			this->SuspendLayout();
			// 
			// sc_rtbs
			// 
			this->sc_rtbs->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top|System::Windows::Forms::AnchorStyles::Bottom)
				|System::Windows::Forms::AnchorStyles::Left)
				|System::Windows::Forms::AnchorStyles::Right));
			this->sc_rtbs->Location = System::Drawing::Point(0, 0);
			this->sc_rtbs->Name = L"sc_rtbs";
			this->sc_rtbs->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// sc_rtbs.Panel1
			// 
			this->sc_rtbs->Panel1->Controls->Add(this->l_Encoded);
			this->sc_rtbs->Panel1->Controls->Add(this->rtb_Encoded);
			// 
			// sc_rtbs.Panel2
			// 
			this->sc_rtbs->Panel2->Controls->Add(this->l_Decoded);
			this->sc_rtbs->Panel2->Controls->Add(this->rtb_Decoded);
			this->sc_rtbs->Size = System::Drawing::Size(407, 362);
			this->sc_rtbs->SplitterDistance = 177;
			this->sc_rtbs->TabIndex = 0;
			// 
			// l_Encoded
			// 
			this->l_Encoded->AutoSize = true;
			this->l_Encoded->Location = System::Drawing::Point(5, 5);
			this->l_Encoded->Name = L"l_Encoded";
			this->l_Encoded->Size = System::Drawing::Size(125, 13);
			this->l_Encoded->TabIndex = 2;
			this->l_Encoded->Text = L"Закодированный текст";
			// 
			// rtb_Encoded
			// 
			this->rtb_Encoded->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top|System::Windows::Forms::AnchorStyles::Bottom)
				|System::Windows::Forms::AnchorStyles::Left)
				|System::Windows::Forms::AnchorStyles::Right));
			this->rtb_Encoded->Location = System::Drawing::Point(3, 21);
			this->rtb_Encoded->Name = L"rtb_Encoded";
			this->rtb_Encoded->Size = System::Drawing::Size(401, 153);
			this->rtb_Encoded->TabIndex = 1;
			this->rtb_Encoded->Text = resources->GetString(L"rtb_Encoded.Text");
			this->rtb_Encoded->TextChanged += gcnew System::EventHandler(this, &MainForm::rtb_Encoded_TextChanged);
			this->rtb_Encoded->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			// 
			// l_Decoded
			// 
			this->l_Decoded->AutoSize = true;
			this->l_Decoded->Location = System::Drawing::Point(5, 5);
			this->l_Decoded->Name = L"l_Decoded";
			this->l_Decoded->Size = System::Drawing::Size(131, 13);
			this->l_Decoded->TabIndex = 3;
			this->l_Decoded->Text = L"Раскодированный текст";
			// 
			// rtb_Decoded
			// 
			this->rtb_Decoded->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top|System::Windows::Forms::AnchorStyles::Bottom)
				|System::Windows::Forms::AnchorStyles::Left)
				|System::Windows::Forms::AnchorStyles::Right));
			this->rtb_Decoded->Location = System::Drawing::Point(3, 21);
			this->rtb_Decoded->Name = L"rtb_Decoded";
			this->rtb_Decoded->Size = System::Drawing::Size(401, 157);
			this->rtb_Decoded->TabIndex = 2;
			this->rtb_Decoded->Text = L"";
			this->rtb_Decoded->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			// 
			// dgv_Frequency
			// 
			this->dgv_Frequency->AllowUserToAddRows = false;
			this->dgv_Frequency->AllowUserToDeleteRows = false;
			this->dgv_Frequency->AllowUserToResizeRows = false;
			this->dgv_Frequency->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top|System::Windows::Forms::AnchorStyles::Bottom)
				|System::Windows::Forms::AnchorStyles::Left)
				|System::Windows::Forms::AnchorStyles::Right));
			this->dgv_Frequency->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgv_Frequency->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dgv_Frequency->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dgv_Frequency->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableWithoutHeaderText;
			this->dgv_Frequency->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_Frequency->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5)
			{
				this->dgv_c_Letter,
					this->dgv_c_Quantity, this->dgv_c_Frequency, this->dgv_c_Replacement, this->dgv_c_Maybe
			});
			this->dgv_Frequency->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnF2;
			this->dgv_Frequency->Location = System::Drawing::Point(3, 32);
			this->dgv_Frequency->Name = L"dgv_Frequency";
			this->dgv_Frequency->RowHeadersVisible = false;
			this->dgv_Frequency->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dgv_Frequency->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgv_Frequency->ShowCellErrors = false;
			this->dgv_Frequency->ShowCellToolTips = false;
			this->dgv_Frequency->ShowEditingIcon = false;
			this->dgv_Frequency->ShowRowErrors = false;
			this->dgv_Frequency->Size = System::Drawing::Size(556, 327);
			this->dgv_Frequency->TabIndex = 2;
			this->dgv_Frequency->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::dgv_Frequency_KeyDown);
			// 
			// dgv_c_Letter
			// 
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->dgv_c_Letter->DefaultCellStyle = dataGridViewCellStyle1;
			this->dgv_c_Letter->HeaderText = L"Буква";
			this->dgv_c_Letter->Name = L"dgv_c_Letter";
			this->dgv_c_Letter->ReadOnly = true;
			// 
			// dgv_c_Quantity
			// 
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->dgv_c_Quantity->DefaultCellStyle = dataGridViewCellStyle2;
			this->dgv_c_Quantity->HeaderText = L"Количество";
			this->dgv_c_Quantity->Name = L"dgv_c_Quantity";
			this->dgv_c_Quantity->ReadOnly = true;
			// 
			// dgv_c_Frequency
			// 
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->dgv_c_Frequency->DefaultCellStyle = dataGridViewCellStyle3;
			this->dgv_c_Frequency->HeaderText = L"Частота";
			this->dgv_c_Frequency->Name = L"dgv_c_Frequency";
			this->dgv_c_Frequency->ReadOnly = true;
			// 
			// dgv_c_Replacement
			// 
			this->dgv_c_Replacement->HeaderText = L"Заменяющий символ";
			this->dgv_c_Replacement->Name = L"dgv_c_Replacement";
			this->dgv_c_Replacement->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->dgv_c_Replacement->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// dgv_c_Maybe
			// 
			this->dgv_c_Maybe->HeaderText = L"Возможные символы";
			this->dgv_c_Maybe->Name = L"dgv_c_Maybe";
			this->dgv_c_Maybe->ReadOnly = true;
			// 
			// b_Decode
			// 
			this->b_Decode->Location = System::Drawing::Point(113, 3);
			this->b_Decode->Name = L"b_Decode";
			this->b_Decode->Size = System::Drawing::Size(104, 23);
			this->b_Decode->TabIndex = 3;
			this->b_Decode->Text = L"расшифровать";
			this->b_Decode->UseVisualStyleBackColor = true;
			this->b_Decode->Click += gcnew System::EventHandler(this, &MainForm::b_Decode_Click);
			this->b_Decode->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			// 
			// b_Check
			// 
			this->b_Check->Location = System::Drawing::Point(3, 3);
			this->b_Check->Name = L"b_Check";
			this->b_Check->Size = System::Drawing::Size(104, 23);
			this->b_Check->TabIndex = 4;
			this->b_Check->Text = L"распознать";
			this->b_Check->UseVisualStyleBackColor = true;
			this->b_Check->Click += gcnew System::EventHandler(this, &MainForm::b_Check_Click);
			this->b_Check->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			// 
			// tb_Precision
			// 
			this->tb_Precision->Location = System::Drawing::Point(223, 5);
			this->tb_Precision->Name = L"tb_Precision";
			this->tb_Precision->Size = System::Drawing::Size(68, 20);
			this->tb_Precision->TabIndex = 5;
			this->tb_Precision->Text = L"0,01";
			this->tb_Precision->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			// 
			// sc_Main
			// 
			this->sc_Main->Dock = System::Windows::Forms::DockStyle::Fill;
			this->sc_Main->Location = System::Drawing::Point(0, 0);
			this->sc_Main->Name = L"sc_Main";
			// 
			// sc_Main.Panel1
			// 
			this->sc_Main->Panel1->Controls->Add(this->sc_rtbs);
			// 
			// sc_Main.Panel2
			// 
			this->sc_Main->Panel2->Controls->Add(this->tb_Precision);
			this->sc_Main->Panel2->Controls->Add(this->dgv_Frequency);
			this->sc_Main->Panel2->Controls->Add(this->b_Decode);
			this->sc_Main->Panel2->Controls->Add(this->b_Check);
			this->sc_Main->Size = System::Drawing::Size(973, 362);
			this->sc_Main->SplitterDistance = 407;
			this->sc_Main->TabIndex = 6;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(973, 362);
			this->Controls->Add(this->sc_Main);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Shown += gcnew System::EventHandler(this, &MainForm::MainForm_Shown);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->sc_rtbs->Panel1->ResumeLayout(false);
			this->sc_rtbs->Panel1->PerformLayout();
			this->sc_rtbs->Panel2->ResumeLayout(false);
			this->sc_rtbs->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sc_rtbs))->EndInit();
			this->sc_rtbs->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_Frequency))->EndInit();
			this->sc_Main->Panel1->ResumeLayout(false);
			this->sc_Main->Panel2->ResumeLayout(false);
			this->sc_Main->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sc_Main))->EndInit();
			this->sc_Main->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private:
	Frequency ^core;

	System::Void MainForm_Shown(System::Object^  sender, System::EventArgs^  e);
	System::Void MainForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	System::Void b_Check_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void b_Decode_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void rtb_Encoded_TextChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void dgv_Frequency_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
};
}
