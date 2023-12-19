// ����ó��(Exception) -> try
// ���� ���� ������ 3���� ��� �ϳ��� ĳġ�ϰ� try���� ������.
// throw�ϴ� ������ Ÿ���̶� catch (int e) ���ο� �ִ� ������ Ÿ���� ���ƾ��Ѵ�!!
#if 0
#include <iostream>
#include <exception>
using namespace std;
int main() {
	try { // throw ���� ������ ������, �޸� �Ҵ� �� ���� �������� throw���� 
		int* p = new int[100000]; // new�� ���� �� �ڵ����� throw���� ������ش�.
		delete p;
	}
	catch (exception& e) {
		cout << "ǥ�� ���ܰ� �߻��߽��ϴ�. " << e.what() << endl;
	}
	return 0;
}

#endif

// Generic Programming
// �Լ� ���ø� - overloading�� �����ϰ�!! - template
// type�� �ڵ����� ������
// �Լ� + Ŭ���� + library
#if 0
#include<iostream>
using namespace std;
template<typename T>
T get_max(T x, T y)
{
	if (x > y) return x;
	else return y;
}

int main()
{
	cout << get_max(1, 3) << endl;
	cout << get_max(1.2, 3.9) << endl;
	return 0;
}
#endif
// ���ø��� �����ε� �� �� ���
#if 0
#include <iostream>
using namespace std;
template <typename T>
void swap_values(T& x, T& y) // ���ø�
{
	T temp;
	temp = x;
	x = y;
	y = temp;
}

void swap_values(char* s1, char* s2) // �����ε�
{
	int len;
	len = (strlen(s1) >= strlen(s2)) ? strlen(s1) : strlen(s2);
	char* tmp = new char[len + 1];
	strcpy(tmp, s1);
	strcpy(s1, s2);
	strcpy(s2, tmp);
	delete[] tmp;
}

int main()
{
	int x = 100, y = 200;
	swap_values(x, y); // x, y�� ��� int Ÿ��- OK!
	cout << x << " " << y << endl;
	char s1[100] = "This is a first string";
	char s2[100] = "This is a second string";
	swap_values(s1, s2); // s1, s2�� ��� �迭 - �����ε� �Լ� ȣ��
	cout << s1 << " " << s2 << endl;
	return 0;
}
#endif
#if 0
// Class ������ Template
#include <iostream>
using namespace std;
template <typename T>
class Box {
	T data; // T�� Ÿ��(type)�� ��Ÿ����.
public:
	Box() { }
	void set(T value) {
		data = value;
	}
	T get() {
		return data;
	}
};

int main()
{
	Box<int> box; // ���� �� Ÿ���� ������. -> ������ Box box -> Box<int> box
	box.set(100); // int 100�� ��.
	cout << box.get() << endl;
	Box<double> box1;// Box box -> Box<doble> box
	box1.set(3.141592);
	cout << box1.get() << endl;
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;
template <typename T1, typename T2>

class Box2 {
	T1 first_data; // T1�� Ÿ
	��(type)�� ��Ÿ����.
	T2 second_data; // T2�� Ÿ��(type)�� ��Ÿ����.
public:
	Box2() { }
	T1 get_first();
	T2 get_second();
	void set_first(T1 value) {
		first_data = value;
	}
	void set_second(T2 value) {
		second_data = value;
	}
};
template <typename T1, typename T2>
T1 Box2<T1, T2>::get_first() {
	return first_data;
}
template <typename T1, typename T2>
T2 Box2<T1, T2>::get_second() {
	return second_data;
}
int main()
{
	Box2<int, double> b;
	b.set_first(10);
	b.set_second(3.14);
	cout << "(" << b.get_first() << ", " << b.get_second() << ")" << endl;
	return 0;
}

#endif

// STL
// Hash -> Map , dictionary
// STL - list
#if 0
#include <iostream>
#include <time.h>
#include <list>
using namespace std;
int main()
{
	list<int> values; // list
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		values.push_back(rand() % 100);
	}
	values.sort(); // �˰���
	for (auto& e : values) {
		std::cout << e << ' ';
	}
	std::cout << endl;
	return 0;
}
#endif
// end�� ������ ��� �ڿ� �� ������ ����Ŵ!!!!

// set_intersection -> ���� �� �ִ��� ã��
#if 0
#include <iostream> // std::cout
#include <algorithm> // std::set_intersection, std::sort
#include <vector> // std::vector
int main() {
	int first[] = { 5,10,15,20,20,25 };
	int second[] = { 50,40,30,20,10,20 };
	std::sort(std::begin(first), std::end(first));
	std::sort(std::begin(second), std::end(second));
	std::vector<int> v;
	std::set_intersection(std::begin(first), std::end(first),
		std::begin(second), std::end(second),
		std::back_inserter(v));
	std::cout << "The intersection has " << v.size() << " elements:\n";
	for (auto i : v)
		std::cout << ' ' << i;
	std::cout << '\n';
}
#endif

// ���� �� ���� ���� �ܾ� ã��  istringsteam(sstream) - �ܾ� �и�
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <set>
using namespace std;
int main()
{
	string report1 = "This is a original report.";
	string report2 = "This is a copy report.";
	vector<string> v1;
	vector<string> v2;
	// ù ��° ����Ʈ�� �ܾ�� �и��ϴ� ����
	istringstream iss1(report1);
	for (string s; iss1 >> s; )
		v1.push_back(s);

	// �� ��° ����Ʈ�� �ܾ�� �и��ϴ� ����
	istringstream iss2(report2);
	for (string s; iss2 >> s; )
		v2.push_back(s);

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	vector<string> common;
	set_intersection(v1.begin(), v1.end(),
		v2.begin(), v2.end(),
		back_inserter(common));
	cout << "report1=" << report1 << endl;
	cout << "report2=" << report2 << endl << endl;
	cout << "�������� �ܾ�: ";
	for (string e : common)
		cout << e << ' ';
	cout << endl;
	return 0;
}
#endif