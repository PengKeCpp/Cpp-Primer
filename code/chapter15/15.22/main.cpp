#include <iostream>
#include <string>
using namespace std;

class Shape{
public:
    using Coordinate = pair<double, double>;
    Shape() = default;
    Shape(const string& _name):name(_name){}
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual ~Shape() = default;
protected:
    string name;
};

class Rectangle : public Shape{
public:
    Rectangle(const string& _name,Coordinate& _a,
              Coordinate& _b, Coordinate& _c,
              Coordinate& _d):Shape(_name),a(_a),b(_b),c(_c),d(_d) {}
    double area() const override {
        return (b.first-a.first) * (c.second-a.second);
    }
    double perimeter() const override {
        return 2*(b.first-a.first+c.second-a.second); 
    }
    virtual ~Rectangle() = default;
protected:
    Coordinate a,b,c,d;
};

int main() {
    return 0;
}