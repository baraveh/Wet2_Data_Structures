//
// Created by Bar The magical on 04/06/2019.
//

#ifndef WET2_DATA_STRUCTURES_PAIR_H
#define WET2_DATA_STRUCTURES_PAIR_H

template<typename T, typename S>
class Pair {
public:
    T p_first;
    S p_second;

    Pair(const T &first = T(), const S &second = S()) : p_first(first),
                                                        p_second(second) {}

    Pair &operator=(const Pair &aPair) {
        p_first = aPair.p_first;
        p_second = aPair.p_second;
        return *this;
    }

    Pair(const Pair&) = default;
    ~Pair() = default;

    bool operator==(const Pair &aPair) {
        return p_first == aPair.p_first && p_second == aPair.p_second;
    }

    bool operator!= (const Pair& aPair){
        return !(operator==(aPair));
    }

    bool operator<(const Pair &aPair) {
        return (p_first < aPair.p_first ||
                (p_first == aPair.p_first && p_second < aPair.p_second));
    }

    bool operator<=(const Pair &aPair) {
        return operator==(aPair) || operator<(aPair);
    }

    bool operator>(const Pair &aPair) {
        return !operator<=(aPair);
    }

    bool operator>=(const Pair &aPair) {
        return operator>(aPair) || operator==(aPair);
    }

    template <T,S> friend bool operator< (const Pair<T,S> &a, const Pair<T,S> &b);

    template <T,S> friend bool operator>(const Pair &a, const Pair &b);

    template <T,S> friend bool operator<=(const Pair &a, const Pair &b);

    template <T,S> friend bool operator>=(const Pair &a, const Pair &b);

    template <T,S> friend bool operator==(const Pair &a, const Pair &b);

    template <T,S> friend bool operator != (const Pair& a, const Pair& b);

    Pair operator-() const{
        return Pair(-p_first, -p_second);
    }

    Pair& operator += (const Pair& aPair){
        p_first+=aPair.p_first;
        p_second += aPair.p_second;
        return *this;
    }

    Pair& operator -= (const Pair& aPair){
        return operator+=(-(aPair));
    }

    template <T,S> friend Pair operator + (const Pair& a, const Pair& b);
    template <T,S> friend Pair operator - (const Pair& a, const Pair& b);

};

template<typename T, typename S>
bool operator<(const Pair<T, S> &a, const Pair<T, S> &b) {
    return (a.p_first < b.p_first ||
            (a.p_first == b.p_first && a.p_second < b.p_second));
}

template<typename T, typename S>
bool operator<=(const Pair<T,S> &a, const Pair<T,S> &b) {
    return operator<(a, b) || operator==(a, b);
}

template<typename T, typename S>
bool operator>(const Pair<T,S> &a, const Pair<T,S> &b) {
    return ! operator<=(a, b);
}

template<typename T, typename S>
bool operator>=(const Pair <T,S>&a, const Pair<T,S> &b) {
    return ! operator<(a, b);
}

template<typename T, typename S>
bool operator==(const Pair<T,S> &a, const Pair<T,S> &b) {
    return (a.p_first == b.p_first &&
            a.p_second == b.p_second);
}

template<typename T, typename S>
bool operator!=(const Pair<T,S> &a, const Pair<T,S> &b) {
    return !operator==(a,b);
}

template<typename T, typename S>
Pair<T,S> operator+(const Pair<T,S> &a, const Pair<T,S> &b) {
    Pair<T,S> temp = Pair<T,S>(a);
    temp += b;
    return Pair<T,S>(temp);
}

template<typename T, typename S>
Pair<T,S> operator-(const Pair<T,S> &a, const Pair<T,S> &b) {
    return operator+(a, -(b));
}


#endif //WET2_DATA_STRUCTURES_PAIR_H
