#include "FMainForm.h"
#include "Matrix.h"

using namespace System;
using namespace System::Windows::Forms;

//���������� ���������� � ���� �����
Matrix a;
Matrix b;
Matrix c;

[System::Runtime::InteropServices::DllImport("user32.dll")]
bool SetProcessDPIAware();

[STAThreadAttribute]
void main() {
    if (Environment::OSVersion->Version->Major >= 6)
        SetProcessDPIAware();

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(true);

    OperationsWithMatrices::FMainForm form;
    Application::Run(% form);
}

OperationsWithMatrices::FMainForm::FMainForm(void) //����������� �����
{
    InitializeComponent();
}

void OperationsWithMatrices::FMainForm::PrintMatrix(EMatrix state) //����� ������
{
    int rows = 0, columns = 0;
    DataGridView^ dgv;

    switch (state)
    {
    case A:
        //����� �������� � �������
        dgv = dataGridView_A; 
        rows = a.GetSize();
        columns = a.GetSize();
        break;

    case B:
        dgv = dataGridView_B;
        rows = b.GetSize();
        columns = b.GetSize();
        break;

    case C:
        dgv = dataGridView_C;
        rows = c.GetSize();
        columns = c.GetSize();
        break;

    default:
        break;
    }

    dgv->Rows->Clear();
    dgv->Columns->Clear();

    for (int i = 0; i < rows; i++) {
        DataGridViewTextBoxColumn^ column = gcnew DataGridViewTextBoxColumn();
        column->HeaderText = Convert::ToString(i + 1);

        dgv->Columns->Add(column);
    }

    for (int i = 0; i < rows; i++) {
        dgv->Rows->Add();
        dgv->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);

        for (int j = 0; j < columns; j++) {
            if (state == EMatrix::A) {
                dgv->Rows[i]->Cells[j]->Value = a.GetMatrix()[i][j].ToString();
            }
            else if (state == EMatrix::B) {
                dgv->Rows[i]->Cells[j]->Value = b.GetMatrix()[i][j].ToString();
            }
            else if (state == EMatrix::C) {
                dgv->Rows[i]->Cells[j]->Value = c.GetMatrix()[i][j].ToString();
            }
        }
    }
}

void OperationsWithMatrices::FMainForm::InputMatrix(EMatrix state) //���� ������
{
    //�������� ������
    if (!_isDirtyA && state == EMatrix::A)
        return;

    if (!_isDirtyB && state == EMatrix::B)
        return;

    DataGridView^ dgv;
    switch (state)
    {
    case A:
        dgv = dataGridView_A;
        break;

    case B:
        dgv = dataGridView_B;
        break;

    case C:
        dgv = dataGridView_C;
        break;

    default:
        return;
    }

    int rows = dgv->Rows->Count;
    int columns = dataGridView_A->Columns->Count;

    //������ �������� ������
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++) {
            if (state == EMatrix::A) {
                a.GetMatrix()[i][j] = Convert::ToSingle(dgv->Rows[i]->Cells[j]->Value);
            }
            else if (state == EMatrix::B) {
                b.GetMatrix()[i][j] = Convert::ToSingle(dgv->Rows[i]->Cells[j]->Value);
            }
        }
    }
    
}

System::Void OperationsWithMatrices::FMainForm::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) //������ �����
{
    Application::Exit();
}

System::Void OperationsWithMatrices::FMainForm::button_Create_Click(System::Object^ sender, System::EventArgs^ e) //������ �������
{
    try {
        int size = Convert::ToInt32(numericUpDown_Size->Value);

        a.Resize(size);
        b.Resize(size);
        c.Resize(size);

        PrintMatrix(EMatrix::A);
        PrintMatrix(EMatrix::B);
        PrintMatrix(EMatrix::C);
    }

    //����� ������
    catch (const std::exception&) {
        throw "���-�� ����� �� ���.\n������� ����������!";
    }
}

System::Void OperationsWithMatrices::FMainForm::button_Gen_Click(System::Object^ sender, System::EventArgs^ e) //���������
{
    try {
        int size = Convert::ToInt32(numericUpDown_Size->Value);

        srand(time(NULL)); //������������ �� �������

        a.Generate(size);
        b.Generate(size);
        c.Generate(size);

        PrintMatrix(EMatrix::A);
        PrintMatrix(EMatrix::B);
        PrintMatrix(EMatrix::C);
    }
    //����� ������
    catch (const std::exception&) {
        throw "���-�� ����� �� ���.\n������� ����������!";
    }
}

System::Void OperationsWithMatrices::FMainForm::button_Plus_Click(System::Object^ sender, System::EventArgs^ e) //������ �������� ����
{
    try {
        InputMatrix(EMatrix::A);
        InputMatrix(EMatrix::B);
        
        c.Addition(a, b);
        PrintMatrix(EMatrix::C);
    }

    //����� ������
    catch (const std::exception&) {
        throw "���-�� ����� �� ���.\n������� ����������!";
    }
}

System::Void OperationsWithMatrices::FMainForm::button_Minus_Click(System::Object^ sender, System::EventArgs^ e) //������ ��������� ����
{
    try {
        InputMatrix(EMatrix::A);
        InputMatrix(EMatrix::B);

        c.Difference(a, b);
        PrintMatrix(EMatrix::C);
    }

    //����� ������
    catch (const std::exception&) {
        throw "���-�� ����� �� ���.\n������� ����������!";
    }
}

System::Void OperationsWithMatrices::FMainForm::button_Multiply_Click(System::Object^ sender, System::EventArgs^ e) //������ ��������� ����
{
    try {
        InputMatrix(EMatrix::A);
        InputMatrix(EMatrix::B);

        c.Multiplication(a, b);
        PrintMatrix(EMatrix::C);
    }

    //����� ������
    catch (const std::exception&) {
        throw "���-�� ����� �� ���.\n������� ����������!";
    }
}

System::Void OperationsWithMatrices::FMainForm::button_Divide_Click(System::Object^ sender, System::EventArgs^ e) //������ ������� ����
{
    try {
        InputMatrix(EMatrix::A);
        InputMatrix(EMatrix::B);

        c.Division(a, b);
        PrintMatrix(EMatrix::C);
    }

    //����� ������
    catch (const std::exception&) {
        throw "���-�� ����� �� ���.\n������� ����������!";
    }
  
}

System::Void OperationsWithMatrices::FMainForm::button_Transpose_Click(System::Object^ sender, System::EventArgs^ e) //������ ���������������� ����
{
    try {
        InputMatrix(EMatrix::A);

        c.Transpose(a);
        PrintMatrix(EMatrix::C);
    }

    //����� ������
    catch (const std::exception&) {
        throw "���-�� ����� �� ���.\n������� ����������!";
    }
}

System::Void OperationsWithMatrices::FMainForm::dataGridView_A_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) //��� ���������� ����� ������� A
{
    _isDirtyA = true; //������ ����
}

System::Void OperationsWithMatrices::FMainForm::dataGridView_B_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) //��� ���������� ����� ������� B
{
    _isDirtyB = true;
}
