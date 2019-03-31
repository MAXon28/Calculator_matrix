#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QWidget>
#include <QComboBox>
#include <QLineEdit>

namespace Ui {
class View;
}

class Model_matrix;
class Controller_matrix;

class View : public QMainWindow
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = nullptr);
    ~View();
    void get_matrix (int rows, int columns);

public slots:
    void on_Row_currentIndexChanged (int index);
    void on_Column_currentIndexChanged (int index);


private:
    Ui::View *ui;
};

#endif // VIEW_H
