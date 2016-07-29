#include "mainwindow.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    init();
}

MainWindow::~MainWindow()
{

}

void MainWindow::init()
{
    translator.load(":/cn.qm");
    qApp->installTranslator( &translator );

    setWindowTitle(tr("switch language"));

    QWidget *widget = new QWidget(this);
    QVBoxLayout *vLayout = new QVBoxLayout(widget);     //垂直布局
    QHBoxLayout *hLayout = new QHBoxLayout(widget);     //水平布局

    label1 = new QLabel(tr("hello world"), this);
    label2 = new QLabel(tr("Welcome to Beijing"), this);

    cBox = new QComboBox(this);
    cBox->addItem(tr("Chinese"));
    cBox->addItem(tr("English"));

    tableWidget = new QTableWidget(7, 5, widget);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //自适应宽度
    strList << tr("One") << tr("Two") << tr("Three") << tr("Four") << tr("Five");
    tableWidget->setHorizontalHeaderLabels(strList);
    strList.clear();
    strList << tr("Monday") << tr("Tuesday") << tr("Wednesday") << tr("Thursday")
            << tr("Friday") << tr("Saturday") << tr("Sunday");
    tableWidget->setVerticalHeaderLabels(strList);

    hLayout->addWidget(label1);
    hLayout->addWidget(label2);
    hLayout->addSpacing(10);
    hLayout->addWidget(cBox);
    vLayout->addLayout(hLayout);
    vLayout->addSpacing(5);
    vLayout->addWidget(tableWidget);

    //设为中心控件
    setCentralWidget(widget);

    resize(500, 285);

    connect(cBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_cBox(int)));
}

//每次切换语言后,需调该函数
void MainWindow::refresh()
{
    setWindowTitle(tr("switch language"));

    label1->setText(tr("hello world"));
    label2->setText(tr("Welcome to Beijng"));

    cBox->setItemText(0, tr("Chinese"));
    cBox->setItemText(1, tr("English"));

//    strList << tr("One") << tr("Two") << tr("Three") << tr("Four") << tr("Five");
    tableWidget->setHorizontalHeaderLabels(QStringList() << tr("One") << tr("Two")
                                           << tr("Three") << tr("Four") << tr("Five"));
    tableWidget->setVerticalHeaderLabels(QStringList() << tr("Monday") << tr("Tuesday")
                                         << tr("Wednesday") << tr("Thursday") << tr("Friday")
                                         << tr("Saturday") << tr("Sunday"));
}

//void MainWindow::changeEvent(QEvent *e)
//{
//    if ( e->type() == QEvent::LanguageChange){
//    }
//}

void MainWindow::slot_cBox(int index)
{
    qDebug() << "index:" << index;
    switch (index) {
    case 0:
        translator.load(":/cn.qm");
        break;
    case 1:
        translator.load(":/en.qm");
        break;
    default:
        break;
    }
    qApp->installTranslator( &translator );

    this->refresh();
}
