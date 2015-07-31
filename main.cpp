#if 1
#include <iostream>
#include <memory>

struct One
{
    int*  x;
    One(int a) : x(new int(a)) {
        //std::cout << "One\n";
    }
    
    One(One const& other) : x(new int(*other.x)) { std::cout << "copy\n"; }
    
    One(One && other) : x(other.x) {
        other.x = nullptr;
        std::cout << "move\n";
    }
    
    One& operator=(One && other) {
        delete x;
        x = other.x;
        other.x = nullptr;
        std::cout << "move =\n";
        return *this;
    }
    
    One& operator=(One const& other) {
        if (this == &other) { return *this; }
        One tmp(other);
        
        std::swap(x, tmp.x);
        std::cout << "copy =\n";
        return *this;
    }
    
    ~One() {
        delete x;
        //std::cout << "~One\n";
    }
};

One getOne() { return One(5); }

void process(const One& one) {
    std::cout << "lvalue\n";
}

void process(One&& one) {
    std::cout << "rvalue\n";
    
}

//std::unique_ptr<One> getOne() { return std::unique_ptr<One>(new One(2)); }

int main()
{
    One o1(1);
    
    process(getOne());
    process(o1);
    
    One o2(2);
    
    One o3(o2);
    
    One o4(std::move(o1));
    One o5(getOne());
    
    o1 = getOne();
    
    o2 = o3;

    
//    std::unique_ptr<One> ip(new One{5});
//    
//    std::cout << ip->x << "\n";
//    
//    std::unique_ptr<One> ip2(std::move(ip));
//    
//  //  ip->x = 5;
}

#endif

#if 0
#include <iostream>
#include <memory>

struct One
{
    int x;
    One(int a) : x(a) { std::cout << "One\n"; }
    ~One() { std::cout << "~One\n"; }
};

std::auto_ptr<One> getOne() { return std::auto_ptr<One>(new One(2)); }

int main()
{
//    std::auto_ptr<One> ip(new One{5});
//    
//    std::cout << ip->x << "\n";
    
    std::auto_ptr<One> ip2(getOne());
    
//    ip->x = 5;
    
    
}

#endif





#if 0
#include <iostream>
#include <set>

template<typename Iter>
void print(Iter begin, Iter end)
{
    for (; begin != end; ++begin)
    {
        std::cout << *begin << " ";
    }
    std::cout << "\n";
}

template<typename T>
struct set_util {
template<typename CMP>
static auto with(CMP c) -> std::set<T, CMP> {
    return std::set<T, CMP>(c);
}
};

template<typename T, typename CMP>
auto make_set(CMP c) -> std::set<T, CMP> {
    return set_util<T>::with(c);
}

struct foo
{
    int x; double y; std::string name;
    foo(int a, double b, std::string n) : x(a), y(b), name(n) {}
};
int main()
{
    auto sp = std::make_shared<foo>(5, 4.5, "bob");
    //auto cmp = [](int x, int y) { return x > y; };
    //std::set<int, decltype(cmp)> s(cmp);
    auto s = make_set<int>([](int x, int y) { return x > y; });
    
    s.insert(2);
    s.insert(7);
    s.insert(9);
    s.insert(1);
    s.insert(5);
    
    print(s.begin(), s.end());
}


#endif



#if 0
#include <iostream>
#include <functional>
struct MS
{
    int x,y;
};

struct Widget
{
    int val;

    std::function<int()> foo() {
        //int lVal(val);
        //return [lVal]() { return lVal; };
        
        //return [lVal=val]() { return lVal; };
        
        return [val=val]() { return val; };
    }
};

struct CT {
    int val;
    CT(int v) : val(v) {}
    int operator()() const { return val; }
};


int main()
{
    MS * ms = new MS;
    Widget * w = new Widget;
    
    auto f = w->foo();
    
    delete w;
    
    std::cout << f() << "\n";
    
    auto fn = [] ()-> bool { return true; };
    
    
    
   // auto fn = [ms]() { return ms->x; }
    
}






#endif


#if 0
#include <iostream>
#include <memory>

struct Highway;

struct City
{
    std::shared_ptr<Highway> h;
    std::string name = "City";
    City() { std::cout << "City\n"; }
    ~City() { std::cout << "~City\n"; }
};

struct Highway
{
    std::weak_ptr<City> c;
    Highway() { std::cout << "Highway\n"; }
    void print() const { std::cout << c.lock()->name << "\n"; }
    ~Highway() { std::cout << "~Highway\n"; }

};

int main()
{
    std::shared_ptr<City> c(new City);
    std::shared_ptr<Highway> h(new Highway);
    
    c->h = h;
    h->c = c;
    h->print();
    
    
}




#endif



#if 0
#include <iostream>
#include <string>
#include <vector>

using namespace std::string_literals;

void func(int * x)
{
    std::cout << typeid(x).name() << "\n";
}
template<typename F, typename T>
void func(F f, T x) {
    f(x);
}

enum class Day { monday };

int main()
{

    //func((int*)0);
    func((std::nullptr_t)0);
    func(nullptr);
//    auto p = nullptr;
//    
//    std::cout << typeid(p).name() << "\n";
//    
//    //std::vector<int> v {23,423,5424,562,3512,33,123,};
//    int v[] {23,423,5424,562,3512,33,123,};
//
//    for (auto& i : v) { std::cout << i << " "; i *= 2;} std::cout << "\n";
//    
//    for (auto it = std::begin(v); it != std::end(v); ++it) {
//        std::cout << *it << " ";
//        *it *= 2;
//    }
//    std::cout << "\n";
//    for (int i : v) { std::cout << i << " "; } std::cout << "\n";
//
//    auto a = "hello"s;
//    
//    std::cout << typeid(a).name() << "\n";
    
    
    
    
}




#endif



#if 0
#include <iostream>

struct Base {
    int a;
    Base(int _a) : a(_a) {}
};

struct Sub : Base {
    Sub(int _a, int _b) : Base(_a), b(_b) {}
    int b;
};

void process(int x) {
    if (x % 2 == 0) {
        throw Sub(1,2);
    } else {
        throw Base(5);
    }
  
}


int main()
{
    try {
        process(1);
    } catch (Sub& s) {
        std::cout << "Sub " << s.a << " " << s.b << "\n";
    } catch (Base& b) {
        std::cout << "Base " << b.a << "\n";
    }
}

#endif






#if 0
#include <iostream>
#include "Timespan.h"

template<typename T>
struct Set
{
    Set() {}
    
    void add(T const&);
};

template<typename T>
void Set<T>::add(const T& val)
{
    //...
}

int main()
{
    Timespan t;
    
    try {
        try {
            throw 5;
        } catch (...) {
            std::cout << "caught it\n";
            throw;
        }
    } catch (int x) {
        std::cout << "caught " << x << "\n";
    }
    
}

#endif








#if 0
#include <iostream>
#include <memory>

struct One {
    One() { std::cout << "One()\n"; }
    ~One() { std::cout << "~One()\n"; }
};
int main()
{
    std::shared_ptr<One> one(new One);
    std::shared_ptr<One> two(one);
    
    
    
    
    
}





#endif




#if 0
#include <iostream>
#include <unordered_set>

struct One {
    int x;
    One(int a) : x(a) {}
};

std::ostream& operator<<(std::ostream& os, One one) {
    os << one.x;
    return os;
}

bool operator<(One lhs, One rhs) { return lhs.x > rhs.x; }

//bool operator==(One lhs, One rhs) { return lhs.x == rhs.x; }

template<typename Iter>
void print(Iter begin, Iter end)
{
    for (; begin != end; ++begin)
    {
        std::cout << *begin << " ";
    }
    std::cout << "\n";
}

//namespace std {
//    template<>
//    struct hash<One>
//    {
//        size_t operator()(const One& val) const {
//            return std::hash<int>()(val.x);
//        }
//    };
//}
struct OneHash
{
    size_t operator()(const One& val) const {
        return std::hash<int>()(val.x);
    }
};

struct OneEqual
{
    size_t operator()(const One& lhs, const One& rhs) const {
        return lhs.x == rhs.x;
    }
};


int main()
{
    std::unordered_set<One, OneHash, OneEqual> s;
    
    s.insert(43);
    s.insert(3);
    s.insert(13);
    s.insert(32);
    s.insert(3);
    s.insert(32);
    
    print(s.begin(), s.end());
}

#endif





#if 0
#include <iostream>
#include <vector>
template<typename Iter>
void print(Iter begin, Iter end)
{
    for (; begin != end; ++begin)
    {
        std::cout << *begin << " ";
    }
    std::cout << "\n";
}


int main()
{
    std::vector<int> vec;
    //vec.reserve(500);

    for (int i = 0; i < 17; ++i) {
        std::cout << "Size : " << vec.size() << " Capacity : " << vec.capacity()
        << "  Pointer to data : " << vec.data() << "\n";
        vec.push_back(i);
    }
    
    std::cout << "Size : " << vec.size() << " Capacity : " << vec.capacity() << "\n";
    
    std::vector<int>(vec.begin(), vec.end()).swap(vec);
    std::cout << "Size : " << vec.size() << " Capacity : " << vec.capacity() << "\n";

    //print(vec.begin(), vec.end());
}



#endif








#if 0
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
struct MultOf
{
    int mult;
    MultOf(int m) : mult(m) {}
    
    bool operator()(const int& val) {  return !(val % mult); }
};


template<typename Iter>
void print(Iter begin, Iter end)
{
    for (; begin != end; ++begin)
    {
        std::cout << *begin << " ";
    }
    std::cout << "\n";
}

int main()
{
    int a[] = { 23,2,5235,2,2,23,12,3,42,23,3,2};
    
    std::vector<int> vec(a, a + sizeof(a)/sizeof(*a));
    
    print(vec.begin(), vec.end());
    
    //std::vector<int>::iterator newEnd = std::remove(vec.begin(), vec.end(), 2);
    
    vec.erase(std::remove_if(vec.begin(), vec.end(), MultOf(3)), vec.end());
    
    //vec.remove(2);
    
    print(vec.begin(), vec.end());
    
    //std::cout << "Size : " << vec.size() << " Capacity : " << vec.capacity() << "\n";
    std::cout << "Size : " << vec.size() << "\n";
    
}


#endif







#if 0
#include <iostream>
#include <vector>

template<typename Iter, typename Pred>
Iter find_if(Iter begin, Iter end, Pred pred) {
    while (begin != end && !(pred(*begin))) {
        ++begin;
    }
           
    return begin;
}

bool multFive(const int& val) { return !(val % 5); }
bool multFour(const int& val) { return !(val % 4); }

struct MultOf
{
    int mult;
    MultOf(int m) : mult(m) {}
  
    bool operator()(const int& val) { return !(val % mult); }
};

int main()
{
    int a[] = { 2,3,4,56,64,354,623,43,12,65,67 };
    int size = sizeof(a)/sizeof(*a);

    MultOf multThree(3);
    MultOf multTwo(2);
    MultOf multSeventeen(17);
    
    std::cout << std::boolalpha << multTwo(18) << "\n";
    
    int* it = find_if(a, a + size, MultOf(13));
    
    std::cout << *it << "\n";
    
    
}




#endif



#if 0
#include <iostream>
#include <vector>

template<typename Iter, typename T>
Iter find(Iter begin, Iter end, T value) {
    while (begin != end) {
        if (*begin == value) {
            break;
        }
        ++begin;
    }
    return begin;
}

int main()
{
    double a[] = { 2,3,4,56,64,354,623,43,12,65,67 };
    std::vector<int> b = { 2,3,4,56,64,354,623,43,12,65,67 };
    
    int size = sizeof(a)/sizeof(*a);
    double * end = a + size;
    double * it = find(a + 8, end, 43.0);
    
    //std::vector<int>::iterator it2 = std::find(b.begin(), b.end(), 43);
    typedef std::vector<int>::iterator Iter;
    Iter it2 = std::find(b.begin(), b.end(), 43);
    
    if (it != end ) {
        std::cout << "found it at address " << it << "\n";
    } else {
        std::cout << "not found\n";
    }
    
//    for (int i = 0; i < size; ++i) {
//        if (a[i] == 43) {
//            std::cout << "found it at index " << i << "\n";
//            break;
//        }
//    }
//    
//    int * begin = a;
//    int * end = a + size;
//    
    
}



#endif









#if 0
#include <iostream>

struct Shape
{
    // when overriding make sure and chain to this implementation first
    virtual void draw() final {
        std::cout << "Necessary Setup to draw\n";
        doDraw();
    }
    
private:
    virtual void doDraw() = 0;
};

struct Line : Shape {
    
private:
    virtual void doDraw() {
        std::cout << "here is my line\n";
    }
};
struct Circle : Shape {
    virtual void doDraw() {
        std::cout << "I do not need your setup\n";
    }
};

void process(Shape* s) {
    s->draw();
}

int main()
{
    Shape* s = new Circle;
    Line* s1 = new Line;
    s1->draw();
    process(s);
    process(s1);
    
    delete s;
    delete s1;
}

#endif







#if 0
#include <iostream>


struct Set
{
    Set(int cap = 4) : capacity(cap), size(0), elements(new int[capacity]) {}
    ~Set() { delete [] elements; }
    
    Set(Set const& other) : capacity(other.capacity), size(other.size),
                            elements(new int[capacity]) {
        std::copy(other.elements, other.elements + size, elements);
    }
    
    Set& operator=(Set tmp) {
        using std::swap;
        
        swap(capacity, tmp.capacity);
        swap(size, tmp.size);
        swap(elements, tmp.elements);

        return *this;
    }
    
private:
    int capacity;
    int size;
    int* elements;
};

int main()
{
    
}



#endif









#if 0
#include <iostream>

template<typename T>
class Counter
{
public:
    Counter() { ++count; }
    Counter(Counter const &) { ++count; }
    ~Counter() { --count; }
    static size_t howMany() { return count; }
    
private:
    static size_t count;
};

template<typename T>
size_t Counter<T>::count = 0;

class Foo : private Counter<Foo>
{
public:
};

class Bar : private Counter<Bar>
{
public:
    using Counter<Bar>::howMany;
};

void process(Foo x) {
    std::cout << "process - " << Counter<Foo>::howMany() << "\n";
}
int main()
{
    Foo f, y;
    
    process(y);
    
    Bar b;
    
    std::cout << "main - " << Counter<Foo>::howMany() << "\n";
}

#endif












#if 0
#include <iostream>

struct Order
{
    int y;
    int x;
    
    Order(int z) :  x(z), y(x) {}
};
struct One {
    One() { std::cout << "One()\n"; }
    One(One const& ) { std::cout << "One(copy)\n"; }
};

struct Base {
    One one;
    Base() { std::cout << "Base()\n"; }
    Base(Base const& other) : one(other.one) { std::cout << "Base(copy)\n"; }

};

struct Derived : public Base {
    Derived() { std::cout << "Derived()\n"; }
    Derived(Derived const& other) : Base(other) { std::cout << "Derived(copy)\n"; }
};

void process(int x) {
    
}

int main()
{
    int a[49];
    a[8] = 4;
 
    Order o4(4);
    
    std::cout << o4.y << "\n";
    
//    Derived d;
//    
//    Derived x = d;
    
}










#endif

#if 0
#include <iostream>
#include <memory>


struct One
{
    int x;
    One(int val = 10) : x(val) { std::cout << "One(" << x << ")\n"; }
    ~One() { std::cout << "~One(" << x << ")\n"; }
};

void process(const std::auto_ptr<One>& better) {
    better->x = 30;
}

void process(std::shared_ptr<One> better) {
    better->x = 30;
}

void process(One* raw) {
    raw->x = 30;
}

int main()
{
//    std::auto_ptr<One> ap(new One);
    std::shared_ptr<One> ap(new One);
    
    process(ap);

    //ap->x = 20;
    
    
//    One* ap(new One);
//    delete ap;
    
}


#endif


#if 0
#include <iostream>

class String {
public:
    String() {}
    char data[10];
    char& operator[](int position)
    {
        std::cout << "non-const\n";
        return const_cast<char&>(const_cast<const String&>(*this)[position]);
    }
    
    const char& operator[](int position) const
    {
        std::cout << "const\n";
        return data[position];
    }
};


int main() {
    const String s;

    s[0] = 'H';
    
    std::cout << s[0] << "\n";
    
    return 0;
}
#endif