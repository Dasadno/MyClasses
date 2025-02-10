#pragma once

#include <string.h>;
#include <iostream>;
class String
{
public:
	String();
	explicit String(int lenght);
	String(const char* str);

	// rule of 3 ���� ���-�� �� ������ ������������������ ��� �����, �� �� ������� ����������� ��������� 2 �����
	~String(); //�����������
	String(const String& other); // ����������� �����������
	String& operator=(const String& other); //�������� ���������������� ����������� Copy assign operator
	
	// rule of 5 / move ���������
	String(String&& other)noexcept; // ����������� ��������
	String& operator=(String&& other); // �������� �������� ����������������

	void reserve(int new_capacity);
	void shrink_to_fit();
	void clean();
	bool empty()const;

	String& operator+=(const String& other);
	String& operator+=(char ch);
	friend String& operator+(const String& lsd, const String& rsd);
	friend String& operator+(const String& lsd, char ch);
	friend String& operator+(char ch, const String& rsd);


	friend String& operator<(const String& lsd, const String& rsd);
	friend bool operator>(const String& lsd, const String& rsd);
	friend bool operator>=(const String& lsd, const String& rsd);
	friend bool operator<=(const String& lsd, const String& rsd);
	friend bool operator==(const String& lsd, const String& rsd);
	friend bool operator!=(const String& lsd, const String& rsd);

private:
	char* str_;
	size_t size_;
	size_t capacity_;
};

