class StockSpanner {
private:
    // Stack stores pairs of {price, span}
    std::stack<std::pair<int, int>> st;

public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};