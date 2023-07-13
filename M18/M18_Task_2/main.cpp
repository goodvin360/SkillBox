#include <iostream>

using namespace std;

int jumps(int stairs, int maxJump =3)
{
    if (stairs == 0)
        return 1;

    int total_jumps=0;
    for (int i = 1; i <= min(maxJump, stairs); ++i)
        total_jumps += jumps(stairs - i, maxJump);

    return total_jumps;
}

int main() {
    cout << "Task 2" << endl;

    cout << jumps(3,2) << endl;

    return 0;
}
