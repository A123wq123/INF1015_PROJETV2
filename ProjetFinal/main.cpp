#include <QApplication>
#include <QFont>
#include <QLCDNumber>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QWidget>
#include "Vue.h"

//Remove these later.
#include "Echiquier.h"
#include "Roi.h"
#include "ChessGame.h"
#include "Debugg.h"
#include "Tour.h"
#include "Fou.h"

//class MyWidget : public QWidget
//{
//public:
    //MyWidget(QWidget* parent = 0);
//};

// placer ces fonctions dans ChessGame?

std::unique_ptr<Echiquier> createBasicEchiquier() {
    // make an empty board
    std::unique_ptr<Echiquier> echiquier = std::make_unique<Echiquier>();

    // add the white peices.
    echiquier->getCase(7, 4)->addPiece(std::make_shared<Roi>(echiquier->getCase(7, 4), "White"));
    echiquier->getCase(7, 7)->addPiece(std::make_shared<Tour>(echiquier->getCase(7, 7), "White"));
    echiquier->getCase(7, 0)->addPiece(std::make_shared<Tour>(echiquier->getCase(7, 0), "White"));
    echiquier->getCase(7, 2)->addPiece(std::make_shared<Fou>(echiquier->getCase(7, 2), "White"));
    echiquier->getCase(7, 5)->addPiece(std::make_shared<Fou>(echiquier->getCase(7, 5), "White"));

    // add the black peices.
    echiquier->getCase(0, 4)->addPiece(std::make_shared<Roi>(echiquier->getCase(0, 4), "Black"));
    echiquier->getCase(0, 7)->addPiece(std::make_shared<Tour>(echiquier->getCase(0, 7), "Black"));
    echiquier->getCase(0, 0)->addPiece(std::make_shared<Tour>(echiquier->getCase(0, 0), "Black"));
    echiquier->getCase(0, 2)->addPiece(std::make_shared<Fou>(echiquier->getCase(0, 2), "Black"));
    echiquier->getCase(0, 5)->addPiece(std::make_shared<Fou>(echiquier->getCase(0, 5), "Black"));

    return std::move(echiquier);
}

Chess::ChessGame createBasicChessGame(Echiquier* const echiquierPtr) {
    return Chess::ChessGame(echiquierPtr);
}

Debugg createbasicDebuggObject(Chess::ChessGame chessGame) {
    return Debugg(chessGame);
}

int main(int argc, char* argv[])
{
    // uncoment the following lines when done with tests.
        /*QApplication app(argc, argv);
        Vue widget;
        widget.show();
        return app.exec();*/
    
    std::unique_ptr<Echiquier> echiquierPtr = createBasicEchiquier();
    Chess::ChessGame chessGame = createBasicChessGame(echiquierPtr.get());
    Debugg debuggObject = createbasicDebuggObject(chessGame);

    //debuggObject.printBoardState();
    debuggObject.lancerSerieTests();
}