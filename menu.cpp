#include "menu.h"
#include "ui_menu.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect (ui->Row, SIGNAL(currentIndexChanged(int)), this, SLOT (on_Row_currentIndexChanged (int)));
    connect (ui->Column, SIGNAL(currentIndexChanged(int)), this, SLOT (on_Column_currentIndexChanged (int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Row_currentIndexChanged(int index)
{
    Controller_matrix m_r;
    m_r.rows = index;
    m_r.get_rows();
}

void MainWindow::on_Column_currentIndexChanged(int index)
{
    Controller_matrix m_c;
    m_c.columns = index;
    m_c.get_columns();
}


int Controller_matrix::get_rows()
{
    for (int i = 2; i < rows; i++)
    {

    }
    return 0;
}

int Controller_matrix::get_columns()
{
    for (int i = 2; i < columns; i++)
    {

    }
    return 0;
}

