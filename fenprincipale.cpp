#include "fenprincipale.h"

FenPrincipale::FenPrincipale() : QWidget()
{
    //Layout global (contient les groupbox)
    layoutGlobal = new QVBoxLayout;

    //Groupbox 3 sous forme de checkbox
    groupbox3 = new QGroupBox("Ajouter des commentaires");
    groupbox3->setCheckable(true);

    layoutGlobal->addWidget(groupbox1 = new QGroupBox("Définition de la classe"));
    layoutGlobal->addWidget(groupbox2 = new QGroupBox("Options"));
    layoutGlobal->addWidget(groupbox3);

    this->setLayout(layoutGlobal);

    //Layout pour chaque groupbox

    //Layout groupbox 1
    layoutGroupbox1 = new QFormLayout;
    layoutGroupbox1->addRow("&Nom : ", nom = new QLineEdit);
    layoutGroupbox1->addRow("Classe &mère : ", classeMere = new QLineEdit);
    groupbox1->setLayout(layoutGroupbox1);

    //Layout groupbox 2
    layoutGroupbox2 = new QFormLayout;
    layoutGroupbox2->addWidget(header = new QCheckBox("Protéger le &header contre les inclusions multiples"));
    layoutGroupbox2->addWidget(ctor = new QCheckBox("Générer un &constructeur par défaut"));
    layoutGroupbox2->addWidget(dtor = new QCheckBox("Générer un &destructeur"));
    groupbox2->setLayout(layoutGroupbox2);

    //Layout groupbox 3
    layoutGroupbox3 = new QFormLayout;
    layoutGroupbox3->addRow("&Auteur : ", auteur = new QLineEdit());
    layoutGroupbox3->addRow("Da&te de création : ", dateCreation = new QDateEdit(QDate::currentDate()));
    layoutGroupbox3->addRow("&Rôle de la classe : ", roleClasse = new QTextEdit());
    groupbox3->setLayout(layoutGroupbox3);

    //Layout boutons de contrôle
    boutonsControle = new QHBoxLayout;
    boutonsControle->addWidget(continuer = new QPushButton("Continuer"));
    boutonsControle->addWidget(quitter = new QPushButton("Annuler"));
    layoutGlobal->addLayout(boutonsControle);

    QObject::connect(continuer, SIGNAL(clicked()), this, SLOT(generer()));
    QObject::connect(quitter, SIGNAL(clicked()), qApp, SLOT(quit()));


}

QString FenPrincipale::genererH()
{
    if(nom->text().isEmpty())
    {
        nom->setText("default");
    }

    QString code = ("/**\n");
    code += "* Auteur : " + auteur->text() + "\n";
    code += "* Date de création : " + dateCreation->date().toString() + "\n";
    code += "* Rôle de la classe : " + roleClasse->toPlainText() + "\n" + "*/" + "\n\n";

    if(header->isChecked())
    {
        code += "#ifndef " + nom->text().toUpper() + "_H\n";
        code += "#define " + nom->text() + "_H\n\n";
    }

    code += "class " + nom->text();

    if(classeMere->text().replace(" ", "") != "")
    {
        code += " : public " + classeMere->text();
    }

    code += "\n{\n\tpublic:\n\t\t";

    if(ctor->isChecked())
    {
        code += nom->text() + "();";
    }

    code += "\n";

    if(dtor->isChecked())
    {
        code += "\t\t~" + nom->text() + "();";
    }

    code += "\n\n\tprotected:\n\n\tprivate:\n\n};";

    return code;

}

QString FenPrincipale::genererCpp()
{
    QString code("#include " + nom->text() + ".h\n\n");

    if(ctor->isChecked())
    {
        code += nom->text() + "::" + nom->text() + "()\n{\n\n}\n\n";
    }

    if(dtor->isChecked())
    {
        code += "~" + nom->text() + "::" + nom->text() + "()\n{\n\n}";
    }

    return code;
}

void FenPrincipale::generer()
{
    FenSecondaire secondaire(this->genererH(), this->genererCpp());
}
