#include "mainwindow.h"
#include <QMenuBar>
#include <QApplication>
#include <QMessageBox>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QImage>
#include <QImageReader>
#include <QPixmap>
#include <QResizeEvent>
#include <QPushButton>
#include <QColor>
#include <QRgb>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(1024,720);


    QMenu *menuFichier = menuBar()->addMenu(tr("Fichier"));

    QAction *actionOuvrir = new QAction(tr("Ouvrir"),this);
    menuFichier->addAction(actionOuvrir);
    connect(actionOuvrir, SIGNAL(triggered()),this,SLOT(openFile()));

    QAction *actionQuitter = new QAction(tr("Quitter"),this);
    menuFichier->addAction(actionQuitter);
    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    QPushButton *tri_d_button = new QPushButton("Mode 3D !!",this);
    connect(tri_d_button,SIGNAL(clicked(bool)),this,SLOT(tri_d_mode()));

    QAction *actionApropos = new QAction(tr("A propos"),this);
    menuBar()->addAction(actionApropos);

    connect(actionApropos, SIGNAL(triggered()), this, SLOT(apropos()));



    QWidget *widget_center = new QWidget();

    QHBoxLayout *HLayout = new QHBoxLayout;

    labelImage = new QLabel;

    //fileName = new QString;

    HLayout->addWidget(labelImage);

    HLayout->addWidget(tri_d_button);

    HLayout->setAlignment(tri_d_button,Qt::AlignRight);

    widget_center->setLayout(HLayout);

    setCentralWidget(widget_center);




}

MainWindow::~MainWindow()
{

}

void MainWindow::apropos()
{
    QMessageBox msgApropos;
    msgApropos.setText(tr("Projet de Programmation 2017-2018 de Gabriel Lorrain"));
    msgApropos.exec();
}

void MainWindow::openFile()
{
    fileName = QFileDialog::getOpenFileName(this,tr("Ouvrir un fichier"),tr("~/"),tr("Images (*.png *.jpg)"));
    QImageReader *imgReader = new QImageReader(fileName);
    pixmap = QPixmap::fromImageReader(imgReader);
    labelImage->setPixmap(pixmap);
    labelImage->adjustSize();

}

void MainWindow::tri_d_mode()
{
    QImage *full = new QImage(fileName);
    int w = full->width()/2;
    int h = full->height();


    QImage left = full->copy(0,0,w,h);
    QImage right = full->copy(w,0,w,h);

    QColor pixL;
    QColor pixR;
    QColor pixF;
    int red,blue,green;

    for(int i = 0 ; i < w ; i++){
        for(int j = 0 ; j < h ; j++){
            pixL = left.pixelColor(i,j);
            pixR = right.pixelColor(i,j);
            red = pixL.red();
            green = pixR.green();
            blue = pixR.blue();
            pixF.setRed(red);
            pixF.setGreen(green);
            pixF.setBlue(blue);
            left.setPixelColor(i,j,pixF);
        }
    }

    tri_d_image = QPixmap::fromImage(left);
    labelImage->setPixmap(tri_d_image);







}









