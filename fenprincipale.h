#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QtWidgets>
#include "fensecondaire.h"

class FenPrincipale : public QWidget
{
    Q_OBJECT
public:
    FenPrincipale();
    QString genererH();
    QString genererCpp();

private:
    //Layout global
    QVBoxLayout *layoutGlobal;
    QGroupBox *groupbox1, *groupbox2, *groupbox3;

    //Layouts secondaires (groupbox)
    QFormLayout *layoutGroupbox1, *layoutGroupbox2, *layoutGroupbox3;

    //groupbox 1
    QLineEdit *nom, *classeMere;

    //groupbox2
    QCheckBox *header, *ctor, *dtor;

    //groupbox3
    QLineEdit *auteur;
    QDateEdit *dateCreation;
    QTextEdit *roleClasse;

    //Boutons de contrôle
    QHBoxLayout *boutonsControle;
    QPushButton *continuer, *quitter;

public slots:
    void generer();
};

#endif // FENPRINCIPALE_H
