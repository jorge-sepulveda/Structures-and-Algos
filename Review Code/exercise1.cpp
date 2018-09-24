#include <iostream>
using namespace std;

//USE: g++ -std=c++11 filename.cpp -o filename.out

struct Point{
    int xCord;
    int yCord;
    
    Point(int x, int y){
        xCord = x;
        yCord = y;
    }
    Point(){
        xCord = 0;
        yCord = 0;
    }
    
    Point& operator=(const Point& p){
        xCord = p.xCord;
        yCord = p.yCord;
    }
    
    
};

class Shape{
    protected:
    Point location;
    public:
    Shape(Point l) : location(l) {}
    virtual void Print()=0;
};

class Circle : public Shape{
    float radius;
    public:
        Circle(Point p, float r) : Shape(p), radius(r) {}
        
        void Print() { cout << "Circle with radius " << radius << " at location (" << location.xCord << ", " << location.yCord << ")" << endl;}
};

class Square : public Shape{
    float sideLength;
    public:
        Square(Point p, float s) : Shape(p), sideLength(s) {}
        
        void Print() {
            cout << "Square with side length of " << sideLength << " at location (" << location.xCord << ", " << location.yCord << ")" << endl;
        }
};



int main() {
    
    Point p1(4,10);
    Point p2(5,25);
    
    Circle c1(p2, 6.5);
    c1.Print();
    
    Square s1(p1,3.5);
    s1.Print();
    
    
    //Shape s1;
    //s1.Print();
    
    //cout << "Hello World!hi" << endl;
    //cout << p1.xCord << endl;
    //cout << p1.yCord << endl;
    
}
