#include <iostream>

using namespace std;

class Base{
public:
    Base() = default;
    virtual void print_net(int num = 10) const {
        cout << "Base:" << endl;
        cout << num << endl;
    }
    virtual ~Base() {}
};

class Drived : public Base{
public:
    void print_net(int num = 20) const override {
        print_net();
    }
};
void print_test(const Base& base) {
    base.print_net();
}
int main() {
    Drived drived;
    print_test(drived);
    return 0;
}