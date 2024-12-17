#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::databaseConnect()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost"); // IP-адрес вашей виртуальной машины Ubuntu (см. на виртуалке)
    db.setPort(5432); // порт по умолчанию для PostgreSQL
    db.setDatabaseName("constellations_of_the_northern_hemisphere"); // имя вашей базы данных (см. на виртуалке)
    db.setUserName("postgres"); // ваше имя пользователя для базы данных (см. на виртуалке)
    db.setPassword("postgres"); // ваш пароль для базы данных (см. на виртуалке)
    db.setConnectOptions("client_encoding=UTF8");

    if (!db.open()) {
        qDebug() << "Failed to connect to database.";
        qDebug() << "Error: ";
        qDebug() << db.lastError().text();
    } else {
        qDebug() << "Connected to database succesfully!";
    }
}

QSqlQuery MainWindow::runQuery(QString left, QString right, float bottom, float top)
{
    // Выполнение sql запроса
    // TODO: оставить как свободную функцию, чтобы можно было "поиграться"

    QSqlQuery query;
    query.prepare("SELECT s.name, s.apparent_magnitude, con.name, con.family "
                  "FROM stars s "
                  "JOIN constellations con ON s.constellation = con.name "
                  "WHERE s.right_ascension BETWEEN ? AND ? AND "
                          "s.declination[1]+s.declination[2]/60+s.declination[3]/360 BETWEEN ? AND ?");

    query.bindValue(0, left); // Биндим
    query.bindValue(1, right); // Биндим
    query.bindValue(2, bottom); // Биндим
    query.bindValue(3, top); // Биндим

    query.exec();

    // Обработка

    if (query.lastError().isValid()) {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
    } else {
        // Запрос выполнен успешно
    }

    return query;
}

void MainWindow::configureTableParameters()
{
    ui->tableStars->setColumnCount(4);

    // Создание таблички для отображения списка дисциплин
    ui->tableStars->horizontalHeader()->setVisible(false);
    ui->tableStars->verticalHeader()->setVisible(false);

    ui->tableStars->setShowGrid(false);

    // Установка политики изменения размера столбцов
    ui->tableStars->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableStars->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableStars->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableStars->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    databaseConnect();
    configureTableParameters();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushQuery_clicked()
{

    QString left = ui->left->text();
    QString right = ui->right->text();
    float bottom = ui->bottom->text().toFloat();
    float top = ui->top->text().toFloat();
    QSqlQuery query;
    query = runQuery(left, right, bottom, top);

    ui->tableStars->clearContents();
    ui->tableStars->setRowCount(0);

    int rows = 0; // Счетчик количества строк в таблице

    while (query.next()) {
            ui->tableStars->insertRow(rows);
            ui->tableStars->setRowHeight(rows, 50); // Высота

            QString a = query.value(0).toString();
            QString b = query.value(1).toString();
            QString c = query.value(2).toString();
            QString d = query.value(3).toString();

            ui->tableStars->setItem(rows, 0, new   QTableWidgetItem(a));
            ui->tableStars->setItem(rows, 1, new QTableWidgetItem(b));
            ui->tableStars->setItem(rows, 2, new QTableWidgetItem(c));
            ui->tableStars->setItem(rows, 3, new QTableWidgetItem(d));
    }
}

