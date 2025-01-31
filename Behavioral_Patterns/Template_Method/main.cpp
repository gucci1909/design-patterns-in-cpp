#include <iostream>
#include <string>
using namespace std;

class Cooking
{
public:
    void prepare()
    {
        boilWater();
        brew();
        pourInCup();
    }

    void boilWater()
    {
        cout << "Boiling water" << endl;
    }

    virtual void brew() = 0;
    void pourInCup()
    {
        cout << "Pouring into cup" << endl;
    }

};

class Tea : public Cooking
{
public:
    void brew() override
    {
        cout << "Steeping tea" << endl;
    }
};

class Coffee : public Cooking
{
public:
    void brew() override
    {
        cout << "Dripping coffee" << endl;
    }
};

int main()
{
    Cooking *tea = new Tea();
    Cooking *coffee = new Coffee();

    cout << "Making Tea:" << endl;
    tea->prepare();

    cout << endl;

    cout << "Making Coffee:" << endl;
    coffee->prepare();

    return 0;
}
