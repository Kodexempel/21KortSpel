#include "kortlek.h"

#include <kort.h>
#include <chrono>
#include <random>
#include <algorithm>
#include <vector>
#include <cassert>
Kortlek::Kortlek()
{
    atertallkortlek();

}

int Kortlek::antalkort() const
{
    return m_korten.size();
}

Kort Kortlek::utPlockatKort()
{
    Kort kort= m_korten.back();
    m_korten.pop_back();
    return kort;

}

void Kortlek::atertallkortlek()
{

    //    m_korten.clear();
    //      Kort::Farg Farger[4] = { Kort::hjarter, Kort::klover, Kort::spader, Kort::ruter };
    //      for (int ixFarg = 0; ixFarg < 4; ++ixFarg)
    //      {
    //          for (int varde = 1; varde <= 13; ++varde)
    //          {
    //              Kort kort(Farger[ixFarg], varde);
    //               m_korten.push_back(kort);

    //          }
    //      }
    m_korten.clear();
    // for (int farg = Kort::klover; farg <= Kort::spader; ++farg)
    //Kort::Farg Farger[4] = { Kort::hjarter, Kort::klover, Kort::spader, Kort::ruter };
    for (int ixFarg = 0; ixFarg < 4; ++ixFarg)
    {
        for (int valoer = 1; valoer <= 13; ++valoer)
        {
            m_korten.push_back(Kort(static_cast<Kort::Farg>(ixFarg), valoer));
        }
    }

    assert(m_korten.size() == 52);
}


void Kortlek::blanda()
{
    static unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::default_random_engine slumpgenerator(seed);
    shuffle(m_korten.begin(), m_korten.end(), slumpgenerator);
}

void Kortlek::aterstallBlandadKortlek()
{
    atertallkortlek();
    blanda();
}
