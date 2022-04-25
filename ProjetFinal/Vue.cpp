#include "Vue.h"
static const int numberRows = 8;
static const int numberCollums = 8;
static int counter = 0;
static int color = 0;
Vue::Vue(QWidget* parent) : QMainWindow(parent) {

    QWidget* window = new QWidget();
    QGridLayout* chessGrid = boxLayout();
    setLayout(chessGrid);
    window->setLayout(chessGrid);
    setCentralWidget(window);

}

QPushButton* Vue::createSquare() {
    button_ = new QPushButton(tr(" "), this);
    button_->setMaximumSize(QSize(200, 200));
    if (color % 2 == 0) {
        if (counter % 2 == 0) {
            button_->setStyleSheet("border: 0px; background-color: beige");
        }
        else {
            button_->setStyleSheet("border: 0px; background-color: white ");
        }

    }
    else {
        if (counter % 2 == 1)
        {
            button_->setStyleSheet("border: 0px; background-color: beige");
        }
        else {
            button_->setStyleSheet("border: 0px; background-color: white");
        }
    }


    counter++;
    return button_;
}
QGridLayout* Vue::boxLayout() {

    QGridLayout* chessGrid = new QGridLayout;

    for (int row = 0; row < numberRows; ++row) {
        for (int column = 0; column < numberCollums; ++column) {
            QPushButton* square = createSquare();
            chessGrid->addWidget(square, row, column);
            chessGrid->setHorizontalSpacing(0);
            chessGrid->setVerticalSpacing(0);
        }
        color++;
    }

    return chessGrid;
}