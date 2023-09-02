#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"

double print_total(ostream& os, const Quote& item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
       << " # sold：" << n << " total due: " << ret << endl;
    return ret;
}

void print_debug(const Quote& quote) {
    quote.debug();
}

int main() {
    Quote quote("quote", 5);
    Bulk_quote bq("bulk_quote", 10, 10, 0.2);
    Limit_Quote lq("Limit_Quote", 15, 20, 0.4);
    cout << print_total(std::cout, quote, 13) << endl;
    cout << print_total(std::cout, bq, 13) << endl;
    cout << print_total(std::cout, lq, 13) << endl;
    // not dynamic,疑惑,等看一下对象模型,看看原理再说
    Quote& q1 = quote;
    q1.debug();
    cout << endl;
    q1 = bq;
    q1.debug();
    cout << endl;
    q1 = lq;
    q1.debug();
    cout << endl;
    //dynamic bidding
    print_debug(quote);
    cout << endl;
    print_debug(bq);
    print_debug(lq);
    
    return 0;
}