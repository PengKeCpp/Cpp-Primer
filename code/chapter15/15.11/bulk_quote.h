#ifndef bulk_quote_h
#define bulk_quote_h
#include "quote.h"

class Bulk_quote : public Quote {
   public:
    Bulk_quote() = default;
    Bulk_quote(const string& bookNo_, double price_, size_t min_qty_, double discount_):
                Quote(bookNo_, price_), min_qty(min_qty_),discount(discount_) {}

    double net_price(size_t cnt) const override {
        return cnt * price * (cnt >= min_qty ? (1 - discount) : 1);
    }
    void debug() const override;
   private:
    size_t min_qty;
    double discount;
};

#endif