#include "kort.h"
#include "kort.h"
#include <iostream>
using namespace std;
Kort::Kort(Farg farg, int valoer): m_farg(farg), m_valoer(valoer)
{
}

Kort::Farg Kort::farg() const
{
    return m_farg;

}


int Kort::valoer() const {


    if (m_valoer >= 10) {

            return 10;
        } else if (m_valoer == 1) {

            return 11;
        } else {

            return m_valoer;
        }

}

std::string Kort::text() const
{
    static const char*valoernamn [14]{"finnsej","ett","tva","tre","fyra","fem","sex","atta","nio",
                                      "tio","knekt","dam","kung"};
    return fargstrang() + "" + valoernamn[m_valoer];
}

std::string Kort::fargstrang() const
{
    static const char* fargnamn[4] = {"hjarter", "klover", "spader", "ruter"};
    return fargnamn[m_farg];
}
