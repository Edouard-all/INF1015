#ifndef VUEPIECE_H
#define VUEPIECE_H

#include <QWidget>

class VuePiece : public QWidget
{
    Q_OBJECT
public:
    explicit VuePiece(QWidget *parent = nullptr);

signals:
    void pieceDeplace();
};

#endif // VUEPIECE_H
