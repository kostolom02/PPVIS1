#pragma once
#ifndef _MATRIX_
#define _MATRIX_

#include <vector>
#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

/**
 * \file
 * \brief Matrix
 * In mathematics, a matrix is a rectangular array or table of numbers, symbols, or expressions, arranged in rows and columns.
 *
 */


class Matrix
{
public:
	Matrix();

	/// \brief sizeX - Matrix rows, sizeY - Matrix cols
	Matrix(const int& sizeX, const int& sizeY);

	///\brief Constructor to initialize a matrix
	Matrix(const Matrix& other);

	///\brief Constructor that creates a matrix based on a vector
	///\param other - vector
	Matrix(const vector<vector<double>>& other);

	///\brief Matrix comparison operator
	///\param other - matrix
	bool operator==(const Matrix& other) const;

	///\brief Matrix comparison operator
	///\param other - matrix
	bool operator!=(const Matrix& other) const;

	///\brief Matrix assignment operator
	///\param other - matrix
	Matrix& operator=(const Matrix& other);

	///\brief Addition operator of a matrix and a number
	///\param other - number
	Matrix operator+(const double& other) const;

	///\brief Addition operator with matrix and number assignment
	///\param other - number
	Matrix& operator+=(const double& other);

	///\brief Operator for adding two matrices
	///\param other - matrix
	Matrix operator+(const Matrix& other) const;

	///\brief Addition operator with assignment of two matrices
	///\param other - matrix
	Matrix& operator+=(const Matrix& other);

	///\brief Difference operator of a matrix and a number
	///\param other - number
	Matrix operator-(const double& other) const;

	///\brief The operator of the difference between the assignment matrix and the number
	///\param other - number
	Matrix& operator-=(const double& other);

	///\brief Difference operator of two matrices
	///\param other - matrix
	Matrix operator-(const Matrix& other) const;

	///\brief The difference operator of two matrices with assignment
	///\param other - matrix
	Matrix& operator-=(const Matrix& other);

	///\brief Matrix multiplication operator with a number
	///\param other - number
	Matrix operator*(const double& other) const;

	///\brief Matrix and number multiplication operator with assignment
	///\param other - number
	Matrix& operator*=(const double& other);

	///\brief Multiplication operator for two matrices
	///\param other - matrix
	Matrix operator*(const Matrix& other) const;

	///\brief Operator for dividing a matrix by a number
	///\param other - number
	Matrix operator/(const double& other) const;

	///\brief Operator for dividing a matrix by a number with assignment
	///\param other - number
	Matrix& operator/=(const double& other);

	///\brief The operator matrix of degree
	///\param other - number
	Matrix operator^(const int& other) const;

	///\brief Matrix exponentiation operator with assignment
	///\param other - number
	Matrix& operator^=(const int& other);

	///\brief Calculation of the matrix determinant
	///\return If method squareMatrixCheck() is true - return determinant \n else - return 0
	double getDeterminantOfMatrix();

	///\brief Calling the normOne() method for a matrix
	double getNormOneOfMatrix() const;

	///\brief Calling the normTwo() method for a matrix
	double getNormTwoOfMatrix() const;

	///\brief Calling the normThree() method for a matrix
	double getNormThreeOfMatrix() const;

	///\brief Checking the matrix for compatibility
	///\return if the matrices are compatible - returns true \n else - returns false
	bool matrixCompatibilityCheck(const Matrix& other) const;

	///\brief Checking the possibility of matrix multiplication
	///\return if the number of columns in the first matrix is equal to the number of rows in the second matrix - returns true
	/// \n else - returns false
	bool matrixMultiplicationCheck(const Matrix& other) const;

	///\brief Checks the matrix for squaring
	///\return if the matrix is square - returns true \n else - returns false
	bool squareMatrixCheck() const;

	///\brief Output operator
	///\return returns stream
	friend ostream& operator<<(ostream& os, const Matrix& matrix);

	///\brief Input operator
	///\return returns stream
	friend istream& operator>>(istream& stream, Matrix& matrix);

	double& operator()(const int& X, const int& Y);

private:
	///\brief A two-dimensional vector that stores the values of the matrix
	vector<vector<double>> arr;

	///\brief Calculating the minor of a matrix
	///\return matrix - matrix
	Matrix minor(Matrix matrix, const int& i, const int& j);

	///\brief Calculating the determinant of a matrix
	///\return matrix - matrix
	double determinant(const Matrix& matrix);

	///\brief Finding the first norm of the matrix
	double normOne() const;

	///\brief Finding the second norm of the matrix
	double normTwo() const;

	///\brief Finding the third norm of the matrix
	double normThree() const;

};

#endif _MATRIX_