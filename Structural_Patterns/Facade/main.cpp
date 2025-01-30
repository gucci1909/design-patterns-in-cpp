#include <iostream>
#include <string>
using namespace std;

// Facade works as a single point of entry for a library or a third-party system.
// We have taken a Zomato class, which is a facade for the restaurant and delivery service.
// A User will only about Zomato, but zomato itself will solve the user's problem by calling the restaurant and delivery service.
// and In the end zomato will work as a single point of entry for the user.

class Restaurant
{
public:
    void prepareFood(string foodItem)
    {
        cout << foodItem << " preparation in the restaurant." << endl;
    }
};

class DeliveryService
{
public:
    void deliverFood(string foodItem)
    {
        cout << "Delivering " << foodItem << " to the user." << endl;
    }
};

class Zomato
{
private:
    Restaurant restaurant;
    DeliveryService delivery;

public:
    void orderFood(string foodItem, int price)
    {
        cout << "Zomato: Starting the food ordering process..." << endl;

        cout << "Zomato: User selected " << foodItem << endl;

        restaurant.prepareFood(foodItem);

        delivery.deliverFood(foodItem);

        cout << "Zomato: Your order is complete! with INR " << price << endl;
    }
};

int main()
{
    Zomato zomato;

    string foodItem = "Pizza";
    int price = 200;

    cout << "User: I want to order food through Zomato." << endl;
    zomato.orderFood(foodItem, price);

    return 0;
}
