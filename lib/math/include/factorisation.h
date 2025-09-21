#ifndef CPP_CHALLENGE_FACTORISATION_H
#define CPP_CHALLENGE_FACTORISATION_H

#include <list>
#include <optional>
#include <set>
#include <cstdint>
#include <ostream>
#include "abs.h"

class Factorisation {
public:
    using value_type = std::uint64_t;

    struct Factor {
        value_type base{1};
        std::optional<value_type> exponent{std::nullopt};

        Factor(value_type b=1, std::optional<value_type> e=std::nullopt) : base(b), exponent(e){};

        [[nodiscard]] value_type value() const;
        [[nodiscard]] inline value_type operator()() const noexcept { return value(); }

        bool operator==(const Factor& other) const noexcept;

        friend std::ostream& operator<<(std::ostream& os, const Factor& factor) noexcept;
    };

    using const_iterator = std::list<Factor>::const_iterator;
    using const_reverse_iterator = std::list<Factor>::const_reverse_iterator;

    Factorisation(value_type nbr=1);

    inline value_type operator()() const noexcept { return value(); };
    value_type value() const noexcept;
    std::set<value_type> getDivisors();

    [[ nodiscard ]] Factorisation gcd(const Factorisation& other) const noexcept;
    [[ nodiscard ]] Factorisation lcm(const Factorisation& other) const noexcept;

    bool operator==(const Factorisation& other) const noexcept;

    Factorisation& operator+=(const Factorisation& other) noexcept;
    Factorisation& operator-=(const Factorisation& other);
    inline Factorisation operator+(const Factorisation& other) const noexcept { Factorisation ans{*this}; ans+=other;  return ans; }
    inline Factorisation operator-(const Factorisation& other) const { Factorisation ans{*this}; ans-=other;  return ans; }

    Factorisation& operator+=(const Factor& factor) noexcept;
    Factorisation& operator-=(const Factor& factor);
    inline Factorisation operator+(const Factor& factor) const noexcept { Factorisation ans{*this}; ans+=factor;  return ans; }
    inline Factorisation operator-(const Factor& factor) const { Factorisation ans{*this}; ans-=factor;  return ans; }


    size_t size() const noexcept;
    const Factor& at(size_t index) const;
    const Factor& operator[](size_t index) const {return at(index);}

    inline const_iterator begin() const { return factors_.begin(); }
    inline const_iterator end() const { return factors_.end(); }
    inline const_iterator cbegin() const { return factors_.cbegin(); }
    inline const_iterator cend() const { return factors_.cend(); }

    inline const_reverse_iterator rbegin() const { return factors_.rbegin(); }
    inline const_reverse_iterator rend() const { return factors_.rend(); }
    inline const_reverse_iterator crbegin() const { return factors_.crbegin(); }
    inline const_reverse_iterator crend() const { return factors_.crend(); }

    friend std::ostream& operator<<(std::ostream& os, const Factorisation& factorisation) noexcept;

private:
    std::list<Factor> factors_;
};

#endif //CPP_CHALLENGE_FACTORISATION_H