#include "Obican.h"

double Obican::operator*() const
{
    if (~(*this) == true) {
        /*Вредност исплате обичног тикета одређује се као производ
            квота жељених исхода на свим паровима тикета и реалне уплате на тикету*/
        double v = 1;
        for (Elem* pom = prvi; pom; pom = pom->sled) {
            v *= pom->par->operator[](pom->ishod);
        }
        return v * uplata;
    }
    else return 0;
}

bool Obican::operator~() const
{
    for (Elem* pom = prvi; pom; pom = pom->sled) {
        if (pom->ishod != pom->par->operator()()) return false;
    }
    return true;
}
