#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


protected:
    void closeEvent(QCloseEvent *event) override;


private slots:
    void addTask();
    void deleteSelected();
    void clearAll();


private:
    void loadTasks();
    void saveTasks() const;
    QString dataFilePath() const;


    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
