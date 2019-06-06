#include "view.h"
#include "ui_view.h"

View::View(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);   

    // Кнопки, которые нам нужны только для нескольких матриц
    ui->Add_matrix->setVisible(false);
    ui->Delete_matrix->setVisible(false);

    ui->Matrix_2->setVisible(false);
    ui->Matrix_3->setVisible(false);
    ui->Matrix_4->setVisible(false);

    // Виджеты для одной матрицы
    ui->matrix->setVisible(false);
    ui->mul_matrix->setVisible(false); // Знак равенства для умножения матрицы на число
    ui->det->setVisible(false); // Знак равенства для определителя матрицы
    ui->number->setVisible(false); // Ячейка для записи числа, на которое надо умножить матрицу
    ui->sum_matrix->setVisible(false); // Знак равенства для сложения и вычитания матриц
    ui->tr_matrix->setVisible(false);
    ui->inversion_matrix->setVisible(false);

    // ComboBox для сложения или вычитания матриц
    ui->variant_1->setVisible(false);
    ui->variant_2->setVisible(false);
    ui->variant_3->setVisible(false);

    ui->A_sum->setVisible(false);
    ui->B_sum->setVisible(false);
    ui->C_sum->setVisible(false);
    ui->D_sum->setVisible(false);
    ui->Size_of_matrix_B->setVisible(false);
    ui->Size_of_matrix_C->setVisible(false);
    ui->Size_of_matrix_D->setVisible(false);
    ui->Row_B->setVisible(false);
    ui->Row_C->setVisible(false);
    ui->Row_D->setVisible(false);
    ui->x_B->setVisible(false);
    ui->x_C->setVisible(false);
    ui->x_D->setVisible(false);
    ui->Column_B->setVisible(false);
    ui->Column_C->setVisible(false);
    ui->Column_D->setVisible(false);
    ui->matrix_mul->setVisible(false);
    matrixA.resize(2);
    for (int i = 0; i < 2; i++)
    {
        matrixA[i].resize(2);
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            QLineEdit* size = new QLineEdit("  0");
            matrixA[i][j] = size;
            ui->gridLayout->addWidget (size, i, j);
            size->setFixedSize(24, 19);
            ui->gridLayout->setRowStretch(7, i);
            ui->gridLayout->setColumnStretch(7, j);
        }
    }

    check_add_delete = 0;

    // Через сигналы об изменениях получаем нужные значения для их обработки и вывода на экран
    connect (ui->Choise_of_number, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (on_Choise_of_number_currentTextChanged(const QString &)));
    connect (ui->Row, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (on_Row_currentTextChanged (const QString)));
    connect (ui->Column, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (on_Column_currentTextChanged(const QString)));
    connect (ui->Row, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (Update_matrix ()));
    connect (ui->Column, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (Update_matrix ()));
    disconnect (ui->Row, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (on_mul_matrix_button_clicked()));
    disconnect (ui->Column, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (on_mul_matrix_button_clicked()));
    connect (ui->variant_1, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (on_variant_1_currentTextChanged(const QString&)));
    connect (ui->variant_2, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (on_variant_2_currentTextChanged(const QString&)));
    connect (ui->variant_3, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (on_variant_3_currentTextChanged(const QString&)));
    connect (ui->Row_B, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (on_Row_B_currentTextChanged (const QString&)));
    connect (ui->Column_B, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (on_Column_B_currentTextChanged(const QString&)));
    connect (ui->Row_C, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (on_Row_C_currentTextChanged (const QString&)));
    connect (ui->Column_C, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (on_Column_C_currentTextChanged(const QString&)));
    connect (ui->Row_D, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (on_Row_D_currentTextChanged (const QString&)));
    connect (ui->Column_D, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (on_Column_D_currentTextChanged(const QString&)));
}

View::~View()
{
    delete ui;
}

// Метод для получения количества строк в матрице
void View::on_Row_currentTextChanged(const QString &A)
{
    int row;
    row = A.toInt();
    array.set_rows(row);
}

// Метод для получения количества столбцов в матрице
void View::on_Column_currentTextChanged(const QString &A)
{
    int column;
    column = A.toInt();
    array.set_columns(column);
}

// Метод, в котором матрица меняет графически свою размерность
void View::Update_matrix()
{
    int rows_matrix, columns_matrix, counter_matrix;
    rows_matrix = array.get_rows();
    columns_matrix = array.get_columns();
    counter_matrix = array.get_count_matrix();

    QLayoutItem* ch;

    int count = 0;
    while (counter_matrix != count)
    {
        count++;
        if(count == 1)
        {
            while ((ch = ui->gridLayout->takeAt(0))!= nullptr)
            {
                delete ch->widget();
            }
            matrixA.resize(rows_matrix);
            for (int i = 0; i < rows_matrix; i++)
            {
                matrixA[i].resize(columns_matrix);
            }
            for (int i = 0; i < rows_matrix; i++)
            {
                for (int j = 0; j < columns_matrix; j++)
                {
                    QLineEdit* size = new QLineEdit("  0");
                    matrixA[i][j] = size;
                    ui->gridLayout->addWidget (size, i, j);
                    size->setFixedSize(24, 19);
                    ui->gridLayout->setRowStretch(rows_matrix, i);
                    ui->gridLayout->setColumnStretch(columns_matrix, j);
                }
            }
        }
        else if (count == 2)
        {
            while ((ch = ui->gridLayout_2->takeAt(0))!= nullptr)
            {
                delete ch->widget();
            }
            matrixB.resize(rows_matrix);
            for (int i = 0; i < rows_matrix; i++)
            {
                matrixB[i].resize(columns_matrix);
            }
            for (int i = 0; i < rows_matrix; i++)
            {
                QVector<QLineEdit> line;
                for (int j = 0; j < columns_matrix; j++)
                {
                    QLineEdit* size = new QLineEdit("  0");
                    matrixB[i][j] = size;
                    ui->gridLayout_2->addWidget (size, i, j);
                    size->setFixedSize(24, 19);
                    ui->gridLayout_2->setRowStretch(rows_matrix, i);
                    ui->gridLayout_2->setColumnStretch(columns_matrix, j);

                }
            }
        }
        else if (count == 3)
        {
            while ((ch = ui->gridLayout_3->takeAt(0))!= nullptr)
            {
                delete ch->widget();
            }
            matrixC.resize(rows_matrix);
            for (int i = 0; i < rows_matrix; i++)
            {
                matrixC[i].resize(columns_matrix);
            }
            for (int i = 0; i < rows_matrix; i++)
            {
                for (int j = 0; j < columns_matrix; j++)
                {
                    QLineEdit* size = new QLineEdit("  0");
                    matrixC[i][j] = size;
                    ui->gridLayout_3->addWidget (size, i, j);
                    size->setFixedSize(24, 19);
                    ui->gridLayout_3->setRowStretch(rows_matrix, i);
                    ui->gridLayout_3->setColumnStretch(columns_matrix, j);
                }
            }
        }
        else if (count == 4)
        {
            while ((ch = ui->gridLayout_4->takeAt(0))!= nullptr)
            {
                delete ch->widget();
            }
            matrixD.resize(rows_matrix);
            for (int i = 0; i < rows_matrix; i++)
            {
                matrixD[i].resize(columns_matrix);
            }
            for (int i = 0; i < rows_matrix; i++)
            {
                for (int j = 0; j < columns_matrix; j++)
                {
                    QLineEdit* size = new QLineEdit("  0");
                    matrixD[i][j] = size;
                    ui->gridLayout_4->addWidget (size, i, j);
                    size->setFixedSize(24, 19);
                    ui->gridLayout_4->setRowStretch(rows_matrix, i);
                    ui->gridLayout_4->setColumnStretch(columns_matrix, j);
                }
            }
        }
    }
}

// Метод, в котором мы получаем сигнал выбора количества матриц (одна матрица или несколько)
void View::on_Choise_of_number_currentTextChanged(const QString &arg1)
{
    QLayoutItem* deleted;
    while ((deleted = ui->gridLayout_5->takeAt(0))!= nullptr)
    {
        delete deleted->widget();
    }
    int RowsMatrix = array.get_rows();
    int ColumnsMatrix = array.get_columns();
    if (arg1 == "Несколько матриц")
    {
        array.set_count_matrix(2);

        ui->many_Matrix->setEnabled(true); // Раздел меню для нескольких матриц
        ui->one_Matrix->setEnabled(false); // Раздел меню для одной матрицы
        ui->matrix->setVisible(false);
        ui->mul_matrix->setVisible(false);
        ui->det->setVisible(false);
        ui->number->setVisible(false);
        ui->Matrix_2->setVisible(true);
        ui->Notifications->setVisible(true);
        ui->Add_matrix->setVisible(true);
        ui->Delete_matrix->setVisible(true);
        ui->Add_matrix->setEnabled(true);
        ui->Delete_matrix->setEnabled(false);
        ui->tr_matrix->setVisible(false);
        ui->inversion_matrix->setVisible(false);
        disconnect (ui->Add_matrix, SIGNAL(clicked()), this, SLOT (on_sum_sub_matrix_clicked()));
        disconnect(ui->Delete_matrix, SIGNAL(clicked()), this, SLOT (on_sum_sub_matrix_clicked()));

        matrixB.resize(RowsMatrix);
        for (int i = 0; i < RowsMatrix; i++)
        {
            matrixB[i].resize(ColumnsMatrix);
        }
        for (int i = 0; i < RowsMatrix; i++)
        {
            for (int j = 0; j < ColumnsMatrix; j++)
            {
                QLineEdit* size2 = new QLineEdit("  0");
                matrixB[i][j] = size2;
                ui->gridLayout_2->addWidget (size2, i, j);
                size2->setFixedSize(24, 19);
                ui->gridLayout_2->setRowStretch(RowsMatrix, i);
                ui->gridLayout_2->setColumnStretch(ColumnsMatrix, j);
            }
        }
    }

    else if (arg1 == "Одна матрица")
    {
        check_add_delete = 0;
        array.set_count_matrix(1);
        disconnect (ui->Row, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (on_mul_matrix_button_clicked()));
        disconnect (ui->Column, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (on_mul_matrix_button_clicked()));
        connect (ui->Row, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (Update_matrix ()));
        connect (ui->Column, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (Update_matrix ()));
        ui->many_Matrix->setEnabled(false);
        ui->one_Matrix->setEnabled(true);

        ui->variant_1->setVisible(false);
        ui->variant_2->setVisible(false);
        ui->variant_3->setVisible(false);
        ui->A_sum->setVisible(false);
        ui->B_sum->setVisible(false);
        ui->C_sum->setVisible(false);
        ui->D_sum->setVisible(false);
        ui->Size_of_matrix_B->setVisible(false);
        ui->Size_of_matrix_C->setVisible(false);
        ui->Size_of_matrix_D->setVisible(false);
        ui->Row_B->setVisible(false);
        ui->Row_C->setVisible(false);
        ui->Row_D->setVisible(false);
        ui->x_B->setVisible(false);
        ui->x_C->setVisible(false);
        ui->x_D->setVisible(false);
        ui->Column_B->setVisible(false);
        ui->Column_C->setVisible(false);
        ui->Column_D->setVisible(false);

        ui->Size_of_matrix->setText("Размер матрицы:");
        ui->Matrix_2->setVisible(false);
        ui->Matrix_3->setVisible(false);
        ui->Matrix_4->setVisible(false);
        ui->Notifications->setVisible(true);
        ui->Add_matrix->setVisible(false);
        ui->Delete_matrix->setVisible(false);
        ui->sum_matrix->setVisible(false);
        ui->matrix->setVisible(false);
        ui->variant_1->setVisible(false);
        ui->variant_2->setVisible(false);
        ui->variant_3->setVisible(false);
        ui->A_sum->setVisible(false);
        ui->B_sum->setVisible(false);
        ui->C_sum->setVisible(false);
        ui->D_sum->setVisible(false);
        ui->matrix_mul->setVisible(false);
        ui->Notifications->setVisible(true);
        QLayoutItem* ch;
        while ((ch = ui->gridLayout_2->takeAt(0))!= nullptr)
        {
            delete ch->widget();
        }
        while ((ch = ui->gridLayout_3->takeAt(0))!= nullptr)
        {
            delete ch->widget();
        }
        while ((ch = ui->gridLayout_4->takeAt(0))!= nullptr)
        {
            delete ch->widget();
        }
    }
}

// Добавление ещё одной матрицы
void View::on_Add_matrix_clicked()
{
    array++;
    int countMatrix = array.get_count_matrix();
    int rowsMatrix = array.get_rows();
    int columnsMatrix = array.get_columns();
    if(countMatrix == 3)
    {
        ui->Matrix_3->setVisible(true);
        ui->Delete_matrix->setEnabled(true);

        matrixC.resize(rowsMatrix);
        for (int i = 0; i < rowsMatrix; i++)
        {
            matrixC[i].resize(columnsMatrix);
        }
        for (int i = 0; i < rowsMatrix; i++)
        {
            for (int j = 0; j < columnsMatrix; j++)
            {
                QLineEdit* size2 = new QLineEdit("  0");
                matrixC[i][j] = size2;
                ui->gridLayout_3->addWidget (size2, i, j);
                size2->setFixedSize(24, 19);
                ui->gridLayout_3->setRowStretch(rowsMatrix, i);
                ui->gridLayout_3->setColumnStretch(columnsMatrix, j);
            }
        }
    }

    if(countMatrix == 4)
    {
        ui->Matrix_4->setVisible(true);
        ui->Add_matrix->setEnabled(false);

        matrixD.resize(rowsMatrix);
        for (int i = 0; i < rowsMatrix; i++)
        {
            matrixD[i].resize(columnsMatrix);
        }
        for (int i = 0; i < rowsMatrix; i++)
        {
            for (int j = 0; j < columnsMatrix; j++)
            {
                QLineEdit* size2 = new QLineEdit("  0");
                matrixD[i][j] = size2;
                ui->gridLayout_4->addWidget (size2, i, j);
                size2->setFixedSize(24, 19);
                ui->gridLayout_4->setRowStretch(rowsMatrix, i);
                ui->gridLayout_4->setColumnStretch(columnsMatrix, j);
            }
        }
    }
    if (check_add_delete == 1)
    {
       on_mul_matrix_button_clicked();
    }
}

void View::on_Delete_matrix_clicked()
{
    int countMatrix = array.get_count_matrix();
    QLayoutItem* deleted;
    if (countMatrix == 4)
    {
        while ((deleted = ui->gridLayout_4->takeAt(0))!= nullptr)
        {
            delete deleted->widget();
        }
        ui->Matrix_4->setVisible(false);
        ui->Add_matrix->setEnabled(true);
        matrixD.clear();
    }
    if (countMatrix == 3)
    {
        while ((deleted = ui->gridLayout_3->takeAt(0))!= nullptr)
        {
            delete deleted->widget();
        }
        ui->Matrix_3->setVisible(false);
        ui->Delete_matrix->setEnabled(false);
        matrixC.clear();
    }
    array--;
    if (check_add_delete == 1)
    {
       on_mul_matrix_button_clicked();
    }
}

void View::on_mul_matrix_number_clicked()
{
    QLayoutItem* deleted;
    while ((deleted = ui->gridLayout_5->takeAt(0))!= nullptr)
    {
        delete deleted->widget();
    }
    ui->Notifications->setVisible(false);
    ui->inversion_matrix->setVisible(false);
    ui->matrix->setVisible(true);
    ui->matrix->setText("· A");
    ui->det->setVisible(false);
    ui->tr_matrix->setVisible(false);
    ui->mul_matrix->setVisible(true);
    ui->number->setVisible(true);
}

void View::on_transporation_matrix_clicked()
{
    QLayoutItem* deleted;
    while ((deleted = ui->gridLayout_5->takeAt(0))!= nullptr)
    {
        delete deleted->widget();
    }
    ui->Notifications->setVisible(false);
    ui->det->setVisible(false);
    ui->mul_matrix->setVisible(false);
    ui->inversion_matrix->setVisible(false);
    ui->number->setVisible(false);
    ui->matrix->setVisible(true);
    ui->matrix->setText("A^(T)");
    ui->tr_matrix->setVisible(true);
}

// Нахождение определителя матрицы
void View::on_det_A_clicked()
{
    QLayoutItem* deleted;
    while ((deleted = ui->gridLayout_5->takeAt(0))!= nullptr)
    {
        delete deleted->widget();
    }
    ui->Notifications->setVisible(false);
    ui->matrix->setVisible(true);
    ui->mul_matrix->setVisible(false);
    ui->tr_matrix->setVisible(false);
    ui->number->setVisible(false);
    ui->inversion_matrix->setVisible(false);
    ui->matrix->setText("det A");
    ui->det->setVisible(true);
}

void View::on_inverse_matrix_clicked()
{
    QLayoutItem* deleted;
    while ((deleted = ui->gridLayout_5->takeAt(0))!= nullptr)
    {
        delete deleted->widget();
    }
    ui->Notifications->setVisible(false);
    ui->det->setVisible(false);
    ui->mul_matrix->setVisible(false);
    ui->number->setVisible(false);
    ui->tr_matrix->setVisible(false);
    ui->matrix->setVisible(true);
    ui->matrix->setText("A^(-1)");
    ui->inversion_matrix->setVisible(true);
}

void View::on_mul_matrix_clicked()
{
    QLayoutItem* deleted;
    while ((deleted = ui->gridLayout_5->takeAt(0))!= nullptr)
    {
        delete deleted->widget();
    }
    int _rows = array.get_rows();
    int _columns = array.get_columns();
    QVector <QVector<double>> matrix;
    double one_element;
    matrix.resize(_rows);
    for (int i = 0; i < _rows; i++)
    {
        matrix[i].resize(_columns);
    }
    bool check_line = false;
    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _columns; j++)
        {
            check_line = array.check_line_edit(matrixA[i][j]->text());
            if (check_line == true)
            {
                one_element = matrixA[i][j]->text().toDouble();
                matrix[i][j] = one_element;
            }
            else
            {
                error_scanf(i, j, matrixA);
                matrixA[i][j]->setStyleSheet("QLineEdit { background: rgb(255, 255, 255);}");
                break;
            }
        }
        if (check_line == false)
        {
            break;
        }
    }
    if (check_line == true)
    {
        check_line = array.check_line_edit(ui->number->text());
        if (check_line == true)
        {
            array.set_matrix(matrix);
            double number = ui->number->text().toDouble();
            matrix = array.matrix_mul(number);
            int check;
            for (int i = 0; i < _rows; i++)
            {
                for (int j = 0; j < _columns; j++)
                {
                    QLabel* size = new QLabel;
                    QFont font = size->font();
                    font.setPixelSize(12);
                    size->setFont(font);
                    check = matrix[i][j];
                    if(matrix[i][j] == check)
                    {
                        size->setText(QString("%1").arg(matrix[i][j], 0, 'f', 0));
                    }
                    else
                    {
                        size->setText(QString("%1").arg(matrix[i][j], 0, 'f', 2));
                    }
                    ui->gridLayout_5->addWidget (size, i, j);
                    size->setFixedSize(28, 19);
                    ui->gridLayout_5->setRowStretch(1, i);
                    ui->gridLayout_5->setColumnStretch(1, j);
                }
            }
        }
        else
        {
            error_scanf();
            ui->number->setStyleSheet("QLineEdit { background: rgb(255, 255, 255);}");
        }
    }
}

void View::on_tr_matrix_clicked()
{
    QLayoutItem* deleted;
    while ((deleted = ui->gridLayout_5->takeAt(0))!= nullptr)
    {
        delete deleted->widget();
    }
    int rows = array.get_rows();
    int columns = array.get_columns();
    QVector <QVector<double>> matrix;
    double one_element;
    matrix.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        matrix[i].resize(columns);
    }
    bool check_line_tr = false;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            check_line_tr = array.check_line_edit(matrixA[i][j]->text());
            if (check_line_tr == true)
            {
                one_element = matrixA[i][j]->text().toDouble();
                matrix[i][j] = one_element;
            }
            else
            {
                error_scanf(i, j, matrixA);
                matrixA[i][j]->setStyleSheet("QLineEdit { background: rgb(255, 255, 255);}");
                break;
            }
        }
        if (check_line_tr == false)
        {
            break;
        }
    }
    if (check_line_tr == true)
    {
        array.set_matrix(matrix);
        matrix.resize(columns);
        for (int i = 0; i < columns; i++)
        {
            matrix[i].resize(rows);
        }
        matrix = array.matrix_transporation();
        int check;
        for (int i = 0; i < columns; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                QLabel* size = new QLabel;
                QFont font = size->font();
                font.setPixelSize(12);
                size->setFont(font);
                check = matrix[i][j];
                if(matrix[i][j] == check)
                {
                    size->setText(QString("%1").arg(matrix[i][j], 0, 'f', 0));
                }
                else
                {
                    size->setText(QString("%1").arg(matrix[i][j], 0, 'f', 2));
                }
                ui->gridLayout_5->addWidget (size, i, j);
                size->setFixedSize(28, 19);
                ui->gridLayout_5->setRowStretch(1, i);
                ui->gridLayout_5->setColumnStretch(1, j);
            }
        }
    }
}

void View::on_det_clicked()
{
    QLayoutItem* deleted;
    while ((deleted = ui->gridLayout_5->takeAt(0))!= nullptr)
    {
        delete deleted->widget();
    }
    int _rows = array.get_rows();
    int _columns = array.get_columns();
    if (_rows == _columns)
    {
        QVector <QVector<double>> matrix;
        double one_element;
        matrix.resize(_rows);
        for (int i = 0; i < _rows; i++)
        {
            matrix[i].resize(_columns);
        }
        bool check_line_det = false;
        for (int i = 0; i < _rows; i++)
        {
            for (int j = 0; j < _columns; j++)
            {
                check_line_det = array.check_line_edit(matrixA[i][j]->text());
                if (check_line_det == true)
                {
                    one_element = matrixA[i][j]->text().toDouble();
                    matrix[i][j] = one_element;
                }
                else
                {
                    error_scanf(i, j, matrixA);
                    matrixA[i][j]->setStyleSheet("QLineEdit { background: rgb(255, 255, 255);}");
                    break;
                }
            }
            if (check_line_det == false)
            {
                break;
            }
        }
        if (check_line_det == true)
        {
            array.set_matrix(matrix);
            double number;
            number = array.det_matrix();
            int check;
            QLabel* size = new QLabel;
            QFont font = size->font();
            font.setPixelSize(12);
            size->setFont(font);
            check = number;
            if(number == check)
            {
                size->setText(QString("%1").arg(number, 0, 'f', 0));
            }
            else
            {
                size->setText(QString("%1").arg(number, 0, 'f', 2));
            }
            ui->gridLayout_5->addWidget (size, 0, 0);
            size->setFixedSize(28, 19);
            ui->gridLayout_5->setRowStretch(_rows, 0);
            ui->gridLayout_5->setColumnStretch(_columns, 0);
        }
    }
    else
    {
        QMessageBox messageBoxError;
        messageBoxError.critical(nullptr, "Ошибка", "Матрица должна быть квадратной!");
        messageBoxError.setFixedSize(528,228);
    }
}

void View::on_inversion_matrix_clicked()
{
    QLayoutItem* deleted;
    while ((deleted = ui->gridLayout_5->takeAt(0))!= nullptr)
    {
        delete deleted->widget();
    }
    int _rows = array.get_rows();
    int _columns = array.get_columns();
    QVector <QVector<double>> matrix;
    double one_element;
    matrix.resize(_rows);
    for (int i = 0; i < _rows; i++)
    {
        matrix[i].resize(_columns);
    }
    bool check_line_inversion = false;
    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _columns; j++)
        {
            check_line_inversion = array.check_line_edit(matrixA[i][j]->text());
            if (check_line_inversion == true)
            {
                one_element = matrixA[i][j]->text().toDouble();
                matrix[i][j] = one_element;
            }
            else
            {
                error_scanf(i, j, matrixA);
                matrixA[i][j]->setStyleSheet("QLineEdit { background: rgb(255, 255, 255);}");
                break;
            }
        }
        if (check_line_inversion == false)
        {
            break;
        }
    }
    if (check_line_inversion == true)
    {
        array.set_matrix(matrix);
        if (_rows == _columns)
        {
            double det = array.det_matrix();
            if (det != 0)
            {
                matrix = array.matrix_inverse();
                int check;
                for (int i = 0; i < _rows; i++)
                {
                    for (int j = 0; j < _columns; j++)
                    {
                        QLabel* size = new QLabel;
                        QFont font = size->font();
                        font.setPixelSize(12);
                        size->setFont(font);
                        check = matrix[i][j];
                        if(matrix[i][j] == check)
                        {
                            size->setText(QString("%1").arg(matrix[i][j], 0, 'f', 0));
                        }
                        else
                        {
                            size->setText(QString("%1").arg(matrix[i][j], 0, 'f', 2));
                        }
                        ui->gridLayout_5->addWidget (size, i, j);
                        size->setFixedSize(40, 19);
                        ui->gridLayout_5->setRowStretch(1, i);
                        ui->gridLayout_5->setColumnStretch(1, j);
                    }
                }
            }
            else
            {
                QMessageBox messageBoxError;
                messageBoxError.critical(nullptr, "Невозможно найти", "Определитель матрицы равен нулю!");
                messageBoxError.setFixedSize(528,228);
            }
        }
        else
        {
            QMessageBox messageBoxError;
            messageBoxError.critical(nullptr, "Ошибка", "Матрица должна быть квадратной!");
            messageBoxError.setFixedSize(528,228);
        }
    }
}

void View::on_mul_matrix_button_clicked()
{
    QLayoutItem* deleted;
    while ((deleted = ui->gridLayout_5->takeAt(0))!= nullptr)
    {
        delete deleted->widget();
    }
    ui->Notifications->setVisible(false);
    ui->variant_1->setVisible(false);
    ui->variant_2->setVisible(false);
    ui->variant_3->setVisible(false);
    ui->A_sum->setVisible(false);
    ui->B_sum->setVisible(false);
    ui->C_sum->setVisible(false);
    ui->D_sum->setVisible(false);
    ui->sum_matrix->setVisible(false);
    ui->Size_of_matrix_C->setVisible(false);
    ui->Row_C->setVisible(false);
    ui->x_C->setVisible(false);
    ui->Column_C->setVisible(false);
    ui->Size_of_matrix_D->setVisible(false);
    ui->Row_D->setVisible(false);
    ui->x_D->setVisible(false);
    ui->Column_D->setVisible(false);
    ui->Size_of_matrix->setText("Размер матрицы A:");
    ui->Size_of_matrix_B->setVisible(true);
    ui->Row_B->setVisible(true);
    ui->x_B->setVisible(true);
    ui->Column_B->setVisible(true);
    ui->matrix_mul->setVisible(true);
    ui->matrix->setVisible(true);
    ui->matrix->setText("A · B");
    int count = array.get_count_matrix();
    int rows_matrix = array.get_rows();
    int columns_matrix = array.get_columns();
    while ((deleted = ui->gridLayout->takeAt(0))!= nullptr)
    {
        delete deleted->widget();
    }
    matrixA.resize(rows_matrix);
    for (int i = 0; i < rows_matrix; i++)
    {
        matrixA[i].resize(columns_matrix);
    }
    for (int i = 0; i < rows_matrix; i++)
    {
        for (int j = 0; j < columns_matrix; j++)
        {
            QLineEdit* size = new QLineEdit("  0");
            matrixA[i][j] = size;
            ui->gridLayout->addWidget (size, i, j);
            size->setFixedSize(24, 19);
            ui->gridLayout->setRowStretch(rows_matrix, i);
            ui->gridLayout->setColumnStretch(columns_matrix, j);
        }
    }
    while ((deleted = ui->gridLayout_2->takeAt(0))!= nullptr)
    {
        delete deleted->widget();
    }
    rows_matrix = array_B.get_rows();
    columns_matrix = array_B.get_columns();
    matrixB.resize(rows_matrix);
    for (int i = 0; i < rows_matrix; i++)
    {
        matrixB[i].resize(columns_matrix);
    }
    for (int i = 0; i < rows_matrix; i++)
    {
        for (int j = 0; j < columns_matrix; j++)
        {
            QLineEdit* size = new QLineEdit("  0");
            matrixB[i][j] = size;
            ui->gridLayout_2->addWidget (size, i, j);
            size->setFixedSize(24, 19);
            ui->gridLayout_2->setRowStretch(rows_matrix, i);
            ui->gridLayout_2->setColumnStretch(columns_matrix, j);
        }
    }
    if (count > 2)
    {
         ui->Size_of_matrix_C->setVisible(true);
         ui->Row_C->setVisible(true);
         ui->x_C->setVisible(true);
         ui->Column_C->setVisible(true);
         ui->matrix->setText("A · B · С");
         rows_matrix = array_C.get_rows();
         columns_matrix = array_C.get_columns();
         while ((deleted = ui->gridLayout_3->takeAt(0))!= nullptr)
         {
             delete deleted->widget();
         }
         matrixC.resize(rows_matrix);
         for (int i = 0; i < rows_matrix; i++)
         {
             matrixC[i].resize(columns_matrix);
         }
         for (int i = 0; i < rows_matrix; i++)
         {
             for (int j = 0; j < columns_matrix; j++)
             {
                 QLineEdit* size = new QLineEdit("  0");
                 matrixC[i][j] = size;
                 ui->gridLayout_3->addWidget (size, i, j);
                 size->setFixedSize(24, 19);
                 ui->gridLayout_3->setRowStretch(rows_matrix, i);
                 ui->gridLayout_3->setColumnStretch(columns_matrix, j);
             }
         }
         if (count == 4)
         {
             ui->Size_of_matrix_D->setVisible(true);
             ui->Row_D->setVisible(true);
             ui->x_D->setVisible(true);
             ui->Column_D->setVisible(true);
             ui->matrix->setText("A · B · С · В");
             rows_matrix = array_D.get_rows();
             columns_matrix = array_D.get_columns();
             while ((deleted = ui->gridLayout_4->takeAt(0))!= nullptr)
             {
                 delete deleted->widget();
             }
             matrixD.resize(rows_matrix);
             for (int i = 0; i < rows_matrix; i++)
             {
                 matrixD[i].resize(columns_matrix);
             }
             for (int i = 0; i < rows_matrix; i++)
             {
                 for (int j = 0; j < columns_matrix; j++)
                 {
                     QLineEdit* size = new QLineEdit("  0");
                     matrixD[i][j] = size;
                     ui->gridLayout_4->addWidget (size, i, j);
                     size->setFixedSize(24, 19);
                     ui->gridLayout_4->setRowStretch(rows_matrix, i);
                     ui->gridLayout_4->setColumnStretch(columns_matrix, j);
                 }
             }
         }
    }
    check_add_delete = 1;
    connect (ui->Row, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (on_mul_matrix_button_clicked()));
    connect (ui->Column, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (on_mul_matrix_button_clicked()));
    disconnect(ui->Delete_matrix, SIGNAL(clicked()), this, SLOT (on_sum_sub_matrix_clicked()));
    disconnect (ui->Add_matrix, SIGNAL(clicked()), this, SLOT (on_sum_sub_matrix_clicked()));
}

void View::on_matrix_mul_clicked()
{
    QLayoutItem* deleted;
    while ((deleted = ui->gridLayout_5->takeAt(0))!= nullptr)
    {
        delete deleted->widget();
    }
    int counter = array.get_count_matrix();
    int row_A = array.get_rows();
    int column_A = array.get_columns();
    double one_element;
    int column_push = column_A;
    QVector <QVector<double>> matrix1;
    matrix1.resize(row_A);
    for (int i = 0; i < row_A; i++)
    {
        matrix1[i].resize(column_A);
    }
    bool check_line_mul = false;
    for (int i = 0; i < row_A; i++)
    {
        for (int j = 0; j < column_A; j++)
        {
            check_line_mul = array.check_line_edit(matrixA[i][j]->text());
            if (check_line_mul == true)
            {
                one_element = matrixA[i][j]->text().toDouble();
                matrix1[i][j] = one_element;
            }
            else
            {
                error_scanf(i, j, matrixA);
                matrixA[i][j]->setStyleSheet("QLineEdit { background: rgb(255, 255, 255);}");
                break;
            }
        }
        if (check_line_mul == false)
        {
            break;
        }
    }
    QVector <QVector<double>> matrix3;
    QVector <QVector<double>> matrix4;
    if (check_line_mul == true)
    {
        int row_B = array_B.get_rows();
        int column_B = array_B.get_columns();
        QVector <QVector<double>> matrix2;
        matrix2.resize(row_B);
        for (int i = 0; i < row_B; i++)
        {
            matrix2[i].resize(column_B);
        }
        check_line_mul = false;
        for (int i = 0; i < row_B; i++)
        {
            for (int j = 0; j < column_B; j++)
            {
                check_line_mul = array.check_line_edit(matrixB[i][j]->text());
                if (check_line_mul == true)
                {
                    one_element = matrixB[i][j]->text().toDouble();
                    matrix2[i][j] = one_element;
                }
                else
                {
                     error_scanf(i, j, matrixB);
                     matrixB[i][j]->setStyleSheet("QLineEdit { background: rgb(255, 255, 255);}");
                     break;
                }
             }
             if (check_line_mul == false)
             {
                    break;
             }
        }
        if (check_line_mul == true)
        {
            array.set_matrix(matrix1);
            array_B.set_matrix(matrix2);
            if (counter > 2)
            {
                int row_C = array_C.get_rows();
                int column_C = array_C.get_columns();
                matrix3.resize(row_C);
                for (int i = 0; i < row_C; i++)
                {
                    matrix3[i].resize(column_C);
                }
                check_line_mul = false;
                for (int i = 0; i < row_C; i++)
                {
                    for (int j = 0; j < column_C; j++)
                    {
                        check_line_mul = array.check_line_edit(matrixC[i][j]->text());
                        if (check_line_mul == true)
                        {
                            one_element = matrixC[i][j]->text().toDouble();
                            matrix3[i][j] = one_element;
                        }
                        else
                        {
                             error_scanf(i, j, matrixC);
                             matrixC[i][j]->setStyleSheet("QLineEdit { background: rgb(255, 255, 255);}");
                             break;
                        }
                     }
                     if (check_line_mul == false)
                     {
                            break;
                     }
                }
                if (check_line_mul == true)
                {
                    array_C.set_matrix(matrix3);
                    if (counter == 4)
                    {
                        int row_D = array_D.get_rows();
                        int column_D = array_D.get_columns();
                        matrix4.resize(row_D);
                        for (int i = 0; i < row_D; i++)
                        {
                            matrix4[i].resize(column_D);
                        }
                        check_line_mul = false;
                        for (int i = 0; i < row_D; i++)
                        {
                            for (int j = 0; j < column_D; j++)
                            {
                                check_line_mul = array.check_line_edit(matrixD[i][j]->text());
                                if (check_line_mul == true)
                                {
                                    one_element = matrixD[i][j]->text().toDouble();
                                    matrix4[i][j] = one_element;
                                }
                                else
                                {
                                     error_scanf(i, j, matrixD);
                                     matrixD[i][j]->setStyleSheet("QLineEdit { background: rgb(255, 255, 255);}");
                                     break;
                                }
                             }
                             if (check_line_mul == false)
                             {
                                    break;
                             }
                        }
                        if (check_line_mul == true)
                        {
                               array_D.set_matrix(matrix4);
                        }
                    }
                }
            }
        }
    }
    if (check_line_mul == true)
    {
        bool columns_rows = true;
        if (array == array_B)
        {
            array = array * array_B;
            if (counter > 2)
            {
                if (array == array_C)
                {
                    array = array * array_C;
                    if (counter == 4)
                    {
                        if (array == array_D)
                        {
                            array = array * array_D;
                        }
                        else
                        {
                            QMessageBox messageBoxError;
                            messageBoxError.critical(nullptr, "Ошибка", "Количество столбцов одной матрицы не совпадает с количеством строк второй матрицы!");
                            messageBoxError.setFixedSize(528,228);
                            columns_rows = false;
                        }
                    }
                }
                else
                {
                    QMessageBox messageBoxError;
                    messageBoxError.critical(nullptr, "Ошибка", "Количество столбцов одной матрицы не совпадает с количеством строк второй матрицы!");
                    messageBoxError.setFixedSize(528,228);
                    columns_rows = false;
                }
            }
        }
        else
        {
            QMessageBox messageBoxError;
            messageBoxError.critical(nullptr, "Ошибка", "Количество столбцов одной матрицы не совпадает с количеством строк второй матрицы!");
            messageBoxError.setFixedSize(528,228);
            columns_rows = false;
        }
        if (columns_rows == true)
        {
            int rows_finish = array.get_rows();
            int columns_finish = array.get_columns();
            matrix1.resize(rows_finish);
            for (int i = 0; i < rows_finish; i++)
            {
                matrix1[i].resize(columns_finish);
            }
            matrix1 = array.get_matrix();
            int check;
            for (int i = 0; i < rows_finish; i++)
            {
                for (int j = 0; j < columns_finish; j++)
                {
                    QLabel* size = new QLabel;
                    QFont font = size->font();
                    font.setPixelSize(12);
                    size->setFont(font);
                    check = matrix1[i][j];
                    if(matrix1[i][j] == check)
                    {
                        size->setText(QString("%1").arg(matrix1[i][j], 0, 'f', 0));
                    }
                    else
                    {
                        size->setText(QString("%1").arg(matrix1[i][j], 0, 'f', 2));
                    }
                    ui->gridLayout_5->addWidget (size, i, j);
                    size->setFixedSize(28, 19);
                    ui->gridLayout_5->setRowStretch(1, i);
                    ui->gridLayout_5->setColumnStretch(1, j);
                }
            }
        }
        array.set_columns(column_push);
    }
}

void View::on_sum_sub_matrix_clicked()
{
    check_add_delete = 0;
    QLayoutItem* deleted;
    while ((deleted = ui->gridLayout_5->takeAt(0))!= nullptr)
    {
        delete deleted->widget();
    }
    ui->Notifications->setVisible(false);
    ui->variant_2->setVisible(false);
    ui->variant_3->setVisible(false);
    ui->Size_of_matrix_B->setVisible(false);
    ui->Size_of_matrix_C->setVisible(false);
    ui->Size_of_matrix_D->setVisible(false);
    ui->Row_B->setVisible(false);
    ui->Row_C->setVisible(false);
    ui->Row_D->setVisible(false);
    ui->x_B->setVisible(false);
    ui->x_C->setVisible(false);
    ui->x_D->setVisible(false);
    ui->Column_B->setVisible(false);
    ui->Column_C->setVisible(false);
    ui->Column_D->setVisible(false);
    ui->matrix_mul->setVisible(false);

    ui->Size_of_matrix->setText("Размер матрицы:");
    ui->Notifications->setVisible(false);
    ui->matrix->setVisible(false);
    ui->mul_matrix->setVisible(false);
    ui->number->setVisible(false);
    ui->det->setVisible(false);
    ui->sum_matrix->setVisible(true);
    int counter = array.get_count_matrix();
    ui->variant_1->setVisible(true);
    int rows_matrix = array.get_rows();
    int columns_matrix = array.get_columns();

    ui->A_sum->setVisible(true);
    ui->B_sum->setVisible(true);
    ui->C_sum->setVisible(false);
    ui->D_sum->setVisible(false);
    while ((deleted = ui->gridLayout_2->takeAt(0))!= nullptr)
    {
        delete deleted->widget();
    }
    matrixB.resize(rows_matrix);
    for (int i = 0; i < rows_matrix; i++)
    {
        matrixB[i].resize(columns_matrix);
    }
    for (int i = 0; i < rows_matrix; i++)
    {
        QVector<QLineEdit> line;
        for (int j = 0; j < columns_matrix; j++)
        {
            QLineEdit* size = new QLineEdit("  0");
            matrixB[i][j] = size;
            ui->gridLayout_2->addWidget (size, i, j);
            size->setFixedSize(24, 19);
            ui->gridLayout_2->setRowStretch(rows_matrix, i);
            ui->gridLayout_2->setColumnStretch(columns_matrix, j);

        }
    }
    if (counter > 2)
    {
        ui->A_sum->setVisible(true);
        ui->B_sum->setVisible(true);
        ui->C_sum->setVisible(true);
        ui->D_sum->setVisible(false);
        ui->variant_2->setVisible(true);
        while ((deleted = ui->gridLayout_3->takeAt(0))!= nullptr)
        {
            delete deleted->widget();
        }
        matrixC.resize(rows_matrix);
        for (int i = 0; i < rows_matrix; i++)
        {
            matrixC[i].resize(columns_matrix);
        }
        for (int i = 0; i < rows_matrix; i++)
        {
            QVector<QLineEdit> line;
            for (int j = 0; j < columns_matrix; j++)
            {
                QLineEdit* size = new QLineEdit("  0");
                matrixC[i][j] = size;
                ui->gridLayout_3->addWidget (size, i, j);
                size->setFixedSize(24, 19);
                ui->gridLayout_3->setRowStretch(rows_matrix, i);
                ui->gridLayout_3->setColumnStretch(columns_matrix, j);

            }
        }
    }
    if (counter == 4)
    {
        ui->A_sum->setVisible(true);
        ui->B_sum->setVisible(true);
        ui->C_sum->setVisible(true);
        ui->D_sum->setVisible(true);
        ui->variant_2->setVisible(true);
        ui->variant_3->setVisible(true);
        while ((deleted = ui->gridLayout_4->takeAt(0))!= nullptr)
        {
            delete deleted->widget();
        }
        matrixD.resize(rows_matrix);
        for (int i = 0; i < rows_matrix; i++)
        {
            matrixD[i].resize(columns_matrix);
        }
        for (int i = 0; i < rows_matrix; i++)
        {
            QVector<QLineEdit> line;
            for (int j = 0; j < columns_matrix; j++)
            {
                QLineEdit* size = new QLineEdit("  0");
                matrixD[i][j] = size;
                ui->gridLayout_4->addWidget (size, i, j);
                size->setFixedSize(24, 19);
                ui->gridLayout_4->setRowStretch(rows_matrix, i);
                ui->gridLayout_4->setColumnStretch(columns_matrix, j);

            }
        }
    }
    connect (ui->Add_matrix, SIGNAL(clicked()), this, SLOT (on_sum_sub_matrix_clicked()));
    connect (ui->Delete_matrix, SIGNAL(clicked()), this, SLOT (on_sum_sub_matrix_clicked()));
    disconnect (ui->Row, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (on_mul_matrix_button_clicked()));
    disconnect (ui->Column, SIGNAL(currentIndexChanged(const QString &)), this, SLOT (on_mul_matrix_button_clicked()));
}
void View::on_sum_matrix_clicked()
{
    QLayoutItem* deleted;
    while ((deleted = ui->gridLayout_5->takeAt(0))!= nullptr)
    {
        delete deleted->widget();
    }
    int counter_matrix = array.get_count_matrix();
    int row = array.get_rows();
    int column = array.get_columns();
    double one_element;

    QVector <QVector<double>> matrix1;
    matrix1.resize(row);
    for (int i = 0; i < row; i++)
    {
        matrix1[i].resize(column);
    }
    bool check_line_sum = false;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            check_line_sum = array.check_line_edit(matrixA[i][j]->text());
            if (check_line_sum == true)
            {
                one_element = matrixA[i][j]->text().toDouble();
                matrix1[i][j] = one_element;
            }
            else
            {
                 error_scanf(i, j, matrixA);
                 matrixA[i][j]->setStyleSheet("QLineEdit { background: rgb(255, 255, 255);}");
                 break;
            }
         }
         if (check_line_sum == false)
         {
                break;
         }
    }
    if (check_line_sum == true)
    {
        QVector <QVector<double>> matrix2;
        matrix2.resize(row);
        for (int i = 0; i < row; i++)
        {
            matrix2[i].resize(column);
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                check_line_sum = array.check_line_edit(matrixB[i][j]->text());
                if (check_line_sum == true)
                {
                    one_element = matrixB[i][j]->text().toDouble();
                    matrix2[i][j] = one_element;
                }
                else
                {
                     error_scanf(i, j, matrixB);
                     matrixB[i][j]->setStyleSheet("QLineEdit { background: rgb(255, 255, 255);}");
                     break;
                }
             }
             if (check_line_sum == false)
             {
                    break;
             }
        }
        if (check_line_sum == true)
        {
            QVector <QVector<double>> matrix3;
            QVector <QVector<double>> matrix4;
            if (counter_matrix == 2)
            {
                array.set_matrix(matrix1, matrix2);
            }
            else
            {
                matrix3.resize(row);
                for (int i = 0; i < row; i++)
                {
                    matrix3[i].resize(column);
                }
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < column; j++)
                    {
                        check_line_sum = array.check_line_edit(matrixC[i][j]->text());
                        if (check_line_sum == true)
                        {
                            one_element = matrixC[i][j]->text().toDouble();
                            matrix3[i][j] = one_element;
                        }
                        else
                        {
                             error_scanf(i, j, matrixC);
                             matrixC[i][j]->setStyleSheet("QLineEdit { background: rgb(255, 255, 255);}");
                             break;
                        }
                     }
                     if (check_line_sum == false)
                     {
                            break;
                     }
                }
                if (check_line_sum == true)
                {
                    if (counter_matrix == 4)
                    {
                        matrix4.resize(row);
                        for (int i = 0; i < row; i++)
                        {
                            matrix4[i].resize(column);
                        }
                        for (int i = 0; i < row; i++)
                        {
                            for (int j = 0; j < column; j++)
                            {
                                check_line_sum = array.check_line_edit(matrixD[i][j]->text());
                                if (check_line_sum == true)
                                {
                                    one_element = matrixD[i][j]->text().toDouble();
                                    matrix4[i][j] = one_element;
                                }
                                else
                                {
                                     error_scanf(i, j, matrixD);
                                     matrixD[i][j]->setStyleSheet("QLineEdit { background: rgb(255, 255, 255);}");
                                     break;
                                }
                             }
                             if (check_line_sum == false)
                             {
                                    break;
                             }
                        }
                        array.set_matrix(matrix1, matrix2, matrix3, matrix4);
                    }
                    else
                    {
                        array.set_matrix(matrix1, matrix2, matrix3);
                    }
                }
            }
        }
    }
    if (check_line_sum == true)
    {
        matrix1 = array.sum_sub_matrix();
        int check;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                QLabel* size = new QLabel;
                QFont font = size->font();
                font.setPixelSize(12);
                size->setFont(font);
                check = matrix1[i][j];
                if(matrix1[i][j] == check)
                {
                    size->setText(QString("%1").arg(matrix1[i][j], 0, 'f', 0));
                }
                else
                {
                    size->setText(QString("%1").arg(matrix1[i][j], 0, 'f', 2));
                }
                ui->gridLayout_5->addWidget (size, i, j);
                size->setFixedSize(28, 19);
                ui->gridLayout_5->setRowStretch(1, i);
                ui->gridLayout_5->setColumnStretch(1, j);
            }
        }
    }
}

void View::on_variant_1_currentTextChanged(const QString &symbol1)
{
    array.set_symbol(symbol1, 0);
}

void View::on_variant_2_currentTextChanged(const QString &symbol2)
{
    array.set_symbol(symbol2, 1);
}

void View::on_variant_3_currentTextChanged(const QString &symbol3)
{
    array.set_symbol(symbol3, 2);
}

// Метод для получения количества строк в матрице
void View::on_Row_B_currentTextChanged(const QString &B)
{
    int row;
    row = B.toInt();
    array_B.set_rows(row);
    on_mul_matrix_button_clicked();
}

// Метод для получения количества столбцов в матрице
void View::on_Column_B_currentTextChanged(const QString &B)
{
    int column;
    column = B.toInt();
    array_B.set_columns(column);
    on_mul_matrix_button_clicked();
}

// Метод для получения количества строк в матрице
void View::on_Row_C_currentTextChanged(const QString &C)
{
    int row;
    row = C.toInt();
    array_C.set_rows(row);
    on_mul_matrix_button_clicked();
}

// Метод для получения количества столбцов в матрице
void View::on_Column_C_currentTextChanged(const QString &C)
{
    int column;
    column = C.toInt();
    array_C.set_columns(column);
    on_mul_matrix_button_clicked();
}

// Метод для получения количества строк в матрице
void View::on_Row_D_currentTextChanged(const QString &D)
{
    int row;
    row = D.toInt();
    array_D.set_rows(row);
    on_mul_matrix_button_clicked();
}

// Метод для получения количества столбцов в матрице
void View::on_Column_D_currentTextChanged(const QString &D)
{
    int column;
    column = D.toInt();
    array_D.set_columns(column);
    on_mul_matrix_button_clicked();
}

void View::error_scanf(int row, int column, QVector<QVector<QLineEdit*>> matrix)
{
    matrix[row][column]->setStyleSheet("QLineEdit { background: rgb(240, 128, 128);}");
    QMessageBox messageBoxError;
    messageBoxError.critical(nullptr, "Ошибка", "Неправильный формат ввода!");
    messageBoxError.setFixedSize(528,228);
}

void View::error_scanf()
{
    ui->number->setStyleSheet("QLineEdit { background: rgb(240, 128, 128);}");
    QMessageBox messageBoxError;
    messageBoxError.critical(nullptr, "Ошибка", "Неправильный формат ввода!");
    messageBoxError.setFixedSize(528,228);
}
