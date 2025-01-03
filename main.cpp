#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>

class MovingObjectWidget : public QWidget
{
    Q_OBJECT

public:
    MovingObjectWidget(QWidget *parent = nullptr)
        : QWidget(parent), xPos(50), yPos(50), speed(20)
    {
        setFixedSize(1500, 200);  // Set the size of the window

        // Set up a timer to update the position every 16ms (~60fps)
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MovingObjectWidget::onTimeout);
        timer->start(16);  // Start the timer
    }

protected:
    void paintEvent(QPaintEvent *event) override
    {
        QPainter painter(this);
        painter.setBrush(Qt::blue);  // Set the color for the moving object
        painter.drawRect(xPos, yPos, 50, 50);  // Draw a 50x50 rectangle
    }

    void keyPressEvent(QKeyEvent *event) override
    {
        // Change direction based on key press
        if (event->key() == Qt::Key_Up) {
            yPos -= speed;
        } else if (event->key() == Qt::Key_Down) {
            yPos += speed;
        } else if (event->key() == Qt::Key_Left) {
            xPos -= speed;
        } else if (event->key() == Qt::Key_Right) {
            xPos += speed;
        }

        update();  // Redraw the widget
    }

private slots:
    void onTimeout()
    {
        // Update the position of the object
        xPos += speed;
        speed = speed - 0.1;
        if (speed <= 0){
            speed = 0;
        }
        if (xPos > width()) {
            xPos = 0;  // Reset position if it goes beyond the window
        }

        update();  // Trigger a repaint
    }

private:
    float xPos, yPos;  // Position of the object
    float speed;       // Speed of movement
    QTimer *timer;   // Timer to move the object
};


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MovingObjectWidget widget;
    widget.show();

    return app.exec();
}

#include "main.moc"

