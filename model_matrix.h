#ifndef MODEL_MATRIX_H
#define MODEL_MATRIX_H


class Model_matrix
{

public:
    explicit Model_matrix ();
    ~Model_matrix ();

    int rows; // Количество строк в матрице
    int columns; // Количество столбцов в матрице
    int count_matrix; // Количество матриц

    void set_rows (int r);
    void set_columns (int c);
    Model_matrix& operator++(int);

};

#endif // MODEL_MATRIX_H
