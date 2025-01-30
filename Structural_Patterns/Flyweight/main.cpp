#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Ball
{
public:
    virtual void display() = 0;
};

class DodgeBall : public Ball
{
private:
    string color;
    string image;

public:
    DodgeBall(string c, string i) : color(c), image(i) {}

    void display() override
    {
        cout << "Dodge Ball - Color: " << color << ", Image: " << image << endl;
    }

    string getColor() { return color; }
    string getImage() { return image; }
};

// The Flyweight Factory ensures that we don't create duplicate balls with the same color and image.
class BallFactory
{
private:
    unordered_map<string, DodgeBall *> ballMap; // A map to store shared balls

public:
    // Method to get or create a ball based on its color and image
    DodgeBall *getBall(string color, string image)
    {
        string key = color + "-" + image;

        if (ballMap.find(key) == ballMap.end())
        {
            // If ball doesn't exist, create a new one and store it
            ballMap[key] = new DodgeBall(color, image);
            cout << "Creating a new ball with color: " << color << " and image: " << image << endl;
        }

        return ballMap[key];
    }
};

class Player
{
private:
    DodgeBall *ball; // Each player has a unique ball with properties like size

public:
    void setBall(DodgeBall *b)
    {
        ball = b;
    }

    void showBallDetails()
    {
        cout << "Player's Ball: ";
        ball->display();
    }
};

int main()
{
    BallFactory ballFactory;

    // Clients (players) requesting dodge balls with the same color and image
    DodgeBall *redBall = ballFactory.getBall("Red", "BallImage1");
    DodgeBall *blueBall = ballFactory.getBall("Blue", "BallImage2");
    DodgeBall *anotherRedBall = ballFactory.getBall("Red", "BallImage1"); // Reuse the same red ball

    // Creating players
    Player player1;
    player1.setBall(redBall);
    player1.showBallDetails();

    Player player2;
    player2.setBall(blueBall);
    player2.showBallDetails();

    Player player3;
    player3.setBall(anotherRedBall); // This will reuse the red ball from the factory
    player3.showBallDetails();

    return 0;
}
