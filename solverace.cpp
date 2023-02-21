#include <thread>
#include <iostream>
#include <mutex>

int shared_variable = 0;
std::mutex mutex;

void thread1()
{
    for (int i = 0; i < 1000000; i++)
    {
        mutex.lock();
        shared_variable++;
        mutex.unlock();
    }
}

void thread2()
{
    for (int i = 0; i < 1000000; i++)
    {
        mutex.lock();
        shared_variable++;
        mutex.unlock();
    }
}

int main()
{
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();

    std::cout << "Shared variable: " << shared_variable << std::endl;
}
