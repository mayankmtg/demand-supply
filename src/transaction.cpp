#include "transaction.h"


Transaction::Transaction(order* demand_order, order* supply_order) {
    this->demand_order = demand_order;
    this->supply_order = supply_order;
    this->quantity = std::min(demand_order->quantity, supply_order->quantity);
    this->profit = this->quantity * (demand_order->price - supply_order->price);
    demand_order->quantity -= this->quantity;
    supply_order->quantity -= this->quantity;
}

std::string Transaction::get_string() {
    std::string return_string = "";
    return_string += this->demand_order->id + " ";
    return_string += this->supply_order->id + " ";
    return_string += std::to_string(this->supply_order->price) + " ";
    return_string += std::to_string(this->quantity);
    return return_string;
}