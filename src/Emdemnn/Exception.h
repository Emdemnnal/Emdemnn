#ifndef EMDEMNN_EXCEPTION_H
#define EMDEMNN_EXCEPTION_H

#include <exception>
#include <string>

namespace Emdemnn
{

/**
 * Shows the basic structure to how exceptions are handled inside the game engine.
 */
struct Exception : public std::exception
{
  /// The constructor for exception handling.
  /**
   * This function sets the argument message to the private variable.
   * It does this by referring to itself using the this pointer.
   */
  Exception(const std::string& message);
  
  /// The destructor for exception handling.
  /**
   * This function calls the throw function on the exception.
   */
  virtual ~Exception() throw();
  
  /// The what() function for exception handling.
  /**
   * This function calls the throw function on the exception.
   * It also returns the passed in message from the constructor as a c-string.
   */
  virtual const char* what() const throw();

private:
  std::string message; ///< The string that contains the error message.
};

}

#endif
