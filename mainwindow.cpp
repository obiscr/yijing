#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qborderlayout.h"

#include <QLabel>
#include <QSystemTrayIcon>

static int GUA_8_64[9][9] = {
     {0x0,  0x7,   0x2,   0x4,   0x1,  0x6,   0x5,   0x0,  0x3},
     {0x7,  0x3F,  0x17,  0x27,  0xF,  0x37,  0x2F,  0x7,  0x1F},
     {0x2,  0x3A,  0x12,  0x22,  0xA,  0x32,  0x2A,  0x2,  0x1A},
     {0x4,  0x3C,  0x14,  0x24,  0xC,  0x34,  0x2C,  0x4,  0x1C},
     {0x1,  0x39,  0x11,  0x21,  0x9,  0x31,  0x29,  0x1,  0x19},
     {0x6,  0x3E,  0x16,  0x26,  0xE,  0x36,  0x2E,  0x6,  0x1E},
     {0x5,  0x3D,  0x15,  0x25,  0xD,  0x35,  0x2D,  0x5,  0x1D},
     {0x0,  0x38,  0x10,  0x20,  0x8,  0x30,  0x28,  0x0,  0x18},
     {0x3,  0x3B,  0x13,  0x23,  0xB,  0x33,  0x2B,  0x3,  0x1B}
};

static QString Gua_Map[9][9] = {
    {"0",   "111",    "010",    "100",    "001",    "110",    "101",    "000",    "011"},
    {"111", "111111", "010111", "100111", "001111", "110111", "101111", "000111", "011111"},
    {"010", "111010", "010010", "100010", "001010", "110010", "101010", "000010", "011010"},
    {"100", "111100", "010100", "100100", "001100", "110100", "101100", "000100", "011100"},
    {"001", "111001", "010001", "100001", "001001", "110001", "101001", "000001", "011001"},
    {"110", "111110", "010110", "100110", "001110", "110110", "101110", "000110", "011110"},
    {"101", "111101", "010101", "100101", "001101", "110101", "101101", "000101", "011101"},
    {"000", "111000", "010000", "100000", "001000", "110000", "101000", "000000", "011000"},
    {"011", "111011", "010011", "100011", "001011", "110011", "101011", "000011", "011011"}
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSystemTrayIcon *sysTrayIcon = new QSystemTrayIcon(this);
    sysTrayIcon->setIcon(QIcon(":taiji_win.ico"));//设置托盘图标的icon
    sysTrayIcon->show();//展示系统托盘图片

    QGridLayout *gradLayout = new QGridLayout(this);
    QWidget *centerWindow = new QWidget(this);
    Tool *tool = new Tool();

    for(int i = 0 ; i < 81 ; i++){
        QWidget *widget = nullptr;
        int row = i/9;
        int col = i%9;
        int hexKey = GUA_8_64[row][col];
        QString stringKey = Gua_Map[row][col];
        if(i == 0) {
            widget = new GuaTaijiWidget();
        } else if (i <= 8 || i % 9 ==0) {
            widget = new Gua8Widget(hexKey,stringKey);
            Gua gua = tool->readJson(stringKey);
            QBorderLayout *pLayout = new QBorderLayout();
            if (i <= 8){
                QLabel *left =new QLabel(gua.left);
                left->setWordWrap(true);
                left->setAlignment(Qt::AlignCenter);
                left->setText(gua.left.split("", QString::SkipEmptyParts).join("\n"));

                QLabel *right =new QLabel(gua.right);
                right->setWordWrap(true);
                right->setAlignment(Qt::AlignCenter);
                right->setText(gua.right.split("", QString::SkipEmptyParts).join("\n"));

                pLayout->addWidget(left, QBorderLayout::West);
                pLayout->addWidget(right, QBorderLayout::East);
                widget->setLayout(pLayout);
            } else {
                QLabel *top =new QLabel(gua.top);
                top->setWordWrap(true);
                top->setAlignment(Qt::AlignCenter);
                top->setText(gua.top.split("", QString::SkipEmptyParts).join("\n"));

                QLabel *bottom =new QLabel(gua.bottom);
                bottom->setWordWrap(true);
                bottom->setAlignment(Qt::AlignCenter);
                bottom->setText(gua.bottom.split("", QString::SkipEmptyParts).join("\n"));

                pLayout->addWidget(top, QBorderLayout::North);
                pLayout->addWidget(bottom, QBorderLayout::South);
                widget->setLayout(pLayout);
            }
        } else {
            widget = new Gua64Widget(hexKey,stringKey);
            widget->setCursor(Qt::PointingHandCursor);

            Gua gua = tool->readJson(stringKey);
            QBorderLayout *pLayout = new QBorderLayout();
            QLabel *top =new QLabel(gua.top);

            QLabel *left =new QLabel(gua.left);
            left->setWordWrap(true);
            left->setAlignment(Qt::AlignTop);
            left->setText(gua.left.split("", QString::SkipEmptyParts).join("\n"));

            QLabel *right =new QLabel(gua.right);
            right->setWordWrap(true);
            right->setAlignment(Qt::AlignTop);
            right->setText(gua.right.split("", QString::SkipEmptyParts).join("\n"));

            top->setAlignment(Qt::AlignCenter);
            pLayout->addWidget(top, QBorderLayout::North);
            pLayout->addWidget(left, QBorderLayout::West);
            pLayout->addWidget(right, QBorderLayout::East);
            widget->setLayout(pLayout);
        }
        gradLayout->addWidget(widget,row,col);
    }
    this->setCentralWidget(centerWindow);
    centerWindow->setLayout(gradLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
