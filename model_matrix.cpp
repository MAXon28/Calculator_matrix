#include "model_matrix.h"

Model_matrix::Model_matrix(){}

Model_matrix::~Model_matrix(){}

void Model_matrix::set_rows(int r)
{
    rows = r;
}

void Model_matrix::set_columns(int c)
{
    columns = c;
}

void Model_matrix::set_count_matrix(int count)
{
    count_matrix = count;
}
