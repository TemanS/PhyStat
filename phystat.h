#ifndef PHYSTAT_H
#define PHYSTAT_H

#include <QDialog>
#include <QLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QList>
#include <QButtonGroup>
#include <QObject>
#include <Qt>
#include <QtGui>
#include <QtWidgets>
#include <QSize>
#include "style.h"
#include "metenglayout.h"

enum {
    enum_weight,
    enum_cholesterol,
    enum_blood_pressure,
    enum_heart_rate,
    enum_max_stat
};

class PhyStat : public QDialog
{
    Q_OBJECT

public:
    PhyStat(QWidget *parent = 0);
    ~PhyStat();

    void createInputGroup();
    void createOutputGroup();

private slots:
    void onGo();
    void onMeasure(int rbId);

private:
    QGroupBox   *inputGroupBox;
    QGroupBox   *outputGroupBox;
    QObjectList outBoxList;
    QObjectList outLabelList;
    QButtonGroup *genderButtons;
    QButtonGroup *measureButtonGroup;
    MetEngLayout *htedit;
};

#endif // PHYSTAT_H
