#include "modelePiece.h"

modele::ModelePiece::ModelePiece(QObject *parent)
    : QObject{parent}
{}

pair<uint8_t, uint8_t> modele::ModelePiece::getPosition() {
    return position_;
}

unique_ptr<pair<uint8_t,uint8_t>[]>& modele::ModelePiece::getPositionsValides() {
    return positionsValides_;
}

void modele::ModelePiece::deplacer(pair<uint8_t, uint8_t> position) {
    for (uint8_t i = 0 ; i < sizeof(positionsValides_) ; i++) {
        if (positionsValides_[i] == position)
            position_ = position;
    }
}

void modele::ModelePiece::mettreAJourPositionsValides() {

}