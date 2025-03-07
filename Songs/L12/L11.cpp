#include<string>
#include <QWidget>
#include <QApplication>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QListWidget>
#include <QLineEdit>

QWidget* getLeftPanel();
QWidget* getRightPanel();
QWidget* getTextInputWithLabel(const char *name);
QWidget* getButtons();
QTableWidget * getTable();

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    auto *wnd= new QWidget();
    auto *hLay=new QHBoxLayout();

    hLay->addWidget(getLeftPanel());
    hLay->addWidget(new QPushButton(">"));
    hLay->addWidget(getRightPanel());

    wnd->setLayout(hLay);
    wnd->setWindowTitle("PLaylist Qt");
    wnd->show();

    return QApplication::exec();
}

QWidget *getRightPanel(){
    auto *panel= new QWidget();
    auto *vLay= new QVBoxLayout();

    auto* label= new QLabel("Playlist");
    vLay->addWidget(label);

    auto *list= new QListWidget();
    vLay->addWidget(list);

    auto* playButton = new QPushButton("PLay");
    vLay->addWidget(playButton);

    auto* nextButton= new QPushButton("Next");
    vLay->addWidget(nextButton);

    panel->setLayout(vLay);
    return panel;
}

QWidget* getLeftPanel(){
    auto* panel= new QWidget;
    auto* vLayLeft= new QVBoxLayout;

    auto* label= new QLabel("all songs");
    vLayLeft->addWidget(label);

    vLayLeft->addWidget(getTable());

    vLayLeft->addWidget(getTextInputWithLabel("Title:"));
    vLayLeft->addWidget(getTextInputWithLabel("Artist:"));
    vLayLeft->addWidget(getTextInputWithLabel("Duration:"));
    vLayLeft->addWidget(getTextInputWithLabel("Path:"));

    vLayLeft->addWidget(getButtons());

    panel->setLayout(vLayLeft);
    return panel;
}

QTableWidget* getTable(){
    auto *table= new QTableWidget;
    QStringList headers={"Title", "Artist", "Duration","Path"};
    table->setColumnCount((int) headers.count());
    table->setHorizontalHeaderLabels(headers);
    return table;
}

QWidget* getButtons(){
    auto *panel= new QWidget();
    auto *hLay= new QHBoxLayout;
    hLay->addWidget(new QPushButton("Add"));
    hLay->addWidget(new QPushButton("Delete"));
    hLay->addWidget(new QPushButton("Update"));
    hLay->addWidget(new QPushButton("Filter"));

    panel->setLayout(hLay);
    return panel;
}

QWidget* getTextInputWithLabel(const char* name){
    auto *panel= new QWidget();
    auto *hLay= new QHBoxLayout();

    auto *label= new QLabel(name);
    hLay->addWidget(label);

    auto *inputText= new QLineEdit();
    hLay->addWidget(inputText);
    panel->setLayout(hLay);
    return panel;
}