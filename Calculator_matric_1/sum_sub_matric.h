#ifndef SUM_SUB_MATRIC_H
#define SUM_SUB_MATRIC_H

#include <QDialog>

namespace Ui {
class Sum_sub_matric;
}

class Sum_sub_matric : public QDialog
{
    Q_OBJECT

public:
    explicit Sum_sub_matric(QWidget *parent = nullptr);
    ~Sum_sub_matric();

private slots:
    void on_comboBox_activated(int index1);

    void on_comboBox_2_activated(int index2);

private:
    Ui::Sum_sub_matric *ui;
};

#endif // SUM_SUB_MATRIC_H
