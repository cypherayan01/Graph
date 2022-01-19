#include <bits/stdc++.h>

using namespace std;


class DSU 
{
    private:
    vector<int>parent;
    vector<int>size;
    vector<int>rank;
    int count;
    public:
        DSU (int n):parent(n),size(n),rank(n),count(n)
        {
            for(int i=0;i<n;i++)
            {
                parent[i]=i;
                size[i]=1;
                rank[i]=1;
            }
        }
        
        int findPar(int node)
        {
            if(node==parent[node])
                return node;
            return parent[node]=findPar(parent[node]);
        }
        
        void unionSize(int u,int v)
        {
            int pu=findPar(u);
            int pv=findPar(v);
            
            if(pu!=pv)
            {
                if(size[pu] < size[pv]) {
			        parent[pu] = pv; 
			        size[pv] += size[pu]; 
                }
                else {
                    parent[pv] = pu; 
                    size[pu] += size[pv]; 
                }
                count--;
            }
            
        }
        
        void unionRank(int x, int y) 
        {
            int rootX = findPar(x);
            int rootY = findPar(y);
            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX] += 1;
                }
                count--;
            }
        }
        
        int getCount()
        {
            return count;
        }
    
};