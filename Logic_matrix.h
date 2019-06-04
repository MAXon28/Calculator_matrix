#ifndef LOGIC_MATRIX_H
#define LOGIC_MATRIX_H

#include "QVector"

class Logic_matrix
{
private:
    int rows; // Количество строк в матрице
    int columns; // Количество столбцов в матрице
    int count_matrix; // Количество матриц
    int number_of_mul;
    double determinant;
    QString symbols;
    QVector <QVector<double>> matrix_A_for_logic;
    QVector <QVector<double>> matrix_B_for_logic;
    QVector <QVector<double>> matrix_C_for_logic;
    QVector <QVector<double>> matrix_D_for_logic;
    QVector<QVector<double>> result;
public:
    explicit Logic_matrix ();
    ~Logic_matrix ();

    void set_rows (int Rows);
    void set_columns (int Columns);
    void set_count_matrix (int counter);
    int get_rows ();
    int get_columns ();
    int get_count_matrix();
    void set_matrix(QVector<QVector<double>> matrix);
    void set_matrix(QVector<QVector<double> > matrix1, QVector<QVector<double> > matrix2);
    void set_matrix(QVector<QVector<double> > matrix1, QVector<QVector<double> > matrix2, QVector<QVector<double> > matrix3);
    void set_matrix(QVector<QVector<double> > matrix1, QVector<QVector<double> > matrix2, QVector<QVector<double> > matrix3, QVector<QVector<double> > matrix4);
    void set_symbol(QString symbol, int element);
    QVector<QVector<double>> matrix_mul(double number);
    QVector<QVector<double>> matrix_transporation();
    double det_matrix();
    QVector<QVector<double>> matrix_inverse();
    QVector<QVector<double>> sum_sub_matrix();
    double minor (QVector<QVector<double>> A_copy, int row, int column);
    Logic_matrix& operator++(int);

};

#endif
