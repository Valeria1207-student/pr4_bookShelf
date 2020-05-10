#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
using namespace std;
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

//Добавление шкафа
void MainWindow::on_pushButton_addBookShelf_clicked()
{
   int id = bookShelfs.size()+1;//ID нового шкафа
   //Доступ к объектам интерфейса чере "ui"
   ui->listWidget_BookShelfs->addItem(QString::number(id));
   Bookshelf bs = Bookshelf(10);
   bookShelfs.push_back(bs);
}
// Добавление книги
void MainWindow::on_pushButton_addBook_clicked()
{
    ui->spinBox_pages->value();// Получить значение страниц
    ui->lineEdit_name->text();// Получить название книги
}
