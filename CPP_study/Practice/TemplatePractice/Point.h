#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
template <typename T>
class Point
{
private:
	static T num;
	T xpos;
	T ypos;
public:
	Point(const T& x = 0, const T& y = 0)
		:xpos(x), ypos(y)
	{ num++; } // Constructor
	Point(const Point<T>& p)
		:xpos(p.xpos), ypos(p.ypos)
	{ num++; } // Copy constructor
	inline T GetNum() const { return num; }
	inline T GetX() const { return xpos; }
	inline T GetY() const { return ypos; }
	Point<T>& operator=(const Point<T>&);
	Point<T> operator+(const Point<T>&) const;
	void ShowPoint() const;
	friend std::ostream& operator<<(std::ostream& os, const Point<int>& pos);
	friend std::ostream& operator<<(std::ostream& os, const Point<double>& pos);
	~Point()
	{ /* Empty destructor */ }
};
template<typename T>
T Point<T>::num = 0;
template<> // Initialized static variable when double
double Point<double>::num = 10; // Not specialized template so we need template<>

// Below are the template functions
template<typename T>
Point<T>& Point<T>::operator=(const Point<T>& p)
{
	xpos = p.xpos;
	ypos = p.ypos;
	return *this;
}

template<typename T>
Point<T> Point<T>::operator+(const Point<T>& p) const
{
	T newx = xpos + p.xpos;
	T newy = ypos + p.ypos;
	num--;
	return Point<T>(newx, newy);
}

template<typename T>
void Point<T>::ShowPoint() const
{
	cout << "[" << xpos << ", " << ypos << "]" << endl;
	return;
}

// Specialized template class when type is string
template<>
class Point<char*>
{
private:
	static int num;
	char* str1;
	char* str2;
public:
	Point<char*>(const char* str1 = nullptr, const char* str2 = nullptr)
	{
		if(!str1)
			this->str1 = nullptr;
		else
		{
			this->str1 = new char[strlen(str1) + 1];
			strcpy(this->str1, str1);
		}
		if(!str2)
			this->str2 = nullptr;
		else
		{
			this->str2 = new char[strlen(str2) + 1];
			strcpy(this->str2, str2);
		}
		num++;
	} // Constructor
	Point<char*>(const Point<char*>& pos)
	{
		this->str1 = new char[strlen(pos.str1) + 1];
		this->str2 = new char[strlen(pos.str2) + 1];
		strcpy(this->str1, pos.str1);
		strcpy(this->str2, pos.str2);
		num++;
	} // Copy constructor
	inline int GetNum() const { return num; }
	inline char* GetX() const { return str1; }
	inline char* GetY() const { return str2; }
	Point<char*>& operator=(const Point<char*>&);
	Point<char*> operator+(const Point<char*>&) const;
	friend std::ostream& operator<<(std::ostream& os, const Point<char*>& pos);
	~Point()
	{
		if(!str1)
			delete[] str1;
		if(!str2)
			delete[] str2;
	} // Destructor
};
int Point<char*>::num = 5;

// Below are the template functions when string
Point<char*>& Point<char*>::operator=(const Point<char*>& pos)
{
	if(!str1)
		delete[] str1;
	if(!str2)
		delete[] str2;
	str1 = new char[strlen(pos.str1) + 1];
	str2 = new char[strlen(pos.str2) + 1];
	strcpy(this->str1, pos.str1);
	strcpy(this->str2, pos.str2);
	return *this;
}

Point<char*> Point<char*>::operator+(const Point<char*>& pos) const
{
	int newxlen = strlen(str1) + strlen(pos.str1);
	int newylen = strlen(str2) + strlen(pos.str2);
	char* temp1 = new char[newxlen + 1];
	char* temp2 = new char[newylen + 1];
	strcpy(temp1, str1);
	strcat(temp1, pos.str1);
	strcpy(temp2, str2);
	strcat(temp2, pos.str2);
	delete[] temp1;
	delete[] temp2;
	num--;
	return Point<char*>(temp1, temp2);
}

#endif