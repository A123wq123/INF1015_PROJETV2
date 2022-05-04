#pragma once
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <Qpoint>
#include <QMargins>
#include "qdebug.h"
#include "squareVue.h"

// The header pour l'affichage Qt
class Vue : public QMainWindow {
	Q_OBJECT
public:
	Vue(QWidget* parent = nullptr);
	QGridLayout* boxLayout();
	SquareVue* createSquare(int row, int collumn);
private:
	QPushButton* button_;
	Echiquier echiquier_;
};