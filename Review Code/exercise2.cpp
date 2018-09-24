#include <iostream>
using namespace std;


class Point{
    int x;
    int y;
    public:
    
    Point(int x1, int y1){
        x = x1;
        y = y1;
    };
    
    Point(){
        x = 1;
        y = 1;
    };
    ~Point(){
        cout << "destructor called" << endl;
    };
    void Print(){
        cout << x << " " << y << endl;
    }
};


int main() {
    Point p1[10];
    
    /*for(int i = 0; i<10;i++){
        
    }*/
    
    
    Point *p2 = new Point[10];
    
    delete[] p2;
    //cout << "something" << endl;
    
    
    //Shape s1;
    //s1.Print();
    
    //cout << "Hello World!hi" << endl;
    //cout << p1.xCord << endl;
    //cout << p1.yCord << endl;
    
}
