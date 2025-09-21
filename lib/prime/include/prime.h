#ifndef CPP_CHALLENGE_PRIME_H
#define CPP_CHALLENGE_PRIME_H

#include <list>
#include <memory>
#include <sys/types.h>


class Prime {
public:
    using value_type = std::uint64_t;
    using value_type_signed = std::int64_t;

    class iterator {
        friend Prime;
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = Prime::value_type;
    private:
        using container_type = std::list<value_type>;


    public:
        iterator() = delete;
    private:
        iterator(Prime* parent, container_type::iterator it);

    public:
        const value_type &operator*() const;
        const value_type *operator->() const;

        iterator &operator++();
        iterator operator++(int);

        bool operator==(const iterator &other) const;
        bool operator!=(const iterator &other) const;

    private:
        Prime* parent_;
        container_type::iterator it_;
    };

    Prime();
    static Prime& instance();

    bool isPrime(value_type_signed number);
    bool isPrime(value_type number);
    void preprocess(value_type max);

    iterator begin();
    iterator last();

private:
    bool checkPrime(value_type number);
    void findNext();
    std::list<value_type> primes_;
    value_type maxTested_;
};


#endif //CPP_CHALLENGE_PRIME_H