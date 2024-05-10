#ifndef RGBPREVIEW_H
#define RGBPREVIEW_H

#include <QLabel>

class RGBPreview {
public:
    void init(QLabel* displayedMouse, QLabel* baseMouseImage, QList<QLabel*> colorLabels);
    void draw(int rgb_mode);

private:
    QList<QLabel*> colors;
    QLabel* displayedMouse;
    QLabel* baseMouseImage;
    double rgb_duration = 0;
    int rgb_color = 0;

    void hideLabels();
};

#endif // RGBPREVIEW_H
