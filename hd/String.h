#pragma once

#include <string.h>;
#include <iostream>;
class String
{
public:
	String();
	explicit String(int lenght);
	String(const char* str);

	// rule of 3 Если что-то из одного нижеперечисленного нам нужно, то мы обязаны реализовать остальные 2 штуки
	~String(); //Деструкотор
	String(const String& other); // Конструктор копирования
	String& operator=(const String& other); //Оператор переприсваивания копирования Copy assign operator

	// rule of 5 / move Семантика
	String(String&& other)noexcept; // Конструктор переноса
	String& operator=(String&& other); // оператор переноса переприсваивания

	void reserve(int new_capacity);
	void shrink_to_fit();
	void clean();
	bool empty()const;

	int capacity()const;
	int size()const;


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

	char& operator[](int i)noexcept;
	const char* operator[](int i)const noexcept;

	char& at(int i);
	const char& at(int i)const;

	friend std::ostream& operator<<(std::ostream& out, const String& rsd);
	friend std::istream& operator>>(std::istream& out, const String& rsd);

	char* data();
	const char* c_str()const;

	class iterator{};
	class const_iterator{};
	class right_iterator{};
	class const_right_iterator {};

	iterator begin();
	iterator end();
	
	right_iterator rbegin();
	right_iterator rend();

	const_iterator cend()const;
	const_iterator cbegin()const;

	const_right_iterator crbegin()const;
	const_right_iterator crend()const;

	void insert(iterator& obj,char ch);
	void emplace(iterator& obj, char ch);

	void push_back(char ch);
	void emplace_back(char ch);   


private:
	
	struct {}allocator_;

	char* str_;
	size_t size_;
	size_t capacity_;
};

