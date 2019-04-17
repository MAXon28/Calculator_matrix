#ifndef MODEL_MATRIX_H
#define MODEL_MATRIX_H


class Model_matrix
{

public:
    explicit Model_matrix ();
    ~Model_matrix ();

    int rows;
    int columns;
    int count_matrix;

    void set_rows (int r);
    void set_columns (int c);
    void set_count_matrix (int count);
};

#endif // MODEL_MATRIX_H
