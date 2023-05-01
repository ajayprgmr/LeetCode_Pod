class Solution {
public:
    double average(vector<int>& salary) {
        int min=salary[0],max=salary[0];
        int n=salary.size();
        for(int i=0;i<n;i++){
            if(max<salary[i]){
                max=salary[i];
            }else if(salary[i]<min){
                min=salary[i];
            }
        }
           
        int salsum=accumulate(salary.begin(),salary.end(),0);
        double avgsal= (double)(salsum-min-max)/(n-2);

        return avgsal;
    }
};
