// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:srv/TextRecognition.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__TEXT_RECOGNITION__STRUCT_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__TEXT_RECOGNITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__srv__TextRecognition_Request __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__srv__TextRecognition_Request __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TextRecognition_Request_
{
  using Type = TextRecognition_Request_<ContainerAllocator>;

  explicit TextRecognition_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->label = "";
    }
  }

  explicit TextRecognition_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : label(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->label = "";
    }
  }

  // field types and members
  using _label_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _label_type label;

  // setters for named parameter idiom
  Type & set__label(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->label = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::srv::TextRecognition_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::srv::TextRecognition_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::srv::TextRecognition_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::srv::TextRecognition_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::TextRecognition_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::TextRecognition_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::TextRecognition_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::TextRecognition_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::srv::TextRecognition_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::srv::TextRecognition_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__srv__TextRecognition_Request
    std::shared_ptr<custom_interfaces::srv::TextRecognition_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__srv__TextRecognition_Request
    std::shared_ptr<custom_interfaces::srv::TextRecognition_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TextRecognition_Request_ & other) const
  {
    if (this->label != other.label) {
      return false;
    }
    return true;
  }
  bool operator!=(const TextRecognition_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TextRecognition_Request_

// alias to use template instance with default allocator
using TextRecognition_Request =
  custom_interfaces::srv::TextRecognition_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_interfaces


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__srv__TextRecognition_Response __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__srv__TextRecognition_Response __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TextRecognition_Response_
{
  using Type = TextRecognition_Response_<ContainerAllocator>;

  explicit TextRecognition_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->start_x = 0l;
      this->start_y = 0l;
      this->end_x = 0l;
      this->end_y = 0l;
    }
  }

  explicit TextRecognition_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->start_x = 0l;
      this->start_y = 0l;
      this->end_x = 0l;
      this->end_y = 0l;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _start_x_type =
    int32_t;
  _start_x_type start_x;
  using _start_y_type =
    int32_t;
  _start_y_type start_y;
  using _end_x_type =
    int32_t;
  _end_x_type end_x;
  using _end_y_type =
    int32_t;
  _end_y_type end_y;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__start_x(
    const int32_t & _arg)
  {
    this->start_x = _arg;
    return *this;
  }
  Type & set__start_y(
    const int32_t & _arg)
  {
    this->start_y = _arg;
    return *this;
  }
  Type & set__end_x(
    const int32_t & _arg)
  {
    this->end_x = _arg;
    return *this;
  }
  Type & set__end_y(
    const int32_t & _arg)
  {
    this->end_y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::srv::TextRecognition_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::srv::TextRecognition_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::srv::TextRecognition_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::srv::TextRecognition_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::TextRecognition_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::TextRecognition_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::TextRecognition_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::TextRecognition_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::srv::TextRecognition_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::srv::TextRecognition_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__srv__TextRecognition_Response
    std::shared_ptr<custom_interfaces::srv::TextRecognition_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__srv__TextRecognition_Response
    std::shared_ptr<custom_interfaces::srv::TextRecognition_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TextRecognition_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->start_x != other.start_x) {
      return false;
    }
    if (this->start_y != other.start_y) {
      return false;
    }
    if (this->end_x != other.end_x) {
      return false;
    }
    if (this->end_y != other.end_y) {
      return false;
    }
    return true;
  }
  bool operator!=(const TextRecognition_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TextRecognition_Response_

// alias to use template instance with default allocator
using TextRecognition_Response =
  custom_interfaces::srv::TextRecognition_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_interfaces

namespace custom_interfaces
{

namespace srv
{

struct TextRecognition
{
  using Request = custom_interfaces::srv::TextRecognition_Request;
  using Response = custom_interfaces::srv::TextRecognition_Response;
};

}  // namespace srv

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__TEXT_RECOGNITION__STRUCT_HPP_
