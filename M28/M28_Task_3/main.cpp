#include <iostream>
#include "thread"
#include "mutex"
#include "random"

using namespace std;

mutex m;

vector<int>orders;
vector<string>dishes;
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
                this_thread::sleep_for(chrono::seconds(t));

                string dish;
                m.lock();
                if (!dishes.empty()) {
                    for (int i = 0; i < dishes.size(); i++) {
                        numOfOrdersToDeliver++;
                    }
                }
                numOfDeliveries++;
                cout << "Delivery message: " << numOfOrdersToDeliver << " orders is delivered." << endl;
                cout << "Delivery message: this is " << numOfDeliveries << " success delivery." << endl;
                cout << endl;
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
                this_thread::sleep_for(chrono::seconds(t));
                int order = 0;
                m.lock();
                if (!orders.empty())
                    order = orders[iter];
                iter++;
                m.unlock();
                string dish;
                if (order == 1) dish = "pizza";
                else if (order == 2) dish = "soup";
                else if (order == 3) dish = "steak";
                else if (order == 4) dish = "salad";
                else if (order == 5) dish = "sushi";

                m.lock();
                dishes.push_back(dish);
                if (dish != "")
                    cout << "Kitchen message: order num " << iter << " (" << dish << ") is cocked" << endl;
                cout << "Kitchen message: " << dishes.size() << " orders is given to delivery" << endl;
                cout << endl;
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
        this_thread::sleep_for(chrono::seconds(t));
        int dish = rand()%5+1;
        m.lock();
        cout << "Order number " << ++totalOrders << " is booked online." << endl;
        string dish_name;
        if (dish == 1) dish_name = "pizza";
        else if (dish == 2) dish_name = "soup";
        else if (dish == 3) dish_name = "steak";
        else if (dish == 4) dish_name = "salad";
        else if (dish == 5) dish_name = "sushi";
        cout << "This is " << dish_name << endl;
        cout << endl;
        orders.push_back(dish);
        m.unlock();
    }
}



int main() {
    cout << "Task 3" << endl;

    srand(time(nullptr));

    thread Orders(orderGenerator);
    thread Kitchen(kitchenRoom);
    thread Courier(courierDelivery);

    Orders.join();
    Kitchen.join();
    Courier.join();

    return 0;
}
