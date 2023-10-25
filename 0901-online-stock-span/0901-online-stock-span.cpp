#include <stack>
#include <utility>
class StockSpanner {
    std::stack<std::pair<int, int>> stocks;
public:
    StockSpanner() {    
    }
    int next(int price) {
        if (this->stocks.empty() || this->stocks.top().first > price) {
            this->stocks.push(make_pair(price, 1));
        } else {
            pair<int, int> newPair = make_pair(price, 1);
            while (!this->stocks.empty() && this->stocks.top().first <= price) {
                newPair.second += this->stocks.top().second;
                this->stocks.pop();
            }
            this->stocks.push(newPair);
        }
        return this->stocks.top().second;
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */