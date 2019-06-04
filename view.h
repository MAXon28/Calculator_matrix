#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QWidget>
#include <QComboBox>
#include <QLineEdit>
#include "QString"
#include <QDebug>
#include <QScrollBar>
#include "QVector"
#include "QTableWidget"
#include "QGridLayout"
#include "Logic_matrix.h"
#include "QMessageBox"
namespace Ui {
class View;
}

class Logic_matrix;

class View : public QMainWindow
{
    Q_OBJECT
private:
    Ui::View *ui;
    Logic_matrix array;
    Logic_matrix array_B;
    Logic_matrix array_C;
    Logic_matrix array_D;
    QVector<QVector<QLineEdit*>> matrixA;
    QVector<QVector<QLineEdit*>> matrixB;
    QVector<QVector<QLineEdit*>> matrixC;
    QVector<QVector<QLineEdit*>> matrixD;

public:
    explicit View(QWidget *parent = nullptr);
    ~View();

private slots:
    void on_Row_currentTextChanged(const QString &A);
    void on_Column_currentTextChanged(const QString &A);
    void Update_matrix();
    void on_Choise_of_number_currentTextChanged(const QString &arg1);
    void on_Add_matrix_clicked();
    void on_mul_matrix_number_clicked();
    void on_transporation_matrix_clicked();
    void on_det_A_clicked();
    void on_inverse_matrix_clicked();
    void on_mul_matrix_clicked();
    void on_tr_matrix_clicked();
    void on_det_clicked();
    void on_inversion_matrix_clicked();
    void on_sum_sub_matrix_clicked();
    void on_sum_matrix_clicked();
    void on_variant_1_currentTextChanged(const QString &arg1);
    void on_variant_2_currentTextChanged(const QString &arg1);
    void on_variant_3_currentTextChanged(const QString &arg1);
    void on_mul_matrix_button_clicked();
    void on_Row_B_currentTextChanged (const QString &B);
    void on_Column_B_currentTextChanged(const QString &B);
    void on_Row_C_currentTextChanged (const QString &C);
    void on_Column_C_currentTextChanged(const QString &C);
    void on_Row_D_currentTextChanged (const QString &D);
    void on_Column_D_currentTextChanged(const QString &D);
};
#endif
