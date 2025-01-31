#include <iostream>
#include <vector>
#include <string>
using namespace std;

// observer pattern is a behavioral design pattern that defines a one-to-many dependency between objects so that when one object changes state.
// Here I have made Station as a Oberservable class and DisplayDevice as Observer class.

class Observer
{
public:
    virtual void notify(int temperature) = 0;
    virtual ~Observer() = default;
};

class DisplayDevice : public Observer
{
private:
    string name;

public:
    DisplayDevice(string name) : name(name) {}

    void notify(int temperature) override
    {
        cout << name << " Current temperature is " << temperature << endl;
    }
};

class Station 
{
private:
    vector<Observer *> observers;
    float temperature;

public:
    void setTemperature(float temp)
    {
        temperature = temp;
        notifyStates();
    }

    float getTemperature() { return temperature; }

    void addObserver(Observer *observer)
    {
        observers.push_back(observer);
    }

    void notifyStates()
    {
        for (Observer *observer : observers)
        {
            observer->notify(temperature);
        }
    }
};

int main()
{
    Station station;

    DisplayDevice phone1("Device 1");
    DisplayDevice phone2("Device 2");

    station.addObserver(&phone1);
    station.addObserver(&phone2);

    station.setTemperature(25);

    //  station.setTemperature(28);

    return 0;
}
