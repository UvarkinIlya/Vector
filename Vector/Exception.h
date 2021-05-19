#pragma once
/*�������� ��������� �������� ����������*/
class Exception{
	char* fileName;//��� �����, � ������� �������� ������
	char* functionName;//��� ������� � �������
	int NumberStr;//����� ������ ������
	char* descr;//��������
	public:
		Exception(const char* file, const char* functionName, int NumberStr, const char* descr);
		Exception(const Exception& excep);
		~Exception();
		void Print() const;
};

