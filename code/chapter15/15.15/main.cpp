#include <iostream>
#include <string>
#include "quote.h"
#include "disc_quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"


int main() {
    //error: cannot declare variable ‘disc_quote’ to be of abstract type ‘Disc_quote’
    Disc_quote disc_quote;
    return 0;
}