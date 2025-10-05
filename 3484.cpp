

class Spreadsheet {
private:
    int R;
    unordered_map<string, int> mp;  // key: cell name like "A1", value: its stored integer

    bool isNumber(const string &s) {
        return !s.empty() && isdigit(s[0]);
    }

public:
    Spreadsheet(int rows) : R(rows) {
        // nothing else needed
    }

    void setCell(string cell, int value) {
        mp[cell] = value;
    }

    void resetCell(string cell) {
        auto it = mp.find(cell);
        if (it != mp.end()) mp.erase(it);
    }

    int getValue(string formula) {
        // Remove '='
        string s = formula.substr(1);
        auto pos = s.find('+');
        string left = s.substr(0, pos);
        string right = s.substr(pos+1);

        auto getOp = [&](const string &op)->int {
            if (isNumber(op)) {
                return stoi(op);
            } else {
                auto it = mp.find(op);
                if (it != mp.end()) return it->second;
                return 0;
            }
        };

        return getOp(left) + getOp(right);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */