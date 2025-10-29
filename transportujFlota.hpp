#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    if (towar == 0)
        return 0;

    Stocznia     stocznia{};
    unsigned int ilosctowaru= 0;
    unsigned int liczbaZaglowcow = 0;

    while (ilosctowaru < towar) {
        Statek* statek = stocznia();
        if (!statek) {
            continue;
        }

        ilosctowaru += statek->transportuj();

        if (dynamic_cast< Zaglowiec* >(statek)) {
            ++liczbaZaglowcow;
        }

        delete statek;
    }

    return liczbaZaglowcow;
}
