// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:srv/TextRecognition.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__TEXT_RECOGNITION__BUILDER_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__TEXT_RECOGNITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/srv/detail/text_recognition__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_TextRecognition_Request_label
{
public:
  Init_TextRecognition_Request_label()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::srv::TextRecognition_Request label(::custom_interfaces::srv::TextRecognition_Request::_label_type arg)
  {
    msg_.label = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::TextRecognition_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::TextRecognition_Request>()
{
  return custom_interfaces::srv::builder::Init_TextRecognition_Request_label();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_TextRecognition_Response_end_y
{
public:
  explicit Init_TextRecognition_Response_end_y(::custom_interfaces::srv::TextRecognition_Response & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::TextRecognition_Response end_y(::custom_interfaces::srv::TextRecognition_Response::_end_y_type arg)
  {
    msg_.end_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::TextRecognition_Response msg_;
};

class Init_TextRecognition_Response_end_x
{
public:
  explicit Init_TextRecognition_Response_end_x(::custom_interfaces::srv::TextRecognition_Response & msg)
  : msg_(msg)
  {}
  Init_TextRecognition_Response_end_y end_x(::custom_interfaces::srv::TextRecognition_Response::_end_x_type arg)
  {
    msg_.end_x = std::move(arg);
    return Init_TextRecognition_Response_end_y(msg_);
  }

private:
  ::custom_interfaces::srv::TextRecognition_Response msg_;
};

class Init_TextRecognition_Response_start_y
{
public:
  explicit Init_TextRecognition_Response_start_y(::custom_interfaces::srv::TextRecognition_Response & msg)
  : msg_(msg)
  {}
  Init_TextRecognition_Response_end_x start_y(::custom_interfaces::srv::TextRecognition_Response::_start_y_type arg)
  {
    msg_.start_y = std::move(arg);
    return Init_TextRecognition_Response_end_x(msg_);
  }

private:
  ::custom_interfaces::srv::TextRecognition_Response msg_;
};

class Init_TextRecognition_Response_start_x
{
public:
  explicit Init_TextRecognition_Response_start_x(::custom_interfaces::srv::TextRecognition_Response & msg)
  : msg_(msg)
  {}
  Init_TextRecognition_Response_start_y start_x(::custom_interfaces::srv::TextRecognition_Response::_start_x_type arg)
  {
    msg_.start_x = std::move(arg);
    return Init_TextRecognition_Response_start_y(msg_);
  }

private:
  ::custom_interfaces::srv::TextRecognition_Response msg_;
};

class Init_TextRecognition_Response_success
{
public:
  Init_TextRecognition_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TextRecognition_Response_start_x success(::custom_interfaces::srv::TextRecognition_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_TextRecognition_Response_start_x(msg_);
  }

private:
  ::custom_interfaces::srv::TextRecognition_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::TextRecognition_Response>()
{
  return custom_interfaces::srv::builder::Init_TextRecognition_Response_success();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__TEXT_RECOGNITION__BUILDER_HPP_
