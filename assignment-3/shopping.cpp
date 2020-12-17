#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int max(int a, int b){
      return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n, vector<int> &v){
      int K[n+1][W+1];

      for(int i = 0; i <= n; i++){
            for(int w = 0; w <= W; w++){
                  if(i==0 || w==0)
                        K[i][w] = 0;
                  else if(wt[i-1] <= w)
                        K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
                  else
                        K[i][w] = K[i-1][w];
            }
      }

      int res = K[n][W];
      int w = W;
      for(int i = n; i > 0 && res > 0; i--){
            if(res == K[i-1][w])
                  continue;
            else{
                  v.push_back(i);
                  res = res - val[i - 1];
                  w = w - wt[i - 1];
            }
      }
      return K[n][W];
}

int main(){
      vector<vector<int> > vec(1000);
      int p[10000];
      int wt[10000];
      int M[10000];
      int F = 0;
      int N = 0;
      int T = 0;
      int max_prince = 0;

      ifstream infile;
      infile.open("shopping.txt");
      if(infile.fail()){
            cout << "Failed to open shopping.txt" << endl;
            return 0;
      }

      ofstream outfile;
      outfile.open("results.txt");
      if(outfile.fail()){
            cout << "Failed to open results.txt" << endl;
            return 0;
      }

      infile >> T;

      for(int i = 0; i < T; i++){
            infile >> N;


            for(int j = 0; j < N; j++){
                  infile >> p[j] >> wt[j];
            }


            infile >> F;

            for(int k = 0; k < F; k++){
                  infile >> M[k];
                  max_prince = max_prince + knapSack(M[k], wt, p, F, vec[k]);
            }

            cout << "Test Case " << i + 1 << endl;
            outfile << "Test Case " << i + 1 << endl;
            cout << "Total Price " << max_prince << endl;
            outfile << "Total Price " << max_prince << endl;
            cout << "Member Items " << endl;
            outfile << "Member Items " << endl;

            for(int i = 0; i < F; i++){
                  sort(vec[i].begin(), vec[i].end());
                  cout << "   " << i + 1 << ":  ";
                  outfile << "   " << i + 1 << ":  ";
                  for(int s = 0; s < vec[i].size(); s++){
                        cout << vec[i][s] << " ";
                        outfile << vec[i][s] << " ";
                  }
                  cout << endl;
                  outfile << endl;
            }

            cout << endl;
            outfile << endl;
      }

      infile.close();
      outfile.close();

      return 0;
}
