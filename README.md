# cpp-pimpl-helper
A simple helper type alias for std::unique_ptr and custom deleter for using pimpl idiom with std::unique_ptr easily on MSVC


## Usage
*impl.hpp*  
```
#include <pimpl.hpp>

class Impl
{
public:
  ...

private:
  class Pimpl_;
  stdx::pimpl::unique_ptr<Pimpl_> pimpl_;
};
```
*impl.cpp*  

```
#include "impl.hpp"
...

class Pimpl_
{
  ...
};

Impl::Impl()
{
  pimpl_ = stdx::pimpl::make_unique<Pimpl_>(...);
  ...
}
...
```
