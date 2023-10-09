
#include "minafunktioner.h"
#include <iostream>
#include <algorithm>

bool boolFranAnvandare(const std::string &txt) {
    char svar;
    do
    {
        std::cout << "Vill du spela? (j/n): ";
        std::cin >> svar;
    } while (svar != 'j' && svar != 'n');
    return svar == 'j';

}
