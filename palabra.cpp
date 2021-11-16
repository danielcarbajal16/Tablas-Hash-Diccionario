#include "palabra.h"

word::word() {
    palab = "";
    definicion = "";
    Alta = true;
}

void word::setPalab(string p) {
    palab = p;
}

string word::getPalab() {
    return palab;
}

void word::setDef(string def) {
    definicion = def;
}

string word::getDef() {
    return definicion;
}

void word::setAlta(bool sn) {
    Alta = sn;
}

bool word::getAlta() {
    return Alta;
}
