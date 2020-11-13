#include <cmath>
#include <iostream>
#include <memory>
#include <string>

template <typename T>
class IntegrationMethod {
public:
    IntegrationMethod() {}

    virtual double Integrate(T func, double begin, double end, int num) const {
        return 0;
    }

    virtual ~IntegrationMethod() {}
};

template <typename T>
class RectangleRule: public IntegrationMethod<T> {
public:
    RectangleRule() {}
    double Integrate(T func, double begin, double end, int num) const override {
        double sum = 0;
        for (size_t i = 0; i < num; ++i) {
            sum += func((begin + (end - begin) * i / num
                    + begin + (end - begin) * (i + 1) / num) / 2)
                    * ((end - begin) / num);
        }
        return sum;
    }

    ~RectangleRule() {}
};

template <typename T>
class TrapezoidalRule: public IntegrationMethod<T> {
public:
    TrapezoidalRule() {}
    double Integrate(T func, double begin, double end, int num) const override {
        double sum = 0;
        for (size_t i = 0; i < num; ++i) {
            sum += (func(begin + (end - begin) * i / num)
                    + func(begin + (end - begin) * (i + 1) / num)) / 2
                    * ((end - begin) / num);
        }
        return sum;
    }

    ~TrapezoidalRule() {}
};

int main() {
    using F = decltype(cos);

    std::string input;
    std::cin >> input;
    std::unique_ptr<IntegrationMethod<F>> method;
    if (input == "rectangle")
        method.reset(new RectangleRule<F>);
    else
        method.reset(new TrapezoidalRule<F>);

    double x, y;
    std::cin >> x >> y;

    int n;
    std::cin >> n;

    std::cout << method->Integrate(cos, x, y, n) << "\n";
    std::cout << method->Integrate(sin, x, y, n) << "\n";
}
