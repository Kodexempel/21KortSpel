#ifndef BANKIR_H
#define BANKIR_H
#include <spelare.h>
#include <kortlek.h>

class Bankir
{
public:
    Bankir();

    void registeraSpelare(Spelare * pSpelare);
    bool harRegisteradeSpelare() const;
    void SpelaEnOmgang();
private :
    Kortlek m_kortlek;
    Spelare *m_spelare;
};

#endif // BANKIR_H
