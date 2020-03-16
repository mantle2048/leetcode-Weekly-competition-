// Ë¼Â·£ºÂãÌâ
class CustomStack {
public:
    vector<int> buf;
    int top;
    CustomStack(int maxSize) {
        buf.resize(maxSize);
        top = 0;
    }
    
    void push(int x) {
        if(top >= buf.size())
            return;
        buf[top++] = x;
    }
    
    int pop() {
        if(top == 0) return -1;
        else return buf[--top];
    }
    
    void increment(int k, int val) {
        int len = min(k, (int)buf.size());
        for(int i = 0; i < len; i++)
            buf[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */