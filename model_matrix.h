#ifndef MODEL_MATRIX_H
#define MODEL_MATRIX_H


class Model_matrix
{

public:
    explicit Model_matrix ();
    ~Model_matrix ();
    int rows;
    int columns;
    void set_rows (int r);
    void set_columns (int c);
    int get_rows () {return rows;}
    int get_columns (){return columns;}

};

#endif // MODEL_MATRIX_H
