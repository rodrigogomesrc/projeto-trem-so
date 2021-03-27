#ifndef REGIAOCRITICA_H
#define REGIAOCRITICA_H


class RegiaoCritica
{
public:
    RegiaoCritica(int, int, int, int);
    bool isOpened();
    void open();
    void close();
    int getX0();
    int getX1();
    int getY0();
    int getY1();

private:
    int x0;
    int y0;
    int x1;
    int y1;
    bool opened;
};


#endif // REGIAOCRITICA_H
