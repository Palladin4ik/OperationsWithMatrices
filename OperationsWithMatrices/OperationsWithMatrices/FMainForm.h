#pragma once

enum EMatrix {
	A,
	B,
	C
};

namespace OperationsWithMatrices {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для FMainForm
	/// </summary>
	public ref class FMainForm : public System::Windows::Forms::Form
	{
	public:
		FMainForm(void);

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FMainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;



	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Button^ button_Plus;


	private: System::Windows::Forms::Button^ button_Gen;

	private: System::Windows::Forms::Button^ button_Create;
	private: System::Windows::Forms::Button^ button_Transpose;


	private: System::Windows::Forms::Button^ button_Divide;

	private: System::Windows::Forms::Button^ button_Multiply;


	private: System::Windows::Forms::Button^ button_Minus;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_Size;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::DataGridView^ dataGridView_A;
	private: System::Windows::Forms::DataGridView^ dataGridView_B;
	private: System::Windows::Forms::DataGridView^ dataGridView_C;
	private: System::Windows::Forms::NotifyIcon^ notifyIcon1;

	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView_A = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView_B = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown_Size = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button_Transpose = (gcnew System::Windows::Forms::Button());
			this->button_Divide = (gcnew System::Windows::Forms::Button());
			this->button_Multiply = (gcnew System::Windows::Forms::Button());
			this->button_Minus = (gcnew System::Windows::Forms::Button());
			this->button_Plus = (gcnew System::Windows::Forms::Button());
			this->button_Gen = (gcnew System::Windows::Forms::Button());
			this->button_Create = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView_C = (gcnew System::Windows::Forms::DataGridView());
			this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_A))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_B))->BeginInit();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Size))->BeginInit();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_C))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->выходToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(845, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &FMainForm::выходToolStripMenuItem_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->dataGridView_A);
			this->groupBox1->Location = System::Drawing::Point(9, 25);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(407, 286);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Матрица А";
			// 
			// dataGridView_A
			// 
			this->dataGridView_A->AllowUserToAddRows = false;
			this->dataGridView_A->AllowUserToDeleteRows = false;
			this->dataGridView_A->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_A->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView_A->Location = System::Drawing::Point(2, 15);
			this->dataGridView_A->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView_A->Name = L"dataGridView_A";
			this->dataGridView_A->RowHeadersWidth = 51;
			this->dataGridView_A->RowTemplate->Height = 24;
			this->dataGridView_A->Size = System::Drawing::Size(403, 269);
			this->dataGridView_A->TabIndex = 0;
			this->dataGridView_A->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FMainForm::dataGridView_A_CellClick);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->dataGridView_B);
			this->groupBox2->Location = System::Drawing::Point(428, 25);
			this->groupBox2->Margin = System::Windows::Forms::Padding(2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(2);
			this->groupBox2->Size = System::Drawing::Size(407, 286);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Матрица B";
			// 
			// dataGridView_B
			// 
			this->dataGridView_B->AllowUserToAddRows = false;
			this->dataGridView_B->AllowUserToDeleteRows = false;
			this->dataGridView_B->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_B->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView_B->Location = System::Drawing::Point(2, 15);
			this->dataGridView_B->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView_B->Name = L"dataGridView_B";
			this->dataGridView_B->RowHeadersWidth = 51;
			this->dataGridView_B->RowTemplate->Height = 24;
			this->dataGridView_B->Size = System::Drawing::Size(403, 269);
			this->dataGridView_B->TabIndex = 1;
			this->dataGridView_B->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FMainForm::dataGridView_B_CellClick);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->numericUpDown_Size);
			this->groupBox4->Controls->Add(this->label1);
			this->groupBox4->Controls->Add(this->button_Transpose);
			this->groupBox4->Controls->Add(this->button_Divide);
			this->groupBox4->Controls->Add(this->button_Multiply);
			this->groupBox4->Controls->Add(this->button_Minus);
			this->groupBox4->Controls->Add(this->button_Plus);
			this->groupBox4->Controls->Add(this->button_Gen);
			this->groupBox4->Controls->Add(this->button_Create);
			this->groupBox4->Location = System::Drawing::Point(9, 316);
			this->groupBox4->Margin = System::Windows::Forms::Padding(2);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Padding = System::Windows::Forms::Padding(2);
			this->groupBox4->Size = System::Drawing::Size(407, 286);
			this->groupBox4->TabIndex = 2;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Действия";
			// 
			// numericUpDown_Size
			// 
			this->numericUpDown_Size->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->numericUpDown_Size->Location = System::Drawing::Point(225, 20);
			this->numericUpDown_Size->Margin = System::Windows::Forms::Padding(2);
			this->numericUpDown_Size->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDown_Size->Name = L"numericUpDown_Size";
			this->numericUpDown_Size->Size = System::Drawing::Size(136, 28);
			this->numericUpDown_Size->TabIndex = 8;
			this->numericUpDown_Size->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(11, 21);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(219, 24);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Размерность матрицы:\r\n";
			// 
			// button_Transpose
			// 
			this->button_Transpose->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button_Transpose->Location = System::Drawing::Point(32, 239);
			this->button_Transpose->Margin = System::Windows::Forms::Padding(2);
			this->button_Transpose->Name = L"button_Transpose";
			this->button_Transpose->Size = System::Drawing::Size(328, 32);
			this->button_Transpose->TabIndex = 6;
			this->button_Transpose->Text = L"Транспонировать А(T)";
			this->button_Transpose->UseVisualStyleBackColor = true;
			this->button_Transpose->Click += gcnew System::EventHandler(this, &FMainForm::button_Transpose_Click);
			// 
			// button_Divide
			// 
			this->button_Divide->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Divide->Location = System::Drawing::Point(32, 202);
			this->button_Divide->Margin = System::Windows::Forms::Padding(2);
			this->button_Divide->Name = L"button_Divide";
			this->button_Divide->Size = System::Drawing::Size(328, 32);
			this->button_Divide->TabIndex = 5;
			this->button_Divide->Text = L"Разделить А \\ B";
			this->button_Divide->UseVisualStyleBackColor = true;
			this->button_Divide->Click += gcnew System::EventHandler(this, &FMainForm::button_Divide_Click);
			// 
			// button_Multiply
			// 
			this->button_Multiply->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Multiply->Location = System::Drawing::Point(32, 164);
			this->button_Multiply->Margin = System::Windows::Forms::Padding(2);
			this->button_Multiply->Name = L"button_Multiply";
			this->button_Multiply->Size = System::Drawing::Size(328, 32);
			this->button_Multiply->TabIndex = 4;
			this->button_Multiply->Text = L"Умножить А * B";
			this->button_Multiply->UseVisualStyleBackColor = true;
			this->button_Multiply->Click += gcnew System::EventHandler(this, &FMainForm::button_Multiply_Click);
			// 
			// button_Minus
			// 
			this->button_Minus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Minus->Location = System::Drawing::Point(32, 127);
			this->button_Minus->Margin = System::Windows::Forms::Padding(2);
			this->button_Minus->Name = L"button_Minus";
			this->button_Minus->Size = System::Drawing::Size(328, 32);
			this->button_Minus->TabIndex = 3;
			this->button_Minus->Text = L"Вычесть А - B";
			this->button_Minus->UseVisualStyleBackColor = true;
			this->button_Minus->Click += gcnew System::EventHandler(this, &FMainForm::button_Minus_Click);
			// 
			// button_Plus
			// 
			this->button_Plus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Plus->Location = System::Drawing::Point(32, 89);
			this->button_Plus->Margin = System::Windows::Forms::Padding(2);
			this->button_Plus->Name = L"button_Plus";
			this->button_Plus->Size = System::Drawing::Size(328, 32);
			this->button_Plus->TabIndex = 2;
			this->button_Plus->Text = L"Сложить А + B";
			this->button_Plus->UseVisualStyleBackColor = true;
			this->button_Plus->Click += gcnew System::EventHandler(this, &FMainForm::button_Plus_Click);
			// 
			// button_Gen
			// 
			this->button_Gen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Gen->Location = System::Drawing::Point(199, 52);
			this->button_Gen->Margin = System::Windows::Forms::Padding(2);
			this->button_Gen->Name = L"button_Gen";
			this->button_Gen->Size = System::Drawing::Size(162, 32);
			this->button_Gen->TabIndex = 1;
			this->button_Gen->Text = L"Сгенерировать";
			this->button_Gen->UseVisualStyleBackColor = true;
			this->button_Gen->Click += gcnew System::EventHandler(this, &FMainForm::button_Gen_Click);
			// 
			// button_Create
			// 
			this->button_Create->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Create->Location = System::Drawing::Point(32, 52);
			this->button_Create->Margin = System::Windows::Forms::Padding(2);
			this->button_Create->Name = L"button_Create";
			this->button_Create->Size = System::Drawing::Size(162, 32);
			this->button_Create->TabIndex = 0;
			this->button_Create->Text = L"Создать";
			this->button_Create->UseVisualStyleBackColor = true;
			this->button_Create->Click += gcnew System::EventHandler(this, &FMainForm::button_Create_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->dataGridView_C);
			this->groupBox3->Location = System::Drawing::Point(428, 316);
			this->groupBox3->Margin = System::Windows::Forms::Padding(2);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(2);
			this->groupBox3->Size = System::Drawing::Size(407, 286);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Результат";
			// 
			// dataGridView_C
			// 
			this->dataGridView_C->AllowUserToAddRows = false;
			this->dataGridView_C->AllowUserToDeleteRows = false;
			this->dataGridView_C->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_C->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView_C->Location = System::Drawing::Point(2, 15);
			this->dataGridView_C->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView_C->Name = L"dataGridView_C";
			this->dataGridView_C->RowHeadersWidth = 51;
			this->dataGridView_C->RowTemplate->Height = 24;
			this->dataGridView_C->Size = System::Drawing::Size(403, 269);
			this->dataGridView_C->TabIndex = 2;
			// 
			// notifyIcon1
			// 
			this->notifyIcon1->Text = L"notifyIcon1";
			this->notifyIcon1->Visible = true;
			// 
			// FMainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(845, 611);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"FMainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Матричный калькулятор";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_A))->EndInit();
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_B))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Size))->EndInit();
			this->groupBox3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_C))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
// Параметры формы
private: bool _isDirtyA = false; //для оптимиз  данные изменены, есть смысл менять, если не менялись, не трогаем
private: bool _isDirtyB = false;

// Методы формы
private: void PrintMatrix(EMatrix state);
private: void InputMatrix(EMatrix state);

// События формы
private: System::Void выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void button_Create_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Gen_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void button_Plus_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Minus_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Multiply_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Divide_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Transpose_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void dataGridView_A_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
private: System::Void dataGridView_B_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
};
}
