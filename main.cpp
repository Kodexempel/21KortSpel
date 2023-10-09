#include <iostream>
#include <bankir.h>
#include <spelare.h>
#include <kortlek.h>
using namespace std;

int main()
{
    cout << "kortSpelet 21!" << endl;
    Bankir bank;
    Spelare spelare;
    bank.registeraSpelare(&spelare);
    while(bank.harRegisteradeSpelare())
        bank.SpelaEnOmgang();

    return 0;
}
