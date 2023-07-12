#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Speedometer" << endl;
    float speed = 0.0;
    float delta = 0.0;
    char speed_str[255];
    do
    {
     cout << "Speed delta:";
     cin >> delta;
     speed+=delta;
     while (speed<0||speed>150)
     {
        speed-=delta;
        sprintf(speed_str, "%.1f", speed);
        cout << "Speed: " << speed_str << endl;
        cout << "Enter another value of delta" << endl;
        cout << "Speed delta:";
        cin >> delta;
        speed+=delta;
     }

     sprintf(speed_str, "%.1f", speed);
     cout << "Speed: " << speed_str << endl;
    } while (speed!=0);

    return 0;
}
