#ifndef MODELECASE_H
#define MODELECASE_H

#include <QObject>

class ModelCase : public QObject
{
    Q_OBJECT
public:
    explicit ModelCase(QObject *parent = nullptr);

signals:
};

#endif // MODELECASE_H
