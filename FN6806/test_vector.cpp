#include "test_vector.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

void test_vector_exception_demo() {
  cout << __FUNCTION__ << ":\n";

  std::vector<int> v(10);
  try {
    v.at(10) = 100;
  } catch (const std::out_of_range &e) {
    std::cout << "Caught out_of_range: " << e.what() << '\n';
  }

  try {
    v.resize(v.max_size() + 1);
  } catch (const std::length_error &e) {
    std::cout << "Caught length_error: " << e.what() << '\n';
  }

  try {
    std::vector<int> v2(v.max_size());
    v2.push_back(1);
  } catch (const std::bad_alloc &e) {
    std::cout << "Caught bad_alloc: " << e.what() << '\n';
  }
  cout << "\n";
}

// -------------------------------------------------

// Use Lippincott functions to handle exceptions centralizely.
// Apply DRY

void handle_exception(const char *time, const char *file, int line,
                      const char *function) {
  std::ostringstream oss;
  oss << "[" << time << "]"
      << " " << file << ":" << line << " (" << function << ") ";
  const auto prefix = oss.str();

  try {
    throw; // re-throw exception already in flight
  } catch (const std::out_of_range &e) {
    std::cout << prefix << "Caught out_of_range: " << e.what() << '\n';
  } catch (const std::length_error &e) {
    std::cout << prefix << "Caught length_error: " << e.what() << '\n';
  } catch (const std::bad_alloc &e) {
    std::cout << prefix << "Caught bad_alloc: " << e.what() << '\n';
  } catch (const std::runtime_error &) {
  } catch (const std::exception &) {
  }
}

void test_vector_exception() {
  cout << __FUNCTION__ << ":\n";
  std::vector<int> v(10);
  try {
    v.at(10) = 100;
  } catch (...) {
    handle_exception(__TIME__, __FILE__, __LINE__, __FUNCTION__);
  }

  try {
    v.resize(v.max_size() + 1);
  } catch (...) {
    handle_exception(__TIME__, __FILE__, __LINE__, __FUNCTION__);
  }

  try {
    std::vector<int> v2(v.max_size());
    v2.push_back(1);
  } catch (...) {
    handle_exception(__TIME__, __FILE__, __LINE__, __FUNCTION__);
  }
  cout << "\n";
}
