#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "book.h"
#include "printBook.h"
#include "shelf.h"
#include "bookshelf.h"
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_addBookShelf_clicked();

    void on_pushButton_addBook_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<Book> books;
    std::vector<Bookshelf> bookShelfs;
};
#endif // MAINWINDOW_H
