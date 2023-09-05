#ifndef sales_data_h
#define sales_data_h
#include <iostream>
#include <string>
using namespace std;

class Sales_data{
    friend istream& operator>>(istream&, Sales_data&);
    friend ostream& operator<<(ostream&, const Sales_data&);
    friend Sales_data operator+(Sales_data& lhs, Sales_data& rhs);
public:
    Sales_data() : book_no(""), units_sold(0), revenue(0) {}
    Sales_data(const string& book_no_,unsigned units_sold_, double revenue_):
               book_no(book_no_),units_sold(units_sold_),revenue(revenue_){}

    Sales_data(const string& book_no_):book_no(book_no_){}

    string isbn() const {
        return book_no;
    }
    Sales_data& operator+=(Sales_data& rhs);
private:
    inline double avg_price() const;
    string book_no;
    unsigned units_sold = 0;
    double revenue = 0;
};
#endif