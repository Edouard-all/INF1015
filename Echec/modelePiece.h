#ifndef MODELEPIECE_H
#define MODELEPIECE_H

#include <QObject>
using namespace std;
namespace modele {

class ModelePiece : public QObject
{
    Q_OBJECT
public:
    explicit ModelePiece(QObject *parent = nullptr);
public slots:
    pair<uint8_t, uint8_t> getPosition();
    virtual unique_ptr<pair<uint8_t, uint8_t>[]>& getPositionsValides() ;
    virtual void deplacer(pair<uint8_t, uint8_t> position);
    virtual void mettreAJourPositionsValides();
signals:

private:
    pair<uint8_t, uint8_t> position_;
    unique_ptr<pair<uint8_t, uint8_t>[]> positionsValides_;
};


#endif // MODELEPIECE_H
}