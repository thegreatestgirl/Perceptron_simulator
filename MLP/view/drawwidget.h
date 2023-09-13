#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>

class DrawWidget : public QGraphicsScene {
  Q_OBJECT

 public:
  explicit DrawWidget(QObject *parent = 0) {}
  ~DrawWidget() {}

 private:
  QPointF previousPoint;  // Координаты предыдущей точки

 private:
  // Для рисования используем события мыши
  void mousePressEvent(QGraphicsSceneMouseEvent *event);
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif  // DRAWWIDGET_H
