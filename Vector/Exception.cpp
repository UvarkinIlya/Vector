#include "Exception.h"
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

Exception::Exception(const char* _fileName, const char* _functionName, int _NumberStr, const char* _descr){
	fileName = new char[strlen(_fileName) + 1];
	strcpy_s(fileName, strlen(_fileName) + 1, _fileName);

	NumberStr = _NumberStr;
	functionName = new char[strlen(_functionName) + 1];
	strcpy_s(functionName, strlen(_functionName) + 1, _functionName);

	descr = new char[strlen(_descr) + 1];
	strcpy_s(descr, strlen(_descr) + 1, _descr);
}

Exception::Exception(const Exception& excep){
	fileName = new char[strlen(excep.fileName) + 1];
	fileName = excep.fileName;

	NumberStr = excep.NumberStr;

	functionName = new char[strlen(excep.functionName) + 1];
	functionName = excep.functionName;

	descr = new char[strlen(excep.descr) + 1];
	descr = excep.descr;
}

Exception::~Exception(){
	delete[] fileName;
	delete[] functionName;
	delete[] descr;
}

void Exception::Print() const{
	cout << "Ошибка!!!" << endl;
	cout << "Описание:" << descr << endl;
	cout << "В файле:" << fileName << endl;
	cout << "В строке:" << NumberStr << endl;
	cout << "В функции: " << functionName << endl << endl;
}
