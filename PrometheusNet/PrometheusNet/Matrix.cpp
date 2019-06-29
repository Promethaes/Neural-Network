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

Matrix  Matrix::transpose()
{
	auto m = Matrix(columns, rows, no);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++)
			m.setValue(j, i,getValue(i,j));
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

Matrix * Matrix::operator*(const Matrix & otherM)
{
	if (columns != otherM.rows)
		exit(0);

	Matrix* tempMatrix =  new Matrix(this->rows, otherM.columns, false);

	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < otherM.columns; j++) {
			for (int k = 0; k < otherM.rows; k++) {
				float p = this->getValue(i, k) * otherM.getValue(k, j);
				float newVal = tempMatrix->getValue(i, j) + p;
				tempMatrix->setValue(i, j, newVal);
			}

			tempMatrix->setValue(i, j, tempMatrix->getValue(i, j));
		}
	}
	return tempMatrix;
}

Matrix Matrix::operator*=(const Matrix & otherM)
{
	if (columns != otherM.rows)
		exit(0);

	Matrix tempMatrix =  Matrix(this->rows, otherM.columns, false);

	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < otherM.columns; j++) {
			for (int k = 0; k < otherM.rows; k++) {
				float p = this->getValue(i, k) * otherM.getValue(k, j);
				float newVal = tempMatrix.getValue(i, j) + p;
				tempMatrix.setValue(i, j, newVal);
			}

			tempMatrix.setValue(i, j, tempMatrix.getValue(i, j));
		}
	}
	return tempMatrix;
}
