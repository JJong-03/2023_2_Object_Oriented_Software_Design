#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
using namespace std;
// 객체 배열 - for문 
#if 0
class Circle
{
public:
	int x, y, radius;
	Circle();
	~Circle();
	Circle(int x, int y, int r) : x{ x }, y{ y }, radius{ r } {}
	void print() { cout << "반지름: " << radius << "--" << x << y << endl; };


private:

};

int main() {
	Circle objArray[10];

	for (Circle& c : objArray) {
		c.x = rand() % 500;
		c.y = rand() % 300;
		c.radius = rand() % 100;
	}
	for (Circle c : objArray) c.print();

	return 0;
}

Circle::Circle()
{
	x = 0;
	y = 0;
	radius = 0;
}

Circle::~Circle()
{
}
#endif
// 벡터
#if 0
#include <iostream>
#include <vector>
using namespace std;
class Circle
{
public:
	int x, y;
	int radius;
	Circle() : x{ 0 }, y{ 0 }, radius{ 0 } { }
	Circle(int x, int y, int r) : x{ x }, y{ y }, radius{ r } { }
	void print() {
		cout << "반지름: " << radius << " @(" << x << ", " << y << ")" << endl;
	}
};
int main() {
	vector<Circle> objArray;
	for (int i = 0; i < 10; i++) {
		Circle obj{ rand() % 300, rand() % 300, rand() % 100 };
		objArray.push_back(obj);
	}
	for (Circle c : objArray) {
		c.print();
	}
}
#endif
// 벡터 + 알고리즘 -> string
#if 0
class Person
{
public:
	Person(string n, int a);
	string get_name() { return name; }
	int get_age() { return age; }
	void print() {
		cout << name << " " << age << endl;
	}

private:
	string name;
	int age;
};

bool compare(Person& p, Person& q) {
	return p.get_age() < q.get_age();
}

Person::Person(string n, int a) {
	name = n;
	age = a;
}

int main() {
	vector<Person> list;
	list.push_back(Person("Kim", 30));
	list.push_back(Person("Park", 22));
	list.push_back(Person("Lee", 26));
	sort(list.begin(), list.end(),compare);
	for (auto& e : list) {
		e.print();
	}
	return 0;
}
#endif
// 동적 메모리 - new
#if 0 
int main() {
	int* ptr;
	srand(time(NULL));
	ptr = new int[10];

	for (int i = 0; i < 10; i++) {
		ptr[i] = rand();
	}
	for (int i = 0; i < 10; i++) {
		cout << ptr[i] << endl;
	}
	delete[] ptr;
	cout << endl;
	return 0;
}

#endif
// unique_ptr - 자동 delete
#if 0
#include <iostream>
#include <memory>
using namespace std;
int main()
{
	unique_ptr<int[]> buf(new int[10]);
	for (int i = 0; i < 10; i++) {
		buf[i] = i;
	}
	for (int i = 0; i < 10; i++) {
		cout << buf[i] << " ";
	}
	cout << endl;
	return 0; // 할당받았던 10개 공간이 자동 해제
}
#endif
// 비교 연산자
#if 0
class Person {
public:
	int age;
	Person(int a) : age(a) { }
};
int main() {
	Person obj1(10);
	Person obj2(20);
	if (obj1.age == obj2.age) {
		cout << "같습니다" << endl;
	}
	else {
		cout << "같지 않습니다" << endl;
	}
	return 0;
}
#endif
// 정적 변수
#if 0
class Circle {
	int x, y;
	int radius;
	static int count; // 정적 변수
public:
	Circle() : x{ 0 }, y{ 0 }, radius{ 0 } {
		count++;
	}
	Circle(int x, int y, int r) : x{ x }, y{ y }, radius{ r } {
		count++;
	}
};
int main()
{
	Circle c1;
	Circle c2;

}
#endif
// 정적 멤버 함수  --> 전체 count를 위해서 사용함
// 외부에서 static 값을 초기화 시켜야한다.
// object 생성 없이 가능하다.
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

int Circle::count = 0; // Class 외부에서 초기화 시켜주어야한다.

int main()
{
	Circle c1;
	cout << "지금까지 생성된 원의 개수 = " << Circle::getCount() << endl; //
	Circle c2(100, 100, 30);
	cout << "지금까지 생성된 원의 개수 = " << Circle::getCount() << endl; //
	return 0;
}
#endif

//--------------10주차 ------------
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
#if 0
#include<iostream>
using namespace std;
class Animal
{
public:
	void speak() { cout << "Animal" << endl; }
	int age = 10;
};
class Dog : public Animal {
public:
	void speak() { cout << "Dog" << endl; }
	int age = 8;
};

class Cat : public Animal {
public:
	void speak() { cout << "cat" << endl; }
	int age = 5;
};

int main()
{
	Dog d;
	Animal& a1 = d;
	a1.speak();

	Cat c;
	Animal& a2 = c;
	a2.speak();

	return 0;
}
#endif