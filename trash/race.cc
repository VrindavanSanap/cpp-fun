#include <thread>
#include <iostream>

int shared_variable = 0;

void thread1()
{
    for (int i = 0; i < 1000000; i++)
    {
        shared_variable++;
    }
}

void thread2()
{
    for (int i = 0; i < 1000000; i++)
    {
        shared_variable++;
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
