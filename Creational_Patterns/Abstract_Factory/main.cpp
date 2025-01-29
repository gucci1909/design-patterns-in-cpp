#include <iostream>
#include <string>
using namespace std;

// we use the abstract factory pattern to create a family of related objects, in this case, we have two families of objects: wooden and steel.
// We are building the house so we use same type of things like door and window , but the material is different.
// that's where abstract factory pattern comes in.
// we can make wooden adn steel house with the same code.

class Door
{
public:
    virtual void create() = 0;
};

class Window
{
public:
    virtual void create() = 0;
};

class WoodenDoor : public Door
{
public:
    void create() override
    {
        cout << "Wooden Door Created!" << endl;
    }
};

class WoodenWindow : public Window
{
public:
    void create() override
    {
        cout << "Wooden Window Created!" << endl;
    }
};

class SteelDoor : public Door
{
public:
    void create() override
    {
        cout << "Steel Door Created!" << endl;
    }
};

class SteelWindow : public Window
{
public:
    void create() override
    {
        cout << "Steel Window Created!" << endl;
    }
};

class HouseFactory
{
public:
    virtual Door *createDoor() = 0;
    virtual Window *createWindow() = 0;
};

class WoodenHouseFactory : public HouseFactory
{
public:
    Door *createDoor() override
    {
        return new WoodenDoor();
    }

    Window *createWindow() override
    {
        return new WoodenWindow();
    }
};

class SteelHouseFactory : public HouseFactory
{
public:
    Door *createDoor() override
    {
        return new SteelDoor();
    }

    Window *createWindow() override
    {
        return new SteelWindow();
    }
};

int main()
{
    HouseFactory *woodenHouseFactory = new WoodenHouseFactory();
    Door *woodenDoor = woodenHouseFactory->createDoor();
    Window *woodenWindow = woodenHouseFactory->createWindow();

    cout << "Wooden House:" << endl;
    woodenDoor->create();
    woodenWindow->create();

    cout << endl;

    HouseFactory *steelHouseFactory = new SteelHouseFactory();
    Door *steelDoor = steelHouseFactory->createDoor();
    Window *steelWindow = steelHouseFactory->createWindow();

    cout << "Steel House:" << endl;
    steelDoor->create();
    steelWindow->create();

    return 0;
}
