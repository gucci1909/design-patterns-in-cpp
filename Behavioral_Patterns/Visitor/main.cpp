#include <iostream>
#include <string>
using namespace std;

class ShapeVisitor
{
public:
    virtual void visit(class Circle &circle) = 0;
    virtual void visit(class Rectangle &rectangle) = 0;
};

class Shape
{
public:
    virtual void accept(ShapeVisitor &visitor) = 0;
};

class Circle : public Shape
{
public:
    void accept(ShapeVisitor &visitor) override
    {
        visitor.visit(*this);
    }
    void draw()
    {
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape
{
public:
    void accept(ShapeVisitor &visitor) override
    {
        visitor.visit(*this);
    }
    void draw()
    {
        cout << "Drawing Rectangle" << endl;
    }
};

class DrawVisitor : public ShapeVisitor
{
public:
    void visit(Circle &circle) override
    {
        circle.draw();
    }

    void visit(Rectangle &rectangle) override
    {
        rectangle.draw();
    }
};

int main()
{
    Circle circle;
    Rectangle rectangle;

    DrawVisitor drawVisitor;

    circle.accept(drawVisitor);
    rectangle.accept(drawVisitor);

    return 0;
}
