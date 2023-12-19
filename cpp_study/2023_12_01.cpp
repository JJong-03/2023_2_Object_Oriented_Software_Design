// Thread의 주의점 -> t1에서 gi가 10이라 11로 만듦, t2에서도 gi가 10이라 11로 만듦. 즉, 원하던 결과 값인 200,000이 나오질 않음.
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