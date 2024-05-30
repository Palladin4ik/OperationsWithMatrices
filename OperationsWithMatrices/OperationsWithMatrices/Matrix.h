#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>

class Matrix
{
private:
	int _size; //������ ������
	float** _matr; //��������� �� ����� �����

	void Transpose(float** matr, float** tMatr, int n); //���������������� ��� �������
	void Get_matr( float** matr, int n, float** temp_matr, int indRow, int indCol); //������� ��� i ������ � j �������
	int Det(float** matr, int n); //�����������
	void Free(float** m, int size); //������������ ������
public: 
	Matrix(); //����������� ��� ����������
	Matrix(int size); //����������� � �����������
	Matrix(const Matrix&); //����������� � ��������
	~Matrix(); //����������

	int GetSize() { return _size; } //������� ������
	float** GetMatrix() { return _matr; } //������� ��������

	void Resize(int size); //��������� �������
	void FillEmpty(); //��������� ������ ������ ������
	void Clear(); //�������� ���������
	void Generate(int size); //��������� ��������
	void Generate();

	void Invers(); //�������� �������

	void Addition(const Matrix& a, const Matrix& b); //��������
	void Difference(const Matrix& a, const Matrix& b); //���������
	void Multiplication(const Matrix& a, const Matrix& b); //���������
	void Division(const Matrix& a, const Matrix& b); //�������
	void Transpose(Matrix& a); //����������������

	//�������

	/*void ConsolePrint();
	void ConsoleInput();
	void Load(std::string fname);*/
};

