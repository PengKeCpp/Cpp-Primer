#ifndef disc_quote_h
#define disc_quote_h
#include "quote.h"

class Disc_quote: public Quote{
public:
    Disc_quote() = default;
    Disc_quote(const string& book, double price, size_t qty, double disc):
              Quote(book, price),quantity(qty),discount(disc){}
    double net_price(size_t cnt) const = 0;
    Disc_quote(const Disc_quote& quote) : Quote(quote),quantity(quote.quantity), discount(quote.discount) {}
    Disc_quote& operator=(const Disc_quote& quote) {
        if (this != &quote) {
            Quote::operator=(quote);
            quantity = quote.quantity;
            discount = quote.discount;
        }
        return *this;
    }
    Disc_quote(Disc_quote&& quote) noexcept
        : Quote(std::move(quote)), quantity(std::move(quote.quantity)), discount(std::move(quote.discount)) {}
    
    Disc_quote& operator=(Disc_quote&& quote) noexcept {
        if (this != &quote) {
            Quote::operator=(std::move(quote));
            quantity = std::move(quote.quantity);
            discount = std::move(quote.discount);
        }
        return *this;
    }
protected:
    size_t quantity = 0;    //折扣使用的购买量
    double discount = 0.0;  //表示折扣的小数量
};

#endif