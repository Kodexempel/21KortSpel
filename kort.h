#ifndef KORT_H
#define KORT_H


#include <string>
class Kort
{
public:
    enum Farg{
        klover,ruter,hjarter,spader
    };

    Kort(Farg farg ,int valoer);
    Farg farg() const;
    int valoer ()const;
    std:: string text() const ;
private :
   std:: string fargstrang() const ;
   Farg m_farg;
   int m_valoer;
};

#endif // KORT_H
