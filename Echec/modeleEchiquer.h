#ifndef MODELEECHIQUER_H
#define MODELEECHIQUER_H

#include <QObject>

class ModeleEchiquer : public QObject
{
    Q_OBJECT
public:
    explicit ModeleEchiquer(QObject *parent = nullptr);

signals:
};

#endif // MODELEECHIQUER_H
