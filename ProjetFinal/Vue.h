#ifndef GENERAL_VUE_H
#define GENERAl_VUE_H
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <Qpoint>
#include <QMargins>
#endif

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