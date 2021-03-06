#pragma once

#include <QOpenGLContext>
#include <QOpenGLFunctions>

namespace Kononov::GL {

template <typename T> constexpr GLenum typeToEnum();
template <> constexpr GLenum typeToEnum<GLfloat>() { return GL_FLOAT; }
template <> constexpr GLenum typeToEnum<GLint>() { return GL_INT; }
template <> constexpr GLenum typeToEnum<GLuint>() { return GL_UNSIGNED_INT; }
template <> constexpr GLenum typeToEnum<GLshort>() { return GL_SHORT; }
template <> constexpr GLenum typeToEnum<GLushort>() {
  return GL_UNSIGNED_SHORT;
}

QOpenGLContext *requireContext();
QOpenGLFunctions *requireFunctions();

} // namespace Kononov::GL
