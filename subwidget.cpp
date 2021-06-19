#include "subwidget.h"

static QBorderLayout *borderLayout;
static QWidget *top;
static Tool *tool = new Tool();

#define WIDGET_WIDTH    446
#define WIDGET_HEIGHT   600

SubWidget::SubWidget(QDialog *parent) : QDialog(parent)
{
    setFixedSize(WIDGET_WIDTH,WIDGET_HEIGHT);
}

void SubWidget::showGua(int hex, QString string){
    delete (borderLayout);
    delete (top);


    borderLayout = new QBorderLayout();
    Gua gua = tool->readJson(string);
    // top
    QBorderLayout *pLayout = new QBorderLayout();
    top = new Gua64Widget(hex,string);

    QLabel *top_content =new QLabel(gua.top);
    top_content->setAlignment(Qt::AlignCenter);

    QLabel *left_content =new QLabel(gua.left);
    left_content->setWordWrap(true);
    left_content->setAlignment(Qt::AlignTop);
    left_content->setText(gua.left.split("", QString::SkipEmptyParts).join("\n"));

    QLabel *right_content =new QLabel(gua.right);
    right_content->setWordWrap(true);
    right_content->setAlignment(Qt::AlignTop);
    right_content->setText(gua.right.split("", QString::SkipEmptyParts).join("\n"));
    pLayout->addWidget(top_content, QBorderLayout::North);
    pLayout->addWidget(left_content, QBorderLayout::West);
    pLayout->addWidget(right_content, QBorderLayout::East);
    top->setLayout(pLayout);
    borderLayout->addWidget(top, QBorderLayout::North);

    // center
    QTextEdit *center = new QTextEdit();
    center->append(gua.gua_ci + "\n");
    center->append(gua.tuan_ci + "\n");
    center->append(gua.da_xiang + "\n");
    center->append(gua.xiang_ci);
    center->append(gua.xiao_xiang_1);
    center->append(gua.xiao_xiang_2);
    center->append(gua.xiao_xiang_3);
    center->append(gua.xiao_xiang_4);
    center->append(gua.xiao_xiang_5);
    center->append(gua.xiao_xiang_6);
    center->append(gua.xiao_xiang_7 + "\n");
    center->append(gua.yao_ci);
    center->append(gua.yao_1);
    center->append(gua.yao_2);
    center->append(gua.yao_3);
    center->append(gua.yao_4);
    center->append(gua.yao_5);
    center->append(gua.yao_6);
    center->append(gua.yao_7);
    center->setReadOnly(true);
    borderLayout->addWidget(center, QBorderLayout::Center);

    // bottom
    QLabel *bottom = new QLabel();
    QImage *image= new QImage(":yijing.jpeg");
    QPixmap pixmap = QPixmap::fromImage(*image);
    bottom->setPixmap(pixmap);

    borderLayout->addWidget(bottom, QBorderLayout::South);
    setLayout(borderLayout);

    MainWindow *w = MainWindow::getInstance();
    int width = w->width();
    int height = w->height();
    int x = w->pos().x();
    int y = w->pos().y();

    QScreen *screen=QGuiApplication::primaryScreen();
    QRect mm = screen->availableGeometry();
    int screen_width = mm.width();
    int screen_height = mm.height();

    // 默认屏幕正中央
    int real_x = (screen_width >> 1)  - (WIDGET_WIDTH >> 1);
    int real_y = (screen_height >> 1) - (WIDGET_HEIGHT >> 1);

    // 如果屏幕分辨率大于两个窗口的总宽度，才会在左侧或者右侧显示
    // 否则用默认值显示在正中央
    if(screen_width > width + WIDGET_WIDTH){
        // 右侧空间不够，则显示到左侧
        if(x + width + WIDGET_WIDTH > screen_width){
            real_x = x - WIDGET_WIDTH;
            real_y = y;
        // 右侧空间足够，则显示到右侧
        } else {
            real_x = x + width;
            real_y = y;
        }
    }
    move(real_x,real_y);
    show();
}
