#ifndef CONTROLLER_MATRIX_H
#define CONTROLLER_MATRIX_H

#include "view.h"
#include "model_matrix.h"

class View;
class Model_matrix;

class Controller_matrix
{
public:
    Controller_matrix();
    ~Controller_matrix ();
    int row;
    int column;
    void onRowcurrentIndexChanged (int row);
    void onColumncurrentIndexChanged (int column);
};

#endif // CONTROLLER_MATRIX_H

