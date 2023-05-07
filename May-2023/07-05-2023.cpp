
class{
public:
    string stringMirror(string str){
        string rev = str;
        reverse(rev.begin(), rev.end());

        int n = str.size();
        int ans = n;
        for (int k = 1; k < n; k++) {
            if (str[k] <= str[ans]) ans = k;
        }

        string prefix = str.substr(0, ans+1);
        string suffix = prefix.substr(0, (n-ans-1));
        reverse(suffix.begin(), suffix.end());

        return prefix + suffix;
    }
};
