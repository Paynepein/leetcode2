class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
    	string res;
    	if ((numerator ^ denominator) & (1 << 31)) res += '-';
    	long long llnumerator = numerator;
    	long long lldenominator = denominator;
    	llnumerator = abs(llnumerator);
    	lldenominator = abs(lldenominator);
        long long m = llnumerator / lldenominator;
        llnumerator %= lldenominator;
        res += to_string(m);
        if (llnumerator > 0) {
        	res += '.';
        	unordered_map<long long, int> mp;
        	int index = 0;
        	while (llnumerator != 0) {
        		if (mp.find(llnumerator) == mp.end()) {
        			mp[llnumerator] = res.size();
        			llnumerator *= 10;
        			res += to_string(llnumerator / lldenominator);
        			llnumerator %= lldenominator;
        		} else {
        			res.insert(mp[llnumerator], 1, '(');
        			res += ')';
        			break;
        		}
        	} 
        }
        return res;
    }
};