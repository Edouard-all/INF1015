#ifndef MODELECHIQUIER_H
#define MODELECHIQUIER_H



#include <QObject>
#include "modelePiece.h"
#include <utility>

using namespace std;

class ModelEchiquier : public QObject
{
    Q_OBJECT
public:
    explicit ModelEchiquier(QObject *parent = nullptr);
    ModelEchiquier();
    pair<int, ModelePiece>& getEchiquier(int range, int colone);
    void movePiece(pair<uint8_t, uint8_t> initial , pair<uint8_t, uint8_t> final);

private:
    pair<int, ModelePiece> echiquier_[8][8];
signals:
};

#endif // MODELECHIQUIER_H
