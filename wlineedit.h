#ifndef WLINEEDIT_H
#define WLINEEDIT_H

#include <QLineEdit>

class WLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    WLineEdit();
    QString getOutputStyle();
    QString getInputStyle();

signals:

public slots:

protected:

    void focusInEvent(QFocusEvent* event);

private:
};

#endif // WLINEEDIT_H
