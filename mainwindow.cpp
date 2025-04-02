#include <Qdebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    analyzer = new TextAnalyzer(ui->textEdit, this);
}

void MainWindow::on_btnAnalyzeText_clicked()
{
    analyzer->analyzeText();

    fillABC();
    fillCounters();
}

void MainWindow::fillABC()
{
    auto ABC = analyzer->getLettersFrequency();

    ui->lineEdit_A->setText(QString::number(ABC.value('a')));
    ui->lineEdit_B->setText(QString::number(ABC.value('b')));
    ui->lineEdit_C->setText(QString::number(ABC.value('c')));
    ui->lineEdit_D->setText(QString::number(ABC.value('d')));
    ui->lineEdit_E->setText(QString::number(ABC.value('e')));
    ui->lineEdit_F->setText(QString::number(ABC.value('f')));
    ui->lineEdit_G->setText(QString::number(ABC.value('g')));
    ui->lineEdit_H->setText(QString::number(ABC.value('h')));
    ui->lineEdit_I->setText(QString::number(ABC.value('i')));
    ui->lineEdit_J->setText(QString::number(ABC.value('j')));
    ui->lineEdit_K->setText(QString::number(ABC.value('k')));
    ui->lineEdit_L->setText(QString::number(ABC.value('l')));
    ui->lineEdit_M->setText(QString::number(ABC.value('m')));
    ui->lineEdit_N->setText(QString::number(ABC.value('n')));
    ui->lineEdit_O->setText(QString::number(ABC.value('o')));
    ui->lineEdit_P->setText(QString::number(ABC.value('p')));
    ui->lineEdit_Q->setText(QString::number(ABC.value('q')));
    ui->lineEdit_R->setText(QString::number(ABC.value('r')));
    ui->lineEdit_S->setText(QString::number(ABC.value('s')));
    ui->lineEdit_T->setText(QString::number(ABC.value('t')));
    ui->lineEdit_U->setText(QString::number(ABC.value('u')));
    ui->lineEdit_V->setText(QString::number(ABC.value('v')));
    ui->lineEdit_W->setText(QString::number(ABC.value('w')));
    ui->lineEdit_X->setText(QString::number(ABC.value('x')));
    ui->lineEdit_Y->setText(QString::number(ABC.value('y')));
    ui->lineEdit_Z->setText(QString::number(ABC.value('z')));
}

void MainWindow::fillCounters()
{
    ui->lineEdit_letters->setText(QString::number(analyzer->getInfo().lettersCount));
    ui->lineEdit_symbols->setText(QString::number(analyzer->getInfo().symbolsCount));
    ui->lineEdit_spaces->setText(QString::number(analyzer->getInfo().spacesCount));
    ui->lineEdit_words->setText(QString::number(analyzer->getInfo().wordsCount));
}
