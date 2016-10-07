#ifndef WIDGET_H
#define WIDGET_H

#include <ctime>

#include <opencv2/opencv.hpp>

#include <QWidget>
#include <QTimer>
#include <QImage>

#include "camera/camera_opencv.hpp"
#include "locator/locator.hpp"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void capture_update();

private:
    Ui::Widget  *ui;

    // capture
	QImage	    capture_image;
    QTimer      *capture_timer;
    Camera      camera;
    cv::Mat     capture_frame;
    Locator     locator;
    std::vector<cv::Point> locator_points;
};

#endif // WIDGET_H
