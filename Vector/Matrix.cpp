//#include "Matrix.h"
//
//template <class T>
//Matrix<T>::Matrix(int _size){
//	size = _size;
//	matr = new Vector[size];
//
//	Vector v(size);
//	for (int i = 0; i < size; i++) {
//		matr[i] = v;
//	}
//}
//
//template <class T>
//Matrix<T>::Matrix(const Matrix<T>& A){
//	size = A.size;
//	matr = new Vector[size];
//
//	//Vector v(size);
//	for (int i = 0; i < size; i++) {
//		matr[i] = A.matr[i];
//	}
//}
//
//template <class T>
//Matrix<T>::~Matrix<T>(){
//	delete[] matr;
//	/*for (int i = 0; i < size; i++) {
//		delete[] matr[i];
//	}*/
//
//}
//
//template <class T>
//Matrix<T> Matrix<T>::operator+(Matrix<T> A){
//	if (size != A.size) {
//		//Ошибка
//	}
//
//	Matrix res(size);
//
//	for (int i = 0; i < size; i++) {
//		cout << matr[i];
//		cout << A[i];
//		res.matr[i] = matr[i] + A.matr[i];
//		cout << res.matr[i];
//	}
//
//	return res;
//}
//
//template <class T>
//Matrix<T> Matrix<T>::operator-(Matrix<T> A){
//	if (size != A.size) {
//		//Ошибка
//	}
//
//	Matrix res(size);
//
//	for (int i = 0; i < size; i++) {
//		res.matr[i] = matr[i] - A.matr[i];
//	}
//
//	return res;
//}
//
//template <class T>
//Matrix<T> Matrix<T>::operator*(Matrix<T> A){
//	if (size != A.size) {
//		//Ошибка
//	}
//
//	Matrix res(size);
//
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size; j++) {
//			double sum = 0;
//			
//			for (int k = 0; k < size; k++) {
//				sum += matr[i][k] * A[k][j];
//			}
//			res.matr[i][j] = sum;
//		}
//	}
//
//	return res;
//}
//
//template <class T>
//Matrix<T> Matrix<T>::operator+=(const Matrix<T>& A){
//	if (size != A.size) {
//		//Ошибка
//	}
//
//	for (int i = 0; i < size; i++) {
//		matr[i] += A.matr[i];
//	}
//
//	return *this;
//}
//
//template <class T>
//Matrix<T> Matrix<T>::operator-=(const Matrix<T>& A){
//	if (size != A.size) {
//		//Ошибка
//	}
//
//	for (int i = 0; i < size; i++) {
//		matr[i] -= A.matr[i];
//	}
//
//	return *this;
//}
//
//template <class T>
//void Matrix<T>::operator=(Matrix<T> A){
//	size = A.size;
//
//	for (int i = 0; i < size; i++) {
//		matr[i] = A.matr[i];
//	}
//}
//
//template <class T>
//Vector<T>& Matrix<T>::operator[](int index){
//	return matr[index];
//}
//
//template <class T>
//Matrix<T> Matrix<T>::operator+(double num){
//	Matrix res(size);
//
//	for (int i = 0; i < size; i++) {
//		res[i] = matr[i] + num;
//	}
//
//	return res;
//}
//
//template <class T>
//Matrix<T> Matrix<T>::operator-(double num){
//	Matrix res(size);
//
//	for (int i = 0; i < size; i++) {
//		res[i] = matr[i] - num;
//	}
//
//	return res;
//}
//
//template <class T>
//istream& operator>>(istream& in, const Matrix<T>& A){
//	for (int i = 0; i < A.size; i++) {
//		in >> A.matr[i];
//	}
//
//	return in;
//}
//
//template <class T>
//ostream& operator<<(ostream& out, const Matrix<T>& A){
//	for (int i = 0; i < A.size; i++) {
//		out << A.matr[i] << endl;
//	}
//	out << endl;
//
//	return out;
//}
