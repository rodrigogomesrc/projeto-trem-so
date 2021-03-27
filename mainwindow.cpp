#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "semaphore.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sem_t s[7];
    for(int i=0; i<7; i++){
       sem_init(&s[i], 0, 1);
    }
    rA = new RegiaoCritica(330, 30, 330, 150, &s[0]);
    rB = new RegiaoCritica(600, 30, 600, 150, &s[1]);
    rC = new RegiaoCritica(80, 150, 199, 150, &s[2]);
    rD = new RegiaoCritica(222, 150, 329, 150, &s[3]);
    rE = new RegiaoCritica(352, 150, 469, 150, &s[4]);
    rF = new RegiaoCritica(492, 150, 599, 150, &s[5]);
    rG = new RegiaoCritica(470, 150, 470, 270, &s[6]);

    regioesCriticas[0] = rA;
    regioesCriticas[1] = rB;
    regioesCriticas[2] = rC;
    regioesCriticas[3] = rD;
    regioesCriticas[4] = rE;
    regioesCriticas[5] = rF;
    regioesCriticas[6] = rG;

    //Cria o trem com seu (ID, posição X, posição Y)
    trem1 = new Trem(1,60,30,regioesCriticas);
    trem2 = new Trem(2,330,30,regioesCriticas);
    trem3 = new Trem(3,600,30,regioesCriticas);
    trem4 = new Trem(4,200,150,regioesCriticas);
    trem5 = new Trem(5,470,150,regioesCriticas);

    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
        ui->label_trem1->setGeometry(x,y,21,17);
        break;
    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem2->setGeometry(x,y,21,17);
        break;
    case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem3
        ui->label_trem3->setGeometry(x,y,21,17);
        break;
    case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem4->setGeometry(x,y,21,17);
        break;
    case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem3
        ui->label_trem5->setGeometry(x,y,21,17);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Ao clicar, trens começam execução
 */
void MainWindow::on_pushButton_clicked()
{
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
}

/*
 * Ao clicar, trens param execução
 */
void MainWindow::on_pushButton_2_clicked()
{
    trem1->terminate();
    trem2->terminate();
    trem3->terminate();
    trem4->terminate();
    trem5->terminate();
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
   trem1->setVelocidade(value);
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    trem2->setVelocidade(value);
}

void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{
    trem3->setVelocidade(value);
}

void MainWindow::on_horizontalSlider_4_valueChanged(int value)
{
    trem4->setVelocidade(value);
}

void MainWindow::on_horizontalSlider_5_valueChanged(int value)
{
    trem5->setVelocidade(value);
}
