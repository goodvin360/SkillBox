#include <iostream>

#define TMP(name) #name
#define PRINT(name) std::cout << TMP(name)


int main() {
    std::cout << "Task 1" << std::endl;

    int num;

    std::cout << "Enter day number: 1 - monday, 2 - tuesday, 3 - wednesday, 4 - thursday, 5 - friday, 6 - saturday, 7 - sunday" << std::endl;
    std::cin >> num;

    if (num==1) PRINT(MONDAY);
    else if (num==2) PRINT(TUESDAY);
    else if (num==3) PRINT(WEDNESDAY);
    else if (num==4) PRINT(THURSDAY);
    else if (num==5) PRINT(FRIDAY);
    else if (num==6) PRINT(SATURDAY);
    else if (num==7) PRINT(SUNDAY);

    return 0;
}