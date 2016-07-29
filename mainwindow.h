#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>
#include <QEvent>
#include <QLabel>
#include <QComboBox>
#include <QTableWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void init();        //初始化

    void refresh();     //刷新

protected:
//    virtual void changeEvent(QEvent *e);

private slots:
    void slot_cBox(int index);

private:
    QLabel *label1;
    QLabel *label2;
    QComboBox *cBox;
    QTableWidget *tableWidget;

    QTranslator translator;

    QStringList strList;
};

#endif // MAINWINDOW_H
