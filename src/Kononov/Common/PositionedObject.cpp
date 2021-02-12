#include "PositionedObject.hpp"

namespace Kononov {

QMatrix4x4 PositionedObject::getTransformMatrix() const {
  QMatrix4x4 res;
  res.translate(m_position);
  res.rotate(m_rotation);
  res.scale(m_scale);
  return res;
}

QMatrix4x4 PositionedObject::getAbsoluteTransformMatrix() const {
  if (m_parent != nullptr) {
    return m_parent->getAbsoluteTransformMatrix() * getTransformMatrix();
  }
  return getTransformMatrix();
}

QVector3D PositionedObject::getAbsolutePosition() const {
  if (m_parent != nullptr) {
    return m_parent->getAbsoluteTransformMatrix() * m_position;
  }
  return m_position;
}

const std::shared_ptr<PositionedObject> &PositionedObject::getParent() const {
  return m_parent;
}

void PositionedObject::setParent(
    const std::shared_ptr<PositionedObject> &parent) {
  m_parent = parent;
}

const QVector3D &PositionedObject::getPosition() const { return m_position; }

void PositionedObject::setPosition(const QVector3D &position) {
  m_position = position;
}

const QQuaternion &PositionedObject::getRotation() const { return m_rotation; }

void PositionedObject::setRotation(const QQuaternion &rotation) {
  m_rotation = rotation;
}

const QVector3D &PositionedObject::getScale() const { return m_scale; }

void PositionedObject::setScale(const QVector3D &scale) { m_scale = scale; }

} // namespace Kononov