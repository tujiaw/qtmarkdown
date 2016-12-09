#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include "webengineview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_edit = new QTextEdit(this);
    m_view = new WebEngineView(this);

    QSplitter *splitter = new QSplitter(Qt::Horizontal);
    splitter->addWidget(m_edit);
    splitter->addWidget(m_view);
    QHBoxLayout *mLayout = new QHBoxLayout(ui->content);
    mLayout->addWidget(splitter);

    m_view->load(QUrl("qrc:/rc/index.html"));
    m_view->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
