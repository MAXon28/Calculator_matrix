#include "view.h"
#include "model_matrix.h"
#include "ui_view.h"
#include <QDebug>
#include "QString"

View::View(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
    connect (ui->Row, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (on_Row_currentTextChanged (const QString)));
    connect (ui->Column, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (on_Column_currentTextChanged(const QString)));
    Update_matrix();
}

View::~View()
{
    delete ui;
}

void View::on_Row_currentTextChanged(const QString &arg1)
{
    int row;
    row = arg1.toInt();
    array->set_rows(row);
}

void View::on_Column_currentTextChanged(const QString &arg1)
{
    int column;
    column = arg1.toInt();
    array->set_columns(column);
    /**qDebug()<<array->columns;*/
}

void View::Update_matrix()
{
    int rows_matrix, columns_matrix;
    rows_matrix = array->rows;
    columns_matrix = array->columns;
    int w, h;
    w = 2;
    h = 2;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            QLineEdit* size = new QLineEdit("");
            ui->gridLayout->addWidget (size = new QLineEdit ("   0"), i, j);
            size->setFixedSize(28, 27);
        }
    }
}
