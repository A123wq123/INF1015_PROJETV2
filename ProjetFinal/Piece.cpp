//#pragma once
//#include "Piece.h"
//#pragma once
#include "Piece.h"
// la classe �tant abstraite l'utilit�e de ce fichier viens de dispara�tre. 

int Piece::row() { return square_->getCoordinates().first; };

int Piece::collumn() { return square_->getCoordinates().second; };