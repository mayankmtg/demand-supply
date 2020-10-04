#ifndef DOMAIN_H
#define DOMAIN_H
#include <algorithm>
#include <vector>

#include "order.h"
#include "transaction.h"

struct domain {
    private:
        static std::vector<order*> possible_suppliers(order &demand, std::vector<order> &supply);
    public:
        static void compute_transactions_greedily(std::vector<order> &demand, std::vector<order> &supply, std::vector<Transaction>& transactions);
};

#endif