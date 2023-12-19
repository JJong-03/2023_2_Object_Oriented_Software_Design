//���� ������
//MyClass(const MyClass& other) {
//
//}

 
// ��������(static) 
// static = global variable , ��ü���� �ϳ�, �ٸ� ������ �ٲ㵵 �������� �ٲ� ���� �� �� ����.

// ��������Լ� - object ���� ���̵� �θ� �� �ִ�. 
#if 0
class Circle {
	int x, y;
	int radius;
public:
	static int count; // ���� ����
	Circle() : x{ 0 }, y{ 0 }, radius{ 0 } {
		count++;
	}
	Circle(int x, int y, int r) : x{ x }, y{ y }, radius{ r } {
		count++;
	}
	// ���� ��� �Լ�
	static int getCount() {
		return count;
	}
};
int Circle::count = 0; // ��
#endif
// Const�� �� �����.
// �ڿ����� �ߺ��� --> ���迡 ����
#if 0
#include <iostream>
#include <string>
using namespace std;
int main() {
	string s1 = "Rogue One: ";
	string s2 = "A Star Wars Story";
	string s3;
	s3 = s1 + s2;
	cout << "s1=" << s1 << endl;
	cout << "s2=" << s2 << endl;
	cout << "s1+s2= " << s3 << endl;
	cout << "s1==s2 " << boolalpha << (s1 == s2) << endl;
	return 0;
}
#endif
#if 0 
#include <iostream>
#include <string>
using namespace std;
class MyVector
{
private:
	double x, y;
public:
	MyVector(double x = 0.0, double y = 0.0) : x{ x }, y{ y } { }
	string toString() {
		return "(" + to_string(x) + ", " + to_string(y) + ")";
	}
	MyVector operator+(const MyVector& v2);
};

MyVector MyVector::operator+(const MyVector& v2)
{
	MyVector v;
	v.x = this->x + v2.x;
	v.y = this->y + v2.y;
	return v;
}
int main()
{
	MyVector v1(1.0, 2.0), v2(3.0, 4.0);
	MyVector v3 = v1 + v2;
	cout << v1.toString() << "+" << v2.toString() << "=" <<
		v3.toString() << endl;
	return 0;
}
#endif
//�������� �ߺ�
#if 0
#include <iostream>
#include <string>
using namespace std;
class MyVector
{
private:
	double x, y; // �� ���� private��
public:
	MyVector(double x = 0.0, double y = 0.0) : x{ x }, y{ y } { } // �����ڴ� public���� �ؾ��� �ܺο��� �������� ����
	string toString() {
		return "(" + to_string(x) + ", " + to_string(y) + ")";
	}
	MyVector operator+(const MyVector& v2); // ���� �������� �ʰ� �ϱ�����
};

MyVector MyVector::operator+(const MyVector& v2)
{
	MyVector v;
	v.x = this->x + v2.x;
	v.y = this->y + v2.y;
	return v;
}
int main()
{
	MyVector v1(1.0, 2.0), v2(3.0, 4.0);
	MyVector v3 = v1 + v2;
	cout << v1.toString() << "+" << v2.toString() << "=" <<
		v3.toString() << endl;
	return 0;
}

#endif
// == �������� �ߺ�
#if 0
#include <iostream>
using namespace std;
class Time
{
	int hour, min, sec;
public:
	Time(int h = 0, int m = 0, int s = 0) : hour(h), min(m), sec(s) { }
	bool operator== (Time& t2) {
		return (hour == t2.hour &&
			min == t2.min &&
			sec == t2.sec);
	}
	bool operator!= (Time& t2) {
		return !(*this == t2);
	}
};
int main()
{
	Time t1(1, 2, 3), t2(1, 2, 3);
	// ���� ������ 1, 0�� �ƴ϶� true, false�� ����ϵ��� �����Ѵ�.
	cout.setf(cout.boolalpha); // true, false�� ��� -> boolalpha
	cout << (t1 == t2) << endl;
	cout << (t1 != t2) << endl;
	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
class Counter {
private:
	int value;
public:
	Counter() : value{ 0 } { };
	~Counter() { }
	int getValue() const { return value; }
	void setValue(int x) { value = x; }
	Counter& operator++()
	{
		++value;
		return *this;
	}
};

int main()
{
	Counter c;
	cout << "ī������ ��: " << c.getValue() << endl;
	++c;
	cout << "ī������ ��: " << c.getValue() << endl;
	return 0;
}

const Counter operator++(int i) // const�� ������ ����Ѵ�. ���纻�� �ѱ�� ������.
{
	Counter temp = { *this }; // ������ ���¸� �����Ѵ�.
	++value;
	return temp;
}
#endif
// Postfix �������� �ߺ�
#if 0
#include<iostream>
using namespace std;
class A {
	int i;
public:
	A() : i(0) {}
	A(int _i) : i{ _i } {}
	void showMe() const {
		cout << "i = " << i << endl;
		return;
	}
	const A operator++(int k) { // postfix inc. op
		A temp = *this; // inc. ���� ��ü�� �ѱ��.
		i++;
		return temp;
	}
	A& operator++() { // prefix inc. op
		i++;
		return *this;
	}
};
void OutsideShowMe(const A& a) {
	a.showMe();
	return;
}

int main(void) {
	A a1(10);
	// postfix inc. op.
	cout << "postfix inc. op." << endl;
	OutsideShowMe(a1++);
	a1.showMe();
	// prefix inc. op.
	cout << "prefix inc. op." << endl;
	OutsideShowMe(++a1);
	a1.showMe();
	return 0;
}
#endif
//������ �Լ�
#if 0
#include <iostream>
using namespace std;
class Box {
	double length, width, height;
public:
	Box(double l, double w, double h) : length{ l }, width{ w }, height{ h } { }
	friend void printBox(Box box);
};
void printBox(Box box) {
	cout << "Box( " << box.length << ", " << box.width << ", "
		<< box.height << ") " << endl;
}

int main() {
	Box box(10, 20, 30);
	printBox(box);
	return 0;
}
#endif

// ����� ���� 3����: public, protected, private
// public -> �ܺ� o, �θ� class o, �ڽ� class o
// protected -> �ܺ� x, �θ� class o, �ڽ� class o
// private -> �ܺ� x, �θ� class o, �ڽ� class x
#if 0
class Parent {
public:
	int public_parent_a;
protected:
	int protected_parent_a;
private:
	int private_parent_a;
};
// �̷��� �ҷ���.
class Child1 : public Parent{};
class Child2 : protected Parent{};
class Child3 : private Parent{};
#endif

// ���� ��� -> ����