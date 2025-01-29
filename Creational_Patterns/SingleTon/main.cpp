#include <iostream>
using namespace std;

class Database {
private:
    static Database* instance;

    Database() {}
public:
    static Database* getInstance() {
        if (!instance) {
            instance = new Database();
        }
        return instance;
    }

    void connect() {
        cout << "Connected to Database!" << endl;
    }
};

Database* Database::instance = nullptr;

int main() {
    Database* db = Database::getInstance();
    db->connect();
    return 0;
}
