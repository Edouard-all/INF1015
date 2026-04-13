#include "modelePiece.h"
#ifndef MODELETOUR_H
#define MODELETOUR_H
namespace modele{
    class ModeleTour : public ModelePiece
    {
    public:
        explicit ModeleTour(QObject *parent = nullptr);
    };
}
#endif // MODELETOUR_H
