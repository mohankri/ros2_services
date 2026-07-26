// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from custom_interfaces:srv/TextRecognition.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "custom_interfaces/srv/detail/text_recognition__struct.h"
#include "custom_interfaces/srv/detail/text_recognition__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool custom_interfaces__srv__text_recognition__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[64];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("custom_interfaces.srv._text_recognition.TextRecognition_Request", full_classname_dest, 63) == 0);
  }
  custom_interfaces__srv__TextRecognition_Request * ros_message = _ros_message;
  {  // label
    PyObject * field = PyObject_GetAttrString(_pymsg, "label");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->label, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * custom_interfaces__srv__text_recognition__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of TextRecognition_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("custom_interfaces.srv._text_recognition");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "TextRecognition_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  custom_interfaces__srv__TextRecognition_Request * ros_message = (custom_interfaces__srv__TextRecognition_Request *)raw_ros_message;
  {  // label
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->label.data,
      strlen(ros_message->label.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "label", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "custom_interfaces/srv/detail/text_recognition__struct.h"
// already included above
// #include "custom_interfaces/srv/detail/text_recognition__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool custom_interfaces__srv__text_recognition__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[65];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("custom_interfaces.srv._text_recognition.TextRecognition_Response", full_classname_dest, 64) == 0);
  }
  custom_interfaces__srv__TextRecognition_Response * ros_message = _ros_message;
  {  // success
    PyObject * field = PyObject_GetAttrString(_pymsg, "success");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->success = (Py_True == field);
    Py_DECREF(field);
  }
  {  // start_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "start_x");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->start_x = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // start_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "start_y");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->start_y = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // end_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "end_x");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->end_x = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // end_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "end_y");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->end_y = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * custom_interfaces__srv__text_recognition__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of TextRecognition_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("custom_interfaces.srv._text_recognition");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "TextRecognition_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  custom_interfaces__srv__TextRecognition_Response * ros_message = (custom_interfaces__srv__TextRecognition_Response *)raw_ros_message;
  {  // success
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->success ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "success", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // start_x
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->start_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "start_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // start_y
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->start_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "start_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // end_x
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->end_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "end_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // end_y
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->end_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "end_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
