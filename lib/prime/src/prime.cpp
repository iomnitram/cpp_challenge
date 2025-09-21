#include <prime.h>

#include <algorithm>
#include <math.h>


Prime::Prime() : primes_{2,3,5},maxTested_{5}{
}

Prime & Prime::instance() {
    static Prime prime;
    return prime;
}

bool Prime::isPrime(Prime::value_type_signed number) {
    if (number < 2)
        return false;
    return isPrime(static_cast<Prime::value_type>(std::abs(static_cast<long>(number))));
}


bool Prime::isPrime(Prime::value_type number) {
    if (maxTested_ > number)
        return std::find(primes_.begin(), primes_.end(), number) != primes_.end();

    value_type sqrtNumber = static_cast<value_type>(std::sqrt(number))+1;
    if (primes_.back() < sqrtNumber){
        preprocess(sqrtNumber);
    }
    return checkPrime(number);
}

bool Prime::checkPrime(Prime::value_type number) {
    value_type sqrtNumber = static_cast<value_type>(std::sqrt(number));
    for (const auto& prime : Prime::primes_) {
        if (number % prime == 0)
            return false;
        if (prime > sqrtNumber)
            return true;
    }
    return true;
}

void Prime::preprocess(Prime::value_type max) {
    if (max%2 == 0)
        --max;
    while (max > maxTested_) {
        maxTested_ += 2;
        if (checkPrime(maxTested_))
            primes_.push_back(maxTested_);
    }
}

void Prime::findNext() {
    while (true) {
        maxTested_ += 2;
        if (checkPrime(maxTested_)) {
            primes_.push_back(maxTested_);
            return;
        }
    }
}

Prime::iterator Prime::begin() {
    return iterator( this, primes_.begin());
}

Prime::iterator Prime::last() {
    return iterator(this,std::prev(primes_.end()));
}

Prime::iterator::iterator(Prime* parent, container_type::iterator it) : parent_(parent), it_(it)
{
}

const Prime::iterator::value_type & Prime::iterator::operator*() const {
    return *it_;
}

const Prime::iterator::value_type * Prime::iterator::operator->() const {
    return &*it_;
}

Prime::iterator & Prime::iterator::operator++() {
    auto current = it_++;
    if (it_ == parent_->primes_.end()) {
        parent_->findNext();
        it_ = ++current;
    }
    return *this;
}

Prime::iterator Prime::iterator::operator++(int) {
    iterator tmp = *this;
    operator++();
    return tmp;
}

bool Prime::iterator::operator==(const iterator &other) const {
    return it_ == other.it_;
}

bool Prime::iterator::operator!=(const iterator &other) const {
    return it_ != other.it_;
}

