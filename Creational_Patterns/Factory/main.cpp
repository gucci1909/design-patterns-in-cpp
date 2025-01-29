#include <iostream>
#include <string>
using namespace std;

// Here we have taken a House example, the main motive of Factory method is to create objects without exposing the object creation logic to the client and refer to the newly created object using a common interface.
// So we are creating a House based on the type of house the user wants to build. and if the input is invalid then we are returning nullptr or Invalid House.

class House
{
public:
    virtual void build() = 0;
    virtual ~House() {}
};

class FirstHouse : public House
{
public:
    void build() override
    {
        cout << "First House!" << endl;
    }
};

class SecondHouse : public House
{
public:
    void build() override
    {
        cout << "Second House!" << endl;
    }
};

class ThirdHouse : public House
{
public:
    void build() override
    {
        cout << "Third House!" << endl;
    }
};

class HouseFactory
{
public:
    static House *createHouse(const string &houseType)
    {
        if (houseType == "First")
            return new FirstHouse();
        else if (houseType == "Second")
            return new SecondHouse();
        else if (houseType == "Third")
            return new ThirdHouse();
        else
            return nullptr;
    }
};

int main()
{
    string houseChoice;

    cout << "Which type of house would you like to build? (First/Second/Third): ";
    cin >> houseChoice;

    House *myHouse = HouseFactory::createHouse(houseChoice);

    if (myHouse)
    {
        myHouse->build();
    }
    else
    {
        cout << "Invalid house" << endl;
    }

    return 0;
}
