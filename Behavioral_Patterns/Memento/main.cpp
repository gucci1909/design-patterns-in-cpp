#include <iostream>
#include <string>
#include <vector>
using namespace std;

// here memento is used to save the state of the object and restore it later
// So I can store the state of the object at any point of time and restore it later from the index

class Memento
{
private:
    string state;

public:
    Memento(string state) : state(state) {}

    string getState()
    {
        return state;
    }
};

class TextEditor
{
private:
    string content;

public:
    void write(string text)
    {
        content += text;
    }

    string getContent()
    {
        return content;
    }

    Memento getMementoState()
    {
        return Memento(content);
    }

    void restore(Memento memento)
    {
        content = memento.getState();
    }
};

class MementoSaver
{
private:
    vector<Memento> savedStates;

public:
    void saveState(Memento memento)
    {
        savedStates.push_back(memento);
    }

    Memento getState(int index)
    {
        if (index >= 0 && index < savedStates.size())
        {
            return savedStates[index];
        }
        return Memento("");
    }
};

int main()
{
    TextEditor editor;
    MementoSaver mementoSaver;

    editor.write("Hello, ");
    mementoSaver.saveState(editor.getMementoState()); 

    editor.write("World!");
    mementoSaver.saveState(editor.getMementoState());

    editor.write(" Adding more text.");

    cout << "Current : " << editor.getContent() << endl;

    editor.restore(mementoSaver.getState(0));
    cout << "Restored : " << editor.getContent() << endl;

    editor.restore(mementoSaver.getState(1));
    cout << "Restored : " << editor.getContent() << endl;

    return 0;
}
