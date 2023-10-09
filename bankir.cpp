
#include <bankir.h>
#include <kortlek.h>
#include <spelare.h>
#include <iostream>
using namespace std;
Bankir::Bankir(): m_kortlek()
{

}

void Bankir::registeraSpelare(Spelare *pSpelare)
{
    m_spelare =pSpelare;


}

bool Bankir::harRegisteradeSpelare() const
{
    return m_spelare != nullptr;
}

/*void Bankir::SpelaEnOmgang()
{
    if (m_spelare== nullptr)
        return;
    if (m_kortlek.antalkort() < 15)
    {
        m_kortlek.aterstallBlandadKortlek();
        (*m_spelare).kortlekenHarBlandats();
    }

    if ((*m_spelare).villSpela())
    {
        Kort k = m_kortlek.utPlockatKort();
        (*m_spelare).tagEmotKort(k);

        while ((*m_spelare).korthand().poang() < 21 && (*m_spelare).villHaKort())
        {
            Kort k = m_kortlek.utPlockatKort();
            (*m_spelare).tagEmotKort(k);
        }
    }

    const int spelarpoang = (*m_spelare).korthand().poang();

    if (spelarpoang > 21)
    {
        (*m_spelare).speletAvslutat(false);
    }
    else if (spelarpoang == 21)
    {
        (*m_spelare).speletAvslutat(true);
    }
    else
    {
        Korthand bankhand;

        while (bankhand.poang() < 16)
        {
            Kort kort = m_kortlek.utPlockatKort();
            bankhand.stoppaInKort(kort);
            (*m_spelare).bangenTagKort(kort);
        }

        int bankpoang = bankhand.poang();
        bool spelarenVann = bankpoang > 21 || spelarpoang > bankpoang;
        (*m_spelare).speletAvslutat(spelarenVann);
    }

    m_spelare = nullptr;

}
*/
void Bankir::SpelaEnOmgang()
{
    if (m_spelare == nullptr)
        return;

    // Fråga spelaren hur mycket de vill satsa
    int belopp;
    do
    {
        std::cout << "Ditt saldo är " << (*m_spelare).saldo() << " kronor." << std::endl;
        std::cout << "Hur mycket vill du satsa? (minst 1 krona, högst ditt saldo): ";
        std::cin >> belopp;
    } while (belopp < 1 || belopp > (*m_spelare).saldo());

    (*m_spelare).placeBet(belopp);

    if (m_kortlek.antalkort() < 15)
    {
        m_kortlek.aterstallBlandadKortlek();
        (*m_spelare).kortlekenHarBlandats();
    }

    if ((*m_spelare).villSpela())
    {
        Kort k = m_kortlek.utPlockatKort();
        (*m_spelare).tagEmotKort(k);

        while ((*m_spelare).korthand().poang() < 21 && (*m_spelare).villHaKort())
        {
            Kort k = m_kortlek.utPlockatKort();
            (*m_spelare).tagEmotKort(k);
        }
    }

    const int spelarpoang = (*m_spelare).korthand().poang();

    if (spelarpoang > 21)
    {

    }
}
