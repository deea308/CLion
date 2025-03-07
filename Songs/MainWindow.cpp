#include "MainWindow.h"

#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUi();
}

MainWindow::~MainWindow() = default;

void MainWindow::setupUi() {

    auto *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);


    auto *mainLayout = new QVBoxLayout(centralWidget);
    QStringList header{"Title", "Artist", "Year", "Price", "Quantity"};
    // Table widget for displaying books
    tableWidget = new QTableWidget(0, 5, this); // 0 rows, 5 columns
    tableWidget->setHorizontalHeaderLabels(header);
    tableWidget->setAlternatingRowColors(true);
    tableWidget->setWordWrap(true);
    tableWidget->verticalHeader()->setDefaultSectionSize(20);
    tableWidget->setStyleSheet("QTableWidget { alternate-background-color: #ADD8E6; }");
    mainLayout->addWidget(tableWidget);

    // Form layout for book input
    auto *formLayout = new QFormLayout();
    titleEdit = new QLineEdit(this);
    artistEdit = new QLineEdit(this);
    yearEdit = new QLineEdit(this);
    priceEdit = new QLineEdit(this);
    quantityEdit = new QLineEdit(this);

    formLayout->addRow("Title:", titleEdit);
    formLayout->addRow("Artist:", artistEdit);
    formLayout->addRow("Year:", yearEdit);
    formLayout->addRow("Price:", priceEdit);
    formLayout->addRow("Quantity:", quantityEdit);

    mainLayout->addLayout(formLayout);

    // Add button
    addButton = new QPushButton("Add", this);
    connect(addButton, &QPushButton::clicked, this, &MainWindow::onAddButtonClicked);
    mainLayout->addWidget(addButton);
}

void MainWindow::onAddButtonClicked() {
    if (!validateInput()) {
        QMessageBox::warning(this, "Input Validation", "Please enter a valid year.");
        return;
    }

    Book book{titleEdit->text(), artistEdit->text(), yearEdit->text().toInt(), priceEdit->text().toDouble(),
              quantityEdit->text().toInt()};
    books.append(book); // Add the book to the array

    int currentRow = tableWidget->rowCount();
    tableWidget->insertRow(currentRow);

    tableWidget->setItem(currentRow, 0, new QTableWidgetItem(book.getTitle()));
    tableWidget->setItem(currentRow, 1, new QTableWidgetItem(book.getartist()));
    tableWidget->setItem(currentRow, 2, new QTableWidgetItem(QString::number(book.getYear())));
    tableWidget->setItem(currentRow, 3, new QTableWidgetItem(QString::number(book.getPrice())));
    tableWidget->setItem(currentRow, 4, new QTableWidgetItem(QString::number(book.getQuantity())));

    // Optionally clear the input fields after adding
    titleEdit->clear();
    artistEdit->clear();
    yearEdit->clear();
    priceEdit->clear();
    quantityEdit->clear();

    tableWidget->resizeRowsToContents();

}

bool MainWindow::validateInput() {
    bool ok;
    int year = yearEdit->text().toInt(&ok);
    // Basic validation: ensure year is a positive integer
    return ok && year > 0;
}