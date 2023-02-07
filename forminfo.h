#ifndef FORMINFO_H
#define FORMINFO_H

#include <QDialog>

namespace Ui {
class FormInfo;
}

class FormInfo : public QDialog
{
    Q_OBJECT

public:
    explicit FormInfo(QWidget *parent = nullptr);
    ~FormInfo();

public slots:
    void setPointX(float value);

private:
    Ui::FormInfo *ui;
    float pointX = 0;
};

#endif // FORMINFO_H
