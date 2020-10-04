#ifndef DOMAIN_H
#define DOMAIN_H
#include <algorithm>
#include <vector>

#include "order.h"
#include "transaction.h"

struct domain {
    public:
        static void max_profit_greedy(std::vector<order> &demand, std::vector<order> &supply, std::vector<Transaction>& transactions);
};

#endif