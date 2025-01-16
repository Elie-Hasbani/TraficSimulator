#include "simulationwidget.h"
#include <QPainter>

SimulationWidget::SimulationWidget(QWidget *parent)
    : QWidget(parent), position(50, 50), velocity(2, 3) {
    // Configurer le timer
    connect(&timer, &QTimer::timeout, this, &SimulationWidget::updatePosition);
    timer.start(16); // 16 ms pour ~60 FPS
}

void SimulationWidget::paintEvent(QPaintEvent * /*event*/) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Dessiner le cercle
    painter.setBrush(Qt::blue);
    painter.drawEllipse(position, 20, 20); // Cercle de rayon 20
}

void SimulationWidget::updatePosition() {
    // Mettre à jour la position en fonction de la vitesse
    position += velocity;

    // Gérer les collisions avec les bords de la fenêtre
    if (position.x() - 20 < 0 || position.x() + 20 > width()) {
        velocity.setX(-velocity.x()); // Inverser la direction horizontale
    }
    if (position.y() - 20 < 0 || position.y() + 20 > height()) {
        velocity.setY(-velocity.y()); // Inverser la direction verticale
    }

    // Redessiner
    update();
}
