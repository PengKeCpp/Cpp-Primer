#include "quote.h"

void Quote::debug() const {
    cout << "data member of this class: \n"
         << "bookNo: " << this->bookNo << " "
         << "price: " << this->price << " ";
}