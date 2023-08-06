#include <iostream>
#include "thread"
#include "mutex"
#include "random"

std::mutex m;

std::vector<int>orders;
std::vector<std::string>dishes;
int numOfDeliveries=0;
int numOfOrdersToDeliver=0;
int iter=0;
int totalOrders=0;


void courierDelivery()
{
    srand(time(nullptr));
        while (numOfDeliveries < 10)
        {
            if (!dishes.empty())
            {
                int t = 30;
                std::this_thread::sleep_for(std::chrono::seconds(t));

                std::string dish;
                m.lock();
                if (!dishes.empty()) {
                    for (int i = 0; i < dishes.size(); i++) {
                        numOfOrdersToDeliver++;
                    }
                }
                numOfDeliveries++;
                std::cout << "Delivery message: " << numOfOrdersToDeliver << " orders is delivered." << std::endl;
                std::cout << "Delivery message: this is " << numOfDeliveries << " success delivery." << std::endl;
                std::cout << std::endl;
                dishes.clear();
                m.unlock();
            }
        }
}

void kitchenRoom()
{
    srand(time(nullptr));
        while(numOfDeliveries<10)
        {
            if(!orders.empty())
            {
                int t = rand() % 15 + 5;
//                int t = 1;
                std::this_thread::sleep_for(std::chrono::seconds(t));
                int order = 0;
                m.lock();
                if (!orders.empty())
                    order = orders[iter];
                iter++;
                m.unlock();
                std::string dish;
                if (order == 1) dish = "pizza";
                else if (order == 2) dish = "soup";
                else if (order == 3) dish = "steak";
                else if (order == 4) dish = "salad";
                else if (order == 5) dish = "sushi";

                m.lock();
                dishes.push_back(dish);
                if (dish != "")
                    std::cout << "Kitchen message: order num " << iter << " (" << dish << ") is cocked" << std::endl;
                std::cout << "Kitchen message: " << dishes.size() << " orders is given to delivery" << std::endl;
                std::cout << std::endl;
                m.unlock();
            }
        }
}

void orderGenerator()
{
    srand(time(nullptr));
    while(numOfDeliveries<10)
    {
        int t = rand()%10+5;
//        int t = 1;
        std::this_thread::sleep_for(std::chrono::seconds(t));
        int dish = rand()%5+1;
        m.lock();
        std::cout << "Order number " << ++totalOrders << " is booked online." << std::endl;
        std::string dish_name;
        if (dish == 1) dish_name = "pizza";
        else if (dish == 2) dish_name = "soup";
        else if (dish == 3) dish_name = "steak";
        else if (dish == 4) dish_name = "salad";
        else if (dish == 5) dish_name = "sushi";
        std::cout << "This is " << dish_name << std::endl;
        std::cout << std::endl;
        orders.push_back(dish);
        m.unlock();
    }
}



int main() {
    std::cout << "Task 3" << std::endl;

    srand(time(nullptr));

    std::thread Orders(orderGenerator);
    std::thread Kitchen(kitchenRoom);
    std::thread Courier(courierDelivery);

    Orders.join();
    Kitchen.join();
    Courier.join();

    return 0;
}
