#ifndef disc_quote_h
#define disc_quote_h
#include "quote.h"

class Disc_quote: public Quote{
public:
    Disc_quote() = default;
    Disc_quote(const string& book, double price, size_t qty, double disc):
              Quote(book, price),quantity(qty),discount(disc){}
    double net_price(size_t cnt) const = 0;
protected:
    size_t quantity = 0;    //折扣使用的购买量
    double discount = 0.0;  //表示折扣的小数量
};

#endif