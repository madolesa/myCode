#include <cstddef>
#include <memory>
#include <tuple>
#include <utility>

template <class T, class Deleter = std::default_delete<T>>
class UniquePtr {
private:
    std::tuple<T*, Deleter> t;

public:
    UniquePtr() noexcept {
        std::get<0>(t) = nullptr;
    }
    UniquePtr(T* other) noexcept {
        std::get<0>(t) = std::move(other);
    }
    UniquePtr(T* other, Deleter deleter) {
        std::get<0>(t) = other;
        other = nullptr;
        std::get<1>(t) = deleter;
    }
    UniquePtr(UniquePtr&& other) noexcept {
        std::get<0>(t) = nullptr;
        std::swap(t, other.t);
    }
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) const = delete;

    UniquePtr& operator=(std::nullptr_t) noexcept {
        std::get<0>(t) = nullptr;
        return *this;
    }

    UniquePtr& operator=(UniquePtr&& other) noexcept {
        std::swap(t, other.t);
        return *this;
    }

    T& operator*() const {
        return *std::get<0>(t);
    }

    T* operator->() const {
        return std::get<0>(t);
    }

    T* release() noexcept {
        T* _ptr = std::get<0>(t);
        std::get<0>(t) = nullptr;
        return _ptr;
    }

    Deleter& get_deleter() noexcept {
        return std::get<1>(t);
    }

    const Deleter& get_deleter() const noexcept {
        return std::get<1>(t);
    }

    void reset(T* other) noexcept {
        T* old_ptr = std::get<0>(t);
        std::get<0>(t) = other;
        if (old_ptr) {
            get_deleter()(old_ptr);
        }
    }

    void swap(UniquePtr& other) noexcept {
        std::swap(t, other.t);
    }

    T* get() const {
        return std::get<0>(t);
    }

    explicit operator bool() const {
        return std::get<0>(t);
    }

    ~UniquePtr() {
        get_deleter()(std::get<0>(t));
    }
};

int main() {

}