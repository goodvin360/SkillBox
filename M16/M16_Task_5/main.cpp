#include <iostream>
#include "sstream"

using namespace std;

int main() {
    cout << "Smart Home" << endl;

    enum switches{
        LIGHTS_INSIDE = 1,
        LIGHTS_OUTSIDE = 2,
        HEATERS = 4,
        WATER_PIPE_HEATING = 8,
        CONDITIONER = 16
    };

    string inp;
    int temp_in=0, temp_out=0, colorTemp=5000;
    string movement, lights;
    int switches_state=0;

    for (int k=0; k<2; k++) {
        for (int i = 0; i < 24; i++) {
            cout << "This is day number " << k+1 << endl;
            if (i < 10) cout << "Time is: 0" << i << ":00" << endl;
            if (i > 9) cout << "Time is: " << i << ":00" << endl;
            cout << "Temperature inside, temperature outside, movement, lights:" << endl;
            cin.clear();
            getline(cin, inp);
            stringstream buffer_string(inp);
            buffer_string >> temp_in >> temp_out >> movement >> lights;

            if (temp_in < 22) switches_state |= HEATERS;
            else if (temp_in >= 25) switches_state &= ~HEATERS;
            if (temp_in >= 30) switches_state |= CONDITIONER;
            else if (temp_in <= 25) switches_state &= ~CONDITIONER;
            if (temp_out < 0) switches_state |= WATER_PIPE_HEATING;
            else if (temp_out > 5) switches_state &= ~WATER_PIPE_HEATING;
            if (i > 16 && i <= 23 || i < 5 && movement == "yes") switches_state |= LIGHTS_OUTSIDE;
            else if (i <= 16 && i >= 5 || movement == "no") switches_state &= ~LIGHTS_OUTSIDE;
            if (lights == "on" && i >= 16 && i <= 20) {
                switches_state |= LIGHTS_INSIDE;
                colorTemp = 5000 - ((5000 - 2700) * (i - 15) / 5);
            } else if (lights == "on" && (i < 16 || i > 20 && i <= 23)) {
                switches_state |= LIGHTS_INSIDE;
                colorTemp = 5000;
            } else if (lights == "off") switches_state &= ~LIGHTS_INSIDE;

            cout << "Current states:" << endl;
            cout << "LIGHTS_INSIDE";
            if (switches_state & LIGHTS_INSIDE) cout << " ON, color " << colorTemp << "K" << endl;
            else cout << " OFF" << endl;
            cout << "LIGHTS_OUTSIDE";
            if (switches_state & LIGHTS_OUTSIDE) cout << " ON" << endl;
            else cout << " OFF" << endl;
            cout << "HEATERS";
            if (switches_state & HEATERS) cout << " ON" << endl;
            else cout << " OFF" << endl;
            cout << "WATER_PIPE_HEATING";
            if (switches_state & WATER_PIPE_HEATING) cout << " ON" << endl;
            else cout << " OFF" << endl;
            cout << "CONDITIONER";
            if (switches_state & CONDITIONER) cout << " ON" << endl;
            else cout << " OFF" << endl;
            cout << endl;
        }
    }

    return 0;
}
