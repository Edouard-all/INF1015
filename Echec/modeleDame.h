#include "modelePiece.h"
#ifndef MODELEDAME_H
#define MODELEDAME_H

namespace modele{
    class ModeleDame : public ModelePiece
    {
    public:
        explicit ModeleDame(QObject *parent = nullptr);
    };
}

#endif // MODELEDAME_H
