// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:srv/TextRecognition.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__TEXT_RECOGNITION__TRAITS_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__TEXT_RECOGNITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/srv/detail/text_recognition__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const TextRecognition_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: label
  {
    out << "label: ";
    rosidl_generator_traits::value_to_yaml(msg.label, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TextRecognition_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: label
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "label: ";
    rosidl_generator_traits::value_to_yaml(msg.label, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TextRecognition_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::srv::TextRecognition_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::TextRecognition_Request & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::TextRecognition_Request>()
{
  return "custom_interfaces::srv::TextRecognition_Request";
}

template<>
inline const char * name<custom_interfaces::srv::TextRecognition_Request>()
{
  return "custom_interfaces/srv/TextRecognition_Request";
}

template<>
struct has_fixed_size<custom_interfaces::srv::TextRecognition_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::srv::TextRecognition_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_interfaces::srv::TextRecognition_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const TextRecognition_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: start_x
  {
    out << "start_x: ";
    rosidl_generator_traits::value_to_yaml(msg.start_x, out);
    out << ", ";
  }

  // member: start_y
  {
    out << "start_y: ";
    rosidl_generator_traits::value_to_yaml(msg.start_y, out);
    out << ", ";
  }

  // member: end_x
  {
    out << "end_x: ";
    rosidl_generator_traits::value_to_yaml(msg.end_x, out);
    out << ", ";
  }

  // member: end_y
  {
    out << "end_y: ";
    rosidl_generator_traits::value_to_yaml(msg.end_y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TextRecognition_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: start_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_x: ";
    rosidl_generator_traits::value_to_yaml(msg.start_x, out);
    out << "\n";
  }

  // member: start_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_y: ";
    rosidl_generator_traits::value_to_yaml(msg.start_y, out);
    out << "\n";
  }

  // member: end_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "end_x: ";
    rosidl_generator_traits::value_to_yaml(msg.end_x, out);
    out << "\n";
  }

  // member: end_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "end_y: ";
    rosidl_generator_traits::value_to_yaml(msg.end_y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TextRecognition_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::srv::TextRecognition_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::TextRecognition_Response & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::TextRecognition_Response>()
{
  return "custom_interfaces::srv::TextRecognition_Response";
}

template<>
inline const char * name<custom_interfaces::srv::TextRecognition_Response>()
{
  return "custom_interfaces/srv/TextRecognition_Response";
}

template<>
struct has_fixed_size<custom_interfaces::srv::TextRecognition_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_interfaces::srv::TextRecognition_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_interfaces::srv::TextRecognition_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interfaces::srv::TextRecognition>()
{
  return "custom_interfaces::srv::TextRecognition";
}

template<>
inline const char * name<custom_interfaces::srv::TextRecognition>()
{
  return "custom_interfaces/srv/TextRecognition";
}

template<>
struct has_fixed_size<custom_interfaces::srv::TextRecognition>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_interfaces::srv::TextRecognition_Request>::value &&
    has_fixed_size<custom_interfaces::srv::TextRecognition_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_interfaces::srv::TextRecognition>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_interfaces::srv::TextRecognition_Request>::value &&
    has_bounded_size<custom_interfaces::srv::TextRecognition_Response>::value
  >
{
};

template<>
struct is_service<custom_interfaces::srv::TextRecognition>
  : std::true_type
{
};

template<>
struct is_service_request<custom_interfaces::srv::TextRecognition_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_interfaces::srv::TextRecognition_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__TEXT_RECOGNITION__TRAITS_HPP_
