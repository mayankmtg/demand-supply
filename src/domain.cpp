#include "domain.h"

std::vector<order*> domain::possible_suppliers(order &demand, std::vector<order> &supply) {
    std::vector<order*> suppliers;
    for (int i = 0; i < supply.size(); i++) {
        if (demand.price < supply[i].price) {
            break;
        }
        if (supply[i].produce == demand.produce && supply[i].quantity != 0) {
            suppliers.push_back(&supply[i]);
        }
    }
    return suppliers;
}


void domain::compute_transactions_greedily(std::vector<order> &demand, std::vector<order> &supply, std::vector<Transaction>& transactions) {
    std::sort(demand.begin(), demand.end(), compare_orders_desc);
    std::sort(supply.begin(), supply.end(), compare_orders_asc);
    for (int i = 0;i<demand.size();i++) {
        std::vector<order*> suppliers = possible_suppliers(demand[i], supply);
        for (int j = 0;j<suppliers.size();j++){
            Transaction transaction = Transaction(&demand[i], suppliers[j]);
            transactions.push_back(transaction);
            if (demand[i].quantity == 0) {
                break;
            }
        }
    }
}
