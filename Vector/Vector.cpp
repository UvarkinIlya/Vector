#include "Vector.h"
#include <iostream>


//using namespace std;
////Vector::Vector(int a) {
////	/*��������� ������ ������� size ������� a*/
////	for (int i = 0; i < size; i++) {
////		vector[i] = a;
////	}
////}
//
//template <class T>
//Vector<T>::Vector(int n, int a) {
//	/*������� ������ ������� size � ��������� ������ ��������� a*/
//	if (n <= 0) {
//		throw 1;
//	}
//	size = n;
//	vector = new double[n];
//	for (int i = 0; i < n; i++) {
//		vector[i] = a;
//	}
//}
//
//template <class T>
//Vector<T>::Vector(const Vector& _vector) {
//	/*����������� �����������, �������� ��� ���� �������(�� � ������ ������ �� ������)*/
//	size = _vector.size;
//	vector = new double[size];
//	
//	for (int i = 0; i < size; i++) {
//		vector[i] = _vector.vector[i];
//	}
//}
//
////�� ��������� ���������, � �� ���� �� ����������
//template <class T>
//Vector<T>::~Vector() {
//	/*����������, ����������� ������ �������*/
//	delete[] vector;
//}
//
//template <class T>
//Vector<T> Vector<T>::operator+(Vector A/*���������� ����������� �����������*/) {
//	Vector res(size);
//	
//	for (int i = 0; i < size; i++) {
//		res.vector[i] = A.vector[i] + vector[i];
//	}
//
//	return res;//���������� ������������ �����������
//}
//
//template <class T>
//Vector<T>& Vector<T>::operator=(const Vector<T>& A) {
//	if (this == &A) {//&A - ������ ������
//		return (*this);//���������� ������, ����� ����������� �� �����(������� �� ������)
//	}
//
//	if (size != A.size) {
//		size = A.size;
//		delete[] vector;
//		vector = new double[size];
//	}
//
//	for (int i = 0; i < size; i++) {
//		vector[i] = A.vector[i];
//	}
//
//	return (*this);//���������� ������, ����� ����������� �� �����(������� �� ������)
//}
//
//template <class T>
//Vector<T>& Vector<T>::operator+=(const Vector<T>& A) {
//	if (size == A.size) {
//		for (int i = 0; i < size; i++) {
//			vector[i] += A.vector[i];
//		}
//	}
//
//	return(*this);
//}
//
//template <class T>
//double Vector<T>::get(int index) {
//	return vector[index];
//}
//
//template <class T>
//void Vector<T>::set(int index, double num) {
//	vector[index] = num;
//}
//
//template <class T>
//T& Vector<T>::operator[](int index) {
//	if (index >= 0 && index < size) {
//		return vector[index];
//	} else {
//		throw index;
//	}
//}
//
//template <class T>
//void Vector<T>::ReSize(int new_size)
//{
//	double* arr;
//	arr = new double[new_size];
//	Vector outVector(new_size);
//	
//	int k = min(size, new_size);
//	for (int i = 0; i < k; i++) {
//		arr[i] = vector[i];
//	}
//
//	for (int i = size; i < new_size; i++) {
//		arr[i] = 0;
//	}
//
//	size = new_size;
//	vector = new double[size];
//	for (int i = 0; i < size; i++) {
//		vector[i] = arr[i];
//	}
//	delete[] arr;
//}
//
//template <class T>
//Vector<T> Vector<T>::operator++() {
//	for (int i = 0; i < size; i++) {
//		vector[i]++;
//	}
//
//	return (*this);
//}
//
//template <class T>
//Vector<T> Vector<T>::operator++(int)
//{
//	Vector temp = Vector(*this);
//
//	for (int i = 0; i < size; i++) {
//		vector[i]++;
//	}
//
//	return temp;
//}
//
//template <class T>
//ostream& operator<<(ostream& out, const Vector<T>& C) {
//	out << "(";
//	for (int i = 0; i < C.size - 1; i++) {
//		out << C.vector[i] << ", ";
//	}
//
//	out << C.vector[C.size - 1] << ")";
//
//	return out;
//}
//
//template <class T>
//istream& operator>>(istream& in, const Vector<T>& C) {
//	for (int i = 0; i < C.size; i++) {
//		in >> C.vector[i];
//	}
//
//	return in;
//}
//
//template <class T>
//Vector<T> operator+(double num, Vector<T> A)
//{
//	for (int i = 0; i < A.size; i++) {
//		A.vector[i] += num;
//	}
//
//	return A;
//}
//
//template <class T>
//Vector<T> Vector<T>::operator-(Vector<T> A) {
//	if (size != A.size) {
//		//������
//	}
//
//	Vector outVector(A.size);
//
//	for (int i = 0; i < size; i++) {
//		outVector[i] = vector[i] - A.vector[i];
//	}
//
//	return outVector;
//}
//
//template <class T>
//Vector<T>& Vector<T>::operator-=(const Vector<T>& A) {
//	if (size != A.size) {
//		//������
//	}
//
//	for (int i = 0; i < size; i++) {
//		vector[i] -= A.vector[i];
//	}
//
//	return (*this);
//}
//
//template <class T>
//Vector<T> Vector<T>::operator+(double num) {
//	for (int i = 0; i < size; i++) {
//		vector[i] += num;
//	}
//	
//	return (*this);
//}
//
//template <class T>
//Vector<T> Vector<T>::operator-(double num){
//	for (int i = 0; i < size; i++) {
//		vector[i] -= num;
//	}
//
//	return (*this);
//}
//
////Vector operator++(int)
//
//template <class T>
//Vector<T> Vector<T>::operator*(Vector<T> A) {
//	Vector outVector(A.size);
//
//	for (int i = 0; i < size; i++) {
//		outVector[i] = vector[i] * A.vector[i];
//	}
//
//	return outVector;
//}

