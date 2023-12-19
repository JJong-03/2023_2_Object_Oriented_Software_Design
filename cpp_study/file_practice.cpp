#include<fstream>
#include<stdio.h>
#include<iostream>
#include<vector>
// 반복자의 .end는 마지막 요소의 다음이다!!!!!
using namespace std;
// 파일 쓰기
#if 0 
int main() {
	ofstream os{ "hello.txt" , ios::trunc };
	if (!os) {
		cerr << "파일 오픈에 실패했습니다." << endl;
		exit(1);

	}
	for (int i = 51; i < 150; i++) {
		os << i << endl;
	}
	return 0;
}
#endif

// 파일 읽기
#if 0
int main() {
	ifstream is{"hello.txt"};
	if (!is) {
		cerr << "파일 오픈 실패" << endl;
		exit(1);
	}
	int hour;
	double temperature;
	// 순서대로 1 1.1 , 2 2.2 저장되어 있으면
	// 1시 1.1도 2시 2.2도로 출력 됨
	while (is >> hour >> temperature) {
		cout << hour << "시" << temperature << "온도" << endl;

	}
	return 0;

}
#endif

// 이진 파일 저장
#if 0
int main() {
	int buffer[] = { 10,20,30,40,50 };
	ofstream os{ "test.txt", ofstream::binary };
	if (!os) {
		cout << "test 파일을 열 수 없습니다." << endl;
		exit(1);
	}
	os.write((char*)&buffer, sizeof(buffer));
	return 0;
}
#endif

// 탬플릿
#if 0
template <typename T>
T get_max(T x, T y) {
	if (x > y) return x;
	else return y;
}
int main() {
	int x = 5;
	int y = 7;
	printf("%d",get_max(5, 7));
	return 0;
}
#endif

// iterator , vector
#if 0
int main() {
	vector<int> vec = { 1,2,3,4,5 };
	vector<int>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++) {
		cout << *it << " ";
	}
}
#endif

#if 0
#include<deque>

int main() {
	deque<int> dq = { 1,2,3,4,5,6,7,8,9 };
	dq.pop_front();
	dq.push_back(15);
	for (auto& n : dq) {
		cout << n << endl;
	}
	return 0;
}
#endif
// list
#if 0
#include<list>
int main() {
	list<int> my_list = { 10,20,30,40,50 };
	auto it = my_list.begin();
	it++;
	it++;
	it--;
	my_list.insert(it, 25);
	for (auto& n : my_list) {
		cout << n << endl;
	}
	return 0;
}
#endif
//map
#if 0
#include<map>

int main() {
	map<string, string> mymap;
	mymap.insert(make_pair("김종원", "010-1234-5678"));
	mymap.insert(make_pair("길철수", "010-5678-1234"));

	mymap["박수영"] = "1234567";

	for (auto& it : mymap) {
		cout << it.first << " " << it.second << endl;
	}
	return 0;
}
#endif
// algorithm
#if 0
int main() {
	vector<string> vec{ "사과", "토마토", "배", "수박", "키위" };
	auto it = find(vec.begin(), vec.end(), "수박");
	if (it != vec.end())
		cout << "수박이" << distance(vec.begin(), it) << "에 있습니다";
	return 0;
}
#endif
