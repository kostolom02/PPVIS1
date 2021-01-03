#define CATCH_CONFIG_MAIN
#include "matrix.h"
#include "catch.hpp"
typedef vector<vector<double>> vec;

TEST_CASE()
{
	SECTION("addition_and_subtraction_matrix_with_matrix_test")
	{
		vec arr1 = { {1,5},{6,8} };
		vec arr2 = { {0,1},{3,9} };
		vec arr3 = { {1,6},{9,17} };
		vec arr4 = { {3},{5},{9},{4} };
		Matrix A(arr1);
		Matrix B(arr2);
		Matrix C(arr3);
		Matrix D(arr4);
		REQUIRE(A == A + D);
		REQUIRE(C == A + B);
		REQUIRE(C != A - B);
		REQUIRE(A == C - B);
		REQUIRE(B == C - A);
		REQUIRE(C == A + B - C + A + B);
		C -= A;
		REQUIRE(C == B);
		C += A;
		REQUIRE(C == A + B);
		C -= B;
		REQUIRE(C == A);
	}
	SECTION("addition_and_subtraction_numbers_with_matrix_test")
	{
		vec arr1 = { {1,5,0},{3,9,1} };
		vec arr2 = { {11,15,10},{13,19,11} };
		Matrix A(arr1);
		Matrix B(arr2);
		REQUIRE(B == A + 10);
		REQUIRE(A == B - 10);
		A += 10;
		REQUIRE(A == B);
		B -= 10;
		REQUIRE(A == B + 10);
		A = B;
		REQUIRE(A == B);
		A -= 10;
		REQUIRE(B - A != A + 10 - B);
	}
	SECTION("multiplication_matrix_with_matrix_test")
	{
		vec arr1 = { {3,9},{0,0},{3,-8},{45,-9},{3,-3} };
		vec arr2 = { {1,3},{-9,-10} };
		vec arr3 = { {-78,-81},{0,0},{75,89},{126,225},{30,39} };
		Matrix A(arr1);
		Matrix B(arr2);
		Matrix C(arr3);
		Matrix D;
		REQUIRE(C == A * B);
		D = C * B;
		REQUIRE(D == A * B * B);
		REQUIRE(A != B * A);
	}
	SECTION("multiplication_and_division_matrix_with_numbers_test")
	{
		vec arr1 = { {3,9},{0,0},{3,-8} };
		vec arr2 = { {9,27},{0,0},{9,-24} };
		Matrix A(arr1);
		Matrix B(arr2);
		REQUIRE(B == A * 3);
		REQUIRE(A == B / 3);
		REQUIRE(A * 4 == ((B * 3) / 9) * 4);
		B /= 3;
		REQUIRE(A == B);
		A *= 3;
		REQUIRE(A == B * 3);
		REQUIRE(B == A / 3);
	}
	SECTION("exponentiation_of_matrix_test")
	{
		vec arr1 = { {3,9,5},{0,0,-3},{3,-8,12} };
		vec arr2 = { {216,-168,735},{-135,207,-549},{684,-1059,2628} };
		Matrix A(arr1);
		Matrix B(arr2);
		Matrix C = A ^ 3;
		REQUIRE(B == C);
		B ^= 2;
		C = A ^ 6;
		REQUIRE(B == C);
		C = A;
		A ^= -4;
		REQUIRE(C == A);
	}
	SECTION("determinant_of_matrix_test")
	{
		vec arr1 = { {4,6,7,9,2},{-9,-4,45,0,0},{3,3,12,23,-60},{0,1,1,76,-5},{-4,-6,-8,-10,0} };
		vec arr2 = { {3,5},{-7,0},{3,5} };
		double arr1_rez = -82734;
		double arr2_rez = 0;
		Matrix A(arr1);
		Matrix B(arr2);
		REQUIRE(arr1_rez == A.getDeterminantOfMatrix());
		REQUIRE(arr2_rez == B.getDeterminantOfMatrix());
	}
	SECTION("norm_of_matrix_test")
	{
		vec arr1 = { {1,-2,3},{4,5,-6},{-7,8,9} };
		vec arr2 = { {1,0,0},{0,1,0},{0,0,1} };
		double arr1_rez_1 = 24;
		double arr1_rez_2 = 18;
		double arr1_rez_3 = sqrt(285);
		double arr2_rez_1 = 1;
		double arr2_rez_2 = 1;
		double arr2_rez_3 = sqrt(3);
		Matrix A(arr1);
		Matrix B(arr2);
		REQUIRE(arr1_rez_1 == A.getNormOneOfMatrix());
		REQUIRE(arr1_rez_2 == A.getNormTwoOfMatrix());
		REQUIRE(arr1_rez_3 == A.getNormThreeOfMatrix());
		REQUIRE(arr2_rez_1 == B.getNormOneOfMatrix());
		REQUIRE(arr2_rez_2 == B.getNormTwoOfMatrix());
		REQUIRE(arr2_rez_3 == B.getNormThreeOfMatrix());
	}
}