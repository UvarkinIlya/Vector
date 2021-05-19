#pragma once
#include <iostream>
#include <ostream>
#include "Exception.h"
//#include "Matrix.h"
const int size = 5;

using namespace std;

template <class T>
class Vector {
	T* vector;
	int size = -1;
	public:
		Vector(int n = 5, T a = 0);/*������� ������ ������� size � ��������� ������ ��������� a*/
		Vector(const Vector& _vector);/*����������� �����������, �������� ��� ���� �������(�� � ������ ������ �� ������)*/
		~Vector();/*����������, ����������� ������ �������*/
		
		T get(int index);
		void set(int index, T num);
		Vector<T> operator*(Vector<T> A);
		Vector<T> operator+(Vector<T> A);
		Vector<T> operator-(Vector<T> A);
		Vector<T>& operator=(const Vector<T>& A);
		Vector<T>& operator+=(const Vector<T>& A);
		Vector<T>& operator-=(const Vector<T>& A);
		Vector<T> operator++();
		Vector<T> operator++(int);//�����������
		Vector<T> operator+(T num);
		Vector<T> operator-(T num);
		T& operator[](int index);
		void ReSize(int new_size);
		T Scal(Vector<T> A);
		//friend Vector<T> operator*(Vector<T>, Matrix<T> A);
		
		//friend ostream& operator<<(ostream& out, const Vector<T>& C);
		//friend istream& operator>>(istream& in, const Vector<T>& C);
		friend Vector<T> operator+(T num, Vector<T> A);

		friend ostream& operator<<(ostream& out, const Vector<T>& C) {
			out << "(";
			for (int i = 0; i < C.size - 1; i++) {
				out << C.vector[i] << ", ";
			}

			out << C.vector[C.size - 1] << ")";

			return out;
		}

		friend istream& operator>>(istream& in, const Vector<T>& C) {
			for (int i = 0; i < C.size; i++) {
				in >> C.vector[i];
			}

			return in;
		}
};

using namespace std;

template <class T>
Vector<T>::Vector(int n, T a) {
	/*������� ������ ������� size � ��������� ������ ��������� a*/
	if (n <= 0) {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "������������� ������ ��� ������������");
	}

	size = n;
	vector = new T[n];
	for (int i = 0; i < n; i++) {
		vector[i] = a;
	}
}

template <class T>
Vector<T>::Vector(const Vector& _vector) {
	/*����������� �����������, �������� ��� ���� �������(�� � ������ ������ �� ������)*/
	size = _vector.size;
	vector = new T[size];

	for (int i = 0; i < size; i++) {
		vector[i] = _vector.vector[i];
	}
}

//�� ��������� ���������, � �� ���� �� ����������
template <class T>
Vector<T>::~Vector() {
	/*����������, ����������� ������ �������*/
	delete[] vector;
	size = -1;
}

template <class T>
Vector<T> Vector<T>::operator+(Vector A/*���������� ����������� �����������*/) {
	if (size != A.size) {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "�� ��������� ������");
	}
	Vector res(size);

	for (int i = 0; i < size; i++) {
		res.vector[i] = A.vector[i] + vector[i];
	}

	return res;//���������� ������������ �����������
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& A) {
	if (this == &A) {//&A - ������ ������
		return (*this);//���������� ������, ����� ����������� �� �����(������� �� ������)
	}

	if (size != A.size) {
		size = A.size;
		delete[] vector;
		vector = new T[size];
	}

	for (int i = 0; i < size; i++) {
		vector[i] = A.vector[i];
	}

	return (*this);//���������� ������, ����� ����������� �� �����(������� �� ������)
}

template <class T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& A) {
	if (size != A.size) {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "�� ��������� ������");
	}

	for (int i = 0; i < size; i++) {
		vector[i] += A.vector[i];
	}

	return(*this);
}

template <class T>
T Vector<T>::get(int index) {
	if (index <= 0 || index > size) {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "����� �� �������");
	}
	return vector[index];
}

template <class T>
void Vector<T>::set(int index, T num) {
	if (index <= 0 || index > size) {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "����� �� �������");
	}

	vector[index] = num;
}

template <class T>
T& Vector<T>::operator[](int index) {
	if (index >= 0 && index < size) {
		return vector[index];
	}
	else {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "����� �� �������");
	}
}

template <class T>
void Vector<T>::ReSize(int new_size){
	if (new_size <= 0) {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "���������� ������ <= 0");
	}
	T* arr;
	arr = new T[new_size];
	Vector outVector(new_size);

	int k = min(size, new_size);
	for (int i = 0; i < k; i++) {
		arr[i] = vector[i];
	}

	for (int i = size; i < new_size; i++) {
		arr[i] = 0;
	}

	size = new_size;
	vector = new T[size];
	for (int i = 0; i < size; i++) {
		vector[i] = arr[i];
	}
	delete[] arr;
}

template<class T>
T Vector<T>::Scal(Vector<T> A){
	T res = 0;

	for (int i = 0; i < size; i++) {
		res += vector[i] * A.vector[i];
	}

	return res;
}

/*template<class T>
Vector<T> Vector<T>::operator*(Matrix<T> A){
	Vector res(size);

	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum = 0;
		for (int j = 0; j < size; j++) {
			sum += matr[j][i] * A.vector[j];
		}
		res[i] = sum;
	}

	return res;
}*/

template <class T>
Vector<T> Vector<T>::operator++() {
	for (int i = 0; i < size; i++) {
		vector[i]++;
	}

	return (*this);
}

template <class T>
Vector<T> Vector<T>::operator++(int)
{
	Vector temp = Vector(*this);

	for (int i = 0; i < size; i++) {
		vector[i]++;
	}

	return temp;
}

/*template <class T>
Vector<T> operator*(Vector<T>, Matrix<T> A){
	Vector a(2);
	return a;
}*/

template <class T>
Vector<T> operator+(T num, Vector<T> A)
{
	for (int i = 0; i < A.size; i++) {
		A.vector[i] += num;
	}

	return A;
}

template <class T>
Vector<T> Vector<T>::operator-(Vector<T> A) {
	if (size != A.size) {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "�� ��������� �������");
	}

	Vector outVector(A.size);

	for (int i = 0; i < size; i++) {
		outVector[i] = vector[i] - A.vector[i];
	}

	return outVector;
}

template <class T>
Vector<T>& Vector<T>::operator-=(const Vector<T>& A) {
	if (size != A.size) {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "�� ��������� �������");
	}

	for (int i = 0; i < size; i++) {
		vector[i] -= A.vector[i];
	}

	return (*this);
}

template <class T>
Vector<T> Vector<T>::operator+(T num) {
	for (int i = 0; i < size; i++) {
		vector[i] += num;
	}

	return (*this);
}

template <class T>
Vector<T> Vector<T>::operator-(T num) {
	for (int i = 0; i < size; i++) {
		vector[i] -= num;
	}

	return (*this);
}

template <class T>
Vector<T> Vector<T>::operator*(Vector<T> A) {
	if (size != A.size) {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "�� ��������� �������");
	}
	Vector outVector(A.size);

	for (int i = 0; i < size; i++) {
		outVector[i] = vector[i] * A.vector[i];
	}

	return outVector;
}
