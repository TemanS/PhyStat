#include "wlineedit.h"

WLineEdit::WLineEdit() : QLineEdit()
{
    setStyleSheet(getOutputStyle());
}

// Reimplementation of the virtual function QLineEdit::focusInEvent().
// When this edit box gets the focus, clear the edit box, set the
// alignment to the left, and set the style sheet to the input style.
//
void WLineEdit::focusInEvent(QFocusEvent *event)
{
    clear();
    setAlignment(Qt::AlignLeft);
    setStyleSheet(getInputStyle());

    QLineEdit::focusInEvent(event);
}

void WLineEdit::setToOutputStyle()
{
    setStyleSheet(getOutputStyle());
}

void WLineEdit::setToInputStyle()
{
    setStyleSheet(getInputStyle());
}

// Different styles for Output and Input in the edit boxes.
//
// setStyleSheet(const QString &), expects a reference to a QString
// constant, so define these functions as const QString &
//
// inputStyle and outputStyle must be class members, because a reference
// defined locally to a function goes out of scope when the function
// exits, so a function returning such a reference returns a "dangling"
// reference, also known as a use-after-free bug. Class members persist
// as long as the class exists, so they can be returned by reference
// from any of the functions in the class.
//
const QString& WLineEdit::getOutputStyle()
{
    outputStyle =
        "color: gainsboro; "
        "font-size:11px; "
        "font-style: italic, oblique; "
        ;
    return outputStyle;
}

const QString& WLineEdit::getInputStyle()
{
    inputStyle =
        "color: cyan; "
        "font-size:12px; "
        "font-style: normal; "
        ;
    return inputStyle;
}
