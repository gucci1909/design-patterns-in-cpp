#include <iostream>
#include <string>
#include <vector>
using namespace std;

// The Mediator acts as a central controller that simplifies communication between multiple objects (or participants).
// Instead of objects talking to each other directly, they communicate through the mediator.

class ChatRoom
{
public:
    virtual void showMessage(string user, string message)
    {
        cout << user << " " << message << endl;
    }
};

class User
{
private:
    string name;
    ChatRoom *chatRoom;

public:
    User(string name, ChatRoom *chatRoom) : name(name), chatRoom(chatRoom) {}

    void sendMessage(string message)
    {
        chatRoom->showMessage(name, message);
    }
};

int main()
{
    ChatRoom chatRoom;

    User user1("Suresh", &chatRoom);
    User user2("Mahesh", &chatRoom);
    User user3("Vikram", &chatRoom);

    cout << "Chatroom Msges: " << endl;
    user1.sendMessage("Hello, everyone!");
    user2.sendMessage("Hi Suresh!");
    user3.sendMessage("Hey Alice and Bob!");

    return 0;
}
