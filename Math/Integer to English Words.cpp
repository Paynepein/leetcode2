class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
    	vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    	vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> thousands = {"", "Thousand", "Million", "Billion"};
        string res, tail;
        int idx = 0;
        while (num > 0) {
        	string cur;
        	if (num%1000/100 > 0) cur = " " + ones[num%1000/100] + " " + "Hundred";
        	if (num % 100 >= 20) {
        	    cur += " " + tens[num % 100 / 10];
        	    if ( num%10 > 0 ) cur += " " + ones[num % 10];
        	} else if (num%20 > 0) {
        	    cur += " " + ones[num%20];
        	}
        	if (cur.size() > 0)
        	    res = cur + " " + thousands[idx] + res;
        	num /= 1000;
        	++idx;
        }
        if (res.back() == ' ') res.erase(res.end()-1);
        return res.substr(1, res.size()-1);
    }
};