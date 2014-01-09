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
#include <QIntValidator>
#include "style.h"
#include "metenglayout.h"

// Enumeration of the output QEditLine boxes used to index into the
// QWidgetList that contains them.
//
enum {
    ob_weight,
    ob_body_mass_index,
    ob_blood_pressure,
    ob_heart_rate,
    ob_total_cholesterol,
    ob_ldl_cholesterol,
    ob_hdl_cholesterol,
    ob_max
};

// Enumeration of the IDs of the Measurement System radio buttons.
//
enum {
    ms_english,
    ms_metric
};

// Enumeration of the IDs of the Gender radio buttons.
//
enum {
    sx_male,
    sx_female
};

// Min/Max age for the QIntValidator *ageValidator
//
#define MIN_AGE 1
#define MAX_AGE 110

// Widths for the various Box objects.
//
#define BOX_WID    100  // typical QLineEdit box, etc
#define INBOX_WID  250  // inputGroupBox width
#define OUTBOX_WID 300  // outputGroupBox width

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
    QGroupBox  *inputGroupBox;
    QGroupBox  *outputGroupBox;
    QWidgetList outBoxList;
    QWidgetList outLabelList;
    QButtonGroup *genderButtonGroup;
    QButtonGroup *measureButtonGroup;
    MetEngLayout *htedit;
    QIntValidator ageValidator;
};

#endif // PHYSTAT_H
