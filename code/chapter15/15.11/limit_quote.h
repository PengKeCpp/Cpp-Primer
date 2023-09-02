#ifndef limit_quote_h
#define limit_quote_h
#include "quote.h"

class Limit_Quote : public Quote {
   public:
    Limit_Quote() = default;
    Limit_Quote(const string& bookNo_, double price_, size_t max_limit_, double discount_)
        : Quote(bookNo_, price_), max_limit(max_limit_), discount(discount_) {}
    double net_price(size_t cnt) const override;
    void debug() const override ;
   private:
    size_t max_limit;
    double discount;
};

#endif