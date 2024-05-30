#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>

class Matrix
{
private:
	int _size; //размер матриц
	float** _matr; //указатель на адрес ячеек

	void Transpose(float** matr, float** tMatr, int n); //транспонирование для деления
	void Get_matr( float** matr, int n, float** temp_matr, int indRow, int indCol); //матрица без i строки и j столбца
	int Det(float** matr, int n); //детерминант
	void Free(float** m, int size); //освобождение памяти
public: 
	Matrix(); //конструктор без параметров
	Matrix(int size); //конструктор с параметрами
	Matrix(const Matrix&); //конструктор с матрицей
	~Matrix(); //деструктор

	int GetSize() { return _size; } //вернуть размер
	float** GetMatrix() { return _matr; } //вернуть значение

	void Resize(int size); //изменение размера
	void FillEmpty(); //заполнить пустые ячейки нулями
	void Clear(); //очищение указателя
	void Generate(int size); //генерация значений
	void Generate();

	void Invers(); //обратная матрица

	void Addition(const Matrix& a, const Matrix& b); //сложение
	void Difference(const Matrix& a, const Matrix& b); //вычитание
	void Multiplication(const Matrix& a, const Matrix& b); //умножение
	void Division(const Matrix& a, const Matrix& b); //деление
	void Transpose(Matrix& a); //транспонирование

	//отладка

	/*void ConsolePrint();
	void ConsoleInput();
	void Load(std::string fname);*/
};

