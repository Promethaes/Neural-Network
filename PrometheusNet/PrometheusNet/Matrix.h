#pragma once
#include <vector>
#define yes true
#define no false
class Matrix {
public:
	Matrix(unsigned ROWS, unsigned COLUMNS, bool isRandom = true);

	Matrix transpose();

	float genRandomNumber();
	void print();
	void setValue(unsigned row, unsigned columnm, float v);
	float getValue(unsigned row, unsigned column) const { return values[row][column]; }

	//0 for rows, 1 for columns
	unsigned getRowsorColumns(bool COLUMNS) { return COLUMNS ? columns : rows; }

	//M E T R O I D
	Matrix* operator*(const Matrix& otherM);

	//MULTIPLICATION FOR NON POINTERS (i know it sucks)
	Matrix operator*=(const Matrix& otherM);

	unsigned rows;
	unsigned columns;
private:
	std::vector<std::vector<float>>values;
};