#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QResizeEvent>
#include <QHBoxLayout>
#include <QString>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private :
    QLabel *labelImage;
    QPixmap pixmap;
    QString fileName;
    QPixmap tri_d_image;



public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void apropos();
    void openFile();
    void tri_d_mode();

protected:
   // void resizeEvent(QResizeEvent *);
};
#endif // MAINWINDOW_H
