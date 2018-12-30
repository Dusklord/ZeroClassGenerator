#include <fensecondaire.h>

FenSecondaire::FenSecondaire(const QString& hContent, const QString& cppContent) : QDialog()
{
    layoutPrincipal = new QVBoxLayout;

    //Tabs pour séparer le .h du .cpp
    classe = new QTabWidget;

    //Dans le .h

    hTab = new QWidget;
    layoutH = new QVBoxLayout;

    hTextEdit = new QTextEdit;
    hTextEdit->setReadOnly(true);
    hTextEdit->setPlainText(hContent);
    layoutH->addWidget(hTextEdit);

    hTab->setLayout(layoutH);

    //Dans le .cpp

    cppTab = new QWidget;
    layoutCpp = new QVBoxLayout;

    cppTextEdit = new QTextEdit;
    cppTextEdit->setReadOnly(true);
    cppTextEdit->setPlainText(cppContent);
    layoutCpp->addWidget(cppTextEdit);

    cppTab->setLayout(layoutCpp);

    classe->addTab(hTab, "Header");
    classe->addTab(cppTab, "Source");

    layoutPrincipal->addWidget(classe);

    layoutPrincipal->addWidget(quitter = new QPushButton("OK"));

    this->setLayout(layoutPrincipal);

    QObject::connect(quitter, SIGNAL(clicked()), this, SLOT(reject()));

    this->exec();

}
