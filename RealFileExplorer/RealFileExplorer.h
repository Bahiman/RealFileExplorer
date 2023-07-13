#pragma once
#include<qlistview.h>
#include <QtWidgets/QMainWindow>
#include<qlineedit.h>
#include "ui_RealFileExplorer.h"
#include <QPushButton>
#include<vector>

class RealFileExplorer : public QMainWindow
{
    Q_OBJECT

public:
    RealFileExplorer(QWidget *parent = nullptr);
    ~RealFileExplorer();
    QListView m_file_view;
    QLineEdit m_search_bar;
    QPushButton m_back_button;
private:
    Ui::RealFileExplorerClass ui;
};
