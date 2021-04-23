// two pointers
// time complexity: O(max(M, N))
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p1 = 0, p2 = 0;
        int n1 = version1.length(), n2 = version2.length();
        while (p1 < n1 || p2 < n2) {
            int v1 = 0, v2 = 0;
            while (p1 < n1 && version1[p1] != '.') {
                v1 = v1 * 10 + (version1[p1] - '0');
                p1++;
            }
            while (p2 < n2 && version2[p2] != '.') {
                v2 = v2 * 10 + (version2[p2] - '0');
                p2++;
            }
            if (v1 < v2) return -1;
            else if (v1 > v2) return 1;
            p1++; p2++;
        }
        return 0;
    }
};

// using istringstream
class Solution {
public:
    
    // Corner case 1: '01' vs '1'
    // Corner case 2: '1.0' vs '1'
    
    int compareVersion(string version1, string version2) {
        
        istringstream v1(version1);
        istringstream v2(version2);
        
        string num1, num2;
        // Consider corner case 2, we need continue the loop is either of them doesn't reach the end
        while( ! v1.eof() || ! v2.eof()) {
            if(! v1.eof()) {
                getline(v1, num1, '.');
            } else {
                num1 = "0";
            }
            
            if(! v2.eof()) {
                getline(v2, num2, '.');
            } else {
                num2 = "0";
            }
            
            // Cannot just use the string compare func since there could be leading '0's, e.g. '01' vs '1'  
            // TODO do we need consider overflow here ??!
            int n1 = stoi(num1), n2 = stoi(num2);
            
            if(n1 == n2)    continue;
            return (n1 > n2) ? 1 : - 1;
        }
        
        return 0;
    }
};
