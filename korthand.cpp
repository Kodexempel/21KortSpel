#include "korthand.h"
#include <algorithm>
#include <kort.h>

Korthand::Korthand()
{

}

void Korthand::rensa()
{
    m_korten.clear();
}

int Korthand::antalkort() const
{
    return m_korten.size();
}

Kort Korthand::kort(int nr) const
{
    if (nr >= 0 && nr < antalkort())
    {
        return m_korten[nr];
    }
    else
    {
        return Kort(Kort::Farg::klover, 0);
    }
}



void Korthand::stoppaInKort(const Kort &kort)
{

    m_korten.push_back(kort);
}

int Korthand::poang() const
{
    int poang = 0;
    bool ess = false;
    for (int i = 0; i < antalkort(); i++)
    {
        int kortvaloer = kort(i).valoer();
        if (kortvaloer == 11)
        {
            ess = true;
        }
        poang += kortvaloer;
    }
    if (ess && poang > 21)
    {

        poang -= 10;
    }
    return poang;

}
int Korthand::checkFiveCards() const
{
    if (antalkort() == 5)
    {
        int totalPoang = poang();
        if (totalPoang <= 21)
        {
            return 21;
        }
    }
    return poang();
}

/*Korthand hand1;
hand1.stoppaInKort(Kort(Kort::Farg::klover, 4));
hand1.stoppaInKort(Kort(Kort::Farg::klover, 3));
hand1.stoppaInKort(Kort(Kort::Farg::klover, 3));
int poang1 = hand1.poang(); // should be 10

Korthand hand2;
hand2.stoppaInKort(Kort(Kort::Farg::klover, 4));
hand2.stoppaInKort(Kort(Kort::Farg::klover, 1));
hand2.stoppaInKort(Kort(Kort::Farg::klover, 3));
int poang2 = hand2.poang(); // should be 21

Korthand hand3;
hand3.stoppaInKort(Kort(Kort::Farg::klover, 4));
hand3.stoppaInKort(Kort(Kort::Farg::klover, 1));
hand3.stoppaInKort(Kort(Kort::Farg::klover, 4));
int poang3 = hand3.poang(); // should be 9

Korthand hand4;
hand4.stoppaInKort(Kort(Kort::Farg::klover, 1));
hand4.stoppaInKort(Kort(Kort::Farg::klover, 1));
hand4.stoppaInKort(Kort(Kort::Farg::klover, 1));
hand4.stoppaInKort(Kort(Kort::Farg::klover, 1));
hand4.stoppaInKort(Kort(Kort::Farg::klover, 5));
int poang4 = hand4.poang(); // should be 9

Korthand hand5;
hand5.stoppaInKort(Kort(Kort::Farg::klover, 1));
hand5.stoppaInKort(Kort(Kort::Farg::klover, 10));
hand5.stoppaInKort(Kort(Kort::Farg::klover, 10));
hand5.stoppaInKort(Kort(Kort::Farg::klover, 10));
int poang5 = hand5.poang(); // should be 31
*/
