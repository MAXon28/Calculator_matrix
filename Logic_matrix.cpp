#include "Logic_matrix.h"

Logic_matrix::Logic_matrix()
{
    rows = 2;
    columns = 2;
    count_matrix = 1;
    symbols = "+++";
}

Logic_matrix::~Logic_matrix(){}

void Logic_matrix::set_rows(int Rows)
{
    rows = Rows;
}

void Logic_matrix::set_columns(int Columns)
{
    columns = Columns;
}

void Logic_matrix::set_count_matrix(int counter)
{
    count_matrix = counter;
}

int Logic_matrix::get_rows()
{
    return rows;
}

int Logic_matrix::get_columns()
{
    return columns;
}

int Logic_matrix::get_count_matrix()
{
    return count_matrix;
}

void Logic_matrix::set_matrix(QVector<QVector<double> > matrix)
{
    matrix_A_for_logic.clear();
    matrix_A_for_logic.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        matrix_A_for_logic[i].resize(columns);
    }
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            matrix_A_for_logic[i][j] = matrix[i][j];
        }
    }
}

void Logic_matrix::set_matrix(QVector<QVector<double> > matrix1, QVector<QVector<double> > matrix2)
{
    matrix_A_for_logic.clear();
    matrix_B_for_logic.clear();
    matrix_A_for_logic.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        matrix_A_for_logic[i].resize(columns);
    }
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            matrix_A_for_logic[i][j] = matrix1[i][j];
        }
    }
    matrix_B_for_logic.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        matrix_B_for_logic[i].resize(columns);
    }
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            matrix_B_for_logic[i][j] = matrix2[i][j];
        }
    }
}

void Logic_matrix::set_matrix(QVector<QVector<double> > matrix1, QVector<QVector<double> > matrix2, QVector<QVector<double> > matrix3)
{
    matrix_A_for_logic.clear();
    matrix_B_for_logic.clear();
    matrix_C_for_logic.clear();
    matrix_A_for_logic.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        matrix_A_for_logic[i].resize(columns);
    }
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            matrix_A_for_logic[i][j] = matrix1[i][j];
        }
    }
    matrix_B_for_logic.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        matrix_B_for_logic[i].resize(columns);
    }
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            matrix_B_for_logic[i][j] = matrix2[i][j];
        }
    }
    matrix_C_for_logic.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        matrix_C_for_logic[i].resize(columns);
    }
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            matrix_C_for_logic[i][j] = matrix3[i][j];
        }
    }
}

void Logic_matrix::set_matrix(QVector<QVector<double> > matrix1, QVector<QVector<double> > matrix2, QVector<QVector<double> > matrix3, QVector<QVector<double> > matrix4)
{
    matrix_A_for_logic.clear();
    matrix_B_for_logic.clear();
    matrix_C_for_logic.clear();
    matrix_D_for_logic.clear();
    matrix_A_for_logic.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        matrix_A_for_logic[i].resize(columns);
    }
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            matrix_A_for_logic[i][j] = matrix1[i][j];
        }
    }
    matrix_B_for_logic.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        matrix_B_for_logic[i].resize(columns);
    }
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            matrix_B_for_logic[i][j] = matrix2[i][j];
        }
    }
    matrix_C_for_logic.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        matrix_C_for_logic[i].resize(columns);
    }
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            matrix_C_for_logic[i][j] = matrix3[i][j];
        }
    }
    matrix_D_for_logic.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        matrix_D_for_logic[i].resize(columns);
    }
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            matrix_D_for_logic[i][j] = matrix4[i][j];
        }
    }
}

void Logic_matrix::set_symbol(QString symbol, int element)
{
    if (symbol == "+")
    {
        symbols[element] = '+';
    }
    else
    {
        symbols[element] = '-';
    }
}

QVector<QVector<double>> Logic_matrix::matrix_mul(double number)
{
    double one_number;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            one_number = matrix_A_for_logic[i][j];
            matrix_A_for_logic[i][j] = one_number * number;
        }
    }
    return matrix_A_for_logic;
}

QVector<QVector<double>> Logic_matrix::matrix_transporation()
{
    QVector <QVector<double>> transporation(columns, QVector<double>(rows)); // создает двумерный вектор для транспонированной матрицы
    for (int i = 0; i < rows; i++) // транспонирование
    {
        for (int j = 0; j < columns; j++)
        {
            transporation[j][i] = matrix_A_for_logic[i][j];
        }
    }
    return transporation;
}

double Logic_matrix::det_matrix()
{
    QVector <QVector <double>> a_logic_copy(rows, QVector <double>(rows)); // создает двумерный вектор для хранения дубликата транспонированной матрицы
    for (int i = 0; i < rows; i++) // присванивание значений из транспонированной матрицы
    {
        for (int j = 0; j < rows; j++)
        {
            a_logic_copy[i][j] = matrix_A_for_logic[i][j];
        }
    }
    double temp = 0;      // временная переменная для хранения элемента
    int temp_index = 0;   // временная переменная для хранения индекса элемента
    int repeat = rows - 1; //кол-во повторов
    int rows_counter = rows;
    determinant = 1;   // переменная для хранения накопленного произведения коэффициентов при минорах

    if (rows_counter == 1)
    {
        determinant = determinant * a_logic_copy[0][0];
        return determinant;
    }

    for (int t = 0; t < repeat; t++)
    {
        temp = 0;
        temp_index = 0;

        for (int i = 0; i < rows_counter; i++) // выбор элемента через который будем делать 0
        {
            if (a_logic_copy[i][0] != 0)
            {
                temp = a_logic_copy[i][0];
                temp_index = i;
                break;
            }
        }

        if (temp == 0)
        {
            return 0;
        }

        double k = 0; // коэффициент пропорциональности

        for (int i = 0; i < rows_counter; i++) // умножение строчки на коэффициент пропорциональности и вычитание ее из всех остальных
        {
            if (i != temp_index)
            {
                k = a_logic_copy[i][0] / temp;
                for (int j = 0; j < rows_counter; j++)
                {
                    a_logic_copy[i][j] = a_logic_copy[i][j] - a_logic_copy[temp_index][j] * k;
                }
            }
        }

        if (temp_index % 2 == 0)
        {
            determinant = determinant * temp;
        }
        else
        {
            determinant = -determinant * temp;
        }

        rows_counter--; // уменьшаем размер матрицы

        a_logic_copy.erase(a_logic_copy.begin()); // делаем вектор на 1 меньше(удаляем 1 столбец)
        for (int i = 0; i < rows_counter; i++) // удаляем строчку
        {
            a_logic_copy[i].erase(a_logic_copy[i].begin() + temp_index);
        }

        if (rows_counter == 1)
        {
            determinant = determinant * a_logic_copy[0][0];
        }
    }
    return determinant;
}

QVector<QVector<double>> Logic_matrix::matrix_inverse()
{
    for (int i = 0; i < rows - 1; i++) // транспонирование
    {
        for (int j = i + 1; j < rows; j++)
        {
            double transporation = matrix_A_for_logic[i][j];
            matrix_A_for_logic[i][j] = matrix_A_for_logic[j][i];
            matrix_A_for_logic[j][i] = transporation;
        }
    }

    QVector <QVector <double>> A_logic_copy(rows, QVector <double>(rows)); // создает двумерный вектор для хранения дубликата транспонированной матрицы
    for (int i = 0; i < rows; i++) // присванивание значений из транспонированной матрицы
    {
        for (int j = 0; j < rows; j++)
        {
            A_logic_copy[i][j] = matrix_A_for_logic[i][j];
        }
    }

    for (int i = 0; i < rows; i++) // вычисление союзной матрицы
    {
        for (int j = 0; j < rows; j++)
        {
            matrix_A_for_logic[i][j] = minor(A_logic_copy, i, j);
        }
    }

    for (int i = 0; i < rows; i++) // умножение (1/определитель) на союзную матрицу
    {
        for (int j = 0; j < rows; j++)
        {
            matrix_A_for_logic[i][j] = matrix_A_for_logic[i][j] * (1 / determinant);
        }
    }
    return matrix_A_for_logic;
}

QVector<QVector<double>> Logic_matrix::sum_sub_matrix()
{
    result.clear();
    result.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        result[i].resize(columns);
    }
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if (symbols[0] == '+')
            {
                result[i][j] = matrix_A_for_logic[i][j] + matrix_B_for_logic[i][j];
            }
            else
            {
                result[i][j] = matrix_A_for_logic[i][j] - matrix_B_for_logic[i][j];
            }
        }
    }
    if (count_matrix > 2)
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                if (symbols[1] == '+')
                {
                    result[i][j] = result[i][j] + matrix_C_for_logic[i][j];
                }
                else
                {
                    result[i][j] = result[i][j] - matrix_C_for_logic[i][j];
                }
            }
        }
        if (count_matrix == 4)
        {
            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < columns; j++)
                {
                    if (symbols[2] == '+')
                    {
                        result[i][j] = result[i][j] + matrix_D_for_logic[i][j];
                    }
                    else
                    {
                        result[i][j] = result[i][j] - matrix_D_for_logic[i][j];
                    }
                }
            }
            return result;
        }
        else
        {
            return result;
        }
    }
    else
    {
        return result;
    }
}

double Logic_matrix::minor(QVector<QVector<double> > A_copy, int row, int column)
{
    int SIZE = rows;
    SIZE--; // уменьшаем размер матрицы
    A_copy.erase(A_copy.begin() + row); // делаем вектор на 1 меньше(удаляем 1 столбец)
    for (int i = 0; i < SIZE; i++) // удаляем строчку
    {
        A_copy[i].erase(A_copy[i].begin() + column);
    }

    double counter;   // переменная для хранения накопленного произведения коэффициентов при минорах

    if ((row + column) % 2 == 0)
    {
        counter = 1;
    }
    else
    {
        counter = -1;
    }

    if (SIZE == 1)
    {
        counter = counter * A_copy[0][0];
        return counter;
    }

    double temp = 0;      // временная переменная для хранения элемента
    int temp_index = 0;   // временная переменная для хранения индекса элемента
    int repeat = SIZE - 1; //кол-во повторов

    for (int t = 0; t < repeat; t++)
    {
        temp = 0;
        temp_index = 0;

        for (int i = 0; i < SIZE; i++) // выбор элемента через который будем делать 0
        {
            if (A_copy[i][0] != 0)
            {
                temp = A_copy[i][0];
                temp_index = i;
                break;
            }
        }

        if (temp == 0) //определитель равен 0
        {
            return 0;
        }

        double k = 0; // коэффициент пропорциональности

        for (int i = 0; i < SIZE; i++) // умножение строчки на коэффициент пропорциональности и вычитание ее из всех остальных
        {
            if (i != temp_index)
            {
                k = A_copy[i][0] / temp;
                for (int j = 0; j < SIZE; j++)
                {
                    A_copy[i][j] = A_copy[i][j] - A_copy[temp_index][j] * k;
                }
            }
        }

        if (temp_index % 2 == 0)
        {
            counter = counter * temp;
        }
        else
        {
            counter = -counter * temp;
        }

        SIZE--; // уменьшаем размер матрицы

        A_copy.erase(A_copy.begin()); // делаем вектор на 1 меньше(удаляем 1 столбец)
        for (int i = 0; i < SIZE; i++) // удаляем строчку
        {
            A_copy[i].erase(A_copy[i].begin() + temp_index);
        }

        if (SIZE == 1)
            counter = counter * A_copy[0][0];
    }
    return counter;
}

Logic_matrix& Logic_matrix::operator++(int)
{
    count_matrix++;
    return *this;
}
