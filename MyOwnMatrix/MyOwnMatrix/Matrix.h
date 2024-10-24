#pragma once

class Matrix
{
public:
	Matrix(size_t width, size_t height);

	void output() const;

	void set_value(int i, int j, int value);

	~Matrix();

private:
	int* matrix;
	int width;
	int height;
};
