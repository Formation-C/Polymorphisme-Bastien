#include <iostream>

using namespace std;

class Shape
{
public:

    int angles;
    int width;
    int height;

    Shape( int _angles,
           int _width,
           int _height
           ):  angles(_angles), width(_width), height(_height)
           {
                cout << "calling shape constructor" << endl;
           }

    virtual ~Shape()
           {
               cout << "calling shape destructor" << endl;
           }

    virtual int getArea() = 0;


};


class Triangle : public Shape
{
public:
    Triangle (int _width, int _height): Shape(3, _width, _height)
    {
        cout << "calling Triangle constructor" << endl;
    }

    ~Triangle()
       {
           cout << "calling Triangle destructor" << endl;
       }

    int getArea()
    {
        return (width * height)/2;
    }
};

class Rectangle : public Shape
{
public:
    Rectangle (int _width, int _height): Shape(4, _width, _height)
    {
        cout << "calling Rectangle constructor" << endl;
    }

    ~Rectangle()
    {
        cout << "calling Rectangle destructor" << endl;
    }

    int getArea()
    {
        return (width * height);
    }
};



void displayArea(Shape& shape){
    cout << shape.getArea() << endl;
}

int main()
{
    cout << "Hello world!" << endl;


    Triangle triangle(10, 5);
    Rectangle rectangle(10, 5);

 //   cout << triangle.getArea() << endl;
 //   cout << rectangle.getArea() << endl;

    displayArea(triangle);
    displayArea(rectangle);

    delete &triangle;
    delete &rectangle;

    return 0;
}
