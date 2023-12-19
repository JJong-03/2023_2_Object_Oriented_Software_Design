// Polymorphism (���⼺)
// upcasting -> �ڽ� Ŭ���� Ÿ���� �θ� Ŭ������ ��ȯ��ų�� �ִ�.
// downcasting -> �θ� Ŭ���� Ÿ���� �ڽ� Ŭ���� Ÿ������ �ٲ� �� �ִµ� -> �ڽ� Ŭ�������� �߰����� �Լ��� ����� �ȵȴ�. (Risk�� �ʹ� ����)

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
		cout <<"�۸�" << endl;
	}
};

class Cat : public Animal {
public:
	void speak()
	{
		cout <<"�߿�" << endl;
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
	//a1->age = 10; // ����!!
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
// virtual Function - ��, (*, &)������ ������ �Ѵ�. C-style casting�� �ȵ�!!!!
#if 0
#include <iostream>
using namespace std;
class Animal {
public:
	virtual void speak() // �� �տ� virtual�� �����ָ� ��.
	{
		cout << "Animal speak()" << endl;
	}
};

class Dog : public Animal {
public:
	int age;
	void speak()
	{
		cout << "�۸�" << endl;
	}
};

class Cat : public Animal {
public:
	void speak()
	{
		cout << "�߿�" << endl;
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
// ����Ҹ��� -> �θ��� �Ҹ��ڵ� virtual�� �ٿ������.
#if 0
class Parent
{
public:
	virtual ~Parent() { cout << "Parent �Ҹ���" << endl; } // �θ��� �Ҹ��ڵ� virtual �ٿ�!!
};

class Child : public Parent
{
public:
	~Child() { cout << "Child �Ҹ���" << endl; }
};
int main()
{
	Parent* p = new Child(); // ���� ����ȯ
	delete p; // Parent �Ҹ��ڸ� ȣ��ȴ�.
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
	ps->draw(); // Rectangle�� draw()�� ȣ��ȴ�.
	delete ps;
	return 0;
}


#endif
// ���� Pure Virtual Function Ex
#if 0
class Animal {
	virtual void move() = 0;
	virtual void eat() = 0;
	virtual void speak() = 0;
};
class Lion : public Animal {
	void move() {
		cout << "������ move() << endl;
	}
	void eat() {
		cout << "������ eat() << endl;
	}
	void speak() {
		cout << "������ speak() << endl;
	}
};
#endif

