#ifndef CLSFONDO_H
#define CLSFONDO_H

#include <clsSprite.h>


class clsFondo : public clsSprite
{
    protected:
    void inherit(){};
    public:
        int init();
        void setPresentacion(int i);
        void setDespedida();
};

#endif // CLSFONDO_H
