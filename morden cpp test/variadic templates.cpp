#include <iostream>
#include "string"

template <typename T, typename U>
bool is_decay_same() {
    using std::is_same, std::decay;
    return is_same<typename decay<T>::type, typename decay<U>::type>::value;
}

template <typename T, typename... Ts>
class tuple : public tuple<Ts...> {
private: 
    T val;

public:
    tuple() : tuple<Ts...>::tuple() {
        val = T();
    }

    tuple(const T& val, const Ts&... args) : tuple<Ts...> (args...) {
        this->val = val;
    }

    tuple(const T&& val, const Ts&&... args) : tuple<Ts...> (args...) {
        this->val = val;
    }

    ~tuple() {
        ;
    }

    template <int idx>
    const auto& get() {
        static_assert(idx <= sizeof...(Ts) && idx >= 0, "get<idx> overflow");
        if constexpr(idx == 0) { return val; }
        else {
            return tuple<Ts...>::template get<idx - 1>();
        }
    }

    template <int idx>
    auto& modify_sub() {
        static_assert(idx <= sizeof...(Ts) && idx >= 0, "modify_sub<idx> overflow");
        
        if constexpr(idx == 0) { return val; }
        else {
            return tuple<Ts...>::template modify_sub<idx - 1>();
        }
    }

    template <int idx, typename modify_t>
    void modify(const modify_t& val) {
        static_assert(idx != 0 || (is_decay_same<modify_t, T>), "modify type error");
        static_assert(idx > 0 && idx < sizeof...(Ts), "modify index overflow");

        modify_sub<idx>() = val;
    }
};
 
template <typename T>
class tuple<T> {
private: 
    T val;
public:
    tuple() {
        val = T();
    }

    tuple(const T& val) {
        this->val = val;
    }

    tuple(const T&& val) {
        this->val = val;
    }

    ~tuple() {
        ;
    }

    template <int idx>
    T get() {
        if constexpr (idx != 0) exit(0);
        return val;
    }

    template <int idx>
    T& modify_sub() {
        if constexpr (idx != 0) exit(0);
        return val;
    }

    template <int idx>
    void modify(T val) {
        modify_sub<idx>() = val;
    }
};

int main() {
    tuple<int, double, std::string> T(2, 3.14, "HEU");
    T.modify<1>(8.9);
    std::cout << T.get<1>() << std::endl;

    system("pause");
    return 0;
}