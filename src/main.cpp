#include "main.h"

void process_input(const std::string& str){
    std::vector<std::string> input = split(str, " ");
    if (input.size() != 5) {
        // Not raising input errors
        return;
    }
    std::string order_id = input[0];
    remove_substr(input[3], "/kg");
    remove_substr(input[4], "kg");
    if (order_id[0] == 's') {
        supply.push_back(order(input));
    }
    else {
        demand.push_back(order(input));
    }
}

int main() {
    std::string str;
    while (true) {
        std::getline (std::cin, str);
        if (str.length() == 0) break;
        process_input(str);
    }
    domain::compute_transactions_greedily(demand, supply, transactions);
    for (int i=0; i<transactions.size(); i++) {
        std::cout << transactions[i].get_string() << std::endl;
    }
    return 0;
}