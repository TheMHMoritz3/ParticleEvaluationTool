#include "ParticleEvaluationTool.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("German Software Engineers");
    QCoreApplication::setOrganizationDomain("german-software-engineers.com");
    QCoreApplication::setApplicationName("Particle Evaluation Tool");

    ParticleEvaluationTool w;
    w.show();
    return a.exec();
}
