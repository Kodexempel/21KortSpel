#include "spelare.h"
#include "minafunktioner.h"
#include <iostream>
#include <kort.h>

Spelare::Spelare()
{
    m_money=100;
    m_currentBet=0;
}


bool Spelare::villSpela()
{
    std::string input;
    std::cout << "Vill du spela? (ja/nej): ";
    std::cin >> input;
    return boolFranAnvandare(input);
    
}

bool Spelare::villHaKort() const
{
    std::string input;
    std::cout << "Vill du ha ett kort till? (ja/nej): ";
    std::cin >> input;
    return boolFranAnvandare(input);
}

void Spelare::tagEmotKort(const Kort &kort)
{
    m_hand.stoppaInKort(kort);
    std::cout << "Du fick kortet: " << kort.valoer() << std::endl;
}

void Spelare::bangenTagKort(const Kort &kort) const
{
    std::cout << " Banken tog kortet  " << kort.valoer() << std::endl;
}

void Spelare::kortlekenHarBlandats()
{
    std::cout << "Kortleken har blandats." << std::endl;
    
}

void Spelare::speletAvslutat(bool spelarnVann)
{
    if (spelarnVann) {
            std::cout << "Grattis, du vann spelet!" << std::endl;
            m_money += m_currentBet * 2;
        } else {
            std::cout << "Tyvarr, du forlorade spelet." << std::endl;
        }
        m_currentBet = 0;
}

const Korthand &Spelare::korthand()
{
    return m_hand;
}

void Spelare::placeBet(int amount)
{
//    if (amount <= m_money) {
//        m_money -= amount;
//        m_currentBet += amount;
//    } else {
//        std::cout << "You don't have enough money to make that bet." << std::endl;
//    }
    if (amount < 1)
    {
        std::cout << "Du måste satsa minst 1 krona." << std::endl;
    }
    else if (amount > m_money)
    {
        std::cout << "Du har inte tillräckligt med pengar på ditt saldo." << std::endl;
    }
    else
    {
        m_currentBet = amount;
        m_money -= amount;
    }
}

void Spelare::doubleBet()
{
    int doubleAmount = m_currentBet;
    if (doubleAmount <= m_money) {
        m_money -= doubleAmount;
        m_currentBet += doubleAmount;
    } else {
        std::cout << "You don't have enough money to double your bet." << std::endl;
    }
}

int Spelare::saldo() const
{
    return m_money;
}
