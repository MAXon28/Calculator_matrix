#include "controller_matrix.h"
#include "view.h"
#include "model_matrix.h"
#include "ui_view.h"

View::View(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
    connect (ui->Row, SIGNAL(currentIndexChanged(int)), this, SLOT (on_Row_currentIndexChanged (int)));
    connect (ui->Column, SIGNAL(currentIndexChanged(int)), this, SLOT (on_Column_currentIndexChanged (int)));
}

View::~View()
{
    delete ui;
}

void View::on_Row_currentIndexChanged(int index)
{

}

void View::on_Column_currentIndexChanged(int index)
{

}


