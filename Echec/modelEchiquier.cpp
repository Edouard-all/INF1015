#include "modelEchiquier.h"

using namespace std;

ModelEchiquier::ModelEchiquier(QObject *parent)
    : QObject{parent}
{}

ModelEchiquier::ModelEchiquier(){
    for (uint8_t i = 0; i < 8; i++){
        for (uint8_t j = 0; j < 8; j++){
            if (i % 2 == 0){
                if (j % 2 == 0){
                    echiquier_[i][j].first = 0; // 0 représente la case claire
                }
                else{
                    echiquier_[i][j].first = 1; // 1 représente la case foncée
                }
            }
        }
    }
}
pair<int, unique_ptr<ModelePiece>>& ModelEchiquier::getEchiquier(int range, int colonne){
    return echiquier_[range][colonne];
}

void ModelEchiquier::movePiece(pair<uint8_t, uint8_t> initial , pair<uint8_t, uint8_t> final){
    if (echiquier_[final.first][final.second].second == nullptr){
    echiquier_[final.first][final.second].second = std::move(echiquier_[initial.first][initial.second].second);
    }

    else {
        echiquier_[final.first][final.second].second.reset();
        echiquier_[final.first][final.second].second = std::move(echiquier_[initial.first][initial.second].second);
    }
}