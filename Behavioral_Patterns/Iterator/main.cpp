#include <iostream>
#include <vector>
using namespace std;

// The Iterator pattern allows access to elements of an aggregate object (which is a collection) without exposing its internal structure.
// Here I have made a array with some numbers, but when I am traversing it I am not exposing any elements directly
// instead I have made a ConcreteAggregate, which is returning the ConcreteIterator to me,
// and when I am trying to follow the hasNext() and next() functions I am getting the getting values from there.
// after using this I can store my array in any format, I don't need to know which format is it using if I want to transverse

class Iterator
{
public:
    virtual bool hasNext() = 0;
    virtual int next() = 0;
};

class ConcreteIterator : public Iterator
{
private:
    vector<int> collection;
    int index;

public:
    ConcreteIterator(vector<int> items) : collection(items), index(0) {}

    bool hasNext() override
    {
        return index < collection.size();
    }

    int next() override
    {
        if (hasNext())
        {
            return collection[index++];
        }
        return -1;
    }
};

class ConcreteAggregate
{
private:
    vector<int> items;

public:
    ConcreteAggregate(vector<int> items) : items(items) {}

    Iterator *createIterator()
    {
        return new ConcreteIterator(items);
    }
};

int main()
{
    vector<int> numbers = {1, 2, 3, 4, 5};

    ConcreteAggregate collection(numbers);

    Iterator *iterator = collection.createIterator();

    while (iterator->hasNext())
    {
        cout << iterator->next() << " ";
    }

    return 0;
}
