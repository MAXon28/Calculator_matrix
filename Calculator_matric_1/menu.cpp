#include "menu.h"
#include "ui_menu.h"
#include "sum_sub_matric.h"

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{
    Sum_sub_matric window_1;
    window_1.setModal(true);
    window_1.exec();
}
