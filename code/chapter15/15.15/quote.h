#ifndef quote_h_
#define quote_h_

#include <iostream>
#include <string>

using namespace std;

class Quote {
   public:
    Quote() = default;
    Quote(const string& bookNo_, double price_) : bookNo(bookNo_), price(price_) {
        cout << "Quote(const string& bookNo_, double price_)" << endl;
    }
    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
    virtual ~Quote() = default;
    virtual void debug() const;
   private:
    string bookNo;

   protected:
    double price = 0;
};

#endif