#include "matrix.h"

Matrix::Matrix() {}

Matrix::Matrix(const int& sizeX, const int& sizeY)
{
	arr.resize(sizeX);
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i].resize(sizeY);
		for (int k = 0; k < arr[i].size(); k++)
		{
			arr[i][k] = 0;
		}
	}
}

Matrix::Matrix(const Matrix& other)
{
	arr.resize(other.arr.size());
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i].resize(other.arr[i].size());
		for (int k = 0; k < arr[i].size(); k++)
		{
			arr[i][k] = other.arr[i][k];
		}
	}
}

Matrix::Matrix(const vector<vector<double>>& other)
{
	arr.resize(other.size());
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i].resize(other[i].size());
		for (int k = 0; k < arr[i].size(); k++)
		{
			arr[i][k] = other[i][k];
		}
	}
}

bool Matrix::operator==(const Matrix& other) const
{
	try
	{
		if (!matrixCompatibilityCheck(other)) { throw "Ошибка;  данные введены неверно!"; }
		for (int i = 0; i < this->arr.size(); i++)
		{
			for (int k = 0; k < this->arr[i].size(); k++)
			{
				if (this->arr[i][k] != other.arr[i][k])
				{
					return false;
				}
			}
		}
		return true;
	}
	catch (const char* error)
	{
		cout << error << endl;
		return false;
	}
}

bool Matrix::operator!=(const Matrix& other) const
{
	return !(*this == other);
}

Matrix& Matrix::operator=(const Matrix& other)
{
	arr.clear();
	arr.resize(other.arr.size());
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i].resize(other.arr[i].size());
		for (int k = 0; k < arr[i].size(); k++)
		{
			arr[i][k] = other.arr[i][k];
		}
	}
	return *this;
}

Matrix Matrix::operator+(const double& other) const
{
	Matrix temp(this->arr.size(), this->arr[arr.size() - 1].size());
	for (int i = 0; i < temp.arr.size(); i++)
	{
		for (int k = 0; k < temp.arr[i].size(); k++)
		{
			temp.arr[i][k] = this->arr[i][k] + other;
		}
	}
	return temp;
}

Matrix& Matrix::operator+=(const double& other)
{
	return *this = *this + other;
}

Matrix Matrix::operator+(const Matrix& other) const
{
	try
	{
		if (!matrixCompatibilityCheck(other)) { throw "Ошибка;  данные введены неверно!"; }
		Matrix temp(this->arr.size(), this->arr[this->arr.size() - 1].size());
		for (int i = 0; i < temp.arr.size(); i++)
		{
			for (int k = 0; k < temp.arr[i].size(); k++)
			{
				temp.arr[i][k] = this->arr[i][k] + other.arr[i][k];
			}
		}
		return temp;
	}
	catch (const char* error)
	{
		cout << error << endl;
		return *this;
	}
}

Matrix& Matrix::operator+=(const Matrix& other)
{
	return *this = *this + other;
}

Matrix Matrix::operator-(const double& other) const
{
	Matrix temp(this->arr.size(), this->arr[this->arr.size() - 1].size());
	for (int i = 0; i < temp.arr.size(); i++)
	{
		for (int k = 0; k < temp.arr[i].size(); k++)
		{
			temp.arr[i][k] = this->arr[i][k] - other;
		}
	}
	return temp;
}

Matrix& Matrix::operator-=(const double& other)
{
	return *this = *this - other;
}

Matrix Matrix::operator-(const Matrix& other) const
{
	try
	{
		if (!matrixCompatibilityCheck(other)) { throw "Ошибка;  данные введены неверно!"; }
		Matrix temp(this->arr.size(), this->arr[this->arr.size() - 1].size());
		for (int i = 0; i < temp.arr.size(); i++)
		{
			for (int k = 0; k < temp.arr[i].size(); k++)
			{
				temp.arr[i][k] = this->arr[i][k] - other.arr[i][k];
			}
		}
		return temp;
	}
	catch (const char* error)
	{
		cout << error << endl;
		return *this;
	}
}

Matrix& Matrix::operator-=(const Matrix& other)
{
	return *this = *this - other;
}

Matrix Matrix::operator*(const double& other) const
{
	Matrix temp(this->arr.size(), this->arr[this->arr.size() - 1].size());
	for (int i = 0; i < temp.arr.size(); i++)
	{
		for (int k = 0; k < temp.arr[i].size(); k++)
		{
			temp.arr[i][k] = this->arr[i][k] * other;
		}
	}
	return temp;
}

Matrix& Matrix::operator*=(const double& other)
{
	return *this = *this * other;
}

Matrix Matrix::operator*(const Matrix& other) const
{
	try
	{
		if (!matrixMultiplicationCheck(other)) { throw "Ошибка;  данные введены неверно!"; }
		Matrix temp(this->arr.size(), other.arr[other.arr.size() - 1].size());
		for (int i = 0; i < temp.arr.size(); i++)
		{
			for (int k = 0; k < temp.arr[i].size(); k++)
			{
				for (int j = 0; j < other.arr.size(); j++)
				{
					temp.arr[i][k] = temp.arr[i][k] + (this->arr[i][j] * other.arr[j][k]);
				}
			}
		}
		return temp;
	}
	catch (const char* error)
	{
		cout << error << endl;
		return *this;
	}
}

Matrix Matrix::operator/(const double& other) const
{
	try
	{
		if (other == 0) { throw "Ошибка; на ноль делить нельзя"; }
		Matrix temp(this->arr.size(), this->arr[this->arr.size() - 1].size());
		for (int i = 0; i < temp.arr.size(); i++)
		{
			for (int k = 0; k < temp.arr[i].size(); k++)
			{
				temp.arr[i][k] = this->arr[i][k] / other;
			}
		}
		return temp;
	}
	catch (const char* error)
	{
		cout << error << endl;
		return *this;
	}
}

Matrix& Matrix::operator/=(const double& other)
{
	return *this = *this / other;
}

Matrix Matrix::operator^(const int& other) const
{
	try
	{
		if (!squareMatrixCheck() && other < 2) { throw "Ошибка; данные введены неверно!"; }
		Matrix temp(*this);
		for (int i = 1; i < other; i++)
		{
			temp = temp * *this;
		}
		return temp;
	}
	catch (const char* error)
	{
		cout << error << endl;
		return *this;
	}
}

Matrix& Matrix::operator^=(const int& other)
{
	return *this = *this ^ other;
}

double Matrix::getDeterminantOfMatrix()
{
	try
	{
		if (!squareMatrixCheck()) { throw "Ошибка; был возвращен 0"; }
		return determinant(*this);
	}
	catch (const char* error)
	{
		cout << error << endl;
		return 0;
	}
}

double Matrix::getNormOneOfMatrix() const
{
	return (this->normOne());
}

double Matrix::getNormTwoOfMatrix() const
{
	return (this->normTwo());
}

double Matrix::getNormThreeOfMatrix() const
{
	return (this->normThree());
}

bool Matrix::matrixCompatibilityCheck(const Matrix& other) const
{
	if (this->arr.size() == other.arr.size() && this->arr[this->arr.size() - 1].size() == other.arr[other.arr.size() - 1].size()) { return true; }
	return false;
}

bool Matrix::matrixMultiplicationCheck(const Matrix& other) const
{
	if (this->arr[this->arr.size() - 1].size() == other.arr.size()) { return true; }
	return false;
}

bool Matrix::squareMatrixCheck() const
{
	if (this->arr.size() == this->arr[this->arr.size() - 1].size() && this->arr.size() > 1) { return true; }
	return false;
}

Matrix Matrix::minor(Matrix matrix, const int& i, const int& j)
{
	matrix.arr.erase(matrix.arr.begin() + i);
	for (int z = 0; z < matrix.arr.size(); z++)
	{
		matrix.arr[z].erase(matrix.arr[z].begin() + j);
	}
	return matrix;
}

double Matrix::determinant(const Matrix& matrix)
{
	if (matrix.arr[0].size() == 1) { return matrix.arr[0][0]; }
	int  signum = 1;
	int  summ = 0;
	int  j = 0;
	for (int i = 0; i < matrix.arr[0].size(); i++)
	{
		summ += matrix.arr[0][i] * signum * determinant(minor(matrix, 0, j));
		signum *= -1;
		j++;
	}
	return summ;
}

double Matrix::normOne() const
{
	double max = 0, num = 0;
	for (int i = 0; i < this->arr.size(); i++, num = 0)
	{
		for (int k = 0; k < this->arr[i].size(); k++)
		{
			num += abs(this->arr[i][k]);
		}
		if (num > max) { max = num; }
	}
	return max;
}

double Matrix::normTwo() const
{
	double max = 0, num = 0;
	for (int i = 0; i < this->arr[this->arr.size() - 1].size(); i++, num = 0)
	{
		for (int k = 0; k < this->arr.size(); k++)
		{
			num += abs(this->arr[k][i]);
		}
		if (num > max) { max = num; }
	}
	return max;
}

double Matrix::normThree() const
{
	double temp = 0;
	for (int i = 0; i < this->arr.size(); i++)
	{
		for (int k = 0; k < this->arr[i].size(); k++)
		{
			temp += this->arr[i][k] * this->arr[i][k];
		}
	}
	return sqrt(temp);
}



ostream& operator<<(ostream& stream, const Matrix& matrix)
{
	for (int i = 0; i < matrix.arr.size(); i++)
	{
		for (int k = 0; k < matrix.arr[i].size(); k++)
		{
			stream << matrix.arr[i][k] << " ";
		}
		stream << endl;
	}
	return stream;
}

istream& operator>>(istream& stream, Matrix& matrix)
{
	int size;
	matrix.arr.clear();
	stream >> size;
	matrix.arr.resize(size);
	stream >> size;
	for (int i = 0; i < matrix.arr.size(); i++)
	{
		matrix.arr[i].resize(size);
		for (int k = 0; k < matrix.arr[i].size(); k++)
		{
			stream >> matrix.arr[i][k];
		}
	}
	return stream;
}

double& Matrix::operator()(const int& X, const int& Y)
{
	try
	{
		if (!(X > 0 && X <= arr.size() && Y > 0 && Y <= arr[arr.size() - 1].size())) { throw "Ошибка; был возвращен элемент [1][1]"; }
		return arr[X - 1][Y - 1];
	}
	catch (const char* error)
	{
		cout << error << endl;
		return arr[0][0];
	}
}