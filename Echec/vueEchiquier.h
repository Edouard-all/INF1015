#ifndef VUEECHIQUIER_H
#define VUEECHIQUIER_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>

class VueEchiquier : public QGraphicsView
{
    Q_OBJECT
public:
    explicit VueEchiquier(QWidget *parent = nullptr);
    void dessinerEchiquier();
private:
    QGraphicsScene* scene;
    int tailleBordure = 8;
    int tailleCarre = 50;

signals:
};

#endif // VUEECHIQUIER_H
