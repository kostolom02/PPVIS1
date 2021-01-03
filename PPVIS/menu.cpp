#include "matrix.h"
#include <cstdlib>
#include <iostream>

int main()
{
	system("chcp 1251>null");
	bool exit = false;
	int func;
	double x;
	int X;
	Matrix A;
	Matrix B;
	Matrix C;
	while (!exit)
	{
		cout << "\n\n\t===  1 - �������� ������� A                ===\n";
		cout << "\t===  2 - �������� ������� �                ===\n";
		cout << "\t===  3 - �������� ������� B                ===\n";
		cout << "\t===  4 - �������� ������� �                ===\n";
		cout << "\t===  5 - C������ ������� A � B             ===\n";
		cout << "\t===  6 - ������� ������� � � ������        ===\n";
		cout << "\t===  7 - ������� ������� � � ������        ===\n";
		cout << "\t===  8 - ������� �� ������� � ������� �    ===\n";
		cout << "\t===  9 - ������� �� ������� � ������� �    ===\n";
		cout << "\t=== 10 - ������� �� ������� � �����        ===\n";
		cout << "\t=== 11 - ������� �� ������� � �����        ===\n";
		cout << "\t=== 12 - ������������ ������� � � ������� � ===\n";
		cout << "\t=== 13 - ������������ ������� � �� �����   ===\n";
		cout << "\t=== 14 - ������������ ������� � �� �����   ===\n";
		cout << "\t=== 15 - ������� ������� � �� �����        ===\n";
		cout << "\t=== 16 - ������� ������� � �� �����        ===\n";
		cout << "\t=== 17 - ���������� ������� � � �������    ===\n";
		cout << "\t=== 18 - ���������� ������� � � �������    ===\n";
		cout << "\t=== 19 - ��������� ����������� ������� �   ===\n";
		cout << "\t=== 20 - ��������� ����������� ������� �   ===\n";
		cout << "\t=== 21 - ��������� ����� ������� �         ===\n";
		cout << "\t=== 22 - ��������� ����� ������� �         ===\n";
		cout << "\t===  0 - �����                             ===\n";
		cout << "\t=== 99 - ������� ������                    ===\n";
		cout << "\n\t�������� �������� - ";
		cin >> func;
		cout << endl;
		switch (func)
		{
		case 0:
			exit = true;
			break;
		case 99:
			system("cls");
			break;
		case 1:
			cout << "������� ������, � ����� ������� �:\n";
			cin >> A;
			break;
		case 2:
			cout << "������� �:\n";
			cout << A;
			break;
		case 3:
			cout << "������� ������, � ����� ������� B\n";
			cin >> B;
			break;
		case 4:
			cout << "������� B:\n";
			cout << B;
			break;
		case 5:
			if (A.matrixCompatibilityCheck(B))
			{
				cout << "��������� ����� ������� � � ������� �:\n";
				cout << A + B;
			}
			else
			{
				cout << "������� � � � ������ �������\n";
			}
			break;
		case 6:
			cout << "������� ����� ������� ���������� ��������� � ������� �:\n";
			cin >> x;
			cout << "��������� �������� ������� � � ����� " << x << endl;
			cout << A + x;
			break;
		case 7:
			cout << "������� ����� ������� ���������� ��������� � ������� B:\n";
			cin >> x;
			cout << "��������� �������� ������� B � ����� " << x << endl;
			cout << B + x;
			break;
		case 8:
			if (A.matrixCompatibilityCheck(B))
			{
				cout << "��������� �������� ������� � � ������� �:\n";
				cout << A - B;
			}
			else
			{
				cout << "�� ������� � ������ ������ ������� �\n";
			}
			break;
		case 9:
			if (B.matrixCompatibilityCheck(A))
			{
				cout << "��������� �������� ������� B � ������� A:\n";
				cout << B - A;
			}
			else
			{
				cout << "�� ������� B ������ ������ ������� A\n";
			}
			break;
		case 10:
			cout << "������� ����� ������� ���������� ������ �� ������� �:\n";
			cin >> x;
			cout << "��������� �������� ������� � � ����� " << x << endl;
			cout << A - x;
			break;
		case 11:
			cout << "������� ����� ������� ���������� ������ �� ������� B:\n";
			cin >> x;
			cout << "��������� �������� ������� B � ����� " << x << endl;
			cout << B - x;
			break;
		case 12:
			if (A.matrixMultiplicationCheck(B))
			{
				cout << "������������ ������� � � �:\n";
				cout << A * B;
			}
			else
			{
				cout << "������� � � � ������ �����������\n";
			}
			break;
		case 13:
			cout << "������� ����� ������� �� ������� ���������� �������� ������� �:\n";
			cin >> x;
			cout << "��������� ������������ ������� � � ����� " << x << endl;
			cout << A * x;
			break;
		case 14:
			cout << "������� ����� �� ������� ���������� �������� ������� B:\n";
			cin >> x;
			cout << "��������� ��������� ������� B � ����� " << x << endl;
			cout << B * x;
			break;
		case 15:
			x = 0;
			while (x == 0)
			{
				cout << "������� ����� �� ������� ���������� ��������� ������� � (����� 0):\n";
				cin >> x;
			}
			cout << "��������� ������� ������� � �� ����� " << x << endl;
			cout << A / x;
			break;
		case 16:
			x = 0;
			while (x == 0)
			{
				cout << "������� ����� �� ������� ���������� ��������� ������� B (����� 0):\n";
				cin >> x;
			}
			cout << "��������� ������� ������� � �� ����� " << x << endl;
			cout << B / x;
			break;
		case 17:
			X = 0;
			while (X == 0)
			{
				cout << "������� ������� � ������� ����� ��������� ������� A:\n";
				cin >> X;
			}
			if (A.squareMatrixCheck())
			{
				cout << "������� A ����������� � ������� " << X << endl;
				C = A ^ X;
				cout << C;
			}
			else
			{
				cout << "������� A ����� �� ���������� ���\n";
			}
			break;
		case 18:
			X = 0;
			while (X == 0)
			{
				cout << "������� ������� � ������� ����� ��������� ������� B:\n";
				cin >> X;
			}
			if (B.squareMatrixCheck())
			{
				cout << "������� B ����������� � ������� " << X << endl;
				C = B ^ X;
				cout << C;
			}
			else
			{
				cout << "������� B ����� �� ���������� ���\n";
			}
			break;
		case 19:
			if (A.squareMatrixCheck())
			{
				cout << "����������� ������� �:\n";
				cout << A.getDeterminantOfMatrix();
			}
			else
			{
				cout << "������� ����� �� ���������� ���\n";
			}
			break;
		case 20:
			if (B.squareMatrixCheck())
			{
				cout << "����������� ������� B:\n";
				cout << B.getDeterminantOfMatrix();
			}
			else
			{
				cout << "������� ����� �� ���������� ���\n";
			}
			break;
		case 21:
			cout << "����� ������� �:\n";
			cout << "A1: " << A.getNormOneOfMatrix() << "\tA2: " << A.getNormTwoOfMatrix() << "\tA3: " << A.getNormThreeOfMatrix() << endl;
			break;
		case 22:
			cout << "����� ������� B:\n";
			cout << "B1: " << B.getNormOneOfMatrix() << "\tB2: " << B.getNormTwoOfMatrix() << "\tB3: " << A.getNormThreeOfMatrix() << endl;
			break;
		}
	}
}