#include <iostream>
#include "cassert"

using namespace std;

float travelTime(float distance, float speed)
{
    assert(speed>0);
    float time = distance/speed;
    return time;
}

int main() {
    std::cout << "Assert using" << std::endl;
    float distance, speed;
    cout << "Enter distance (km)  and speed (km/h) values: " << endl;
    cin >> distance >> speed;
    float time = travelTime(distance, speed);
    cout << "Travel time is " <<  time << " hours" << endl;
    return 0;
}
