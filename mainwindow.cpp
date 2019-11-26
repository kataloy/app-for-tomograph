#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFileDialog dialog;
    QVector<QImage> images(100);
    QStandardItemModel *model = new QStandardItemModel;

    QStringList addresses = dialog.getOpenFileNames(this,
        "Select one or more images to open",
        "/home",
        "Image Files (*.png *.jpg *.jpeg *.bmp)");

    for (int i = 0; i < addresses.count(); i++) {
        QStandardItem *item = new QStandardItem();
        QGridLayout *layout = new QGridLayout;
        QLabel *lbl1 = new QLabel("Text");
        QLabel *lbl2 = new QLabel("Text");
        QLabel *lbl3 = new QLabel("Text");
        QLabel *lbl4 = new QLabel("Text");
        QLabel *lbl5 = new QLabel("Text");

        images[i].load(addresses[i]);
        images[i] = images[i].scaled(800 / 6, 100);

        layout->addWidget(lbl1, 0, 0);
        layout->addWidget(lbl2, 0, 2);
        layout->addWidget(lbl3, 1, 0);
        layout->addWidget(lbl4, 1, 1);
        layout->addWidget(lbl5, 1, 2);

        QVariant lyt = QVariant::fromValue(layout);

        item->setData(QVariant(QPixmap::fromImage(images[i])), Qt::DecorationRole);
        item->setData(QVariant(lyt));
        model->setItem(qFloor(i / 6), i - 6 * qFloor(i / 6), item);
    }
    ui->table_of_pictures->setModel(model);

    for(int i = 0; i < 6; i++) {
        ui->table_of_pictures->setColumnWidth(i, 840 / 6);
    }

    for (int i = 0; i < model->rowCount(); i++) {
        ui->table_of_pictures->setRowHeight(i, 150);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_change_clicked()
{

}
