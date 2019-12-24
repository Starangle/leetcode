class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        int n=A.size();
        vector<int> *link=new vector<int>[n];
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(A[i],A[j])){
                    link[i].push_back(j);
                    link[j].push_back(i);
                }
            }
        }

        int ans=0;
        bool *vis=new bool[n]{0};
        queue<int> q;
        while(true){
            int i=-1;
            for(int j=0;j<n;j++){
                if(vis[j]==0){
                    i=j;
                    break;
                }
            }
            if(i==-1)break;
            q.push(i);
            vis[i]=true;
            ans++;

            while(!q.empty()){
                i=q.front();
                q.pop();
                for(int j=0;j<link[i].size();j++){
                    int x=link[i][j];
                    if(!vis[x]){
                        q.push(x);
                        vis[x]=true;
                    }
                }
            }
        }
        return ans;

    }
    bool check(string &a,string &b){
        int n=a.size();
        int count=0;
        for(int i=0;i<n;i++){
            count+=(a[i]!=b[i]);
        }
        return count<=2;
    }
};