//
// Created by Andreea on 6/4/2024.
//

#ifndef L11L12_SONGS_MAINWINDOW_H
#define L11L12_SONGS_MAINWINDOW_H
#include <QMainWindow>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QVector>
#include <QMessageBox>
class Book{
private:
    QString title;
    QString artist;
    int year;
    double price;
    int quantity;
public:
    Book(QString t,QString a, int y, double p, int q ):
            title{t}, artist{a}, year{y}, price{p}, quantity{q} {};
    QString getTitle() const{return title;}
    QString getartist() const {return artist;}
    int getYear() const{return year;}
    int getPrice() const {return price;}
    int getQuantity() const {return quantity;}
};


class MainWindow:public QMainWindow {
    Q_OBJECT;
private slots:
    void onAddButtonClicked();
private:
    QTableWidget *tableWidget;
    QLineEdit *titleEdit;
    QLineEdit *artistEdit;
    QLineEdit *yearEdit;
    QLineEdit *priceEdit;
    QLineEdit *quantityEdit;
    QPushButton *addButton;

    void setupUi();
    bool validateInput(); //input validation function
    QVector<Book> books;//dyn arr of books
public:
    MainWindow(QWidget *parent= nullptr);
    ~MainWindow();

};


#endif //L11L12_SONGS_MAINWINDOW_H
