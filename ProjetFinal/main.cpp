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

//class MyWidget : public QWidget
//{
//public:
    //MyWidget(QWidget* parent = 0);
//};

std::unique_ptr<Echiquier> createBasicEchiquier() {
    std::unique_ptr<Echiquier> echiquier = std::make_unique<Echiquier>();
    echiquier->getCase(2, 2)->addPiece(std::make_shared<Roi>(echiquier->getCase(2, 2), "White"));
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