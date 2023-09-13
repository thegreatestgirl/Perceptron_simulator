#include "drawwidget.h"

void DrawWidget::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  // При нажатии кнопки мыши отрисовываем эллипс
  addEllipse(event->scenePos().x() - 5, event->scenePos().y() - 5, 50, 50,
             QPen(Qt::NoPen), QBrush(QColor("#fff")));
  // QBrush(QColor("#19822d")));
  // Сохраняем координаты точки нажатия
  previousPoint = event->scenePos();
}

void DrawWidget::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
  // Отрисовываем линии с использованием предыдущей координаты
  addLine(previousPoint.x(), previousPoint.y(), event->scenePos().x(),
          event->scenePos().y(),
          QPen(QColor("#fff"), 50, Qt::SolidLine, Qt::RoundCap));
  // Обновляем данные о предыдущей координате
  previousPoint = event->scenePos();
}
