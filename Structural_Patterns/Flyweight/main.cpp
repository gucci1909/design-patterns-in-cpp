#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// here I have created a DodgeBall game, and every ball have same properties color and image.
// so we can use the flyweight pattern here.
// instead of making every time a new ball, we can use the same ball if it is already created.
// I am using a map and checking if the ball is already created or not.
// in the ball Factory, where we are taking the ball color and image, is the basic factory pattern, so here you can see flyweight always implemented with factory pattern.

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
};

class BallFactory
{
private:
    unordered_map<string, DodgeBall *> ballMap;

public:
    DodgeBall *getBall(string color, string image)
    {
        string key = color + "-" + image;

        if (ballMap.find(key) == ballMap.end())
        {
            ballMap[key] = new DodgeBall(color, image);
            cout << "Creating a new ball with color: " << color << " and image: " << image << endl;
        }

        return ballMap[key];
    }
};

class Player
{
private:
    DodgeBall *ball;

public:
    void setBall(DodgeBall *b)
    {
        ball = b;
    }

    void showBallDetails(string name)
    {
        cout << name << endl;
        ball->display();
    }
};

int main()
{
    BallFactory ballFactory;

    DodgeBall *Ball_1 = ballFactory.getBall("Red", "BallImage1");

    Player amit;
    amit.setBall(Ball_1);
    amit.showBallDetails("amit");

    cout << endl;

    DodgeBall *Ball_2 = ballFactory.getBall("Blue", "BallImage2");

    Player suresh;
    suresh.setBall(Ball_2);
    suresh.showBallDetails("suresh");

    DodgeBall *ResUse_Ball_1 = ballFactory.getBall("Red", "BallImage1");

    cout << endl;

    Player harry;
    harry.setBall(ResUse_Ball_1);
    harry.showBallDetails("harry");

    return 0;
}
