#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), instructor("Jane Smith") {
    ui->setupUi(this);

    QStringList headers = {"Name", "Age", "Weight", "Goal", "Exercise", "Description", "Duration", "Calories"};
    ui->tableWidget->setRowCount(1); // Одна строка для ввода данных
    ui->tableWidget->setColumnCount(headers.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    connect(ui->tableWidget, &QTableWidget::cellChanged, this, &MainWindow::on_tableWidget_cellChanged);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_tableWidget_cellChanged(int row, int column) {
    if (row == 0) {
        createWorkoutPlan();
    }
}

void MainWindow::createWorkoutPlan() {
    QString name = ui->tableWidget->item(0, 0) ? ui->tableWidget->item(0, 0)->text() : "";
    int age = ui->tableWidget->item(0, 1) ? ui->tableWidget->item(0, 1)->text().toInt() : 0;
    int weight = ui->tableWidget->item(0, 2) ? ui->tableWidget->item(0, 2)->text().toInt() : 0;
    QString goal = ui->tableWidget->item(0, 3) ? ui->tableWidget->item(0, 3)->text() : "";

    if (!name.isEmpty() && age > 0 && weight > 0 && !goal.isEmpty()) {
        user = std::make_unique<User>(name, age, weight, goal);

        auto plan = instructor.createWorkoutPlan(*user);
        user->setWorkoutPlan(std::move(plan));

        ui->tableWidget->setRowCount(1); // Очистить таблицу, оставив строку для ввода данных

        int currentRow = 1; // Начать со второй строки
        for (const auto& exercise : user->getWorkoutPlan()->getExercises()) {
            ui->tableWidget->insertRow(currentRow);
            ui->tableWidget->setItem(currentRow, 0, new QTableWidgetItem(user->getName()));
            ui->tableWidget->setItem(currentRow, 1, new QTableWidgetItem(QString::number(user->getAge())));
            ui->tableWidget->setItem(currentRow, 2, new QTableWidgetItem(QString::number(user->getWeight())));
            ui->tableWidget->setItem(currentRow, 3, new QTableWidgetItem(user->getGoal()));
            ui->tableWidget->setItem(currentRow, 4, new QTableWidgetItem(exercise->getName()));
            ui->tableWidget->setItem(currentRow, 5, new QTableWidgetItem(exercise->getDescription()));
            ui->tableWidget->setItem(currentRow, 6, new QTableWidgetItem(QString::number(exercise->getDuration())));
            ui->tableWidget->setItem(currentRow, 7, new QTableWidgetItem(QString::number(exercise->getCalories())));
            currentRow++;
        }
    }
}
