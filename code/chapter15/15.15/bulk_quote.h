#ifndef bulk_quote_h
#define bulk_quote_h
#include "disc_quote.h"

class Bulk_quote : public Disc_quote {
   public:
    Bulk_quote() = default;
    Bulk_quote(const string& bookNo_, double price_, size_t min_qty_, double discount_):
                Disc_quote(bookNo_, price_,min_qty_,discount_) {}

    double net_price(size_t cnt) const override {
        return cnt * price * (cnt >= quantity ? (1 - discount) : 1);
    }
    void debug() const override;

};

#endif