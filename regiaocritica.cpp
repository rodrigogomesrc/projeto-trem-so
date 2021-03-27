#include "regiaocritica.h"
#include "semaphore.h"

RegiaoCritica::RegiaoCritica(int x0, int y0, int x1, int y1, sem_t* mutex)
{
    this->x0 = x0;
    this->y0 = y0;
    this->x1 = x1;
    this->y1 = y1;
    this->mutex = mutex;
    this->opened = false;
}

bool RegiaoCritica::isOpened(){
    return this->opened;
}

void RegiaoCritica::close(){
    this->opened = false;
}

void RegiaoCritica::open(){
    this->opened = true;
}

int RegiaoCritica::getX0(){
    return this->x0;
}

int RegiaoCritica::getX1(){
    return this->x1;
}

int RegiaoCritica::getY0(){
    return this->y0;
}

int RegiaoCritica::getY1(){
    return this->y1;
}
