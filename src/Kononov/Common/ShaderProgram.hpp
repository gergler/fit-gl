#pragma once

#include <memory>

#include <QOpenGLShaderProgram>
#include <QVector3D>
#include <QVector4D>

#include "Camera.hpp"

namespace Kononov {

template <typename TVertex> class ShaderProgram {
private:
  std::unique_ptr<QOpenGLShaderProgram> m_shader;

protected:
  [[nodiscard]] QOpenGLShaderProgram &getShader() const noexcept {
    return *m_shader;
  }

public:
  ShaderProgram() : m_shader(std::make_unique<QOpenGLShaderProgram>()){};
  ShaderProgram(const ShaderProgram &) = delete;
  ShaderProgram(ShaderProgram &&) noexcept = default;
  virtual ~ShaderProgram() = default;
  ShaderProgram &operator=(const ShaderProgram &) = delete;
  ShaderProgram &operator=(ShaderProgram &&) noexcept = default;

  void bind() { m_shader->bind(); }
  void release() { m_shader->release(); }
  virtual void setupCurrentVao() = 0;
  virtual void prepare(Camera camera, QMatrix4x4 model_matrix) = 0;
};

} // namespace Kononov
