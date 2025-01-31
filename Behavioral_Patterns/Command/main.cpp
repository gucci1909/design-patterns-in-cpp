#include <iostream>
#include <vector>
using namespace std;

// Command is used where a user have to give the command to the invoker who will decide what action will be taken or business logic will take up for the command which is received.

class Light
{
public:
    void turnOn()
    {
        cout << "The light is now ON." << endl;
    }
    void turnOff()
    {
        cout << "The light is now OFF." << endl;
    }
};

class Command
{
public:
    virtual void execute() = 0;
    virtual ~Command() {}
};

class TurnOnLightCommand : public Command
{
    Light light;

public:
    TurnOnLightCommand(Light light) : light(light) {}
    void execute() override
    {
        light.turnOn();
    }
};

class TurnOffLightCommand : public Command
{
    Light light;

public:
    TurnOffLightCommand(Light light) : light(light) {}
    void execute() override
    {
        light.turnOff();
    }
};

class RemoteControl
{
    vector<Command *> commands;

public:
    void addCommand(Command *command)
    {
        commands.push_back(command);
    }

    void executeCommands()
    {
        for (auto command : commands)
        {
            command->execute();
        }
    }
};

int main()
{
    Light roomLight;

    TurnOnLightCommand lightOn(roomLight);
    TurnOffLightCommand lightOff(roomLight);

    RemoteControl remote;
    remote.addCommand(&lightOn);
    remote.addCommand(&lightOff);

    cout << "Executing house automation commands:" << endl;
    remote.executeCommands();

    return 0;
}
