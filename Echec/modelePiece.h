#ifndef MODELEPIECE_H
#define MODELEPIECE_H

#include <QObject>

class ModelePiece : public QObject
{
    Q_OBJECT
public:
    explicit ModelePiece(QObject *parent = nullptr);

signals:
};

#endif // MODELEPIECE_H
