#include "vueEchiquier.h"
#include <QGraphicsRectItem>

VueEchiquier::VueEchiquier(QWidget *parent)
    : QGraphicsView{parent}
{
    scene = new QGraphicsScene(this);

    setScene(scene);

    dessinerEchiquier();
}

void VueEchiquier::dessinerEchiquier(){
    for (int i = 0; i < tailleBordure; i++){
        for (int j = 0; j < tailleBordure; j++ ){
             auto carre = scene->addRect(j*tailleCarre, i * tailleCarre, tailleCarre, tailleCarre);
            if (i % 2 == 0){
                 if (j % 2 == 0){
                 carre->setBrush(Qt::white);
                 }
                 else {
                     carre->setBrush(Qt::black);
                 }
           }
           else{
                 if (j % 2 == 0){
                 carre->setBrush(Qt::black);
                 }
                 else {
                     carre->setBrush(Qt::white);
                 }
           }

        }
    }
}