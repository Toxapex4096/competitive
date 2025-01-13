#if !__INCLUDE_LEVEL__
#include __FILE__

int main(){
    string S;
    cin >> S;
    vs divide = {"dream","dreamer","erase","eraser"};
    std::reverse(all(S));
    for(auto& d : divide){
        std::reverse(all(d));
    }
    // インデックス管理用
    ull pos = 0;
    bool can = true;
    while (pos < S.size()){
        bool can2 = false;
        for(auto& d : divide){
            if (S.substr(pos, d.size()) == d){
                can2 = true;
                pos += d.size();
                break;
            }
        }
        if(!can2){
            can = false;
            break;
        }
    }
    YESNO(can);
}

#else
#include <bits/stdc++.h>
using namespace std;
// this is for std::ranges::sort(container), std::ranges::iota_view(start, end)
using namespace std::ranges;

// clang-format off
/* accelration */
// 高速バイナリ生成
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
// cin cout の結びつけ解除, stdioと同期しない(入出力非同期化);
// cとstdの入出力を混在させるとバグるので注意;
struct Init { 
    Init() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout << setprecision(13);
    }
}init;

/* alias */
// type
using ull = unsigned long long;
using ll = long long;
using ld = long double;
// pair
using pii = pair<int,int>;
using pll = pair<ll,ll>;
// vector
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvll = vector<vll>;
using vs = vector<string>;
using vpii = vector<pii>;
// unordered set
using usi = unordered_set<int>;
using usll = unordered_set<ll>;
using uss = unordered_set<string>;

#define pb push_back
#define mp std::make_pair
template <typename K, typename V>
using um = std::unordered_map<K, V>;

// STLコンテナの要素全体を表すイテレータ範囲の簡易記法;
// std::sort(all(container))のように書ける;
// ただし、C++20が使えるならstd::ranges::sort(container)を使おう;
#define all(container) container.begin(), container.end()
#define rall(container) container.rbegin(), container.rend()

// repの代替としての、半開区間と閉区間のrangeの生成テンプレートおよび関数;
// ただし、C++20が使えるならstd::ranges::iota_view(start, end)を使おう;
template <typename T>
class Range {
    T start, stop;
    bool is_closed;

public:
    Range(T start, T stop, bool is_closed = false)
        : start(start), stop(stop), is_closed(is_closed) {}

    class iterator {
        T current;
        T stop;
        bool is_closed;

    public:
        iterator(T current, T stop, bool is_closed)
            : current(current), stop(stop), is_closed(is_closed) {}

        T operator*() const {
            return current;
        }

        iterator& operator++() {
            ++current;
            return *this;
        }

        bool operator!=(const iterator& other) const {
            return current != other.current;
        }
    };

    iterator begin() const {
        return iterator(start, stop + (is_closed ? 1 : 0), is_closed);
    }

    iterator end() const {
        return iterator(stop + (is_closed ? 1 : 0), stop, is_closed);
    }
};

template <typename T>
inline Range<T> range_until(T start, T stop) {
    return Range<T>(start, stop, false);
}

template <typename T>
inline Range<T> range_to(T start, T stop) {
    return Range<T>(start, stop, true);
}

// Yes,No出力の省略 true=yes, false=no;
inline void YESNO(bool condition) { std::cout << (condition ? "YES" : "NO") << '\n'; }
inline void yesno(bool condition) { std::cout << (condition ? "yes" : "no") << '\n'; }
inline void YesNo(bool condition) { std::cout << (condition ? "Yes" : "No") << '\n'; }

// 引数の変数名とその値を一行で(標準エラー出力へ)出力する;
template <typename T>
inline void debug(const std::string& var_name, const T& value, int line = -1) {
    std::cerr << "\033[33m";
    if (line != -1) {
        std::cerr << "(line:" << line << ") ";
    }
    std::cerr << var_name << ": " << value << "\033[m" << '\n';
}

// 改行コード、半角スペースの省略;
constexpr char el = '\n';
constexpr const char* spa = " ";

// エラー訂正のための非常に小さな小数点型の数値;
// 小数点型特有の誤差を考慮し、引数の2値が厳密に一致していなくともeps未満の差であれば一致していると返す関数;
constexpr double eps = 1e-10;

template <typename T>
inline bool Equals(T a, T b, T epsilon = static_cast<T>(eps)) {
    return std::fabs(a - b) < epsilon;
}

const double pi = 3.141592653589793238;

// 10^9より大きく、inf+infしてもオーバーフローしない数
const int inf = 1073741823;

// long long型の大きい数,2^60;
const ll infl = 1LL << 60;

// アルファベット26文字を昇順に並べた文字列のalias;
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string abc = "abcdefghijklmnopqrstuvwxyz";

// <<にstd::pairをstd::coutに直接渡せるような機能を追加する（演算子オーバーロード）;
template<typename T1, typename T2>
std::ostream &operator<< (std::ostream &os, std::pair<T1,T2> p){
    os << "{" << p.first << "," << p.second << "}";
    return os;
}

// 配列の要素を空白区切りで出力 第二引数をtrueにすると改行区切り
template<typename T> inline void print_vec(const vector<T> &v, bool split_line=false) {
    if(v.empty()){
        cout << "This vector is empty." << el;
        return;
    }
    constexpr bool isValue = is_integral<T>::value;
    for (int i = 0; i < (int)v.size(); i++) {
        if constexpr(isValue){
            if((v[i]==inf) || (v[i]==infl)) cout << 'x' << " \n"[split_line || i+1==(int)v.size()];
            else cout << v[i] << " \n"[split_line || i+1==(int)v.size()];
        }else cout << v[i] << " \n"[split_line || i+1==(int)v.size()];
    }
}

template<typename T1, typename T2> inline void print_vec(const vector<pair<T1,T2>> &v, bool split_line=false){
    if(v.empty()){
        cout << "This vector is empty." << el;
        return;
    }
    for(int i = 0; i < (int)v.size(); i++){
        cout << '{';
        auto [a,b] = v[i];
        constexpr pair<bool,bool> isValue = {is_integral<T1>::value, is_integral<T2>::value};
        if constexpr(isValue.first){
            if(a==inf || a==infl) cout << "x,";
            else cout << a << ",";
        }else cout << a << ",";
        if constexpr(isValue.second){
            if(b==inf || b==infl) cout << "x,";
            else cout << b;
        }else cout << b;
        cout << "}" << " \n"[split_line || i+1==(int)v.size()];
    }
}

// 動的計画法で使うらしい;
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
    bool compare = a < b;
    if(compare) a = b;
    return compare;
}
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
    bool compare = a > b;
    if(compare) a = b;
    return compare;
}
#include <type_traits>

// 最大公約数を計算;
// 三項演算子で書けるらしいのだが、却下した;
template <typename T>
inline T gcd(T a, T b) {
    static_assert(std::is_integral<T>::value, "T must be an integral type.");
    while (b != 0) {
        T temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 最小公倍数を計算;
template <typename T>
inline T lcm(T a, T b) {
    static_assert(std::is_integral<T>::value, "T must be an integral type.");
    return (a / gcd(a, b)) * b;
}

// aをbで割り上方向に切り上げ;
template <typename T>
inline T ceil(T a, T b) {
    static_assert(std::is_integral<T>::value, "T must be an integral type.");
    return (a + (b - 1)) / b;
}

// aをbで割り下方向に切り捨て;
template <typename T>
inline T floor(T a, T b) {
    static_assert(std::is_integral<T>::value, "T must be an integral type.");
    return a / b;
}

// 4近傍、(一般的に)上右下左;
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

// 8方向 左上, 上, 右上, 右, 右下, 下, 左下, 左;
const int dy8[8] = {-1,-1,-1,0,1,1,1,0};
const int dx8[8] = {-1,0,1,1,1,0,-1,-1};

// 範囲外アクセスを防ぐ関数;
inline bool is_out_of_bounds(uint pos_y, uint pos_x, uint height, uint width) {
    return pos_y >= height or pos_x >= width;
}

// std::chronoを利用した時間計測用クラス
class Timer{
    chrono::system_clock::time_point start;
    public:
        Timer() : start(chrono::system_clock::now()) {}
    
        double count(){
            chrono::duration<double> Time_ = chrono::system_clock::now() - start;
            return Time_.count();
        }

        bool is_under(double x){
            return (this -> count()) < x;
        }
};

// std::uniform_int_distributionを利用した一様乱数生成クラス;
// std::rand()は使わないほうが良いらしいのでこれを使う;
class Random_Gen{
    random_device seed_gen;
    mt19937 engine;
    uniform_int_distribution<int64_t> dist;
    public:
        // Constructor [l,r]で生成する値の範囲を指定
        Random_Gen() : engine(seed_gen()) {}
        Random_Gen(int64_t l, int64_t r) : engine(seed_gen()), dist(l,r) {}
        
        // 現在の生成する値の範囲をstd::pairで返す
        pair<int64_t,int64_t> get_range(){
            return make_pair(dist.min(),dist.max());
        }
        // 生成する値の範囲を[l,r]に変更する
        void set_range(int64_t l, int64_t r){
            uniform_int_distribution<int64_t>::param_type Param(l,r);
            dist.param(Param);
        }
        // [l,r]内の一様分布の整数を返す
        int64_t gen(){
            return dist(engine);
        }
        int64_t operator()(){ return gen(); }
};

#endif
