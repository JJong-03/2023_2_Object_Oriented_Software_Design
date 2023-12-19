// Thread�� ������ -> t1���� gi�� 10�̶� 11�� ����, t2������ gi�� 10�̶� 11�� ����. ��, ���ϴ� ��� ���� 200,000�� ������ ����.
#if 0
#include <iostream>
#include <thread>
using namespace std;

void increment(int& _gi) {
    for (int i = 0; i < 100000; i++) {
        _gi++;
    }
}

int main() {
    int gi = 0;
    cout << "Spawning 2 threads..." << endl;

    thread t1(increment, ref(gi));
    thread t2(increment, ref(gi));

    t1.join();
    t2.join();
    
    cout << "End of main" << endl;
    cout << "Value of gi: " << gi << endl;

    return 0;
}
#endif

#if 0
#include<iostream>
#include<thread>
using namespace std;

void hello(int n) {
    for (int i = 0; i < 100; i++) {
        cout << "Hello Thread" << n  << endl;
    }
}
void hello2() {
    cout << "Hello 2" << endl;
}

int main() {
    thread aThread(hello, 5);
    for (int i = 0; i < 100; i++) {
        cout << "Main" << endl;
    }
    aThread.join();
    cout << "End of main" << endl;
    return 0;
}
#endif