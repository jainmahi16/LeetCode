class Solution {
public:
    string simplifyPath(string path) {

        vector<string> token;
        auto tok = path.find('/');
        int start = 0;
        string res = \/\;

        //tokenize string
        while(tok != string::npos){
            string sub = path.substr(start, tok - start);
            token.push_back(sub);
            start = tok + 1;
            tok = path.find('/', start);
        }
        token.push_back(path.substr(start, path.size() - start));

        //canonicalize
        for(int i = 0; i < token.size(); i++){
            if(token[i] == \.\ || token[i] == \\){
                token[i] = \\;
                continue;
            }
            if(token[i] == \..\){
                for(int j = i - 1; j >= 0; j--){
                    if(token[j] != \\){
                        token[j] = \\;
                        break;
                    }
                }
                token[i] = \\;
            }
        }

        //create result
        for(auto i : token){
            if(i != \\){
                res += i;
                res += '/';
            }
        }

        //pop the last slash
        if(res.size() > 1)
            res.pop_back();

        return res;
    }
};