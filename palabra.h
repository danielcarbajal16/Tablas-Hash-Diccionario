#ifndef PALABRA_H_INCLUDED
#define PALABRA_H_INCLUDED
#include <string>

using namespace std;

class word {
    private:
        string palab;
        string definicion;
        bool Alta;
    public:
        word();

        void setPalab(string);
        string getPalab();

        void setDef(string);
        string getDef();

        void setAlta(bool);
        bool getAlta();
};

#endif // PALABRA_H_INCLUDED
