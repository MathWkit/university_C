#include "matrix.h"

#include <iostream>

Matrix::Matrix(size_t width, size_t height) :
	width(width), height(height)
{
	matrix = new int[width * height];

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			matrix[i * height + j] = 0;
		}
	}
}

void Matrix::set_value(int i, int j, int value)
{
	if (i < height && j < width) {
		matrix[i * height + j] = value;
	}
	else {
		std::cout << "ERROR";
	}
}

void Matrix::output() const
{
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			std::cout << matrix[i * height + j] << " ";
		}
		std::cout << std::endl;
	}
}

Matrix::~Matrix()
{
	delete[] matrix;
}