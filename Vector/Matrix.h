#pragma once
#include "Vector.h"
#include "Exception.h"

template <class T>
class Matrix{
	public:
		Vector<T>* matr;
		int size;
	public:
		Matrix(int _size = 10);
		Matrix(const Matrix& A);
		~Matrix();
		Matrix<T> operator+(Matrix<T> A);
		Matrix<T> operator-(Matrix<T> A);
		Matrix<T> operator*(Matrix<T> A);
		Matrix<T> operator+=(const Matrix<T>& A);
		Matrix<T> operator-=(const Matrix<T>& A);
		void operator=(Matrix A);
		Vector<T>& operator[](int index);
		Matrix<T> operator+(T num);
		Matrix<T> operator-(T num);
		Vector<T> operator*(Vector<T> A);

		//friend istream& operator>>(istream& in, const Matrix<T>& A);
		//friend ostream& operator<<(ostream& out, const Matrix<T>& A);

		friend istream& operator>>(istream& in, const Matrix<T>& A) {
			for (int i = 0; i < A.size; i++) {
				in >> A.matr[i];
			}

			return in;
		}

		friend ostream& operator<<(ostream& out, const Matrix<T>& A) {
			for (int i = 0; i < A.size; i++) {
				out << A.matr[i] << endl;
			}
			out << endl;

			return out;
		}
};

template <class T>
Matrix<T>::Matrix(int _size) {
	if (_size < 0) {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "Не верный размер");
	}

	size = _size;
	matr = new Vector<T>[size];

	Vector<T> v(size);
	for (int i = 0; i < size; i++) {
		matr[i] = v;
	}
}

template <class T>
Matrix<T>::Matrix(const Matrix<T>& A) {
	size = A.size;
	matr = new Vector<T>[size];

	//Vector v(size);
	for (int i = 0; i < size; i++) {
		matr[i] = A.matr[i];
	}
}

template <class T>     
Matrix<T>::~Matrix<T>() {
	delete[] matr;
	size = -1;
	/*for (int i = 0; i < size; i++) {
		delete[] matr[i];
	}*/

}

template<class T>
Matrix<T> Matrix<T>::operator+(Matrix<T> A) {
	if (size != A.size) {
 		throw Exception(__FILE__, __FUNCTION__, __LINE__, "Не совпадает размер");
	}

	Matrix res(size);

	for (int i = 0; i < size; i++) {
		cout << matr[i];
		cout << A[i];
		res.matr[i] = matr[i] + A.matr[i];
		cout << res.matr[i];
	}

	return res;
}

template <class T>
Matrix<T> Matrix<T>::operator-(Matrix<T> A) {
	if (size != A.size) {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "Не совпадает размер");
	}

	Matrix res(size);

	for (int i = 0; i < size; i++) {
		res.matr[i] = matr[i] - A.matr[i];
	}

	return res;
}

template <class T>
Matrix<T> Matrix<T>::operator*(Matrix<T> A) {
	if (size != A.size) {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "Не совпадает размер");
	}

	Matrix res(size);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			T sum = 0;

			for (int k = 0; k < size; k++) {
				sum += matr[i][k] * A[k][j];
			}
			res.matr[i][j] = sum;
		}
	}

	return res;
}

template <class T>
Matrix<T> Matrix<T>::operator+=(const Matrix<T>& A) {
	if (size != A.size) {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "Не совпадает размер");
	}

	for (int i = 0; i < size; i++) {
		matr[i] += A.matr[i];
	}

	return *this;
}

template <class T>
Matrix<T> Matrix<T>::operator-=(const Matrix<T>& A) {
	if (size != A.size) {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "Не совпадает размер");
	}

	for (int i = 0; i < size; i++) {
		matr[i] -= A.matr[i];
	}

	return *this;
}

template <class T>
void Matrix<T>::operator=(Matrix<T> A) {
	size = A.size;

	for (int i = 0; i < size; i++) {
		matr[i] = A.matr[i];
	}
}

template <class T>
Vector<T>& Matrix<T>::operator[](int index) {
	if (index < 0 || index >= size) {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "Выход за границу");
	}

	return matr[index];
}

template <class T>
Matrix<T> Matrix<T>::operator+(T num) {
	Matrix res(size);

	for (int i = 0; i < size; i++) {
		res[i] = matr[i] + num;
	}

	return res;
}

template <class T>
Matrix<T> Matrix<T>::operator-(T num) {
	Matrix res(size);

	for (int i = 0; i < size; i++) {
		res[i] = matr[i] - num;
	}

	return res;
}

template<class T>
Vector<T> Matrix<T>::operator*(Vector<T> A){
	Vector<T> res(size);

	for (int i = 0; i < size; i++) {
		res[i] = A.Scal(matr[i]);
	}

	return res;
}

/*template<class T>
Vector<T> Matrix<T>::operator*(Matrix<T> A){
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
