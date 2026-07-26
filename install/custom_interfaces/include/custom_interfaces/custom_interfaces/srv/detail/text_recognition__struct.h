// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:srv/TextRecognition.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__TEXT_RECOGNITION__STRUCT_H_
#define CUSTOM_INTERFACES__SRV__DETAIL__TEXT_RECOGNITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'label'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/TextRecognition in the package custom_interfaces.
typedef struct custom_interfaces__srv__TextRecognition_Request
{
  /// Label to look for
  rosidl_runtime_c__String label;
} custom_interfaces__srv__TextRecognition_Request;

// Struct for a sequence of custom_interfaces__srv__TextRecognition_Request.
typedef struct custom_interfaces__srv__TextRecognition_Request__Sequence
{
  custom_interfaces__srv__TextRecognition_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__TextRecognition_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/TextRecognition in the package custom_interfaces.
typedef struct custom_interfaces__srv__TextRecognition_Response
{
  /// was label string found?
  bool success;
  /// X axis coordinate of Start point of Bounding Box
  int32_t start_x;
  /// Y axis coordinate of Start point of Bounding Box
  int32_t start_y;
  /// X axis coordinate of End point of Bounding Box
  int32_t end_x;
  /// Y axis coordinate of End point of Bounding Box
  int32_t end_y;
} custom_interfaces__srv__TextRecognition_Response;

// Struct for a sequence of custom_interfaces__srv__TextRecognition_Response.
typedef struct custom_interfaces__srv__TextRecognition_Response__Sequence
{
  custom_interfaces__srv__TextRecognition_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__TextRecognition_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__TEXT_RECOGNITION__STRUCT_H_
