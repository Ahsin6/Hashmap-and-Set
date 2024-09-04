template <typename T>
class SetList
{
    struct ListNode 
    {
        T data;
        ListNode* next;
    };
    ListNode* head;
public:
    class iterator {
        ListNode* current;
        public:
            using iterator_category = std::forward_iterator_tag;
            using value_type = T;
            using pointer = value_type*;
            using reference = value_type&;
            using difference_type = std::ptrdiff_t;

            explicit iterator( ListNode* const ptr = nullptr)
            : current(ptr) {}
            iterator& operator++()
            {
                current = current->next;
                return *this;
            }
            iterator operator++(int)
            {
                iterator tmp(current);
                current = current -> next;
                return tmp;
            }
            reference operator*() const
            {
                return current -> data;
            }
            pointer operator ->() const
            {
                return &(current -> data);
            }
            bool operator==( iterator const& other) const = default;
    };
    static_assert(std::forward_iterator<iterator>);
public:
    using value_type = T;

    SetList()
    : head(nullptr) {}
    SetList(SetList const& other ) = delete;
    SetList& operator=(SetList const& other) = delete;
    iterator begin()
    {
        return iterator(head);
    }
    iterator end()
    {
        return iterator(nullptr);
    }
    iterator find( T value)
    {
        for (auto it = begin(); it != end(); it++)
        {
            if (*it == value)
            {
                return it;
            }
        }
        return end();
    }
    iterator insert(iterator const, T value)
    {
        auto exist = find(value);
        if(exist == end())
        {
            head = new ListNode(value, head);
            return iterator(head);
        }
        return exist;
    }
    ~SetList()
    {
         while (head != nullptr)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    
};
