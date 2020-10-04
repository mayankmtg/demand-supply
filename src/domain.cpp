#include "domain.h"

void domain::compute_transactions_greedily(std::vector<order> &demand, std::vector<order> &supply, std::vector<Transaction>& transactions) {
    std::sort(demand.begin(), demand.end(), compare_orders_desc);
    std::sort(supply.begin(), supply.end(), compare_orders_asc);
    for (int i = 0;i<demand.size();i++) {
        for (int j = 0;j<supply.size();j++){
            if (demand[i].price < supply[j].price) {
                break;
            }
            if (supply[j].quantity == 0) {
                continue;
            }
            Transaction transaction = Transaction(&demand[i], &supply[j]);
            transactions.push_back(transaction);
            if (demand[i].quantity == 0) {
                break;
            }
        }
    }
}
