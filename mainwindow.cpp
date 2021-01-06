#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "sortalgorithm.h"

#include <QtCore>
#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    ui->comboBox->addItem("Selection Sort");
    ui->comboBox->addItem("Insertion Sort");
    ui->comboBox->addItem("Bubble Sort");
    ui->comboBox->addItem("Merge Sort");
    ui->comboBox->addItem("Quick Sort");
    ui->comboBox->addItem("Shell Sort");
    // ui->comboBox->addItem("Bin Sort");
    // ui->comboBox->addItem("Radix Sort");


    N = 300;

    for(int i = 0; i < N; i++)
    {
        arr.push_back(new ArrayElement(i, 0, 1, 800));
        scene->addItem(arr[i]);
    }
//    for(int i = 0; i < N; i++)
//    {
//        arr[i]->setHeight(qrand() % 800);
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startButton_clicked()
{
    SortAlgorithm algo;

    // select algorithm to run from comboBox
    QString selection = ui->comboBox->currentText();

    if(selection == QString("Selection Sort"))
    {
        algo.selectionSort(arr, speed);
    }
    else if(selection == QString("Insertion Sort"))
    {
        algo.insertionSort(arr, speed);
    }
    else if(selection == QString("Bubble Sort"))
    {
        algo.bubbleSort(arr, speed);
    }
    else if(selection == QString("Merge Sort"))
    {
        algo.mergeSort(arr, speed, 0, N-1);
    }
    else if(selection == QString("Quick Sort"))
    {
        algo.quickSort(arr, speed, 0, N-1);
    }
    else if(selection == QString("Shell Sort"))
    {
        algo.shellSort(arr, speed);
    }

    ui->swapsCount->setText(QString::number(algo.getCount()));
}

void MainWindow::on_randomizeButton_clicked()
{
    ui->swapsCount->clear();
    for(int i = 0; i < N; i++)
    {   
        arr[i]->setHeight(qrand() % 800);

        // update every 'x' milliseconds
        QEventLoop loop;
        QTimer::singleShot(1, &loop, SLOT(quit()));
        loop.exec();
    }
}

void MainWindow::on_frequencySlider_valueChanged(int value)
{
    speed = value;
    ui->spinBox->setValue(value);
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->frequencySlider->setValue(arg1);
}
