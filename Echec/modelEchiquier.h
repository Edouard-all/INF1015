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
    pair<int, unique_ptr<ModelePiece>>& getEchiquier(int range, int colone);
    void placerPiece(pair<uint8_t, uint8_t> cases, unique_ptr<ModelePiece> piece);
    void movePiece(pair<uint8_t, uint8_t> initial , pair<uint8_t, uint8_t> final);

private:
    pair<int, unique_ptr<ModelePiece>> echiquier_[8][8];
signals:
};

#endif // MODELECHIQUIER_H
