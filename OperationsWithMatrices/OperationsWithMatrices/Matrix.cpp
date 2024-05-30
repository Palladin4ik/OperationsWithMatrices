#include "Matrix.h"

void Matrix::Transpose(float** matr, float** tMatr, int n) //транспонирование
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tMatr[j][i] = matr[i][j];
}

void Matrix::Get_matr(float** matr, int n, float** temp_matr, int indRow, int indCol) //поиск побочной матрицы (берет значения матрицы без строки i и столбца j)
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

int Matrix::Det(float** matr, int n) //детерминант
{
    int temp = 0;   //временная переменная для хранения определителя
    int k = 1;      //степень
    if (n < 1) {    //если размер матрицы меньше 1
        return 0;
    }
    else if (n == 1) //если размер матрицы 1
        temp = matr[0][0]; //детерминантом является эта же ячейка
    else if (n == 2)
        temp = matr[0][0] * matr[1][1] - matr[1][0] * matr[0][1]; //формула поиска детерминанта матрицы размером 2
    else { //иначе
        for (int i = 0; i < n; i++) {
            int m = n - 1;

            float** temp_matr = new float* [m]; //задаем переменную для хранения значений матрицы без i строки и j столбца
            for (int j = 0; j < m; j++)
                temp_matr[j] = new float[m];

            Get_matr(matr, n, temp_matr, 0, i); //поиск побочной матрицы
            temp = temp + k * matr[0][i] * Det(temp_matr, m); //формула поиска детерминанта
            k = -k;

            Free(temp_matr, m); //освобождение памяти
        }
    }
    return temp; //возвращаем значение детерминанта
}

void Matrix::Free(float** m, int size) //освобождение памяти
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

Matrix::Matrix(const Matrix& m) //копия матрицы
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
    if (_matr != nullptr) //если не пустой
    {
        Free(_matr, _size);
    }
}

void Matrix::Resize(int size) 
{
    if(_matr != nullptr) //если не пустой
    {
        for (int i = 0; i < _size; i++) //прошлые значения удаляются
            delete[] _matr[i];
        delete[] _matr;
    }

    //задается новый размер
    _size = size;
    _matr = new float* [_size];
    for (int i = 0; i < _size; i++) 
        _matr[i] = new float[_size];

    FillEmpty(); //заполнение нулями
}

void Matrix::FillEmpty() //заполнение нулями
{
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            _matr[i][j] = 0;
        }
    }
}

void Matrix::Clear() //очистка памяти
{
    Free(_matr, _size);
}

void Matrix::Generate(int size) //перегенирирование размера+ ген значений
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

void Matrix::Invers() //обратная матрица
{
    float** obr_matr = new float* [_size];
    float** tobr_matr = new float* [_size];
    for (int i = 0; i < _size; i++) {
        obr_matr[i] = new float[_size];
        tobr_matr[i] = new float[_size];
    }

    int det = Det(_matr, _size);

    if (det == 0) {
        throw "Matrix::Invers(): Детерминат должен быть больше нуля!\nМатрица вырождена!";
        return;
    }

    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            int m = _size - 1;
            
            float** temp_matr = new float* [m];
            for (int k = 0; k < m; k++)
                temp_matr[k] = new float[m];

            Get_matr(_matr, _size, temp_matr, i, j); //берет матрицу без строки i и столбца j
            obr_matr[i][j] = pow(-1.0, i + j + 2) * Det(temp_matr, m) / det; //формула вычисления обратной матрицы
            Free(temp_matr, m); //освобождение памяти, выделенной под temp_matr
        }
    }

    Transpose(obr_matr, tobr_matr, _size); //(обратная, транспонированная матрицы) Трвнспонирование

    for (int i = 0; i < _size; i++) { //перенос значений из транспонированной матрицы в требуемую
        for (int j = 0; j < _size; j++) {
            _matr[i][j] = tobr_matr[i][j];
        }
    }

    //освобождение памяти
    Free(obr_matr, _size);
    Free(tobr_matr, _size);
}

void Matrix::Addition(const Matrix& a, const Matrix& b) //сложение
{
    if (a._size != b._size &&
        _size != a._size) {
        throw std::string("Matrix::Addition(): Размерность матриц не совпала!");
        return;
    }

    FillEmpty(); //заполнение нулями
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            _matr[i][j] = a._matr[i][j] + b._matr[i][j];
        }
    }
}

void Matrix::Difference(const Matrix& a, const Matrix& b) //разность
{
    if (a._size != b._size &&
        _size != a._size) {
        throw std::string("Matrix::Difference(): Размерность матриц не совпала!");
        return;
    }

    FillEmpty();
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            _matr[i][j] = a._matr[i][j] - b._matr[i][j];
        }
    }
}

void Matrix::Multiplication(const Matrix& a, const Matrix& b) //умножение
{
    if (a._size != b._size && 
        _size != a._size) {
        throw std::string("Matrix::Multiplication(): Размерность матриц не совпала!");
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

void Matrix::Division(const Matrix& a, const Matrix& b) //деление
{

    if (a._size != b._size && _size != a._size) {
        throw std::string("Matrix::Division(): Размерность матриц не совпала!");
        return;
    }

    FillEmpty();

    Matrix b_(b);

    b_.Invers();
    Multiplication(a, b_);
}

void Matrix::Transpose(Matrix& a) //транспонирование
{
    if (a._size != _size) {
        throw std::string("Matrix::Transpose(): Размерность матриц не совпала!");
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
