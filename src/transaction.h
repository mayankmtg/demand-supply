#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "order.h"

struct Transaction{
    public:
        Transaction(order *demand_order, order *supply_order);

        order* demand_order;
        order* supply_order;
        int quantity;
        int profit;

        std::string get_string();
};

#endif