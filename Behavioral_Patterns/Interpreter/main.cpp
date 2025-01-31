#include <iostream>
#include <vector>
using namespace std;

class Expression
{
public:
    virtual void interpret() = 0;
    virtual ~Expression() = default;
};

class BuildWalls : public Expression
{
public:
    void interpret() override
    {
        cout << "Building Walls" << endl;
    }
};

class BuildRoof : public Expression
{
public:
    void interpret() override
    {
        cout << "Building Roof" << endl;
    }
};

class BuildHouse : public Expression
{
private:
    vector<Expression *> tasks;

public:
    void addTask(Expression *task)
    {
        tasks.push_back(task);
    }

    void interpret() override
    {
        for (Expression *task : tasks)
        {
            task->interpret();
        }
    }
};

int main()
{
    BuildWalls walls;
    BuildRoof roof;

    BuildHouse house;
    house.addTask(&walls);
    house.addTask(&roof);

    cout << "Interpreting House Construction: " << endl;
    house.interpret();

    return 0;
}
