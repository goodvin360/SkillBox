#include <iostream>


int jumps(int stairs, int maxJump =3)
{
    if (stairs == 0)
        return 1;

    int total_jumps=0;
    for (int i = 1; i <= std::min(maxJump, stairs); ++i)
        total_jumps += jumps(stairs - i, maxJump);

    return total_jumps;
}

int main() {
    std::cout << "Task 2" << std::endl;

    std::cout << jumps(3,2) << std::endl;

    return 0;
}
