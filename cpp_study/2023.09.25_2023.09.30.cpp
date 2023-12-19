//포인터, 객체의 주소를 함수로 전달하기 - call by reference
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
// new와 delete (동적 메모리)
#if 0
#include <iostream>
#include <time.h>
using namespace std;
int main(){
	int* ptr;
	srand(time(NULL)); // 난수 발생기 시드 설정
	ptr = new int[10]; // ① 동적 메모리 할당
	for (int i = 0; i < 10; i++)
		ptr[i] = rand(); // ② 동적 메모리 사용
	for (int i = 0; i < 10; i++)
		cout << ptr[i] << " ";
	delete[] ptr; // ③ 동적 메모리 반납
	cout << endl;
	return 0;
}
#endif
// 복사 생성자 - class에서 함수 객체 전달을 할 때 필요함
#if 0
#include<iostream>
using namespace std;

class Complex{
public:
double real, imag;
Complex(double r = 0.0, double i = 0.0) : real{ r }, imag{ i } {
cout << "생성자 호출";
print();
}

Complex(const Complex& c) {
cout << "복사생성자 호출";
real = c.real;
imag = c.imag;
print();
}

~Complex() { cout << "소멸자 호출"; print(); }
void print() {
cout << real << "+" << imag << "i" << endl;
}

};
#endif