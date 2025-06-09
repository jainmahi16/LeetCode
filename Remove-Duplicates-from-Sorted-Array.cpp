class Solution {
 public:
  int removeDuplicates(vector<int>& n){
    int i = 0;
    for (int j = 1; j < n.size(); j++) 
    {
        if(n[j]!= n[i])
        {
            n[i+1] = n[j];
            i++;
        }
    }
    return(i + 1);
  }
};
  

