// METHOD-1: declare with struct or class to overwrite operator() function
class Foo
{

};

class Compare
{
public:
    bool operator() (Foo, Foo)
    {
        return true;
    }
};

int main()
{
    std::priority_queue<Foo, std::vector<Foo>, Compare> pq;
    return 0;
}

// METHOD-2: declare with function:
class Foo
{

};

bool Compare(Foo, Foo)
{
    return true;
}

int main()
{
    std::priority_queue<Foo, std::vector<Foo>, std::function<bool(Foo, Foo)>> pq(Compare);
    return 0;
}

// METHOD-3: lambda expression
auto compare = [](Node a, Node b) { return a.foo < b.foo; }
std::priority_queue<Node, std::vector<Node>, decltype(compare)> pq(compare);
