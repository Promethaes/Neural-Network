#include "Matrix.h"
#include <random>
#include <iostream>
Matrix::Matrix(unsigned ROWS, unsigned COLUMNS, bool isRandom)
{
	rows = ROWS;
	columns = COLUMNS;
	for (int i = 0; i < rows; i++) {
		std::vector<float> columnValues;

		for (int j = 0; j < columns; j++) {
			float r = 0.00f;
			if (isRandom)
				r = genRandomNumber();
			columnValues.push_back(r);
		}
		values.push_back(columnValues);
	}
}

Matrix * Matrix::transpose()
{
	Matrix *m = new Matrix(columns, rows, no);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++)
			m->setValue(j, i,getValue(i,j));
		std::cout << "\n";
	}

	return m;
}

float Matrix::genRandomNumber()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0, 1);
	return dis(gen);
}

void Matrix::print()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++)
			std::cout << values[i][j] << "\t";
		std::cout << "\n";
	}
}

void Matrix::setValue(unsigned row, unsigned columnm, float v)
{
	values[row][columnm] = v;
}
