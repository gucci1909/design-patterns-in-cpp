#include <iostream>
#include <string>
using namespace std;

// Add additional features dynamically to an object without changing its base implementation.
// Here I am creating a House class with a Base House with no additional features.
// But If I want to add features to it, I am using a HouseDecorator, which will take my base house and add features to it.
// This house Decorator is the Decorator Design Pattern.
// I have created two features Garden and Pool, which will add a garden and pool to the house respectively.

class House
{
public:
    virtual string getHouse() const = 0;
    virtual int getCost() const = 0;
    virtual ~House() {}
};

class BasicHouse : public House
{
public:
    string getHouse() const override
    {
        return "Basic House";
    }

    int getCost() const override
    {
        return 100;
    }
};

class HouseDecorator : public House
{
protected:
    House *house;

public:
    HouseDecorator(House *house) : house(house) {}

    string getHouse() const override
    {
        return house->getHouse();
    }

    int getCost() const override
    {
        return house->getCost();
    }

    virtual ~HouseDecorator() {}
};

class Garden : public HouseDecorator
{
public:
    Garden(House *house) : HouseDecorator(house) {}

    string getHouse() const override
    {
        return house->getHouse() + " with a Garden";
    }

    int getCost() const override
    {
        return house->getCost() + 200;
    }
};

class Pool : public HouseDecorator
{
public:
    Pool(House *house) : HouseDecorator(house) {}

    string getHouse() const override
    {
        return house->getHouse() + " with a Pool";
    }

    int getCost() const override
    {
        return house->getCost() + 500;
    }
};

int main()
{
    House *house = new BasicHouse();
    cout << "Basic House: " << house->getHouse() << " | Cost: " << house->getCost() << " INR" << endl;

    house = new Garden(house);
    cout << "Basic Garden House: " << house->getHouse() << " | Added Cost: " << house->getCost() << " INR" << endl;

    house = new Pool(house);
    cout << "Basic Garden + Pool House: " << house->getHouse() << " | Added Cost: " << house->getCost() << " INR" << endl;

    return 0;
}
