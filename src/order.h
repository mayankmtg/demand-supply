#include <vector>
#include <string>
#include <ctime>

struct order
{
    public:
        static std::tm process_time(std::string time_string);
        order(std::vector<std::string> input);
        std::string id;
        std::tm time;
        std::string produce;
        int price;
        int quantity;
};
