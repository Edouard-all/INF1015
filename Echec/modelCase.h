#ifndef MODELCASE_H
#define MODELCASE_H

#include <QObject>

class ModelCase : public QObject
{
    Q_OBJECT
public:
    explicit ModelCase(QObject *parent = nullptr);

signals:
};

#endif // MODELCASE_H
