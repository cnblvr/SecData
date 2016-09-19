#pragma once
#include "Frequency.h"

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
	private: System::Windows::Forms::SplitContainer^  sc_Main;
	protected:
	private: System::Windows::Forms::Label^  l_Encoded;
	private: System::Windows::Forms::RichTextBox^  rtb_Encoded;

	private: System::Windows::Forms::Label^  l_Decoded;
	private: System::Windows::Forms::RichTextBox^  rtb_Decoded;


	private: System::Windows::Forms::DataGridView^  dgv_Frequency;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dgv_c_Letter;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dgv_c_Quantity;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dgv_c_Frequency;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dgv_c_StatisticalFrequency;



















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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->sc_Main = (gcnew System::Windows::Forms::SplitContainer());
			this->l_Encoded = (gcnew System::Windows::Forms::Label());
			this->rtb_Encoded = (gcnew System::Windows::Forms::RichTextBox());
			this->l_Decoded = (gcnew System::Windows::Forms::Label());
			this->rtb_Decoded = (gcnew System::Windows::Forms::RichTextBox());
			this->dgv_Frequency = (gcnew System::Windows::Forms::DataGridView());
			this->dgv_c_Letter = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgv_c_Quantity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgv_c_Frequency = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgv_c_StatisticalFrequency = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sc_Main))->BeginInit();
			this->sc_Main->Panel1->SuspendLayout();
			this->sc_Main->Panel2->SuspendLayout();
			this->sc_Main->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_Frequency))->BeginInit();
			this->SuspendLayout();
			// 
			// sc_Main
			// 
			this->sc_Main->Location = System::Drawing::Point(12, 12);
			this->sc_Main->Name = L"sc_Main";
			this->sc_Main->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// sc_Main.Panel1
			// 
			this->sc_Main->Panel1->Controls->Add(this->l_Encoded);
			this->sc_Main->Panel1->Controls->Add(this->rtb_Encoded);
			// 
			// sc_Main.Panel2
			// 
			this->sc_Main->Panel2->Controls->Add(this->l_Decoded);
			this->sc_Main->Panel2->Controls->Add(this->rtb_Decoded);
			this->sc_Main->Size = System::Drawing::Size(312, 256);
			this->sc_Main->SplitterDistance = 126;
			this->sc_Main->TabIndex = 0;
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
			this->rtb_Encoded->Location = System::Drawing::Point(0, 20);
			this->rtb_Encoded->Name = L"rtb_Encoded";
			this->rtb_Encoded->Size = System::Drawing::Size(312, 106);
			this->rtb_Encoded->TabIndex = 1;
			this->rtb_Encoded->Text = resources->GetString(L"rtb_Encoded.Text");
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
			this->rtb_Decoded->Location = System::Drawing::Point(0, 20);
			this->rtb_Decoded->Name = L"rtb_Decoded";
			this->rtb_Decoded->Size = System::Drawing::Size(312, 106);
			this->rtb_Decoded->TabIndex = 2;
			this->rtb_Decoded->Text = L"";
			this->rtb_Decoded->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			// 
			// dgv_Frequency
			// 
			this->dgv_Frequency->AllowUserToAddRows = false;
			this->dgv_Frequency->AllowUserToDeleteRows = false;
			this->dgv_Frequency->AllowUserToResizeRows = false;
			this->dgv_Frequency->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::ColumnHeader;
			this->dgv_Frequency->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dgv_Frequency->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dgv_Frequency->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableWithoutHeaderText;
			this->dgv_Frequency->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_Frequency->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4)
			{
				this->dgv_c_Letter,
					this->dgv_c_Quantity, this->dgv_c_Frequency, this->dgv_c_StatisticalFrequency
			});
			this->dgv_Frequency->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->dgv_Frequency->Location = System::Drawing::Point(330, 12);
			this->dgv_Frequency->Name = L"dgv_Frequency";
			this->dgv_Frequency->ReadOnly = true;
			this->dgv_Frequency->RowHeadersVisible = false;
			this->dgv_Frequency->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dgv_Frequency->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgv_Frequency->ShowCellErrors = false;
			this->dgv_Frequency->ShowCellToolTips = false;
			this->dgv_Frequency->ShowEditingIcon = false;
			this->dgv_Frequency->ShowRowErrors = false;
			this->dgv_Frequency->Size = System::Drawing::Size(370, 256);
			this->dgv_Frequency->TabIndex = 2;
			this->dgv_Frequency->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			// 
			// dgv_c_Letter
			// 
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->dgv_c_Letter->DefaultCellStyle = dataGridViewCellStyle4;
			this->dgv_c_Letter->HeaderText = L"Буква";
			this->dgv_c_Letter->Name = L"dgv_c_Letter";
			this->dgv_c_Letter->ReadOnly = true;
			this->dgv_c_Letter->Width = 62;
			// 
			// dgv_c_Quantity
			// 
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->dgv_c_Quantity->DefaultCellStyle = dataGridViewCellStyle5;
			this->dgv_c_Quantity->HeaderText = L"Количество";
			this->dgv_c_Quantity->Name = L"dgv_c_Quantity";
			this->dgv_c_Quantity->ReadOnly = true;
			this->dgv_c_Quantity->Width = 91;
			// 
			// dgv_c_Frequency
			// 
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->dgv_c_Frequency->DefaultCellStyle = dataGridViewCellStyle6;
			this->dgv_c_Frequency->HeaderText = L"Частота";
			this->dgv_c_Frequency->Name = L"dgv_c_Frequency";
			this->dgv_c_Frequency->ReadOnly = true;
			this->dgv_c_Frequency->Width = 74;
			// 
			// dgv_c_StatisticalFrequency
			// 
			this->dgv_c_StatisticalFrequency->HeaderText = L"Статистическая частота";
			this->dgv_c_StatisticalFrequency->Name = L"dgv_c_StatisticalFrequency";
			this->dgv_c_StatisticalFrequency->ReadOnly = true;
			this->dgv_c_StatisticalFrequency->Width = 141;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(707, 279);
			this->Controls->Add(this->dgv_Frequency);
			this->Controls->Add(this->sc_Main);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Shown += gcnew System::EventHandler(this, &MainForm::MainForm_Shown);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->sc_Main->Panel1->ResumeLayout(false);
			this->sc_Main->Panel1->PerformLayout();
			this->sc_Main->Panel2->ResumeLayout(false);
			this->sc_Main->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sc_Main))->EndInit();
			this->sc_Main->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_Frequency))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private:
	System::Void MainForm_Shown(System::Object^  sender, System::EventArgs^  e);
	System::Void MainForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
};
}
