#include "sum_sub_matric.h"
#include "ui_sum_sub_matric.h"
#include "QLineEdit"
#include "QVector"
#include "QString"
#include "QPointer"

class comboBoxes
{
private:
    QVector<QComboBox> c1;
    QVector<QComboBox> c2;
public:
};

Sum_sub_matric::Sum_sub_matric(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sum_sub_matric)
{
    ui->setupUi(this);

}

Sum_sub_matric::~Sum_sub_matric()
{
    delete ui;
}

void Sum_sub_matric::on_comboBox_activated(int index1)
{
    QVector<QLineEdit*> matrica_1;


    matrica_1.append(ui->lineEdit_15);
    matrica_1.append(ui->lineEdit_16);
    matrica_1.append(ui->lineEdit_17);
    matrica_1.append(ui->lineEdit_18);
    matrica_1.append(ui->lineEdit_19);
    matrica_1.append(ui->lineEdit_20);
    matrica_1.append(ui->lineEdit_21);
    matrica_1.append(ui->lineEdit_22);
    matrica_1.append(ui->lineEdit_23);
    matrica_1.append(ui->lineEdit_24);
    matrica_1.append(ui->lineEdit_25);
    matrica_1.append(ui->lineEdit_26);
    matrica_1.append(ui->lineEdit_27);
    matrica_1.append(ui->lineEdit_28);
    matrica_1.append(ui->lineEdit_29);
    matrica_1.append(ui->lineEdit_30);
    matrica_1.append(ui->lineEdit_31);
    matrica_1.append(ui->lineEdit_32);
    matrica_1.append(ui->lineEdit_33);
    matrica_1.append(ui->lineEdit_34);
    matrica_1.append(ui->lineEdit_35);
    matrica_1.append(ui->lineEdit_36);
    matrica_1.append(ui->lineEdit_37);
    matrica_1.append(ui->lineEdit_38);
    matrica_1.append(ui->lineEdit_39);
    matrica_1.append(ui->lineEdit_40);
    matrica_1.append(ui->lineEdit_41);
    matrica_1.append(ui->lineEdit_42);
    matrica_1.append(ui->lineEdit_43);
    matrica_1.append(ui->lineEdit_44);
    matrica_1.append(ui->lineEdit_45);
    matrica_1.append(ui->lineEdit_46);
    matrica_1.append(ui->lineEdit_47);
    matrica_1.append(ui->lineEdit_48);
    matrica_1.append(ui->lineEdit_49);


    for (int i = 34; i > 48 - 7 * (7 - index1); i--)
    {
        matrica_1[i]->setVisible(false);
    }
    /**for (int i = 48 - 7 * (7 - index1); i >= 0; i--)
    {
        matrica_1[i]->setVisible(true);
    }*/

    QVector<QLineEdit*> matrica_2;

    matrica_2.append(ui->lineEdit_64);
    matrica_2.append(ui->lineEdit_65);
    matrica_2.append(ui->lineEdit_66);
    matrica_2.append(ui->lineEdit_67);
    matrica_2.append(ui->lineEdit_68);
    matrica_2.append(ui->lineEdit_69);
    matrica_2.append(ui->lineEdit_70);
    matrica_2.append(ui->lineEdit_71);
    matrica_2.append(ui->lineEdit_72);
    matrica_2.append(ui->lineEdit_73);
    matrica_2.append(ui->lineEdit_74);
    matrica_2.append(ui->lineEdit_75);
    matrica_2.append(ui->lineEdit_76);
    matrica_2.append(ui->lineEdit_77);
    matrica_2.append(ui->lineEdit_78);
    matrica_2.append(ui->lineEdit_79);
    matrica_2.append(ui->lineEdit_80);
    matrica_2.append(ui->lineEdit_81);
    matrica_2.append(ui->lineEdit_82);
    matrica_2.append(ui->lineEdit_83);
    matrica_2.append(ui->lineEdit_84);
    matrica_2.append(ui->lineEdit_85);
    matrica_2.append(ui->lineEdit_86);
    matrica_2.append(ui->lineEdit_87);
    matrica_2.append(ui->lineEdit_88);
    matrica_2.append(ui->lineEdit_89);
    matrica_2.append(ui->lineEdit_90);
    matrica_2.append(ui->lineEdit_91);
    matrica_2.append(ui->lineEdit_92);
    matrica_2.append(ui->lineEdit_93);
    matrica_2.append(ui->lineEdit_94);
    matrica_2.append(ui->lineEdit_95);
    matrica_2.append(ui->lineEdit_96);
    matrica_2.append(ui->lineEdit_97);
    matrica_2.append(ui->lineEdit_98);

    for (int i = 34; i > 48 - 7 * (7 - index1); i--)
    {
        matrica_2[i]->setVisible(false);
    }
    for (int i = 48 - 7 * (7 - index1); i >= 0; i--)
    {
        matrica_2[i]->setVisible(true);
    }
}

void Sum_sub_matric::on_comboBox_2_activated(int index2)
{
    QVector<QLineEdit*> matrica_1;

    matrica_1.append(ui->lineEdit_3);
    matrica_1.append(ui->lineEdit_10);
    matrica_1.append(ui->lineEdit_17);
    matrica_1.append(ui->lineEdit_24);
    matrica_1.append(ui->lineEdit_31);
    matrica_1.append(ui->lineEdit_38);
    matrica_1.append(ui->lineEdit_45);
    matrica_1.append(ui->lineEdit_4);
    matrica_1.append(ui->lineEdit_11);
    matrica_1.append(ui->lineEdit_18);
    matrica_1.append(ui->lineEdit_25);
    matrica_1.append(ui->lineEdit_32);
    matrica_1.append(ui->lineEdit_39);
    matrica_1.append(ui->lineEdit_46);
    matrica_1.append(ui->lineEdit_5);
    matrica_1.append(ui->lineEdit_12);
    matrica_1.append(ui->lineEdit_19);
    matrica_1.append(ui->lineEdit_26);
    matrica_1.append(ui->lineEdit_33);
    matrica_1.append(ui->lineEdit_40);
    matrica_1.append(ui->lineEdit_47);
    matrica_1.append(ui->lineEdit_6);
    matrica_1.append(ui->lineEdit_13);
    matrica_1.append(ui->lineEdit_20);
    matrica_1.append(ui->lineEdit_27);
    matrica_1.append(ui->lineEdit_34);
    matrica_1.append(ui->lineEdit_41);
    matrica_1.append(ui->lineEdit_48);
    matrica_1.append(ui->lineEdit_7);
    matrica_1.append(ui->lineEdit_14);
    matrica_1.append(ui->lineEdit_21);
    matrica_1.append(ui->lineEdit_28);
    matrica_1.append(ui->lineEdit_35);
    matrica_1.append(ui->lineEdit_42);
    matrica_1.append(ui->lineEdit_49);

    for (int i = 34; i > 48 - 7 * (7 - index2); i--)
    {
       matrica_1[i]->close();
    }
    for (int i = 48 - 7 * (7 - index2); i >= 0; i--)
    {
       matrica_1[i]->show();
    }
}



