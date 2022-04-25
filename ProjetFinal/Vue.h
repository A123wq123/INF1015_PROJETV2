#pragma once
#pragma once
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <Qpoint>
#include <QMargins>
// The header pour l'affichage Qt
class Vue : public QMainWindow {
	Q_OBJECT
public:
	Vue(QWidget* parent = nullptr);
	QGridLayout* boxLayout();
	QPushButton* createSquare();
private:
	QPushButton* button_;

};