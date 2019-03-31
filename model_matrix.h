#ifndef MODEL_MATRIX_H
#define MODEL_MATRIX_H


class Model_matrix
{
private:
    int rows;
    int columns;

public:
    explicit Model_matrix ();
    ~Model_matrix ();
    void get_rows (int rows);
    void get_columns (int columns);
    void get_array ();

};

#endif // MODEL_MATRIX_H
