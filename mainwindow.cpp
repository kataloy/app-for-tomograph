#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_get_pictures_clicked()
{
    QFileDialog dialog;
    QVector<QImage> images(10);
    QStandardItemModel *model = new QStandardItemModel;

    QStringList addresses = dialog.getOpenFileNames(this,
        "Select one or more images to open",
        "/home",
        "Image Files (*.png *.jpg *.jpeg *.bmp)");

    for (int i = 0; i < addresses.count(); i++) {
        QStandardItem *item = new QStandardItem();

        images[i].load(addresses[i]);
        images[i].scaled(800 / 6, 100);

        item->setData(QVariant(QPixmap::fromImage(images[i])), Qt::DecorationRole);
        model->setItem(qFloor(i / 6), i - 6 * qFloor(i / 6), item);
    }
    ui->table_of_pictures->setModel(model);

    for(int i = 0; i < 6; i++) {
        ui->table_of_pictures->setColumnWidth(i, 800 / 6);
    }

    for (int i = 0; i < model->rowCount(); i++) {
        ui->table_of_pictures->setRowHeight(i, 100);
    }
}

void MainWindow::on_btn_change_clicked()
{

}
