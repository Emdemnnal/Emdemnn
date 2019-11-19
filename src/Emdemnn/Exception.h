#ifndef EMDEMNN_EXCEPTION_H
#define EMDEMNN_EXCEPTION_H

#include <exception>
#include <string>

namespace Emdemnn
{

struct Exception : public std::exception
{
  Exception(const std::string& message);
  virtual ~Exception() throw();
  virtual const char* what() const throw();

private:
  std::string message;

};

}

#endif
