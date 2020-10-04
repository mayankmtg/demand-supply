#include "domain.h"

void domain::max_profit_greedy(std::vector<order> &demand, std::vector<order> &supply, std::vector<Transaction>& transactions) {
    std::sort(demand.begin(), demand.end(), compare_orders_desc);
    std::sort(supply.begin(), supply.end(), compare_orders_asc);
    for (int i = 0;i<demand.size();i++) {
        int dq = demand[i].quantity;
        int dp = demand[i].price;

        for (int j = 0;j<supply.size();j++){
            int sq = supply[j].quantity;
            int sp = supply[j].price;
            if (dp < sp) {
                break;
            }
            if (sq == 0) {
                continue;
            }
            Transaction transaction = Transaction(&demand[i], &supply[j]);
            transactions.push_back(transaction);
            dq -= transaction.quantity;
            if (dq == 0) {
                break;
            }
        }
    }
}