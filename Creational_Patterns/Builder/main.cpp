#include <iostream>
#include <string>
using namespace std;

// I am using an example of building a HOUSE here. We have made a single House class which has 4 attributes (walls, rooms, windows, doors). 
// These 4 attributes work as properties (props) to build a house, but they can also be optional.
// 
// If the number of properties increases, 
// we can distribute them logically into smaller groups or components. For example:
// 
// - ExteriorProperties: walls, roof, garden, garage
// - InteriorProperties: doors, windows, flooring, paint
// 
// This way, we can create separate smaller classes or builders to handle each group of properties.
// It makes the design more organized, reusable, and easier to manage when the number of properties grows.

class House
{
public:
    string gate;
    string rooms;
    string windows;
    string doors;

    void mainHouse()
    {
        cout << gate << endl;
        cout << rooms << endl;
        cout << windows << endl;
        cout << doors << endl;
    }
};

class HouseBuilder
{
public:
    virtual void buildGate() = 0;
    virtual void buildRooms() = 0;
    virtual void buildWindows() = 0;
    virtual void buildDoors() = 0;

    virtual House *getHouse() = 0;
    virtual ~HouseBuilder() {}
};

class FirstHouseBuilder : public HouseBuilder
{
    House *house;

public:
    FirstHouseBuilder() { house = new House(); }

    void buildGate() override { house->gate = "1st House Walls"; }
    void buildRooms() override { house->rooms = "1st House Rooms"; }
    void buildWindows() override { house->windows = "1st House Windows"; }
    void buildDoors() override { house->doors = "1st House Doors"; }

    House *getHouse() override { return house; }
};

class SecondHouseBuilder : public HouseBuilder
{
    House *house;

public:
    SecondHouseBuilder() { house = new House(); }

    void buildGate() override { house->gate = "2nd House Walls"; }
    void buildRooms() override { house->rooms = "2nd House Rooms"; }
    void buildWindows() override { house->windows = "2nd House Windows"; }
    void buildDoors() override { house->doors = "2nd House Doors"; }

    House *getHouse() override { return house; }
};

int main()
{
    FirstHouseBuilder first;

    first.buildGate();
    first.buildRooms();
    first.buildDoors();

    House *woodenHouse = first.getHouse();
    cout << "First House:" << endl;
    woodenHouse->mainHouse();

    cout << endl;

    SecondHouseBuilder second;

    second.buildRooms();
    second.buildWindows();

    House *SecondHouse = second.getHouse();
    cout << "Second House:" << endl;
    SecondHouse->mainHouse();

    return 0;
}