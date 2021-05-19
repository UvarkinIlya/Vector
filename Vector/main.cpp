#include "Vector.h"
#include "Matrix.h"
#include "Exception.h"
#include <iostream>

using namespace std;

void TestVector() {
	Vector<int> a, b(3), c(4);

	cout << "Создание 3 векторов: " << endl;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	cout << "Введите вектор b(3) :" << endl;
	cin >> b;
	cout << "Введите вектор c(4) :" << endl;
	cin >> c;

	cout << "Вектор b до:" << endl << b << endl;
	b++;
	cout << "Вектор b++ :" << endl;
	cout << b << endl << endl;

	cout << "Вектор b до:" << endl << b << endl;
	++b;
	cout << "Вектор ++b :" << endl;
	cout << b << endl << endl;

	cout << "Вектор b до:" << endl << b << endl;
	b.ReSize(4);
	cout << "Вектор b.ReSize(4) :" << endl;
	cout << b << endl << endl;

	cout << "Вектор a до:" << endl << a << endl;
	cout << "Вектор b до:" << endl << b << endl;
	cout << "Вектор c до:" << endl << c << endl;
	a = b + c;
	cout << "Вектор a = b + c :" << endl;
	cout << a << endl << endl;

	cout << "Вектор b до:" << endl << b << endl;
	cout << "Вектор c до:" << endl << c << endl;
	a = b - c;
	cout << "Вектор a = b - c :" << endl;
	cout << a << endl << endl;

	cout << "Вектор b до:" << endl << b << endl;
	cout << "Вектор c до:" << endl << c << endl;
	a = b * c;
	cout << "Вектор a = b * c :" << endl;
	cout << a << endl << endl;

	cout << "Вектор a до:" << endl << a << endl;
	cout << "Вывод a[2]: ";
	cout << a[2] << endl;

	cout << "Вектор a до:" << endl << a << endl;
	a[2] = 8;
	cout << "Вывод a[2], после : a[2] = 8" << endl;
	cout << a[2] << endl;

	cout << "Вектор b до:" << endl << b << endl;
	a = b + 5;
	cout << "Вектор a = b + 5 :" << endl;
	cout << a << endl;
}

void TestMatrix() {
	Matrix<int> A(2), B(2), C;
	cout << "Введите матрицу A(2):" << endl;
	cin >> A;
	cout << A;
	cout << "Введите матрицу B(2):" << endl;
	cin >> B;
	cout << B;

	C = A + B;

	C = A + B;
	cout << "Результат C = A + B:" << endl;
	cout << C;

	C = A - B;
	cout << "Результат C = A - B:" << endl;
	cout << C;

	C = A * B;
	cout << "Результат C = A * B:" << endl;
	cout << C;

	C = A + 5;
	cout << "Результат C = A + 5:" << endl;
	cout << C;

	C = A - 3;
	cout << "Результат C = A - 3:" << endl;
	cout << C;

	cout << "Матрица A до:" << endl;
	cout << A;
	cout << "Матрица B до:" << endl;
	cout << B;
	A += B;
	cout << "Результат A += B:" << endl;
	cout << A;

	cout << "Матрица A до:" << endl;
	cout << A;
	cout << "Матрица B до:" << endl;
	cout << B;
	A -= B;
	cout << "Результат A -= B:" << endl;
	cout << A;

}

void TestExceptionMatrix() {
	Matrix<int> A(2), B(1), C;
	cout << "Исключения" << endl;
	cout << "Введите матрицу A(2):" << endl;
	cin >> A;
	cout << A;
	cout << "Введите матрицу B(1):" << endl;
	cin >> B;
	cout << B;

	try {
		C = A + B;
		cout << C;
	}
	catch (const Exception& excep) {
		cout << endl << "Операция C = A + B" << endl;
		excep.Print();
	}

	try {
		A -= B;
		cout << A;
	}
	catch (const Exception& excep) {
		cout << "Операция A -= B" << endl;
		excep.Print();
	}

	try {
		cout << C[-5];
	}
	catch (const Exception& excep) {
		cout << "Операция C[-5]" << endl;
		excep.Print();
	}

	try {
		cout << C[1000];
	}
	catch (const Exception& excep) {
		cout << "Операция C[1000]" << endl;
		excep.Print();
	}

	try {
		Matrix<int> D(-2);
	}
	catch (const Exception& excep) {
		cout << "Matrix<int> D(-2)" << endl;
		excep.Print();
	}
}

void TestExceptionVector() {
	Vector<int> A(3), B(2), C;

	cout << "Введите вектор A(3) :" << endl;
	cin >> A;
	cout << "Введите вектор B(2) :" << endl;
	cin >> B;

	try {
		Vector<int> D(-2);
	}
	catch (const Exception& excep) {
		cout << endl << "Операция Vector<int> D(-2)" << endl;
		excep.Print();
	}

	try {
		A[-2];
	}
	catch (const Exception& excep) {
		cout << "Операция A[-2]" << endl;
		excep.Print();
	}

	try {
		C = A + B;
	}
	catch (const Exception& excep) {
		cout << "Операция C = A + B" << endl;
		excep.Print();
	}

	try {
		A -= B;
	}
	catch (const Exception& excep) {
		cout << "Операция A -= B" << endl;
		excep.Print();
	}

	try {
		A.ReSize(0);
	}
	catch (const Exception& excep) {
		cout << "A.ReSize(0)" << endl;
		excep.Print();
	}
}

void main() {
	setlocale(LC_ALL, "Russian");

	TestVector();
	TestMatrix();
	TestExceptionMatrix();
	TestExceptionVector();

	Vector<int> A(3), C;
	cout << "Вектор A(3): ";
	cin >> A;

	Matrix<int> M(3);
	cout << "Матрица M(3): ";
	cin >> M;

	cout << "Умножение матрицы M(3) на вектор A(3): ";
	C = M * A;
	cout << C;
}