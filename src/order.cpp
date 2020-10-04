#include "order.h"
#include <sstream>

std::tm order::process_time(std::string time_string) {
    std::tm time_obj;
    strptime(time_string.c_str(), "%H:%M", &time_obj);
    return time_obj;

}

order::order(std::vector<std::string> input) {
    this->id = input[0];
    this->time = process_time(input[1]);
    this->produce = input[2];
    this->price = stoi(input[3]);
    this->quantity = stoi(input[4]);
}
