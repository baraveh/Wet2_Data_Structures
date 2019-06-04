//
// Created by Bar The magical on 04/06/2019.
//

#ifndef WET2_DATA_STRUCTURES_TRIPLET_H
#define WET2_DATA_STRUCTURES_TRIPLET_H

template<typename T, typename S, typename U>
class Triplet {
public:
    T t_first;
    S t_second;
    U t_third;

    Triplet(const T &first = T(), const S &second = S(), const S &third = U())
            : t_first(first),
              t_second(second), t_third(third) {}

    Triplet &operator=(const Triplet &aTriplet) {
        t_first = aTriplet.t_first;
        t_second = aTriplet.t_second;
        t_third = aTriplet.t_third;
        return *this;
    }

    bool operator==(const Triplet &aTriplet) {
        return t_first =
               aTriplet.p_first && t_second =
                       aTriplet.p_second && t_third == aTriplet.t_third;
    }

    bool operator<(const Triplet &aTriplet) {
        return (t_first < aTriplet.t_first ||
                (t_first == aTriplet.t_first && t_second < aTriplet.t_second) ||
                (t_first == aTriplet.t_first && t_second == aTriplet.t_second &&
                 t_third < aTriplet.t_third));
    }

    bool operator<=(const Triplet &aTriplet) {
        return operator==(aTriplet) || operator<(aTriplet);
    }

    bool operator>(const Triplet &aTriplet) {
        return !operator<=(aTriplet);
    }

    bool operator>=(const Triplet &aTriplet) {
        return operator>(aTriplet) || operator==(aTriplet);
    }

    friend bool operator<(const Triplet &a, const Triplet &b);

    friend bool operator>(const Triplet &a, const Triplet &b);

    friend bool operator<=(const Triplet &a, const Triplet &b);

    friend bool operator>=(const Triplet &a, const Triplet &b);

    friend bool operator==(const Triplet &a, const Triplet &b);

};

template<typename T, typename S, typename U>
bool operator<(const Triplet<T, S, U> &a, const Triplet<T, S, U> &b) {
    return (a.t_first < b.t_first ||
            (a.t_first == b.t_first && a.t_second < b.t_second) ||
            (a.t_first == b.t_first && a.t_second == b.t_second &&
             a.t_third < b.t_third));
}

template<typename T, typename S, typename U>
bool operator<=(const Triplet<T, S, U> &a, const Triplet<T, S, U> &b) {
    return operator<(a, b) || operator==(a, b);
}

template<typename T, typename S, typename U>
bool operator>(const Triplet<T, S, U> &a, const Triplet<T, S, U> &b) {
    return !operator<=(a, b);
}

template<typename T, typename S, typename U>
bool operator>=(const Triplet<T, S, U> &a, const Triplet<T, S, U> &b) {
    return !operator<(a, b);
}

template<typename T, typename S, typename U>
bool operator==(const Triplet<T, S, U> &a, const Triplet<T, S, U> &b) {
    return (a.t_first == b.t_first &&
            a.t_second == b.t_second && a.t_third == b.t_third);
}


#endif //WET2_DATA_STRUCTURES_TRIPLET_H
