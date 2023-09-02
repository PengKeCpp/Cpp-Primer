#include "limit_quote.h"

double Limit_Quote::net_price(size_t cnt) const {
    if (cnt <= max_limit) {
        return cnt * price * (1 - discount);
    }
    return (cnt - max_limit) * price + max_limit * price * (1 - discount);
}

void Limit_Quote::debug() const {
    Quote::debug();
    cout << "max_limit: " << max_limit << " "
         << "discount: " << discount << endl;
}