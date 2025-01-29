#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

// I have created House Builder class as a singleton class. the instance created for this class is shared among all the threads. But instance should be created only once.
// So, I have used mutex to lock the instance creation part. So, that only one thread can create the instance and other threads will wait until the instance is created.

class HouseBuilder
{
private:
    HouseBuilder()
    {
        cout << "HouseBuilder instance created!" << endl;
    }

    static HouseBuilder *instance;

    static mutex mtx;

public:
    static HouseBuilder *getInstance()
    {
        mtx.lock();

        if (instance == nullptr)
        {
            instance = new HouseBuilder();
        }

        mtx.unlock();
        return instance;
    }

    void buildHouse()
    {
        cout << "Building a house..." << endl;
    }
};

HouseBuilder *HouseBuilder::instance = nullptr;
mutex HouseBuilder::mtx;

void threadFunction()
{
    HouseBuilder *builder = HouseBuilder::getInstance();
    builder->buildHouse();
}

int main()
{
    thread t1(threadFunction);
    thread t2(threadFunction);

    t1.join();
    t2.join();

    HouseBuilder *builder = HouseBuilder::getInstance();
    builder->buildHouse();

    return 0;
}
