#ifndef SPELARE_H
#define SPELARE_H
#include<korthand.h>
#include <kort.h>

class Spelare
{
public:
    Spelare();

    bool villSpela();
    bool villHaKort() const;
    void tagEmotKort(const Kort &kort);
    void bangenTagKort(const Kort & kort) const;
    void kortlekenHarBlandats();
    void speletAvslutat(bool spelarnVann);
    const Korthand& korthand();
    ///
    void placeBet(int amount);
    void doubleBet();
    int saldo() const;

private:
    Korthand m_hand;
    //////
    int m_money;
    int m_currentBet;
};

#endif // SPELARE_H
