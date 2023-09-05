#include "Sales_data.h"

istream& operator>>(istream& is, Sales_data& items){
    double price;
    is >> items.book_no >> items.units_sold >> price;
    if (is) {
        items.revenue = items.units_sold * price;
    } else {
        items = Sales_data();
    }
    return is;
}

ostream& operator<<(ostream& os, const Sales_data& hs){
    os << "book_no: " << hs.book_no << " "
       << "units_sold: " << hs.units_sold << " "
       << "revenue: " << hs.revenue << " " << endl;
    return os;
}

Sales_data operator+(Sales_data& lhs, Sales_data& rhs){
    Sales_data item = lhs;
    item += rhs;
    return item;
}

Sales_data& Sales_data::operator+=(Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

inline
double Sales_data::avg_price() const {
    return units_sold ? revenue / units_sold : 0;
}