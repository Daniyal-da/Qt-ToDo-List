#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QListWidgetItem>
#include <QFile>
#include <QDir>
#include <QStandardPaths>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QCloseEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // اتصال دکمه‌ها و ورودی‌ها
    connect(ui->btnAdd, &QPushButton::clicked, this, &MainWindow::addTask);
    connect(ui->inputTask, &QLineEdit::returnPressed, this, &MainWindow::addTask);
    connect(ui->btnDeleteSelected, &QPushButton::clicked, this, &MainWindow::deleteSelected);
    connect(ui->btnClearAll, &QPushButton::clicked, this, &MainWindow::clearAll);


    loadTasks();
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    saveTasks();
    QMainWindow::closeEvent(event);
}


void MainWindow::addTask()
{
    const QString text = ui->inputTask->text().trimmed();
    if (text.isEmpty()) return;


    auto *item = new QListWidgetItem(text);
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable | Qt::ItemIsEditable | Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    item->setCheckState(Qt::Unchecked); // به عنوان تیک‌خورده/انجام‌شده استفاده می‌کنیم
    ui->listTasks->addItem(item);


    ui->inputTask->clear();
    ui->inputTask->setFocus();
}


void MainWindow::deleteSelected()
{
    const auto selected = ui->listTasks->selectedItems();
    for (QListWidgetItem *it : selected) {
        delete it; // خود آیتم را حذف می‌کند
    }
}


void MainWindow::clearAll()
{
    ui->listTasks->clear();
}
QString MainWindow::dataFilePath() const
{
    const QString dir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir().mkpath(dir);
    return dir + "/tasks.json";
}


void MainWindow::loadTasks()
{
    QFile f(dataFilePath());
    if (!f.open(QIODevice::ReadOnly)) return;


    const QJsonDocument doc = QJsonDocument::fromJson(f.readAll());
    f.close();
    if (!doc.isArray()) return;


    const QJsonArray arr = doc.array();
    for (const QJsonValue &v : arr) {
        const QJsonObject obj = v.toObject();
        auto *item = new QListWidgetItem(obj.value("text").toString());
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable | Qt::ItemIsEditable | Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        const bool done = obj.value("done").toBool(false);
        item->setCheckState(done ? Qt::Checked : Qt::Unchecked);
        ui->listTasks->addItem(item);
    }
}


void MainWindow::saveTasks() const
{
    QJsonArray arr;
    for (int i = 0; i < ui->listTasks->count(); ++i) {
        QListWidgetItem *item = ui->listTasks->item(i);
        QJsonObject obj;
        obj["text"] = item->text();
        obj["done"] = (item->checkState() == Qt::Checked);
        arr.append(obj);
    }


    QFile f(dataFilePath());
    if (f.open(QIODevice::WriteOnly)) {
        QJsonDocument doc(arr);
        f.write(doc.toJson(QJsonDocument::Indented));
        f.close();
    }
}
