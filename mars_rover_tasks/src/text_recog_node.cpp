// Basic structure for text recognition - can be enhanced with OpenCV text
// detection
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>

class TextRecognitionNode : public rclcpp::Node {
public:
    TextRecognitionNode() : Node("text_recognition_node") {
        // Subscribe to image topic
        image_subscriber_ = this->create_subscription<sensor_msgs::msg::Image>(
            "/leo/camera/image_raw", 1,
        std::bind(&TextRecognitionNode::image_callback, this,
                  std::placeholders::_1));
    }

private:
  void image_callback(const sensor_msgs::msg::Image::SharedPtr msg) {
    // Convert ROS image to OpenCV image
    cv_bridge::CvImagePtr cv_ptr;
    try {
      cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    } catch (cv_bridge::Exception &e) {
      RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
      return;
    }

    // Perform text detection here
    detect_text(cv_ptr->image);
  }

  void detect_text(const cv::Mat &image) {
    // Simplified text detection - replace with full AI model integration
    // For now, we'll simulate detection results
    RCLCPP_INFO(this->get_logger(), "Processing image for text detection...");

    // Here you would integrate the Python text recognition model
    // or implement OpenCV-based text detection

    cv::Mat gray, thresh;
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    cv::threshold(gray, thresh, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

    // Find contours that might contain text
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(thresh, contours, cv::RETR_EXTERNAL,
                     cv::CHAIN_APPROX_SIMPLE);

    for (const auto &contour : contours) {
      cv::Rect bounding_rect = cv::boundingRect(contour);

      // Filter by size (assuming text boxes have reasonable dimensions)
      if (bounding_rect.width > 50 && bounding_rect.height > 20 &&
          bounding_rect.width < 200 && bounding_rect.height < 100) {

        // Extract ROI
        cv::Mat roi = image(bounding_rect);

        // Simulate text recognition (replace with actual OCR)
        std::string detected_text = simulateTextRecognition(roi);

        if (!detected_text.empty()) {
          std::string position =
              std::to_string(bounding_rect.x) + "-" +
              std::to_string(bounding_rect.y) + "-" +
              std::to_string(bounding_rect.x + bounding_rect.width) + "-" +
              std::to_string(bounding_rect.y + bounding_rect.height);

          RCLCPP_INFO(this->get_logger(), "OCR Result: %s, (%s)",
                      detected_text.c_str(), position.c_str());
        }
      }
    }
  }

  std::string simulateTextRecognition(const cv::Mat &roi) {
    // This is a simplified simulation - replace with actual OCR
    // For a complete solution, integrate Tesseract OCR or the Python model

    // Analyze color patterns to guess the text
    cv::Scalar mean_color = cv::mean(roi);

    // Simple heuristic based on the expected label colors
    // This is just for demonstration - use proper OCR in production
    if (mean_color[1] > mean_color[0] && mean_color[1] > mean_color[2]) {
      return "FOOD"; // Greenish tint might indicate FOOD label
    } else if (mean_color[0] > mean_color[1] && mean_color[2] < mean_color[0]) {
      return "WASTE"; // Reddish tint might indicate WASTE label
    }

    return ""; // No text detected
  }

  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_subscriber_;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<TextRecognitionNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}