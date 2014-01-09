#include "wlineedit.h"

WLineEdit::WLineEdit() : QLineEdit()
{
    //QLineEdit();
}

void WLineEdit::focusInEvent(QFocusEvent *event)
{
    this->clear();

    QLineEdit::focusInEvent(event);
}
