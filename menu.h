#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QWidget>
#include <QComboBox>
#include <QLineEdit>

namespace Ui {
class MainWindow;
class Controller_matrix;
}

class Model_matrix;
class View_matrix;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_Row_currentIndexChanged(int index);
    void on_Column_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};

class Controller_matrix : public QMainWindow
{
public:
    int rows;
    int columns;
    Controller_matrix () : rows(0) , columns (0)
    {}
    int get_rows();
    int get_columns();
};

#endif // MENU_H
