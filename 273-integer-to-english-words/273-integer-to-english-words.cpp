class Solution {
private:
    string digits[20] = {   "Zero", "One", "Two", "Three", "Four", "Five",
                            "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
                            "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                            "Seventeen", "Eighteen", "Nineteen"};
    string tens[10] = { "Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
                        "Seventy", "Eighty", "Ninety"};
    
public:
    string numberToWords(int num) {
        return num ? int2string(num).substr(1) : "Zero";
    }
    
    string int2string(int num) {
        if(num >= 1000000000)
            return int2string(num / 1000000000) + " Billion" + int2string(num % 1000000000);
        else if(num >= 1000000)
            return int2string(num / 1000000) + " Million" + int2string(num % 1000000);
        else if(num >= 1000)
            return int2string(num / 1000) + " Thousand" + int2string(num % 1000);
        else if(num >= 100)
            return int2string(num / 100) + " Hundred" + int2string(num % 100);
        else if(num >= 20)
            return " " + tens[num / 10] + int2string(num % 10);
        else if(num >= 1)
            return " " + digits[num];
        else
            return "";
    }
};