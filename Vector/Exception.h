#pragma once
/*Содержит подробное описание исключения*/
class Exception{
	char* fileName;//Имя файла, в котором возникла ошибка
	char* functionName;//Имя функции с ошибкой
	int NumberStr;//Номер строки ошибки
	char* descr;//Описание
	public:
		Exception(const char* file, const char* functionName, int NumberStr, const char* descr);
		Exception(const Exception& excep);
		~Exception();
		void Print() const;
};

