#ifndef CUSTOMKEYBOARDDIALOG_H
#define CUSTOMKEYBOARDDIALOG_H

#include "mousesettings.h"
#include <QDialog>

namespace Ui {
class CustomKeyboardDialog;
}

class CustomKeyboardDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomKeyboardDialog(MouseSettings::MouseButton &btn, QWidget *parent = nullptr);
    ~CustomKeyboardDialog();

signals:
    void applySpecialAction(uint16_t value);

private slots:

    void on_radioButton_2_toggled(bool checked);

    void on_radioButton_toggled(bool checked);

    void on_specialAction_activated(int index);

    void on_customKeybind_keySequenceChanged(const QKeySequence &keySequence);

private:
    MouseSettings::MouseButton &button;
    Ui::CustomKeyboardDialog *ui;
};

#endif // CUSTOMKEYBOARDDIALOG_H
