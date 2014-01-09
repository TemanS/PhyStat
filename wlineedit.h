#ifndef WLINEEDIT_H
#define WLINEEDIT_H

#include <QLineEdit>

class WLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    WLineEdit();

signals:

public slots:

protected:

    void focusInEvent(QFocusEvent* event);

};

#endif // WLINEEDIT_H
