#include <vector>

using namespace std;

template <typename Key, typename Value>
class MapArray {
    vector<pair<Key, Value>> vec;

public:
    class iterator {
        pair<Key, Value>* current;
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = pair<Key, Value>;
        using pointer = value_type*;
        using reference = value_type&;
        using difference_type = std::ptrdiff_t; 

        explicit iterator(pointer const ptr = nullptr) : current(ptr) {}
        iterator& operator++() {
            ++current;
            return *this;
        }
        iterator& operator--() {
            --current;
            return *this;
        }
        iterator operator++(int) {
            iterator tmp(current);
            ++current;
            return tmp;
        }
        iterator operator--(int) {
            iterator tmp(current);
            --current;
            return tmp;
        }
        iterator& operator+=(difference_type const d)
        {
            current += d;
            return *this;

        }
        iterator& operator-=(difference_type const d)
        {
            current -= d;
            return *this;
        }
        friend iterator operator+(iterator i, difference_type const d)
        {
            return iterator(i.current + d);
        }
        friend iterator operator+(difference_type const d, iterator i)
        {
            return iterator(d + i.current);
        }
        friend iterator operator-(iterator i, difference_type const d)
        {
            return iterator(i.current - d);
        }
        friend difference_type operator-(iterator const i, iterator const j)
        {
            return (i.current - j.current);
        }
        auto operator <=> (iterator const& other) const = default;
        reference operator*() const
        {
            return *current;
        }
        pointer operator->() const
        {
            return current;
        }
        reference operator[](difference_type const d) const
        {
            return *(current + d);
        }
    };

    static_assert(std::random_access_iterator<iterator>);
    using value_type = pair<Key, Value>;
    iterator begin()
    {
        return iterator(vec.data());
    }
    iterator end()
    {
        return iterator(vec.data() + vec.size());
    }
    Value& operator[](Key const& key){
    auto it = lower_bound(vec.begin(), vec.end(), key,
        [](pair <Key, Value>const& lhs, Key const& key) {
            return lhs.first < key;
        });
    if (it != vec.end() && it->first == key) {
        return it->second;
    } else {
        it = vec.insert(it, pair{key, Value{}});
        return it -> second;
    }
}



};