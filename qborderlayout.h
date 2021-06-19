#ifndef QBORDERLAYOUT_H
#define QBORDERLAYOUT_H

#include <QLayout>
#include <QRect>

class QBorderLayout : public QLayout
{
public:
    enum Position {West, North, South, East, Center};

    explicit QBorderLayout(QWidget *parent, int margin = 0, int spacing = -1);
    QBorderLayout(int spacing = -1);
    ~QBorderLayout();

    void addItem(QLayoutItem *item) Q_DECL_OVERRIDE;
    void addWidget(QWidget *widget, Position position);
    Qt::Orientations expandingDirections() const Q_DECL_OVERRIDE;
    bool hasHeightForWidth() const Q_DECL_OVERRIDE;
    int count() const Q_DECL_OVERRIDE;
    QLayoutItem *itemAt(int index) const Q_DECL_OVERRIDE;
    QSize minimumSize() const Q_DECL_OVERRIDE;
    void setGeometry(const QRect &rect) Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;
    QLayoutItem *takeAt(int index) Q_DECL_OVERRIDE;

    void add(QLayoutItem *item, Position position);

private:
    struct ItemWrapper
    {
        ItemWrapper(QLayoutItem *i, Position p) {
            item = i;
            position = p;
        }

        QLayoutItem *item;
        Position position;
    };

    enum SizeType { MinimumSize, SizeHint };
    QSize calculateSize(SizeType sizeType) const;

    QList<ItemWrapper *> list;
};

#endif // QBORDERLAYOUT_H
