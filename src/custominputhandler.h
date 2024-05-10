#ifndef INPUTMONITORINGTHREAD_H
#define INPUTMONITORINGTHREAD_H

#include "mousesettings.h"
#include <QThread>
#include <hidapi/hidapi.h>


class CustomMouseInputHandler : public QObject
{
    Q_OBJECT
public:
    CustomMouseInputHandler(hid_device *device, MouseSettings *mouseSettings);
    ~CustomMouseInputHandler();
    void run();
signals:
    void input(unsigned char inputType, unsigned char mouseKey, unsigned char dpi);
private:
    hid_device *device;
    MouseSettings *mouseSettings;
    void sendCustomKeyInput(hid_device *device, QKeyCombination keyCombo);
    void sendMultimediaKey(hid_device *device, uint16_t key);
};

#endif // INPUTMONITORINGTHREAD_H
