#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class HousePart
{
public:
    virtual void showDetails() = 0;
};

class Wall : public HousePart
{
public:
    void showDetails() override
    {
        cout << "Wall: A solid structure that encloses the house." << endl;
    }
};

class Door : public HousePart
{
public:
    void showDetails() override
    {
        cout << "Door: Allows access to the house." << endl;
    }
};

class Window : public HousePart
{
public:
    void showDetails() override
    {
        cout << "Window: Provides light and ventilation." << endl;
    }
};

class HousePartFactory
{
private:
    unordered_map<string, HousePart *> houseParts;

public:
    HousePart *getHousePart(string partType)
    {
        if (houseParts.find(partType) == houseParts.end())
        {
            if (partType == "Wall")
                houseParts[partType] = new Wall();
            else if (partType == "Door")
                houseParts[partType] = new Door();
            else if (partType == "Window")
                houseParts[partType] = new Window();
            else
                cout << "Unknown house part!" << endl;
        }

        return houseParts[partType];
    }
};

class House
{
private:
    HousePartFactory partFactory;
    string houseType;

public:
    House(string type) : houseType(type) {}

    void buildHouse()
    {
        cout << "Building a " << houseType << " house..." << endl;

        HousePart *wall = partFactory.getHousePart("Wall");
        HousePart *door = partFactory.getHousePart("Door");
        HousePart *window = partFactory.getHousePart("Window");

        wall->showDetails();
        door->showDetails();
        window->showDetails();
    }
};

int main()
{
    House house1("Modern");
    House house2("Traditional");

    house1.buildHouse();
    house2.buildHouse();

    return 0;
}
