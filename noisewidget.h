#ifndef NOISEWIDGET_H
#define NOISEWIDGET_H
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QSlider>
#include <QLabel>
#include <QComboBox>
#include "Noise.h"
#include <QtGui/QWidget>


class noiseWidget : public QWidget
{
    Q_OBJECT
    QGridLayout *layout;      // layout for the centralwidget
    QLineEdit * edit_int_red,*edit_int_green,*edit_int_blue,*edit_pro_red,*edit_pro_green,*edit_pro_blue,*edit_num;
    QPushButton *select;
    QComboBox *combo;
    QSlider *slideIntensity,*slideProbability;


public:
    noiseWidget(QWidget *parent = 0);
    ~noiseWidget();

public slots:
    void on_slideIntensity_valueChanged(int value);
    void on_slideProbability_valueChanged(int value);
    void hide();
    void on_combo_IndexChanged(int ind);
    noiseClass* getNoise();
};

#endif // NOISEWIDGET_H
