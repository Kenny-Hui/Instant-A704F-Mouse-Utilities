#include "rgbpreview.h"
#include "mousesettings.h"
#include <QPainter>
#include <math.h>

void RGBPreview::init(QLabel* displayedMouse, QLabel* baseMouseImage, QList<QLabel*> colorLabels) {
    this->displayedMouse = displayedMouse;
    this->baseMouseImage = baseMouseImage;
    this->colors.append(colorLabels);
    hideLabels();
}

void RGBPreview::hideLabels() {
    baseMouseImage->hide();
    for(QLabel* label : colors) {
        label->hide();
    }
}

void RGBPreview::draw(int rgb_mode) {
    int speed = rgb_mode - 0x09;
    bool is_static = rgb_mode == MouseSettings::RGBMode::STATIC;
    bool is_off = rgb_mode == MouseSettings::RGBMode::OFF;

    QLabel* &targetLabel = is_off ? colors[colors.size()-1] : is_static ? colors[2] : colors[rgb_color];
    QPixmap mousePixmap = baseMouseImage->pixmap();
    QPixmap rgbOverlayPixmap = targetLabel->pixmap();

    QPainter painter(&mousePixmap);
    painter.setOpacity(is_static ? 1 : sin(rgb_duration));
    painter.drawPixmap(0, 0, rgbOverlayPixmap);
    painter.end();
    displayedMouse->setPixmap(mousePixmap);

    rgb_duration += (pow(speed, 3) / 20000.0);

    if(rgb_duration >= 3) {
        rgb_duration = 0;
        rgb_color = (rgb_color + 1) % colors.size();
    }
}
