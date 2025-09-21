#include <factorisation.h>
#include <cmath>
#include <ostream>
#include <vector>
#include<prime.h>


Factorisation::value_type Factorisation::Factor::value() const {
    return static_cast<Factorisation::value_type>(std::pow(base, exponent.value_or(0)));
}

bool Factorisation::Factor::operator==(const Factor &other) const noexcept {
    return base==other.base && exponent == other.exponent;
}

std::ostream & operator<<(std::ostream &os, const Factorisation::Factor &factor) noexcept {
    return os << factor.base << "^" << (factor.exponent.has_value()? std::to_string(factor.exponent.value()):"x");
}

Factorisation::Factorisation(value_type nbr) {
    Prime primes;
    value_type exponent = 0;
    auto prime = primes.begin();
    while (nbr > 1) {
        if (nbr % *prime == 0) {
            nbr /= *prime;
            ++exponent;
        } else {
            if (exponent > 0) {
                factors_.push_back(Factor(*prime, exponent));
                exponent = 0;
            }
            ++prime;
        }
    }
    if (exponent > 0) {
        factors_.push_back(Factor(*prime, exponent));
    }
}

Factorisation::value_type Factorisation::value() const noexcept {
    value_type ans = 1;
    for (const auto &factor : factors_)
        ans *= factor.value();
    return ans;
}

std::set<Factorisation::value_type> Factorisation::getDivisors() {
    std::set<Factorisation::value_type> ans {1};
    for (const auto &factor : factors_) {
        auto ans_tmp = ans;
        for ( value_type e=1;e<=factor.exponent;++e) {
            auto p = static_cast<Factorisation::value_type>(std::pow(factor.base, e));
            for (auto div : ans_tmp)
                ans.insert(div * p);
        }
    }
    return ans;
}

Factorisation Factorisation::gcd(const Factorisation &other) const noexcept {
    auto it = factors_.begin();
    auto it_other = other.factors_.begin();
    Factorisation ans;

    while (it != factors_.end() && it_other != other.factors_.end()) {
        if (it->base == it_other->base) {
            ans+= Factor(it->base, std::min(it->exponent.value_or(0), it_other->exponent.value_or(0)));
            ++it;
            ++it_other;
        } else if (it->base < it_other->base) {
            ++it;
        } else {
            ++it_other;
        }
    }
    return ans;
}

Factorisation Factorisation::lcm(const Factorisation &other) const noexcept {
    auto it = factors_.begin();
    auto it_other = other.factors_.begin();
    Factorisation ans;

    while (it != factors_.end() && it_other != other.factors_.end()) {
        if (it->base < it_other->base) {
            ans+= *it;
            ++it;
        } else if (it_other->base < it->base) {
            ans+= *it_other;
            ++it_other;
        } else {
            ans+= Factor(it->base, std::max(it->exponent.value_or(0), it_other->exponent.value_or(0)));
            ++it;
            ++it_other;
        }
    }
    for (;it != factors_.end(); ++it)
        ans+= *it;
    for (;it_other != other.factors_.end(); ++it_other)
        ans+= *it_other;
    return ans;
}

bool Factorisation::operator==(const Factorisation &other) const noexcept {
    return factors_ == other.factors_;
}

Factorisation & Factorisation::operator+=(const Factorisation &other) noexcept {
    for (const auto &factor : other.factors_)
        operator+=(factor);
    return *this;
}

Factorisation & Factorisation::operator-=(const Factorisation &other) {
    for (const auto &factor : other.factors_)
        operator-=(factor);
    return *this;
}

Factorisation & Factorisation::operator+=(const Factor &factor) noexcept {
    if (!factor.exponent.has_value())
        return *this;
    auto it = factors_.begin();
    while (it != factors_.end() && it->base < factor.base)
        ++it;
    if (it == factors_.end() || it->base > factor.base)
        factors_.insert(it, factor);
    else
        it->exponent = it->exponent.value() + factor.exponent.value();
    return *this;
}

Factorisation & Factorisation::operator-=(const Factor &factor) {
    if (!factor.exponent.has_value())
        return *this;
    auto it = factors_.begin();
    while (it != factors_.end() && it->base < factor.base)
        ++it;
    if (it == factors_.end() || it->base > factor.base)
        throw std::range_error("Factorisation don't contain this factor");
    if (it->exponent.value() < factor.exponent.value())
        throw std::range_error("The factor exponent is bigger than the Factorisation");
    if (it->exponent.value() == factor.exponent.value())
        factors_.erase(it);
    else
        it->exponent = it->exponent.value() - factor.exponent.value();
    return *this;
}

size_t Factorisation::size() const noexcept {
    return factors_.size();
}

const Factorisation::Factor & Factorisation::at(size_t index) const {
    if (index >= factors_.size())
        throw std::out_of_range("Index out of range");
    auto it = factors_.begin();
    std::advance(it, index);
    return *it;
}

std::ostream & operator<<(std::ostream &os, const Factorisation &factorisation) noexcept {
    os<<"(1";
    for (const auto &factor : factorisation.factors_)
        os<<"*"<<factor;
    return os<<")";
}