#include "controller_matrix.h"
#include "view.h"
#include "model_matrix.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    View w;
    w.show();

    return a.exec();
}
