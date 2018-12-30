#ifndef FENSECONDAIRE_H
#define FENSECONDAIRE_H

#include <QtWidgets>

class FenSecondaire : public QDialog
{
public:
    FenSecondaire(const QString&, const QString&);
private:
    QVBoxLayout *layoutPrincipal, *layoutH, *layoutCpp;
    QTabWidget *classe;
    QWidget *hTab, *cppTab;
    QTextEdit *hTextEdit, *cppTextEdit;
    QPushButton *quitter;
};

#endif // FENSECONDAIRE_H
