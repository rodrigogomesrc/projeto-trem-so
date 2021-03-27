#ifndef REGIAOCRITICA_H
#define REGIAOCRITICA_H
#include "semaphore.h"

class RegiaoCritica
{
public:
    RegiaoCritica(int, int, int, int, sem_t *);
    bool isOpened();
    void open();
    void close();
    int getX0();
    int getX1();
    int getY0();
    int getY1();
    sem_t* mutex;

private:
    int x0;
    int y0;
    int x1;
    int y1;
    bool opened;
};


#endif // REGIAOCRITICA_H
