#include <bits/stdc++.h>
#include <fstream>
#include "order.h"

using namespace std;
vector<order> supply;
vector<order> demand;

// TODO::refactor this
vector<string> split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

void process_input(const string& str){
    vector<string> input = split(str, " ");
    string order_id = input[0];
    if (order_id[0] == 's') {
        supply.push_back(order(input));
    }
    else {
        demand.push_back(order(input));
    }
}

int max_profit() {
    int profit = 0;
    for (int i=0; i<demand.size(); i++) {
        int dq = demand[i].quantity;
        int dp = demand[i].price;
        if (dq == 0){
            continue;
        }
        for (int j=0; j<supply.size(); j++) {
            int sq = supply[j].quantity;
            int sp = supply[j].price;
            if (sq == 0) {
                continue;
            }
            int tq = min(dq, sq);

            if (dp < sp) {
                continue;
            }

            demand[i].quantity -= tq;
            supply[j].quantity -= tq;

            int remaining_profit = max_profit();

            profit = max(profit, remaining_profit + tq * (dp-sp));

            demand[i].quantity += tq;
            supply[j].quantity += tq;
        }
    }
    return profit;
}

bool compare_orders_desc(order o1, order o2) { 
    return (o1.price > o2.price);
}

bool compare_orders_asc(order o1, order o2) {
    return (o1.price > o2.price);
}

int max_profit_greedy(){
    int profit = 0;
    sort(demand.begin(), demand.end(), compare_orders_desc);
    sort(supply.begin(), supply.end(), compare_orders_asc);
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
            int tq = min(dq, sq);
            profit += tq * (dp - sp);
            cout << demand[i].id << " " << demand[i].quantity << " " << supply[j].id << " " << supply[j].quantity << endl;
            demand[i].quantity -= tq;
            dq = demand[i].quantity;
            supply[j].quantity -= tq;
            if (demand[i].quantity == 0){
                break;
            }
        }
    }
    return profit;
}

int main() {
    string str;
    while (true) {
        getline (cin, str);
        // cout << str << endl;
        if (str.length() == 0) break;
        process_input(str);
    }
    // cout << demand.size() << endl;
    // cout << supply.size() << endl;
    cout << max_profit() << endl;
    // cout << max_profit_greedy() << endl;
    return 0;
}