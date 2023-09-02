#include "bulk_quote.h"

void Bulk_quote::debug() const {
    Quote::debug();
    cout << "min_qty: " << min_qty << " "
         << "discount: " << discount << endl;
}