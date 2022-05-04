//#pragma once
//#include "Piece.h"
//#pragma once
#include "Piece.h"
// la classe étant abstraite l'utilitée de ce fichier viens de disparaître. 

int Piece::row() { return square_->getCoordinates().first; };

int Piece::collumn() { return square_->getCoordinates().second; };