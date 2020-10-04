#include "order.h"
#include <sstream>

order::order(std::vector<std::string> input) {
    this->id = input[0];
    this->time = process_time(input[1]);
    this->produce = input[2];
    this->price = stoi(input[3]);
    this->quantity = stoi(input[4]);
}

time_t order::process_time(std::string time_string) {
    std::tm time_obj;
    strptime(time_string.c_str(), "%H:%M", &time_obj);
    return mktime(&time_obj);
}

bool compare_orders_desc(order o1, order o2) {
    if (o1.price == o2.price) {
        return o1.time < o2.time;
    }
    return (o1.price > o2.price);
}

bool compare_orders_asc(order o1, order o2) {
    if (o1.price == o2.price) {
        return o1.time < o2.time;
    }
    return (o1.price < o2.price);
}
