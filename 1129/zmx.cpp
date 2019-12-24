class Solution {
public:
   
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {

        vector<vector<int>> graph(n,vector<int>(n,0x3f3f3f3f));
        vector<vector<int>> color(n,vector<int>(n,-1)); // 
        for(auto & e: red_edges){ graph[e[0]][e[1]] = 1; color[e[0]][e[1]] = 0;} 
        for(auto & e: blue_edges){ graph[e[0]][e[1]] = 1; if(color[e[0]][e[1]]==0)color[e[0]][e[1]] = 2; else color[e[0]][e[1]] = 1;  } // 一个方向的边可能既有蓝色又有红色


        // read , blue
        // vector<int> res(n,-1);
        // 选择路径的时候加上边的颜色的限制

        vector<vector<int>> min_len(2,vector<int>(n,0x3f3f3f3f));

        min_len[0][0]=0;
        min_len[1][0]=0;

        vector<vector<int>> used(2,vector<int>(n,0)); // 0 means not used,1 means used


       // vector<int> last_col(n,-1) ; // -1 means start , 0 means red , 1 means blue


       /////////

        int p = 2*n;
      
        while(p--){ 

            int red_chosen;
            int blue_chosen;
            int red_max_ = 0x3f3f3f3f; // infinite
            int blue_max_ = 0x3f3f3f3f;

            for(int i = 0 ;i < n; i++ ) {
            
                if(!used[0][i]&& min_len[0][i]<red_max_ ) { red_max_ = min_len[0][i]; red_chosen= i;}
                  if(!used[1][i]&& min_len[1][i]<blue_max_ ) { blue_max_ = min_len[1][i]; blue_chosen= i;}  
            }

            if(red_max_==0x3f3f3f3f && blue_max_==0x3f3f3f3f) break;
           
            if(red_max_!=0x3f3f3f3f){

               used[0][red_chosen] = 1;

           for(int i = 0;i<n;i++){ // 更新路径距离

                if(!used[1][i] && color[red_chosen][i] != 0 ) { // 1 or 2 

                    if(min_len[1][i]> min_len[0][red_chosen]+ graph[red_chosen][i]){
                      
                      //last_col[i] = 1- last_col[chosen];
                      min_len[1][i] = std::min(min_len[1][i], min_len[0][red_chosen]+graph[red_chosen][i]);
                     
                     } 
                     
                     }

          }
           }

          if(blue_max_!=0x3f3f3f3f){

                used[1][blue_chosen] = 1;

           for(int i = 0;i<n;i++){ // 更新路径距离

                if(!used[0][i] && color[blue_chosen][i] != 1 ) { // 1 or 2 

                    if(min_len[0][i]> min_len[1][blue_chosen]+ graph[blue_chosen][i]){
                      
                      //last_col[i] = 1- last_col[chosen];

                      min_len[0][i] = std::min(min_len[0][i], min_len[1][blue_chosen]+graph[blue_chosen][i]);
                     
                     } 
                     
                     }

          }




          }



        }



        vector<int> res(n,0x3f3f3f3f);
        for(int i = 0 ;i< n; i++ ){
           if(min_len[0][i]==0x3f3f3f3f && min_len[1][i]==0x3f3f3f3f) res[i]=-1;
           else res[i] = std::min(min_len[0][i],min_len[1][i]);
        }

        return res;
        
    }
};