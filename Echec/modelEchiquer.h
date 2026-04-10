#ifndef MODELECHIQUER_H
#define MODELECHIQUER_H

#include <QObject>

class ModelEchiquer : public QObject
{
    Q_OBJECT
public:
    explicit ModelEchiquer(QObject *parent = nullptr);

signals:
};

#endif // MODELECHIQUER_H
