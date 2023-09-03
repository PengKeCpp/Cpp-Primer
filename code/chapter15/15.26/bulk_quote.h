#ifndef bulk_quote_h
#define bulk_quote_h
#include "disc_quote.h"

class Bulk_quote : public Disc_quote {
   public:
    Bulk_quote() = default;
    Bulk_quote(const string& bookNo_, double price_, size_t min_qty_, double discount_):
                Disc_quote(bookNo_, price_,min_qty_,discount_) {}

    Bulk_quote(const Bulk_quote& bulk_quote):Disc_quote(bulk_quote){}
    
    Bulk_quote(Bulk_quote&& bulk_quote) noexcept:
               Disc_quote(std::move(bulk_quote)){}

    Bulk_quote& operator=(const Bulk_quote& bulk_quote) {
        if(this != &bulk_quote) {
            Disc_quote::operator=(bulk_quote);
        }
        return *this;
    }

    Bulk_quote& operator=(Bulk_quote&& bulk_quote) noexcept{
        if(this != &bulk_quote) {
            Disc_quote::operator=(std::move(bulk_quote));
        }
        return *this;
    }
    double net_price(size_t cnt) const override {
        return cnt * price * (cnt >= quantity ? (1 - discount) : 1);
    }
    void debug() const override;

};

#endif