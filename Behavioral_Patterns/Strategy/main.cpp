#include <iostream>
#include <string>
using namespace std;

// Strategy design pattern is a behavioral design pattern that enables selecting an algorithm at runtime.
// So Here I have Strategy selector as Payment , which can be CreditCard or PayTM.
// Helper class is used to set the strategy and execute the payment.
// I can setStrategy to CreditCard or PayTM and execute the payment. 

class Payment
{
public:
    virtual void pay(int amount) = 0;
    virtual ~Payment() = default;
};

class CreditCard : public Payment
{
private:
    string cardNumber;

public:
    CreditCard(string cardNumber) : cardNumber(cardNumber) {}

    void pay(int amount) override
    {
        cout << amount << " using Credit Card: " << cardNumber << endl;
    }
};

class PayTM : public Payment
{
private:
    string email;

public:
    PayTM(string email) : email(email) {}

    void pay(int amount) override
    {
        cout << amount << " using PayTM :" << email << endl;
    }
};

class Helper
{
private:
    Payment *strategy;

public:
    Helper(Payment *strategy_1) : strategy(strategy_1) {}

    void setStrategy(Payment *strategy_1)
    {
        strategy = strategy_1;
    }

    void execute(int amount)
    {
        strategy->pay(amount);
    }
};

int main()
{
    Helper payment(new CreditCard("1234"));
    payment.execute(100);

    payment.setStrategy(new PayTM("user@example.com"));
    payment.execute(200);

    return 0;
}
