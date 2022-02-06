class Bitset {
public:
    string real,flipped;
    int cnt;
    
    Bitset(int size) {
        real=string(size,'0');
        flipped=string(size,'1');
        cnt=0;
    }
    
    void fix(int idx) {
        cnt+=(real[idx]=='0');
        real[idx]='1';
        flipped[idx]='0';
    }
    
    void unfix(int idx) {
        cnt-=(real[idx]=='1');
        real[idx]='0';
        flipped[idx]='1';
    }
    
    void flip() {
        string temp=real;
        real=flipped;
        flipped=temp;
        cnt=real.size()-cnt;
    }
    
    bool all() {
        return cnt==real.size();
    }
    
    bool one() {
        return cnt>=1;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        return real;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */