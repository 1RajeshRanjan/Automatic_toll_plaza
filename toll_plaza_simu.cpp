#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
using namespace std;

queue<int> buffer;
const int SIZE = 5;
mutex mtx;
condition_variable cv;

void producer() {
    for (int i = 1; i <= 10; i++) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return buffer.size() < SIZE; });

        buffer.push(i);
        cout << "Vehicle " << i << " arrived at toll\n";

        cv.notify_all();
        lock.unlock();
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

void consumer() {
    for (int i = 1; i <= 10; i++) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return !buffer.empty(); });

        int v = buffer.front();
        buffer.pop();
        cout << "Toll collected from vehicle " << v << endl;

        cv.notify_all();
        lock.unlock();
        this_thread::sleep_for(chrono::milliseconds(800));
    }
}

int main() {
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}
