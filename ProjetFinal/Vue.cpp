#include "Vue.h"
#include "Roi.h"
#include "Tour.h"
//#include "Vue.h"
//#pragma once

static const int numberRows = 8;
static const int numberCollums = 8;
static int counter = 0;
static int color = 0;
Vue::Vue(QWidget* parent): QMainWindow(parent), echiquier_() {
    auto widgetP = new QWidget(this);
    auto layoutP = new QHBoxLayout(widgetP);
    
    auto widgetS = new QWidget(this);
    auto layoutS = new QVBoxLayout(widgetS);
    auto quitButton = new QPushButton(tr("Quitter la partie "), this);
    QObject::connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    layoutS->addWidget(quitButton);
    layoutS->setAlignment(Qt::AlignTop);
    layoutP->addWidget(widgetS);
    auto window = new QWidget(this);
    QGridLayout* chessGrid = boxLayout();
    window->setLayout(chessGrid);
    layoutP->addWidget(window);
    setCentralWidget(widgetP);

    
}

SquareVue* Vue::createSquare(int row, int collumn) {
    auto squareVue = new SquareVue(echiquier_.getCase(row,collumn).get());
    squareVue->setFixedSize(QSize(150, 150));
    
    if (color % 2 == 0) {
        if (counter % 2 == 0) {
            squareVue->setStyleSheet("border: 0px; background-color: beige");
            
            
        }
        else {
            squareVue->setStyleSheet("border: 0px; background-color: white ");
            
            
        }

    }
    else {
        if (counter % 2 == 1)
        {
            squareVue->setStyleSheet("border: 0px; background-color: beige");
            
           
        }
        else {
            squareVue->setStyleSheet("border: 0px; background-color: white");
            
            
        }
    }


    counter++;
    return squareVue;
}
QGridLayout* Vue::boxLayout() {
    echiquier_.getCase(2, 2)->addPiece(make_shared<Roi>(echiquier_.getCase(2, 2).get(), "White"));
    echiquier_.getCase(2, 3)->addPiece(make_shared<Tour>(echiquier_.getCase(2, 3).get(), "White"));
    QGridLayout* chessGrid = new QGridLayout;
    for (int row = 0; row < numberRows; ++row) {
        for (int column = 0; column < numberCollums; ++column) {

            SquareVue* square = createSquare(row,column);
            chessGrid->addWidget(square,row,column);
            chessGrid->setHorizontalSpacing(0);
            chessGrid->setVerticalSpacing(0);
            square->majUI();
        }
        color++;
    }
    
    
    return chessGrid;
}

