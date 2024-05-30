#include "Matrix.h"

void Matrix::Transpose(float** matr, float** tMatr, int n) //����������������
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tMatr[j][i] = matr[i][j];
}

void Matrix::Get_matr(float** matr, int n, float** temp_matr, int indRow, int indCol) //����� �������� ������� (����� �������� ������� ��� ������ i � ������� j)
{
    int ki = 0;
    for (int i = 0; i < n; i++) {
        if (i != indRow) {
            for (int j = 0, kj = 0; j < n; j++) {
                if (j != indCol) {
                    temp_matr[ki][kj] = matr[i][j];
                    kj++;
                }
            }
            ki++;
        }
    }
}

int Matrix::Det(float** matr, int n) //�����������
{
    int temp = 0;   //��������� ���������� ��� �������� ������������
    int k = 1;      //�������
    if (n < 1) {    //���� ������ ������� ������ 1
        return 0;
    }
    else if (n == 1) //���� ������ ������� 1
        temp = matr[0][0]; //������������� �������� ��� �� ������
    else if (n == 2)
        temp = matr[0][0] * matr[1][1] - matr[1][0] * matr[0][1]; //������� ������ ������������ ������� �������� 2
    else { //�����
        for (int i = 0; i < n; i++) {
            int m = n - 1;

            float** temp_matr = new float* [m]; //������ ���������� ��� �������� �������� ������� ��� i ������ � j �������
            for (int j = 0; j < m; j++)
                temp_matr[j] = new float[m];

            Get_matr(matr, n, temp_matr, 0, i); //����� �������� �������
            temp = temp + k * matr[0][i] * Det(temp_matr, m); //������� ������ ������������
            k = -k;

            Free(temp_matr, m); //������������ ������
        }
    }
    return temp; //���������� �������� ������������
}

void Matrix::Free(float** m, int size) //������������ ������
{
    if (m == nullptr)
        return;

    for (int i = 0; i < size; i++)
        delete[] m[i];
    delete[] m;
}

Matrix::Matrix()
{
    Resize(0);
}

Matrix::Matrix(int size)
{
    Resize(size);
}

Matrix::Matrix(const Matrix& m) //����� �������
{
    _size = m._size;
    _matr = new float* [_size];
    for (int i = 0; i < _size; i++)
        _matr[i] = new float[_size];

    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            _matr[i][j] = m._matr[i][j];
        }
    }
}

Matrix::~Matrix()
{
    if (_matr != nullptr) //���� �� ������
    {
        Free(_matr, _size);
    }
}

void Matrix::Resize(int size) 
{
    if(_matr != nullptr) //���� �� ������
    {
        for (int i = 0; i < _size; i++) //������� �������� ���������
            delete[] _matr[i];
        delete[] _matr;
    }

    //�������� ����� ������
    _size = size;
    _matr = new float* [_size];
    for (int i = 0; i < _size; i++) 
        _matr[i] = new float[_size];

    FillEmpty(); //���������� ������
}

void Matrix::FillEmpty() //���������� ������
{
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            _matr[i][j] = 0;
        }
    }
}

void Matrix::Clear() //������� ������
{
    Free(_matr, _size);
}

void Matrix::Generate(int size) //����������������� �������+ ��� ��������
{
    Resize(size);
    Generate();
}

void Matrix::Generate()
{
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            _matr[i][j] = rand() % 50;
        }
    }
}

void Matrix::Invers() //�������� �������
{
    float** obr_matr = new float* [_size];
    float** tobr_matr = new float* [_size];
    for (int i = 0; i < _size; i++) {
        obr_matr[i] = new float[_size];
        tobr_matr[i] = new float[_size];
    }

    int det = Det(_matr, _size);

    if (det == 0) {
        throw "Matrix::Invers(): ���������� ������ ���� ������ ����!\n������� ���������!";
        return;
    }

    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            int m = _size - 1;
            
            float** temp_matr = new float* [m];
            for (int k = 0; k < m; k++)
                temp_matr[k] = new float[m];

            Get_matr(_matr, _size, temp_matr, i, j); //����� ������� ��� ������ i � ������� j
            obr_matr[i][j] = pow(-1.0, i + j + 2) * Det(temp_matr, m) / det; //������� ���������� �������� �������
            Free(temp_matr, m); //������������ ������, ���������� ��� temp_matr
        }
    }

    Transpose(obr_matr, tobr_matr, _size); //(��������, ����������������� �������) ����������������

    for (int i = 0; i < _size; i++) { //������� �������� �� ����������������� ������� � ���������
        for (int j = 0; j < _size; j++) {
            _matr[i][j] = tobr_matr[i][j];
        }
    }

    //������������ ������
    Free(obr_matr, _size);
    Free(tobr_matr, _size);
}

void Matrix::Addition(const Matrix& a, const Matrix& b) //��������
{
    if (a._size != b._size &&
        _size != a._size) {
        throw std::string("Matrix::Addition(): ����������� ������ �� �������!");
        return;
    }

    FillEmpty(); //���������� ������
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            _matr[i][j] = a._matr[i][j] + b._matr[i][j];
        }
    }
}

void Matrix::Difference(const Matrix& a, const Matrix& b) //��������
{
    if (a._size != b._size &&
        _size != a._size) {
        throw std::string("Matrix::Difference(): ����������� ������ �� �������!");
        return;
    }

    FillEmpty();
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            _matr[i][j] = a._matr[i][j] - b._matr[i][j];
        }
    }
}

void Matrix::Multiplication(const Matrix& a, const Matrix& b) //���������
{
    if (a._size != b._size && 
        _size != a._size) {
        throw std::string("Matrix::Multiplication(): ����������� ������ �� �������!");
        return;
    }

    FillEmpty();
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            for (int k = 0; k < _size; k++) {
                _matr[i][j] += a._matr[i][k] * b._matr[k][j];
            }
        }
    }
}

void Matrix::Division(const Matrix& a, const Matrix& b) //�������
{

    if (a._size != b._size && _size != a._size) {
        throw std::string("Matrix::Division(): ����������� ������ �� �������!");
        return;
    }

    FillEmpty();

    Matrix b_(b);

    b_.Invers();
    Multiplication(a, b_);
}

void Matrix::Transpose(Matrix& a) //����������������
{
    if (a._size != _size) {
        throw std::string("Matrix::Transpose(): ����������� ������ �� �������!");
        return;
    }

    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            _matr[i][j] = a._matr[j][i];
        }
    }
}

//void Matrix::ConsolePrint()
//{
//    for (int i = 0; i < _size; i++) {
//        for (int j = 0; j < _size; j++) {
//            std::cout << _matr[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//}
//
//void Matrix::ConsoleInput()
//{
//    for (int i = 0; i < _size; i++) {
//        for (int j = 0; j < _size; j++) {
//            std::cin >> _matr[i][j];
//        }
//    }
//}
//
//void Matrix::Load(std::string fname)
//{
//    std::ifstream fin(fname);
//    if (!fin)
//        return;
//
//    fin >> _size;
//    Resize(_size);
//
//    for (int i = 0; i < _size; i++) {
//        for (int j = 0; j < _size; j++) {
//            fin >> _matr[i][j];
//        }
//    }
//}
