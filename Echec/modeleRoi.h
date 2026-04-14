#include "modelePiece.h"
#ifndef MODELEROI_H
#define MODELEROI_H

namespace modele {
    class ModeleRoi : public ModelePiece
    {
    public:
        explicit ModeleRoi(QObject *parent = nullptr);
    };
}

#endif // MODELEROI_H
