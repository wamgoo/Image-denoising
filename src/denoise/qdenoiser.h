#ifndef QDENOISER_H
#define QDENOISER_H
#include "Denoise.h"
#include "src/RgbMy.h"
#include <math.h>
#include <QImage>
#include <QMessageBox>
#include <QFuture>
#include <QtConcurrentRun>
#include <QFile>
#include <QElapsedTimer>
#include <QTextStream>
#include <QColor>

class QDenoiser
{
private:
    bool rendering,paused;
    QImage *input,*output;
    QString _status;
    denoiseClass* sets;
    int progress,m,n;
    denoiseClass::method denoisingMethod;

public:
    QDenoiser();
    QDenoiser(QImage* input,denoiseClass* settings);
private slots:
    void simple_squares(int size);
    void NLM(QImage *inim,QImage *outim,QString settings, int* progress);
    void NLM_multyThread(QImage *inim,QImage *outim,QString settings);
    void NLM_fast(int size_m,int size_b,int h);
    void NLM_fast_FFT(int size_m,int size_b,int h);
    void popMessageBox(int m1,int n1,int size_b);
    void setProgress(int prog);

public slots:
    void setRendering(bool state);
    void setPaused(bool state);
    void setStatus(QString status);
    void setImage(QImage* inim);
    void setSettings(denoiseClass* settings);
    void setDenoisingMethod(denoiseClass::method val);
    denoiseClass::method getDenoisingMethod();

    denoiseClass* getSettings();
    QImage* getImage();
    int getProgress();
    QString getStatus();

    bool isRendering();
    bool isPaused();

    void startRender();
    void pauseRender();
    void resumeRender();
    void cancelRender();
};

#endif // QDENOISER_H
