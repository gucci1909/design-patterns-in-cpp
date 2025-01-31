#include <iostream>
using namespace std;

class FanContext;

class FanState
{
public:
    virtual void handle(FanContext *context) = 0;
    virtual string getStateName() = 0;
    virtual ~FanState() = default;
};

class FanContext
{
private:
    FanState *currentState;

public:
    FanContext(FanState *initialState) : currentState(initialState) {}

    void setState(FanState *state)
    {
        currentState = state;
    }

    void request()
    {
        currentState->handle(this);
    }

    string getCurrentState()
    {
        return currentState->getStateName();
    }
};

class OffState : public FanState
{
public:
    void handle(FanContext *context) override;
    string getStateName() override
    {
        return "Fan is OFF";
    }
};

class LowState : public FanState
{
public:
    void handle(FanContext *context) override;
    string getStateName() override
    {
        return "Fan is on LOW speed";
    }
};

class HighState : public FanState
{
public:
    void handle(FanContext *context) override;
    string getStateName() override
    {
        return "Fan is on HIGH speed";
    }
};

void OffState::handle(FanContext *context)
{
    cout << "Turning to LOW speed." << endl;
    context->setState(new LowState());
}

void LowState::handle(FanContext *context)
{
    cout << "Turning to HIGH speed." << endl;
    context->setState(new HighState());
}

void HighState::handle(FanContext *context)
{
    cout << "Turning the fan OFF." << endl;
    context->setState(new OffState());
}

int main()
{
    FanContext fan(new OffState());

    cout << "Initial State: " << fan.getCurrentState() << endl;

    fan.request();
    cout << "Current State: " << fan.getCurrentState() << endl;

    fan.request();
    cout << "Current State: " << fan.getCurrentState() << endl;

    return 0;
}
