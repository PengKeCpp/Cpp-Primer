#include <iostream>
#include <string>

using namespace std;

class Quote {
   public:
    Quote() = default;
    Quote(const string& bookNo_, double price_) : bookNo(bookNo_), price(price_) {
        cout << "Quote(const string& bookNo_, double price_)" << endl;
    }
    string isbn() const { return bookNo; }
    virtual Quote& operator=(const Quote& quote) { 
        cout << "Quote" << endl;
        return *this;
    }
    virtual double net_price(size_t n) const { return n * price; }
    virtual ~Quote() = default;

   private:
    string bookNo;

   protected:
    double price = 0;
};

class Bulk_quote : public Quote {
   public:
    Bulk_quote() = default;
    Bulk_quote(const string& bookNo_, double price_, size_t min_qty_, double discount_);
    double net_price(size_t n) const override;
    Bulk_quote& operator=(const Quote& quote) override { 
        cout << "Bulk_quote" << endl;
        return *this;
    }
   private:
    size_t min_qty;
    double discount;
};
Bulk_quote::Bulk_quote(const string& bookNo_, double price_, size_t min_qty_, double discount_)
    : Quote(bookNo_, price_), min_qty(min_qty_), discount(discount_) {}

double Bulk_quote::net_price(size_t cnt) const {
    if (cnt >= min_qty) {
        return cnt * price * (1 - discount);
    } else {
        return cnt * price;
    }
}

class Limit_Quote : public Quote {
   public:
    Limit_Quote() = default;
    Limit_Quote(const string& bookNo_, double price_, size_t max_limit_, double discount_)
        : Quote(bookNo_, price_), max_limit(max_limit_), discount(discount_) {}
    double net_price(size_t cnt) const override;

   private:
    size_t max_limit;
    double discount;
};

double Limit_Quote::net_price(size_t cnt) const {
    if (cnt <= max_limit) {
        return cnt * price * (1 - discount);
    }
    return (cnt - max_limit) * price + max_limit * price * (1 - discount);
}

double print_total(ostream& os, const Quote& item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
       << " # sold：" << n << " total due: " << ret << endl;
    return ret;
}


int main() {
    Quote quote("quote", 5);
    Bulk_quote bq("bulk_quote", 5, 10, 0.2);
    Limit_Quote lq("Limit_Quote", 5, 10, 0.2);
    cout << print_total(std::cout, quote, 13) << endl;
    cout << print_total(std::cout, bq, 13) << endl;
    cout << print_total(std::cout, lq, 13) << endl;
    Quote *q1 = new Quote("quote", 6);
    Quote item(bq);
    cout << item.isbn() << endl;
    //item = bq;
    return 0;
}