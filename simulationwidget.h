#ifndef SIMULATIONWIDGET_H
#define SIMULATIONWIDGET_H

#include <QWidget>
#include <QTimer>

class SimulationWidget : public QWidget {
    Q_OBJECT

public:
    SimulationWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void updatePosition();

private:
    QPointF position; // Position actuelle du cercle
    QPointF velocity; // Vitesse du cercle
    QTimer timer;     // Timer pour mettre à jour la position
};

#endif // SIMULATIONWIDGET_H
