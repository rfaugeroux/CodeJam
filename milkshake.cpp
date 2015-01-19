#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {

    int C;
    scanf("%d", &C);

    for (int c = 1; c <= C; ++c) {
        int N, M;
        scanf("%d", &N);
        scanf("%d", &M);
        
        vector<vector<set<int> > > customers(M, vector<set<int> >(2));
        vector<vector<set<int> > > flavors(N, vector<set<int> >(2));
        
        vector<int> single;
                
        for (int m = 0; m < M; m++) {
            int T;
            scanf("%d", &T);
            
            if(T==1) single.push_back(m);
            
            for (int t = 0; t < T; t++) {
                int flavor, malted;
                scanf("%d", &flavor);
                scanf("%d", &malted);
                customers[m][malted].insert(flavor-1);
                flavors[flavor-1][malted].insert(m);
            }
        }
        
        vector<int> batch(N, -1);
        vector<bool> sat(M, false);
        
        bool poss = true;
        
        while (!single.empty()) {
            int cust = single.back();
            single.pop_back();
            
            if(sat[cust]) continue;
            
            int malted = customers[cust][0].empty() ? 1 : 0;
            int flavor = *customers[cust][malted].begin();
            if(batch[flavor] != -1) {
                poss = false;
                break;
            }
            
            batch[flavor] = malted;
            sat[cust] = true;
            
            set<int> happy = flavors[flavor][malted];
                
            for (set<int>::iterator it = happy.begin(); it != happy.end(); ++it) {
                    sat[*it] = true;
            }
            
            set<int> unhappy = flavors[flavor][1-malted];
            
            for (set<int>::iterator it = unhappy.begin(); it != unhappy.end(); ++it) {
                if(sat[*it]) continue;
                customers[*it][1-malted].erase(flavor);
                if(customers[*it][0].size() + customers[*it][1].size() == 1) single.push_back(*it);              
            }          
        }
        
        printf("Case #%d: ", c);
        if(poss) {
            for(vector<int>::iterator val = batch.begin(); val != batch.end(); ++val) {
                printf("%d ", (*val==1) ? 1 : 0);
            }
        } else {
            printf("IMPOSSIBLE");
        }
        printf("\n");  
    }
    return 0;
}
