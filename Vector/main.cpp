#include "Vector.h"
#include "Matrix.h"
#include "Exception.h"
#include <iostream>

using namespace std;

void TestVector() {
	Vector<int> a, b(3), c(4);

	cout << "�������� 3 ��������: " << endl;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	cout << "������� ������ b(3) :" << endl;
	cin >> b;
	cout << "������� ������ c(4) :" << endl;
	cin >> c;

	cout << "������ b ��:" << endl << b << endl;
	b++;
	cout << "������ b++ :" << endl;
	cout << b << endl << endl;

	cout << "������ b ��:" << endl << b << endl;
	++b;
	cout << "������ ++b :" << endl;
	cout << b << endl << endl;

	cout << "������ b ��:" << endl << b << endl;
	b.ReSize(4);
	cout << "������ b.ReSize(4) :" << endl;
	cout << b << endl << endl;

	cout << "������ a ��:" << endl << a << endl;
	cout << "������ b ��:" << endl << b << endl;
	cout << "������ c ��:" << endl << c << endl;
	a = b + c;
	cout << "������ a = b + c :" << endl;
	cout << a << endl << endl;

	cout << "������ b ��:" << endl << b << endl;
	cout << "������ c ��:" << endl << c << endl;
	a = b - c;
	cout << "������ a = b - c :" << endl;
	cout << a << endl << endl;

	cout << "������ b ��:" << endl << b << endl;
	cout << "������ c ��:" << endl << c << endl;
	a = b * c;
	cout << "������ a = b * c :" << endl;
	cout << a << endl << endl;

	cout << "������ a ��:" << endl << a << endl;
	cout << "����� a[2]: ";
	cout << a[2] << endl;

	cout << "������ a ��:" << endl << a << endl;
	a[2] = 8;
	cout << "����� a[2], ����� : a[2] = 8" << endl;
	cout << a[2] << endl;

	cout << "������ b ��:" << endl << b << endl;
	a = b + 5;
	cout << "������ a = b + 5 :" << endl;
	cout << a << endl;
}

void TestMatrix() {
	Matrix<int> A(2), B(2), C;
	cout << "������� ������� A(2):" << endl;
	cin >> A;
	cout << A;
	cout << "������� ������� B(2):" << endl;
	cin >> B;
	cout << B;

	C = A + B;

	C = A + B;
	cout << "��������� C = A + B:" << endl;
	cout << C;

	C = A - B;
	cout << "��������� C = A - B:" << endl;
	cout << C;

	C = A * B;
	cout << "��������� C = A * B:" << endl;
	cout << C;

	C = A + 5;
	cout << "��������� C = A + 5:" << endl;
	cout << C;

	C = A - 3;
	cout << "��������� C = A - 3:" << endl;
	cout << C;

	cout << "������� A ��:" << endl;
	cout << A;
	cout << "������� B ��:" << endl;
	cout << B;
	A += B;
	cout << "��������� A += B:" << endl;
	cout << A;

	cout << "������� A ��:" << endl;
	cout << A;
	cout << "������� B ��:" << endl;
	cout << B;
	A -= B;
	cout << "��������� A -= B:" << endl;
	cout << A;

}

void TestExceptionMatrix() {
	Matrix<int> A(2), B(1), C;
	cout << "����������" << endl;
	cout << "������� ������� A(2):" << endl;
	cin >> A;
	cout << A;
	cout << "������� ������� B(1):" << endl;
	cin >> B;
	cout << B;

	try {
		C = A + B;
		cout << C;
	}
	catch (const Exception& excep) {
		cout << endl << "�������� C = A + B" << endl;
		excep.Print();
	}

	try {
		A -= B;
		cout << A;
	}
	catch (const Exception& excep) {
		cout << "�������� A -= B" << endl;
		excep.Print();
	}

	try {
		cout << C[-5];
	}
	catch (const Exception& excep) {
		cout << "�������� C[-5]" << endl;
		excep.Print();
	}

	try {
		cout << C[1000];
	}
	catch (const Exception& excep) {
		cout << "�������� C[1000]" << endl;
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

	cout << "������� ������ A(3) :" << endl;
	cin >> A;
	cout << "������� ������ B(2) :" << endl;
	cin >> B;

	try {
		Vector<int> D(-2);
	}
	catch (const Exception& excep) {
		cout << endl << "�������� Vector<int> D(-2)" << endl;
		excep.Print();
	}

	try {
		A[-2];
	}
	catch (const Exception& excep) {
		cout << "�������� A[-2]" << endl;
		excep.Print();
	}

	try {
		C = A + B;
	}
	catch (const Exception& excep) {
		cout << "�������� C = A + B" << endl;
		excep.Print();
	}

	try {
		A -= B;
	}
	catch (const Exception& excep) {
		cout << "�������� A -= B" << endl;
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
	cout << "������ A(3): ";
	cin >> A;

	Matrix<int> M(3);
	cout << "������� M(3): ";
	cin >> M;

	cout << "��������� ������� M(3) �� ������ A(3): ";
	C = M * A;
	cout << C;
}