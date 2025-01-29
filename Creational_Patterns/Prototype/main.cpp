#include <iostream>
#include <string>
using namespace std;

// The Prototype design pattern allows you to create a new object by copying an existing object. Instead of creating new objects from scratch, you can clone an existing object and make modifications to it.

// Here we are copying the same function to clonedHouse from originalFirstHouse.
class House
{
protected:
    string houseType;

public:
    virtual House *clone() = 0;

    void showHouseDetails()
    {
        cout << "House Type: " << houseType << endl;
    }

    virtual ~House() {}
};
class FirstHouse : public House
{
public:
    FirstHouse()
    {
        houseType = "First House";
    }

    House *clone() override
    {
        return new FirstHouse(*this);
    }
};

int main()
{
    FirstHouse originalFirstHouse;

    House *clonedHouse = originalFirstHouse.clone();

    originalFirstHouse.showHouseDetails();

    cout << endl;

    clonedHouse->showHouseDetails();

    return 0;
}
