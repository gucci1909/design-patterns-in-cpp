#include <iostream>
#include <string>
using namespace std;

// Proxy design pattern is used as a placeholder for another object to control access to it.
// or you can say proxy don't let the user to access the object directly.
// it prevents the user to access the object directly.
// the user will deal with the proxy object instead of the real object.

class RealDatabase
{
public:
    void getData()
    {
        cout << "Fetching data from the real database" << endl;
    }
};

class ProxyDatabase
{
private:
    RealDatabase realDatabase;

public:
    void getData()
    {
        string user;
        cout << "Enter username: ";
        cin >> user;

        if (user == "admin")
        {
            cout << "Access granted." << endl;
            realDatabase.getData();
        }
        else
        {
            cout << "Access denied!" << endl;
        }
    }
};

int main()
{
    ProxyDatabase proxyDatabase;

    cout << "Client trying to access the database!" << endl;
    proxyDatabase.getData();

    return 0;
}
