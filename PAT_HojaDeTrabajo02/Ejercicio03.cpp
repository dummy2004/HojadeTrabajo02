#include "Ejercicio03.h"

int Ejercicio03::calculate(string s)
{
    int suma = 0;
    long long ant = 0;
    long long ant_r = 1;
    char ant_operador = '+';

    if (s.size() < 1)
        return suma;

    int i = 0;
    int posneg = 1;

    while (i < s.size()) {
        if (s[i] == ' ') {
            ++i;
            continue;
        }

        if (s[i] == '+' || s[i] == '-') {
            suma += ant_r * posneg;
            posneg = s[i++] == '+' ? 1 : -1;
            ant_r = 1;
            ant_operador = '+';
        }

        else if (s[i] == '/' || s[i] == '*') {
            ant_operador = s[i];
            ++i;
        }

        if (isdigit(s[i])) {
            ant = 0;

            while (i < s.size() && isdigit(s[i])) {
                ant = ant * 10 + s[i] - '0';
                i++;
            }

            if (ant_operador == '*')
                ant_r *= ant;
            else if (ant_operador == '/')
                ant_r /= ant;
            else
                ant_r = ant;
        }
    }
    suma += ant_r * posneg;
    return suma;
}
