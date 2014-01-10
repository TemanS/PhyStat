#include "wlineedit.h"

WLineEdit::WLineEdit() : QLineEdit()
{
    setStyleSheet(getOutputStyle());
}

// Reimplementation of the virtual function QLineEdit::focusInEvent().
// We need to clear the edit box and set the style sheet to the input
// style, when this edit box gets the focus.
//
void WLineEdit::focusInEvent(QFocusEvent *event)
{
    clear();
    setStyleSheet(getInputStyle());

    QLineEdit::focusInEvent(event);
}

// Different styles for Output and Input in the edit boxes.
//
QString WLineEdit::getOutputStyle()
{
        QString outputStyle =
            "color: gainsboro; "
            "font-size:11px; "
            "font-style: italic, oblique; "
            ;
        return outputStyle;
}

QString WLineEdit::getInputStyle()
{
        QString inputStyle =
            "color: cyan; "
            "font-size:12px; "
            "font-style: normal; "
            ;
        return inputStyle;
}
