#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
struct Order {
    string customerID;
    string productID;
    int price;
    string shopID;
    string timePoint;
};
int timeToSeconds(const string &time) {
    int hh, mm, ss;
    sscanf(time.c_str(), "%d:%d:%d", &hh, &mm, &ss);
    return hh * 3600 + mm * 60 + ss;
}
int main() {
    vector<Order> orders; 
    string line;
    map<string, long long> shopRevenue;                
    map<string, map<string, long long>> customerShop; 
    long long totalRevenue = 0;                        
    int totalOrders = 0;                               
    while (getline(cin, line) && line != "#") {
        Order order;
        size_t pos = 0;
        order.customerID = line.substr(0, line.find(' ', pos));
        pos = line.find(' ', pos) + 1;

        order.productID = line.substr(pos, line.find(' ', pos) - pos);
        pos = line.find(' ', pos) + 1;

        order.price = stoi(line.substr(pos, line.find(' ', pos) - pos));
        pos = line.find(' ', pos) + 1;

        order.shopID = line.substr(pos, line.find(' ', pos) - pos);
        pos = line.find(' ', pos) + 1;

        order.timePoint = line.substr(pos);
        orders.push_back(order);
        totalOrders++;
        totalRevenue += order.price;
        shopRevenue[order.shopID] += order.price;
        customerShop[order.customerID][order.shopID] += order.price;
    }
    while (getline(cin, line) && line != "#") {
        if (line == "?total_number_orders") {
            cout << totalOrders << endl;

        } else if (line == "?total_revenue") {
            cout << totalRevenue << endl;

        } else if (line.substr(0, 18) == "?revenue_of_shop") {
            string shopID = line.substr(19);
            cout << shopRevenue[shopID] << endl;

        } else if (line.substr(0, 31) == "?total_consume_of_customer_shop") {
            size_t pos = line.find(' ', 32);
            string customerID = line.substr(32, pos - 32);
            string shopID = line.substr(pos + 1);
            cout << customerShop[customerID][shopID] << endl;

        } else if (line.substr(0, 24) == "?total_revenue_in_period") {
            size_t pos = line.find(' ', 25);
            string fromTime = line.substr(25, pos - 25);
            string toTime = line.substr(pos + 1);
            int start = timeToSeconds(fromTime);
            int end = timeToSeconds(toTime);

            long long revenueInPeriod = 0;
            for (const auto &order : orders) {
                int orderTime = timeToSeconds(order.timePoint);
                if (orderTime >= start && orderTime <= end) {
                    revenueInPeriod += order.price;
                }
            }
            cout << revenueInPeriod << endl;
        }
    }

    return 0;
}
