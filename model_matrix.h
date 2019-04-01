#ifndef MODEL_MATRIX_H
#define MODEL_MATRIX_H


class Model_matrix
{
public:
    explicit Model_matrix ();
    ~Model_matrix ();
    int set_rows (int index_r);
    int set_columns (int index_c);
    void get_size_array ();
    int rows;
    int columns;

};

#endif // MODEL_MATRIX_H
