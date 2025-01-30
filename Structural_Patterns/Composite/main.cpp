#include <iostream>
#include <vector>
#include <string>
using namespace std;

// In a city, there can be multiple colonies or independent houses only and  also each colony can have multiple houses.
// The city is a composite of colonies and colonies are a composite of houses.

class HouseComponent
{
public:
    virtual void showDetailsOfCity() const = 0;
    virtual ~HouseComponent() {}
};

class House : public HouseComponent
{
private:
    string name;

public:
    House(const string &name) : name(name) {}

    void showDetailsOfCity() const override
    {
        cout << "  House: " << name << endl;
    }
};

class Colony : public HouseComponent
{
private:
    string name;
    vector<HouseComponent *> houses;

public:
    Colony(const string &name) : name(name) {}

    void addHouse(HouseComponent *house)
    {
        houses.push_back(house);
    }

    void showDetailsOfCity() const override
    {

        cout << "Colony: " << name << endl;
        for (int i = 0; i < houses.size(); i++)
        {
            houses[i]->showDetailsOfCity();
        }
    }

    ~Colony() {};
};

int main()
{
    HouseComponent *house1 = new House("House 1");
    HouseComponent *house2 = new House("House 2");
    HouseComponent *house3 = new House("House 3");

    Colony *colony1 = new Colony("Colony A");
    colony1->addHouse(house1);
    colony1->addHouse(house2);

    Colony *colony2 = new Colony("Colony B");
    colony2->addHouse(house3);

    Colony *city = new Colony("Mumbai City");
    city->addHouse(colony1);
    city->addHouse(colony2);

    cout << "City : ";

    city->showDetailsOfCity();

    return 0;
}
