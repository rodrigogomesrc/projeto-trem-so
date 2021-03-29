#include "trem.h"
#include <QtCore>
#include <iostream>

//Construtor
Trem::Trem(int ID, int x, int y, RegiaoCritica* regioesCriticas[7]){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->velocidade = 500;
    this->velocidadeMaxima = 999;
    this->parado = false;
    this->regioesCriticas = regioesCriticas;

}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            this->canMove();

            if (y == 30 && x < 330)
                x+=10;
            else if (x == 330 && y < 150)
                y+=10;
            else if (x > 60 && y == 150)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2: //Trem 2
            this->canMove();
            if (y == 30 && x < 600)
                x+=10;
            else if (x == 600 && y < 150)
                y+=10;
            else if (x > 330 && y == 150)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 3: //Trem 3
            this->canMove();
            if (y == 30 && x < 870)
                x+=10;
            else if (x == 870 && y < 150)
                y+=10;
            else if (x > 600 && y == 150)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 4: //Trem 4
            this->canMove();
            if (y == 150 && x < 470)
                x+=10;
            else if (x == 470 && y < 270)
                y+=10;
            else if (x > 200 && y == 270)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 5: //Trem 5
            this->canMove();
            if (y == 150 && x < 740)
                x+=10;
            else if (x == 740 && y < 270)
                y+=10;
            else if (x > 470 && y == 270)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal

            break;
        default:
            break;
        }
        msleep(this->velocidade);
    }
}

void Trem::setVelocidade(int velocidade){
    this->velocidade = (this->velocidadeMaxima - velocidade);
    if(this->velocidade == this->velocidadeMaxima){
        this->parado = true;
    } else {
        this->parado = false;
    }
}


bool Trem::canMove(){

    switch (ID) {
           case 1:
               if(x == 310 && y == 30){sem_wait(&this->regioesCriticas[0]->mutex);}
               if(x == 180 && y == 150){sem_post(&this->regioesCriticas[0]->mutex);}
               break;
            case 2:
               if(x == 580 && y == 30){sem_wait(&this->regioesCriticas[0]->mutex);}
               if(x == 350 && y == 30){sem_post(&this->regioesCriticas[0]->mutex);}
               break;
            case 3:
                if(x == 760 && y == 150){sem_wait(&this->regioesCriticas[0]->mutex);}
                if(x == 620 && y == 30){sem_post(&this->regioesCriticas[0]->mutex);}
                break;
            case 4:
                if(x == 200 && y == 170){sem_wait(&this->regioesCriticas[0]->mutex);}
                if(x == 450 && y == 270){sem_post(&this->regioesCriticas[0]->mutex);}
                break;
            case 5:
                if(x == 490 && y == 270){sem_wait(&this->regioesCriticas[0]->mutex);}
                if(x == 740 && y == 170){sem_post(&this->regioesCriticas[0]->mutex);}
                break;

           }


    if(this->parado == false){
        return true;
    }

    return false;
}




