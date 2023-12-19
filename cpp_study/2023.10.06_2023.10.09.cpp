//복사 생성자
//MyClass(const MyClass& other) {
//
//}

 
// 정적변수(static) 
// static = global variable , 전체에서 하나, 다른 곳에서 바꿔도 기존에서 바뀐 값을 볼 수 있음.

// 정적멤버함수 - object 생성 없이도 부를 수 있다. 
#if 0
class Circle {
	int x, y;
	int radius;
public:
	static int count; // 정적 변수
	Circle() : x{ 0 }, y{ 0 }, radius{ 0 } {
		count++;
	}
	Circle(int x, int y, int r) : x{ x }, y{ y }, radius{ r } {
		count++;
	}
	// 정적 멤버 함수
	static int getCount() {
		return count;
	}
};
int Circle::count = 0; // ①
#endif
// Const를 잘 써야함.
// ★연산자 중복★ --> 시험에 나옴
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
//연산자의 중복
#if 0
#include <iostream>
#include <string>
using namespace std;
class MyVector
{
private:
	double x, y; // 값 들은 private로
public:
	MyVector(double x = 0.0, double y = 0.0) : x{ x }, y{ y } { } // 생성자는 public으로 해야함 외부에서 가져오기 위해
	string toString() {
		return "(" + to_string(x) + ", " + to_string(y) + ")";
	}
	MyVector operator+(const MyVector& v2); // 값을 변경하지 않게 하기위해
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
// == 연산자의 중복
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
	// 참과 거짓을 1, 0이 아니라 true, false로 출력하도록 설정한다.
	cout.setf(cout.boolalpha); // true, false로 출력 -> boolalpha
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
	cout << "카운터의 값: " << c.getValue() << endl;
	++c;
	cout << "카운터의 값: " << c.getValue() << endl;
	return 0;
}

const Counter operator++(int i) // const를 무조건 써야한다. 복사본을 넘기기 때문에.
{
	Counter temp = { *this }; // 현재의 상태를 저장한다.
	++value;
	return temp;
}
#endif
// Postfix 연산자의 중복
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
		A temp = *this; // inc. 전의 객체를 넘긴다.
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
//프렌드 함수
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

// 상속의 종류 3가지: public, protected, private
// public -> 외부 o, 부모 class o, 자식 class o
// protected -> 외부 x, 부모 class o, 자식 class o
// private -> 외부 x, 부모 class o, 자식 class x
#if 0
class Parent {
public:
	int public_parent_a;
protected:
	int protected_parent_a;
private:
	int private_parent_a;
};
// 이렇게 불러옴.
class Child1 : public Parent{};
class Child2 : protected Parent{};
class Child3 : private Parent{};
#endif

// 다중 상속 -> 나옴