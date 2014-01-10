#ifndef WLINEEDIT_H
#define WLINEEDIT_H

#include <QLineEdit>

class WLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    WLineEdit();
    const QString& getOutputStyle();
    const QString& getInputStyle();
    void setToOutputStyle();
    void setToInputStyle();

signals:

public slots:

protected:

    void focusInEvent(QFocusEvent* event);

private:
    QString outputStyle;
    QString inputStyle;

};

#endif // WLINEEDIT_H
