// Polymorphism (다향성)
// upcasting -> 자식 클래스 타입을 부모 클래스로 변환시킬수 있다.
// downcasting -> 부모 클래스 타입을 자식 클래스 타입으로 바꿀 수 있는데 -> 자식 클래스에서 추가적인 함수를 만들면 안된다. (Risk가 너무 높음)

// upcasting Ex
#if 0
#include <iostream>
using namespace std;
class Animal {
public:
	void speak()
	{
		cout << "Animal speak()" << endl;
	}
};

class Dog : public Animal {
public:
	int age;
	void speak()
	{
		cout <<"멍멍" << endl;
	}
};

class Cat : public Animal {
public:
	void speak()
	{
		cout <<"야옹" << endl;
	}
};

int main()
{
	Animal* a1 = new Dog();
	a1->speak();
	Animal* a2 = new Cat();
	a2->speak();

	Dog* a3 = new Dog();
	a3->speak();
	Cat* a4 = new Cat();
	a4->speak();
	//a1->age = 10; // 오류!!
	return 0;
}
#endif
// upcasting by reference 1
#if 0
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
// upcasting by reference 2
#if 0
int main()
{
	Dog* d = new Dog;
	Animal& a1 = *d;
	a1.speak();
	Cat* c = new Cat;
	Animal& a2 = *c;
	a2.speak();
	return 0;
}
#endif
// virtual Function - 단, (*, &)에서만 동작을 한다. C-style casting은 안됨!!!!
#if 0
#include <iostream>
using namespace std;
class Animal {
public:
	virtual void speak() // 형 앞에 virtual만 적어주면 됨.
	{
		cout << "Animal speak()" << endl;
	}
};

class Dog : public Animal {
public:
	int age;
	void speak()
	{
		cout << "멍멍" << endl;
	}
};

class Cat : public Animal {
public:
	void speak()
	{
		cout << "야옹" << endl;
	}
};

int main()
{
	Animal* a1 = new Dog();
	a1->speak();
	Animal* a2 = new Cat();
	a2->speak();
	Animal* a3 = new Animal();
	a3->speak();

	return 0;
}
#endif
// 가상소멸자 -> 부모의 소멸자도 virtual을 붙여줘야함.
#if 0
class Parent
{
public:
	virtual ~Parent() { cout << "Parent 소멸자" << endl; } // 부모의 소멸자도 virtual 붙여!!
};

class Child : public Parent
{
public:
	~Child() { cout << "Child 소멸자" << endl; }
};
int main()
{
	Parent* p = new Child(); // 상향 형변환
	delete p; // Parent 소멸자만 호출된다.
}
#endif
// Pure Virtual Function 
#if 0
class Shape {
protected:
	int x, y;
public:
	Shape(int x, int y) : x(x), y(y) { }
	virtual void draw() = 0; // Pure_Virtual_Function
};

class Rect : public Shape {
private:
	int width, height;
public:
	Rect(int x, int y, int w, int h) : Shape(x, y), width(w), height(h) { }
	void draw() {
		cout << "Rectangle Draw" << endl;
	}
};

int main()
{
	Shape* ps = new Rect(0, 0, 100, 100); // OK!
	ps->draw(); // Rectangle의 draw()가 호출된다.
	delete ps;
	return 0;
}


#endif
// 쉬운 Pure Virtual Function Ex
#if 0
class Animal {
	virtual void move() = 0;
	virtual void eat() = 0;
	virtual void speak() = 0;
};
class Lion : public Animal {
	void move() {
		cout << "사자의 move() << endl;
	}
	void eat() {
		cout << "사자의 eat() << endl;
	}
	void speak() {
		cout << "사자의 speak() << endl;
	}
};
#endif

