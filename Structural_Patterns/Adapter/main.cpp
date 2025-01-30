#include <iostream>
#include <string>
using namespace std;

// In my house, I have a normal charger to charge my phone, But now I have purchase iphone, and I have only normal charger. I need to charge my phone using normal charger. So I need to create an adapter which will convert the power from normal charger to apple charger.
// That is adaptor design pattern;

class NewSocket
{
public:
    virtual void supplyPower() = 0;
};

class NormalCharger
{
public:
    void provideElectricity()
    {
        cout << "Normal Charger providing electricity." << endl;
    }
};

class AppleChargerAdapter : public NewSocket
{
private:
    NormalCharger *normalCharger;

public:
    AppleChargerAdapter(NormalCharger *socket)
    {
        normalCharger = socket;
    }

    void supplyPower() override
    {
        cout << "AppleChargerAdapter converting power from normal charger socket to apple charger socket." << endl;
        normalCharger->provideElectricity();
    }
};

class PhoneCharger
{
private:
    NewSocket *socket;

public:
    PhoneCharger(NewSocket *socketType)
    {
        socket = socketType;
    }

    void powerUp()
    {
        cout << "phone is charging using a adaptor socket which is connecting normal charger with apple charger." << endl;
        socket->supplyPower();
    }
};

int main()
{
    NormalCharger *normalCharger = new NormalCharger();

    AppleChargerAdapter *adapter = new AppleChargerAdapter(normalCharger);

    PhoneCharger *charger = new PhoneCharger(adapter);

    charger->powerUp();

    return 0;
}
