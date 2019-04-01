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
    void onRowcurrentIndexChanged (int index);
    void onColumncurrentIndexChanged (int index);
    Model_matrix *array_size;
};

#endif // CONTROLLER_MATRIX_H

