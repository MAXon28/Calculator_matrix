#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QWidget>
#include <QComboBox>
#include <QLineEdit>
#include "QString"
#include <QDebug>
#include <QScrollBar>
#include "QDialog"
#include "QVector"
#include "QGridLayout"
#include "model_matrix.h"

namespace Ui {
class View;
}

class Model_matrix;

class View : public QMainWindow
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = nullptr);
    ~View();

private slots:
    void on_Row_currentTextChanged(const QString &arg1);

    void on_Column_currentTextChanged(const QString &arg1);

    void Update_matrix(const QString & r_c);

    void on_Choise_of_number_currentTextChanged(const QString &arg1);


    void on_Add_matrix_clicked();

    void on_det_A_clicked();

private:
    Ui::View *ui;
    Model_matrix array;
};

#endif // VIEW_H
