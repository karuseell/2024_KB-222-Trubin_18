#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "user.h"
#include "fitnessinstructor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_tableWidget_cellChanged(int row, int column);

private:
    Ui::MainWindow *ui;
    std::unique_ptr<User> user;
    FitnessInstructor instructor;

    void createWorkoutPlan();
};

#endif // MAINWINDOW_H
