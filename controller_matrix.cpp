#include "controller_matrix.h"
#include "view.h"
#include "model_matrix.h"

Controller_matrix::Controller_matrix() {}

Controller_matrix::~Controller_matrix() {}

void Controller_matrix::onRowcurrentIndexChanged(int index)
{
    array_size->set_rows(index);
}

void Controller_matrix::onColumncurrentIndexChanged(int index)
{
    array_size->set_columns(index);
}
