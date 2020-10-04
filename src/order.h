#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <string>
#include <ctime>
#include <time.h>

struct order
{
    public:
        static time_t process_time(std::string time_string);
        order(std::vector<std::string> input);
        std::string id;
        time_t time;
        std::string produce;
        int price;
        int quantity;
};

bool compare_orders_desc(order o1, order o2);
bool compare_orders_asc(order o1, order o2);

#endif