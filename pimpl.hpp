#ifndef PIMPL_HPP
#define PIMPL_HPP

#include <memory>
#include <type_traits>

namespace stdx {
    namespace pimpl {
        namespace _details {
            template<typename T>
            struct deleter
            {
                void operator()(T *ptr_) { delete ptr_; }
            };
        } // namespace _details
        
        template<typename T>
        using unique_ptr = std::unique_ptr<T, _details::deleter<T>>;
        
        template <class T>
        unique_ptr<T> make_unique() {
            return unique_ptr<T>(new T());
        }
        
        template <class T, class... Ts>
        unique_ptr<T> make_unique(Ts&&... args) {
            return unique_ptr<T>(new T(std::forward<Ts>(args)...));
        }
    } // namespace pimpl
} // namespace stdx

#endif // PIMPL_HPP
