#include <iostream>
#include <string>
using namespace std;

// I have created a HouseCompany class that has three pure virtual functions. This will create a bridge for making different quality of houses,
// this will act as an abstraction for the House class. this is just a company taking orders for making different quality of houses. like AHouse or BHouse.
// THE a AND b both have same function but gives different quality of houses.
// the HOUSE company is the bridge here.

class HouseCompany
{
public:
    virtual void useLand() = 0;
    virtual void useWall() = 0;
    virtual void useGate() = 0;
    virtual ~HouseCompany() {}
};

class AHouse : public HouseCompany
{
public:
    void useLand() override
    {
        cout << "We Use High Quality Land." << endl;
    }
    void useWall() override
    {
        cout << "We Use High Quality Material" << endl;
    }
    void useGate() override
    {
        cout << "We Use High Quality Gates" << endl;
    }
};

class BHouse : public HouseCompany
{
public:
    void useLand() override
    {
        cout << "We Use Low Quality Land." << endl;
    }
    void useWall() override
    {
        cout << "We Use Low Quality Material." << endl;
    }
    void useGate() override
    {
        cout << "We Use Low Quality Gates." << endl;
    }
};

class House
{
protected:
    HouseCompany *builder;

public:
    House(HouseCompany *builder) : builder(builder) {}

    virtual void constructHouse() = 0;
    virtual ~House() {}
};

class NewHouse : public House
{
public:
    NewHouse(HouseCompany *builder) : House(builder) {}

    void constructHouse() override
    {
        cout << "Constructing a House:" << endl;
        builder->useLand();
        builder->useWall();
        builder->useGate();
    }
};

int main()
{
    HouseCompany *aHouse = new AHouse();
    House *newHouse = new NewHouse(aHouse);

    newHouse->constructHouse();

    cout << endl;

    HouseCompany *bHouse = new BHouse();
    House *oldHouse = new NewHouse(bHouse);

    oldHouse->constructHouse();

    return 0;
}
