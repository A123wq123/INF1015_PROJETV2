#pragma once
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QPushButton>
#include "Square.h"
#include "Roi.h"

#include <QString>

#pragma pop()
#include <functional>



using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .

class SquareVue : public QPushButton {
	Q_OBJECT
public:
	SquareVue(Square* square) : QPushButton(){

			square_ = square;
	};

	void majUI() {
		
		this->setText(QString::fromStdString(square_->getPiece()->getName()));
	
	}
public slots:


signals:
	

private:
	Square* square_;
};
