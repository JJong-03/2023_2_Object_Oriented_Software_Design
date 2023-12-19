//������, ��ü�� �ּҸ� �Լ��� �����ϱ� - call by reference
#if 0
#include<iostream>
using namespace std;

class Pizza {
	int radius;
public:
	Pizza(int r = 0) : radius{ r } { }
	~Pizza(){}
	void setRadius(int r) { radius = r; }
	void print() { cout << "Pizza(" << radius << ")" << endl; }
};

void upgrade(Pizza &p) { p.setRadius(20); }

int main() {
	Pizza obj(10);
	upgrade(obj);
	obj.print();
	return 0;
}
#endif
//nullptr
#if 0
#include<iostream>
using namespace std
;
void fun_a(int *p)
{
	cout <<"pointer function" << endl;
	return;
}
void fun_a(int p)
{
	cout <<"int function" << endl;
}
int main()
{
	fun_a(NULL); // int function
	fun_a(nullptr); // pointer function
	return 0;
}
#endif
// new�� delete (���� �޸�)
#if 0
#include <iostream>
#include <time.h>
using namespace std;
int main(){
	int* ptr;
	srand(time(NULL)); // ���� �߻��� �õ� ����
	ptr = new int[10]; // �� ���� �޸� �Ҵ�
	for (int i = 0; i < 10; i++)
		ptr[i] = rand(); // �� ���� �޸� ���
	for (int i = 0; i < 10; i++)
		cout << ptr[i] << " ";
	delete[] ptr; // �� ���� �޸� �ݳ�
	cout << endl;
	return 0;
}
#endif
// ���� ������ - class���� �Լ� ��ü ������ �� �� �ʿ���
#if 0
#include<iostream>
using namespace std;

class Complex{
public:
double real, imag;
Complex(double r = 0.0, double i = 0.0) : real{ r }, imag{ i } {
cout << "������ ȣ��";
print();
}

Complex(const Complex& c) {
cout << "��������� ȣ��";
real = c.real;
imag = c.imag;
print();
}

~Complex() { cout << "�Ҹ��� ȣ��"; print(); }
void print() {
cout << real << "+" << imag << "i" << endl;
}

};
#endif