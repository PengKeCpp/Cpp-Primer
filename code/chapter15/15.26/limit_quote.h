#ifndef limit_quote_h
#define limit_quote_h
#include "disc_quote.h"

class Limit_Quote : public Disc_quote {
   public:
    Limit_Quote() = default;
    Limit_Quote(const string& bookNo_, double price_, size_t max_limit_, double discount_)
        : Disc_quote(bookNo_, price_, max_limit_, discount_){}
    double net_price(size_t cnt) const override;
    void debug() const override ;
};

#endif